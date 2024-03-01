#include <stdlib.h>
#include "unity.h"
#include "rashunal.h"

const int SIZER = sizeof(Rashunal);

void setUp()
{

}

void tearDown()
{

}

void test_n_Rashunal_normalizes_numerator_and_denominator()
{
    Rashunal *a = n_Rashunal(-1, -2);
    Rashunal *e1 = n_Rashunal(1, 2);
    Rashunal *b = n_Rashunal(1, -2);
    Rashunal *c = n_Rashunal(24, 36);
    Rashunal *e2 = n_Rashunal(2, 3);
    TEST_ASSERT_EQUAL_MEMORY(e1, a, SIZER);
    TEST_ASSERT_EQUAL(-1, b->numerator);
    TEST_ASSERT_EQUAL(2, b->denominator);
    TEST_ASSERT_EQUAL_MEMORY(e2, c, SIZER);
    free(a);
    free(b);
    free(c);
    free(e1);
    free(e2);
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

void test_inv()
{
    Rashunal* a = n_Rashunal(1, 2);
    Rashunal* b = r_inv(a);
    TEST_ASSERT_EQUAL(2, b->numerator);
    TEST_ASSERT_EQUAL(1, b->denominator);
    free(a);
    free(b);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_n_Rashunal_normalizes_numerator_and_denominator);
    RUN_TEST(test_add);
    RUN_TEST(test_sub);
    RUN_TEST(test_mul);
    RUN_TEST(test_div);
    RUN_TEST(test_inv);

    return UNITY_END();
}
