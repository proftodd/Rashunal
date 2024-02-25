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

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_gcd);
    RUN_TEST(test_lcm);

    return UNITY_END();
}
