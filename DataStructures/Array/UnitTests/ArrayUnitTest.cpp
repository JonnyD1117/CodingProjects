#include <gtest/gtest.h>
#include "../Array.h"


TEST(TestArrayMethods, TestArrayDefaultConstructor) {
    Array<int, 5> myArray();
    EXPECT_TRUE(true);
}

TEST(TestArrayMethods, TestArraySizeMethod) {
    const size_t expected_len = 10;
    Array<int, expected_len> array;

    int length = array.size();
    EXPECT_EQ(length, expected_len);

}

TEST(TestArrayMethods, TestArrayATMethod) {


    const size_t expected_len = 10;
    Array<int, expected_len> array;

    int multipler = 3;
    int desire_index = 4;
    int expected_value = desire_index * multipler;

    for(int i =0 ; i< expected_len; i++)
    {
        array[i] = 3*i;
    }

    EXPECT_EQ(array[desire_index], expected_value);
}

TEST(TestArrayMethods, TestArrayFrontMethod) {

    const size_t length = 10;
    Array<int, length> array;

    int multipler = 3;
    int expected_value = 0;

    for(int i =0 ; i< length; i++)
    {
        array[i] = multipler*i;
    }

    EXPECT_EQ(array.front(), expected_value);
}

TEST(TestArrayMethods, TestArrayBackMethod) {


    const size_t length = 10;
    Array<int, length> array;

    int multipler = 3;
    int expected_value = (length-1)*multipler;

    for(int i =0 ; i< length; i++)
    {
        array[i] = multipler*i;
    }

    EXPECT_EQ(array.back(), expected_value);
}

TEST(TestArrayMethods, TestArrayEmptyMethod) {

    const size_t empty_length = 0;
    const size_t length = 10;

    Array<int,empty_length> empty_array;
    Array<int, length> array;

    EXPECT_TRUE(empty_array.empty());
    EXPECT_FALSE(array.empty());

}

TEST(TestArrayMethods, TestArrayDataMethod) {


    const size_t length = 10;
    Array<int, length> array;

    int multipler = 3;

    for(int i =0 ; i< length; i++)
    {
        array[i] = multipler*i;
    }

    int* arr_ptr = array.data();

    EXPECT_NE(arr_ptr, nullptr);

    int offset = 3;
    int expected_value = offset* multipler;

    arr_ptr += offset;

    EXPECT_EQ(*arr_ptr, expected_value);
}

TEST(TestArrayIterator, TestArrayRangeBasedForLoop) {

    const size_t length = 10;
    Array<int, length> array;

    int multipler = 3;

    for(int i =0 ; i< length; i++)
    {
        array[i] = multipler*i;
    }

    int ctr = 0;
    for(auto i : array)
    {
        EXPECT_EQ(i,ctr*multipler);
        ctr++;
    }
}

TEST(TestArrayIterator, TestArrayForwardIterator) {

    const size_t length = 10;
    Array<int, length> array;

    int multipler = 3;

    for(int i =0 ; i< length; i++)
    {
        array[i] = multipler*i;
    }

    int ctr = 0;
    for (iterator<int> it = array.begin(); it != array.end(); ++it) {

        EXPECT_EQ(*it, ctr*multipler);
        ctr++;
    }
}

TEST(TestArrayIterator, TestArrayReverseIterator) {

    const size_t length = 10;
    Array<int, length> array;

    int multipler = 3;

    for(int i =0 ; i< length; i++)
    {
        array[i] = multipler*i;
    }

    int ctr = length;
    for (reverse_iterator<int> it = array.rbegin(); it != array.rend(); ++it) {
        ctr--;
        EXPECT_EQ(*it, ctr*multipler);
    }
}

TEST(TestArrayIterator, TestArrayIndexAccessOperator) {

    const size_t length = 10;
    Array<int, length> array;

    int multipler = 3;

    for(int i =0 ; i< length; i++)
    {
        array[i] = multipler*i;
    }

//    int ctr = 0;
//    for (iterator<int> it = array.begin(); it != array.end(); ++it) {
//
//        std::cout<< it[]
////
////        EXPECT_EQ(*it, ctr*multipler);
////        ctr++;
//    }

    iterator<int> it = array.begin();

    for (int j=0; j<length; j++)
    {
//        std::cout<< it[j] << std::endl;
//        std::cout<< it[j] << std::endl;
    }
}

TEST(TestArrayIterator, TestArrayArrowDereferenceOperator) {

    const size_t length = 10;
    Array<int, length> array;

    int multipler = 3;

    for(int i =0 ; i< length; i++)
    {
        array[i] = multipler*i;
    }

    iterator<int> it = array.begin();

    for (int j=0; j<length; j++)
    {
//        std::cout<< it[j] << std::endl;
        *it = 5;
        std::cout<< *it << std::endl;
        ++it;
    }
}