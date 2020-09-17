#include "gtest/gtest.h"
#include "HelperFunctions.h"

#include <sstream>

namespace{
TEST(TestUniqueWordsCounter, line_with_one_word_with_size_less_then_read_block_size) {
    std::stringstream ss;
    ss << "fhjky";
    EXPECT_EQ(1, helper::calculate_unique_words(ss, 8));
}

TEST(TestUniqueWordsCounter, line_with_spaces_only) {
    std::stringstream ss;
    ss << "                           ";
    EXPECT_EQ(0, helper::calculate_unique_words(ss, 8));
}

TEST(TestUniqueWordsCounter, empty_line) {
    std::stringstream ss;
    ss << "";
    EXPECT_EQ(0, helper::calculate_unique_words(ss, 8));
}

TEST(TestUniqueWordsCounter, line_with_one_word_with_size_more_then_read_block_size) {
    std::stringstream ss;
    ss << "fhjkytyytytfdfgdgfgfr";
    EXPECT_EQ(1, helper::calculate_unique_words(ss, 8));
}

TEST(TestUniqueWordsCounter, line_with_multiple_different_words) {
    std::stringstream ss;
    ss << "fh jkyt yyt yt fdfgdg fgfr";
    EXPECT_EQ(6, helper::calculate_unique_words(ss, 8));
}

TEST(TestUniqueWordsCounter, line_with_multiple_identical_words) {
    std::stringstream ss;
    ss << "fh fh fh fh fh fh";
    EXPECT_EQ(1, helper::calculate_unique_words(ss, 8));
}

TEST(TestUniqueWordsCounter, line_with_multiple_words) {
    std::stringstream ss;
    ss << "a horse and a dog";
    EXPECT_EQ(4, helper::calculate_unique_words(ss, 8));
}

TEST(TestUniqueWordsCounter, line_with_words_in_between_read_block) {
    std::stringstream ss;
    ss << "mj ki poiuyt jkui ki poiuyt";
    EXPECT_EQ(4, helper::calculate_unique_words(ss, 8));
}

TEST(TestUniqueWordsCounter, default_read_block_size) {
    std::stringstream ss;
    ss << "mj ki poiuyt jkui ki poiuyt";
    EXPECT_EQ(4, helper::calculate_unique_words(ss));
}

TEST(TestUniqueWordsCounter, line_with_spaces_at_the_beginning) {
    std::stringstream ss;
    ss << "     a h o r s e a n d a d o g";
    EXPECT_EQ(9, helper::calculate_unique_words(ss, 8));
}
}  // namespace

