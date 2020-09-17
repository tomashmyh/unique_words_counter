#pragma once

#include <unordered_set>
#include <string>
#include <istream>

namespace {
constexpr size_t INPUT_SIZE = 1024;
}

namespace helper {
size_t calculate_unique_words(std::istream& input, size_t read_block_size = INPUT_SIZE);
} // namespace helper
