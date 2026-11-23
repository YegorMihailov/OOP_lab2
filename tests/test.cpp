#include <gtest/gtest.h>
#include "../include/my_string.h"

TEST(StringTest, DefaultConstructor) {
    String s;
    EXPECT_EQ(s.size(), 0);
    EXPECT_EQ(s.capacity(), 1);
    EXPECT_STREQ(s.c_str(), "");
}

TEST(StringTest, CStringConstructor) {
    String s("A");
    EXPECT_EQ(s.size(), 1);
    EXPECT_STREQ(s.c_str(), "A");
}

TEST(StringTest, CopyConstructor) {
    String s1("Hello");
    String s2(s1);
    EXPECT_EQ(s2.size(), 5);
    EXPECT_STREQ(s2.c_str(), "Hello");
    EXPECT_NE(s1.c_str(), s2.c_str());
}

TEST(StringTest, MoveConstructor) {
    String s1("Hello");
    String s2(std::move(s1));
    EXPECT_STREQ(s2.c_str(), "Hello");
    EXPECT_EQ(s1.c_str(), nullptr);
}

TEST(StringTest, CopyAssignment) {
    String s1("Original");
    String s2;
    s2 = s1;
    EXPECT_STREQ(s2.c_str(), "Original");
}

TEST(StringTest, SelfAssignment) {
    String s("Self");
    s = s;
    EXPECT_STREQ(s.c_str(), "Self");
}

TEST(StringTest, MoveAssignment) {
    String s1("Temp");
    String s2("Old");
    s2 = std::move(s1);
    EXPECT_STREQ(s2.c_str(), "Temp");
}

TEST(StringTest, PushBack) {
    String s;
    s.push_back('a');
    EXPECT_EQ(s.capacity(), 1);
    s.push_back('b');
    EXPECT_EQ(s.capacity(), 2);
    s.push_back('c');
    EXPECT_EQ(s.capacity(), 4);
    EXPECT_STREQ(s.c_str(), "abc");
}

TEST(StringTest, AppendEmptyString) {
    String s("Hello");
    s.append("");
    EXPECT_STREQ(s.c_str(), "Hello");
    EXPECT_EQ(s.size(), 5);
}

TEST(StringTest, CountChar) {
    String s("Hello");
    EXPECT_EQ(s.count_char('l'), 2);
}

TEST(StringTest, CountCharNotFound) {
    String s("Hello");
    EXPECT_EQ(s.count_char('z'), 0);
}

TEST(StringTest, CountCharEmpty) {
    String s;
    EXPECT_EQ(s.count_char('a'), 0);
}