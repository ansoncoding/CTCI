#include "pch.h"

class FooTest : public testing::TestWithParam<const char*> {};

class BaseTest : public testing::Test {};

class BarTest : public BaseTest, public testing::TestWithParam<const char *> { };

TEST_P(FooTest, DoesBlah) {
	std::cout << "Example Test Param: " << GetParam() << std::endl;
}

INSTANTIATE_TEST_CASE_P(MeenyMinyMoe, FooTest, testing::Values("MEENY", "MINY", "MOE"));

class MyTestSuite : public testing::TestWithParam<int> {};

TEST_P(MyTestSuite, MyTest) {
	std::cout << "Example Test Param: " << GetParam() << std::endl;
}

INSTANTIATE_TEST_CASE_P(RangeTest, MyTestSuite, testing::Range(0, 10));
#if 1
int main(int argc, char ** argv) {
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
}
#endif