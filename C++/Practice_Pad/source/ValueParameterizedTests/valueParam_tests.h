#include "pch.h"
#include "DualStackQueue.h"

// Define value-parameterized tests in a library and let others instantiate them later

// 1. Define the fixture class in a header file
// 2. Define the TEST_P in the .cpp file
// 3. In another source file, invoke INSTANTIATE_TEST_SUITE_P
class BarTest : public testing::Test, public testing::WithParamInterface<const char*> {
public:
	
	std::string m_answer_key;
	DSQueue m_queue;

	void BarTest::SetUp() override {
		m_answer_key = std::string(GetParam());
		m_queue = DSQueue();

		for (int i = 0; i < 8; i++) {
			m_queue.add(i);
		}
	}
};

