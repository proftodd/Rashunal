#include "unity.h"
#include "rashunal_util.h"

void setUp()
{

}

void tearDown()
{

}

void test_gcd()
{
    int g = gcd(24, 36);
    TEST_ASSERT_EQUAL(12, g);
}

void test_lcm()
{
    int l = lcm(24, 36);
    TEST_ASSERT_EQUAL(72, l);
}

void test_count_digits()
{
    int n1 = 32;
    int n2 = -529;
    int n3 = 10;
    TEST_ASSERT_EQUAL(2, count_digits(n1));
    TEST_ASSERT_EQUAL(4, count_digits(n2));
    TEST_ASSERT_EQUAL(2, count_digits(n3));
}

void test_count_digits_radix() {

}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_gcd);
    RUN_TEST(test_lcm);
    RUN_TEST(test_count_digits);

    return UNITY_END();
}
