#include "pch.h"
#include "ArrayList.h"


TEST(ArrayListTests, Initializing) {
    ArrayList al = ArrayList();
    EXPECT_EQ(al.getSize(), 0);
    EXPECT_EQ(al.getCapacity(), 8);
    EXPECT_TRUE(al.isEmpty());
}

TEST(ArrayListTests, AddGetElements) {
    
    ArrayList al = ArrayList();
    int retval;

    al.add(1);
    EXPECT_EQ(al.getSize(), 1);
    EXPECT_TRUE(al.contains(1, retval));
    EXPECT_EQ(retval, 0);
    EXPECT_EQ(al.get(retval), 1);

    al.add(3);
    EXPECT_EQ(al.getSize(), 2);
    EXPECT_TRUE(al.contains(3, retval));
    EXPECT_EQ(retval, 1);
    EXPECT_EQ(al.get(retval), 3);

    al.add(5);
    EXPECT_EQ(al.getSize(), 3);
    EXPECT_TRUE(al.contains(5, retval));
    EXPECT_EQ(retval, 2);
    EXPECT_EQ(al.get(retval), 5);
}

TEST(ArrayListTests, SetElement) {
    ArrayList al = ArrayList();
    int retval;

    al.add(1);
    EXPECT_TRUE(al.contains(1, retval));
    al.set(retval, 11);
    EXPECT_FALSE(al.contains(1, retval));
    EXPECT_TRUE(al.contains(11, retval));
    EXPECT_EQ(al.get(retval), 11);
}

TEST(ArrayListTests, RemoveElements) {

    ArrayList al = ArrayList();
    int retval;

    al.add(1);
    EXPECT_EQ(al.getSize(), 1);
    EXPECT_TRUE(al.contains(1, retval));
    EXPECT_EQ(retval, 0);

    al.remove(0);
    EXPECT_EQ(al.getSize(), 0);
    EXPECT_FALSE(al.contains(1, retval));
}

TEST(ArrayListTests, CapacityTest) {

    ArrayList al = ArrayList();
    for (int i = 0; i < 8; i++) {
        al.add(i * 10);
    }

    EXPECT_EQ(al.getSize(), 8);
    EXPECT_EQ(al.getCapacity(), 8);

    al.add(80);
    EXPECT_EQ(al.getSize(), 9);
    EXPECT_EQ(al.getCapacity(), 16);

    // ensure all values got copied over correctly
    int retval;
    for (int i = 0; i < 8; i++) {
        EXPECT_TRUE(al.contains(i * 10, retval));
        EXPECT_EQ(al.get(retval), i * 10);
    }
    
    //=============== 2nd time capacity expands =====================

    for (int i = 9; i < 16; i++) {
        al.add(i * 10);
    }

    EXPECT_EQ(al.getSize(), 16);
    EXPECT_EQ(al.getCapacity(), 16);

    al.add(160);
    EXPECT_EQ(al.getSize(), 17);
    EXPECT_EQ(al.getCapacity(), 32);

    // ensure all values got copied over correctly
    for (int i = 0; i < 17; i++) {
        EXPECT_TRUE(al.contains(i * 10, retval));
        EXPECT_EQ(al.get(retval), i * 10);
    }
}

TEST(ArrayListTests, InvalidIndex) {
    ArrayList al = ArrayList();
    for (int i = 0; i < 100; i++) {
        al.add(i << 2);
    }
    
    EXPECT_THROW(al.get(-1), OutofBoundsException);
    EXPECT_THROW(al.get(-10), OutofBoundsException);
    EXPECT_THROW(al.get(100), OutofBoundsException);
    EXPECT_THROW(al.get(200), OutofBoundsException);
    EXPECT_THROW(al.set(-1,  22), OutofBoundsException);
    EXPECT_THROW(al.set(-10, 22), OutofBoundsException);
    EXPECT_THROW(al.set(100, 22), OutofBoundsException);
    EXPECT_THROW(al.set(200, 22), OutofBoundsException);
    EXPECT_THROW(al.remove(-1), OutofBoundsException);
    EXPECT_THROW(al.remove(-10), OutofBoundsException);
    EXPECT_THROW(al.remove(100), OutofBoundsException);
    EXPECT_THROW(al.remove(200), OutofBoundsException);
}