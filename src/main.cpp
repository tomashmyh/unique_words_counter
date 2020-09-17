#include "HelperFunctions.h"

#include <iostream>

int main(int argc, char** argv) {

    const size_t unique_word_count = helper::calculate_unique_words(std::cin);

    const auto& input_state = std::cin.rdstate();
    if ( (input_state & std::istream::failbit ) != 0 ) {
        std::cout << "Logical error on i/o operation\n";
    } else if ( (input_state & std::istream::badbit ) != 0 ) {
        std::cout << "	Read/writing error on i/o operation\n";
    } else {
        std::cout << "There are " << unique_word_count << " unique words" << std::endl;
    }

    return 0;
}

