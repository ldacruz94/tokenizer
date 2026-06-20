
#include <gtest/gtest.h>
#include "tokenizer.h"

TEST(TokenizerTest, SingleCharacter) {
  Tokenizer t;
  auto result = t.tokenize("a");
  EXPECT_EQ(result.size(), 1);
}

TEST(TokenizerTest, CommonWord) {
  Tokenizer t;
  auto result = t.tokenize("the");
  EXPECT_FALSE(result.empty());
}

TEST(TokenizerTest, MultiWord) {
  Tokenizer t;
  auto result = t.tokenize("hello world");
  EXPECT_FALSE(result.empty());
}

TEST(TokenizerTest, ExactId) {
  Tokenizer t;
  auto result = t.tokenize("lowest");
  EXPECT_EQ(result[0], 9319);
  EXPECT_EQ(result[1], 395);
}

TEST(TokenizerTest, Empty) {
  Tokenizer t;
  auto result = t.tokenize("");
  EXPECT_TRUE(result.empty());
}

TEST(TokenizerTest, SingleSpace) {
  Tokenizer t;
  auto result = t.tokenize(" ");
  EXPECT_EQ(result.size(), 1);
}

TEST(TokenizerTest, Numbers) {
  Tokenizer t;
  auto result = t.tokenize("123");
  EXPECT_FALSE(result.empty());
}

TEST(TokenizerTest, RepeatedWord) {
  Tokenizer t;
  auto first = t.tokenize("the");
  auto second = t.tokenize("the");
  EXPECT_EQ(first, second);
}
