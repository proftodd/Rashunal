#include <stdlib.h>
#include "unity.h"
#include "rashunal.h"

const int SIZER = sizeof(Rashunal);
static int signal_sent;
void fpe_handler(int sig)
{
    signal_sent = 1;
}
static void (*orig_handler)(int);

void setUp()
{
    signal_sent = 0;
    orig_handler = signal(SIGFPE, fpe_handler);
}

void tearDown()
{
    signal(SIGFPE, orig_handler);
}

void test_n_Rashunal_normalizes_numerator_and_denominator()
{
    Rashunal *a = n_Rashunal(-1, -2);
    Rashunal *e1 = n_Rashunal(1, 2);
    Rashunal *b = n_Rashunal(1, -2);
    Rashunal *c = n_Rashunal(24, 36);
    Rashunal *e2 = n_Rashunal(2, 3);
    Rashunal *d = n_Rashunal(0, 2);
    TEST_ASSERT_EQUAL_MEMORY(e1, a, SIZER);
    TEST_ASSERT_EQUAL(-1, b->numerator);
    TEST_ASSERT_EQUAL(2, b->denominator);
    TEST_ASSERT_EQUAL_MEMORY(e2, c, SIZER);
    TEST_ASSERT_EQUAL(0, d->numerator);
    TEST_ASSERT_EQUAL(1, d->denominator);
    free(a);
    free(b);
    free(c);
    free(d);
    free(e1);
    free(e2);
}

void test_n_Rashunal_raises_SIGFPE_if_denominator_is_zero()
{
    Rashunal *a = n_Rashunal(1, 0);
    TEST_ASSERT_NOT_EQUAL(0, signal_sent);
    free(a);
}

void test_add()
{
    Rashunal* a = n_Rashunal(1, 2);
    Rashunal* b = n_Rashunal(1, 3);
    Rashunal* c = r_add(a, b);
    Rashunal *e = n_Rashunal(5, 6);
    TEST_ASSERT_EQUAL(5, c->numerator);
    TEST_ASSERT_EQUAL(6, c->denominator);
    TEST_ASSERT_EQUAL_MEMORY(e, c, sizeof(Rashunal));
    free(a);
    free(b);
    free(c);
    free(e);
}

void test_sub()
{
    Rashunal* a = n_Rashunal(1, 2);
    Rashunal* b = n_Rashunal(1, 3);
    Rashunal* c = r_sub(a, b);
    TEST_ASSERT_EQUAL(1, c->numerator);
    TEST_ASSERT_EQUAL(6, c->denominator);
    free(a);
    free(b);
    free(c);
}

void test_mul()
{
    Rashunal* a = n_Rashunal(1, 2);
    Rashunal* b = n_Rashunal(1, 3);
    Rashunal* c = r_mul(a, b);
    TEST_ASSERT_EQUAL(1, c->numerator);
    TEST_ASSERT_EQUAL(6, c->denominator);
    free(a);
    free(b);
    free(c);
}

void test_div()
{
    Rashunal* a = n_Rashunal(1, 2);
    Rashunal* b = n_Rashunal(1, 3);
    Rashunal* c = r_div(a, b);
    TEST_ASSERT_EQUAL(3, c->numerator);
    TEST_ASSERT_EQUAL(2, c->denominator);
    free(a);
    free(b);
    free(c);
}

void test_div_raises_SIGFPE_if_denominator_is_zero()
{
    Rashunal *a = n_Rashunal(1, 2);
    Rashunal *b = n_Rashunal(0, 1);
    Rashunal *q = r_div(a, b);
    TEST_ASSERT_NOT_EQUAL(0, signal_sent);
    free(a);
    free(b);
    free(q);
}

void test_inv()
{
    Rashunal* a = n_Rashunal(1, 2);
    Rashunal* b = r_inv(a);
    TEST_ASSERT_EQUAL(2, b->numerator);
    TEST_ASSERT_EQUAL(1, b->denominator);
    free(a);
    free(b);
}

void test_inv_raises_SIGFPE_if_numerator_is_zero()
{
    Rashunal *a = n_Rashunal(0, 1);
    Rashunal *q = r_inv(a);
    TEST_ASSERT_NOT_EQUAL(0, signal_sent);
    free(a);
    free(q);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_n_Rashunal_normalizes_numerator_and_denominator);
    RUN_TEST(test_n_Rashunal_raises_SIGFPE_if_denominator_is_zero);
    RUN_TEST(test_add);
    RUN_TEST(test_sub);
    RUN_TEST(test_mul);
    RUN_TEST(test_div);
    RUN_TEST(test_div_raises_SIGFPE_if_denominator_is_zero);
    RUN_TEST(test_inv);
    RUN_TEST(test_inv_raises_SIGFPE_if_numerator_is_zero);

    return UNITY_END();
}
