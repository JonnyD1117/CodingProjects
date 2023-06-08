#include <gtest/gtest.h>
#include "../LinkedList.h"


TEST(TestLinkedListBasic, ListDefaultConstructor) {
    LinkedList<int> List;
    EXPECT_EQ(&List.getHead(), nullptr);
}

TEST(TestLinkedListBasic, ListOverloadConstructor) {
    LinkedList<int> List(5);

    EXPECT_NE(&List.getHead(), nullptr);
}

//TEST(TestLinkedListBasic, ListDestructor) {
//
//    LinkedList<int> myList;
//
//}

TEST(TestLinkedListBasic, TestAddToList) {

    LinkedList<int> List;

    List.Add(7);
    List.Add(8);
    List.Add(9);

    int _size = List.size();
    EXPECT_EQ(_size, 3);

    List.Add(999);

    _size = List.size();
    EXPECT_EQ(_size, 4);

}

TEST(TestLinkedListBasic, TestRemoveFromList) {

    LinkedList<int> List;

    List.Add(7);
    List.Add(8);
    List.Add(9);

    int _size = List.size();
    EXPECT_EQ(_size, 3);

    List.Remove();

    _size = List.size();
    EXPECT_EQ(_size, 2);
}

TEST(TestLinkedListBasic, TestClearList) {
    LinkedList<int> List;

    List.Add(7);
    List.Add(8);
    List.Add(9);

    EXPECT_GT(List.size(), 0);

    List.clear();

    EXPECT_EQ(List.size(), 0);
}

TEST(TestLinkedListBasic, TestEmptyList) {
    LinkedList<int> List;

    List.Add(7);
    List.Add(8);
    List.Add(9);

    EXPECT_FALSE(List.empty());
    List.clear();
    EXPECT_TRUE(List.empty());

}

//TEST(TestLinkedListBasic, TestForwardIterator) {
//}
//
//TEST(TestLinkedListBasic, TestReverseIterator) {
//}


