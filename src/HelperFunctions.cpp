#include "HelperFunctions.h"

namespace {
constexpr uint8_t MIN_READ_BLOCK_SIZE = 8;
}

namespace helper {
size_t calculate_unique_words(std::istream& input, size_t read_block_size) {
    if (read_block_size < MIN_READ_BLOCK_SIZE){
        // TODO: Add logs
        return 0;
    }
    char input_line[read_block_size];
    size_t read_line_size = 0;
    std::unordered_set<size_t> unique_word_ids;

    std::string new_word;
    new_word.reserve(read_block_size);
    do{
        input.get( input_line, read_block_size, '\0' );
        read_line_size = input.gcount();

        size_t start = 0;
        size_t end = start;

        while(end != read_line_size) {
            while(std::isspace(input_line[start] ) && (start != read_line_size) ) {
                ++start;
            }
            if (start == read_line_size){
                break;
            }
            if (start != 0 && !new_word.empty()){
                unique_word_ids.emplace(std::hash<std::string>{}(new_word));
                new_word.clear();
            }
            end = start;
            while(!std::isspace(input_line[end]) && (end != read_line_size)) {
                ++end;
            }

            // TODO: Word beginning can be too long in case there are no spaces(
            new_word.append(input_line + start, end - start);
            if(!std::isspace(input_line[end - 1] ) && (end == read_line_size)){
                break;
            }

            unique_word_ids.emplace(std::hash<std::string>{}(new_word));
            new_word.clear();
            start = end;
       }
    }while(!input.eof() && !input.fail() && (read_line_size == (read_block_size - 1)));

    if (!new_word.empty()){
        unique_word_ids.emplace(std::hash<std::string>{}(new_word));
    }

    return unique_word_ids.size();
}
} // namespace helper

