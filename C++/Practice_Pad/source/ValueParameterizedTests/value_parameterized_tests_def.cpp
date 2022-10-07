#include "pch.h"
#include "LinkedList.h"
#include "LinkedListT.h"
#include "practice_exceptions.h"
#include "valueParam_tests.h"

// 1. Create a fixture class
// 2. TEST_P is the test case
// 3. INSTANTIATE_TEST_CASE_P

class testLinkedList : public testing::Test, public testing::WithParamInterface<int> {
 
protected:


    void testLinkedList::SetUp() override {
        std::cout << "Setup " << std::to_string(GetParam()) << std::endl;
    }
    void testLinkedList::TearDown() override {
        std::cout << "TearDown" << std::endl;
    }
    
    LinkedList q0;  
};

TEST_P(testLinkedList, BasicTest) {
    q0 = LinkedList(GetParam());
    ASSERT_EQ(q0.getLength(), GetParam());
}

INSTANTIATE_TEST_CASE_P(TestValueParameter, testLinkedList, testing::Range(1, 4));

/////////////////////////////////////////////////////////////////////////////////////
// 1. Define the fixture class in a header file
// 2. Define the TEST_P in the .cpp file
// 3. In another source file, invoke INSTANTIATE_TEST_SUITE_P
TEST_P(BarTest, FirstBarTest) {
    std::string answer;
    m_queue.EmptyQueueIntoString(answer);
    std::cout << answer << std::endl;
    std::cout << m_answer_key << std::endl;

    ASSERT_TRUE(m_answer_key == answer);
}