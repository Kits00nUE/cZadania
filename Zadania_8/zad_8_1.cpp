#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to replace word representations of numbers with numeric
void replace_word_with_number(std::string& str, const std::string& word, char number) {
    size_t pos = str.find(word);
    while (pos != std::string::npos) {
        str[pos] = number;
        str.erase(pos + 1, word.length() - 1);
        pos = str.find(word);
    }
}

int main() {
    std::ifstream input_file("C:\\Users\\phant\\CLionProjects\\cZadania\\Zadania_7\\input.txt");
    std::ofstream output_file("C:\\Users\\phant\\CLionProjects\\cZadania\\Zadania_7\\output.txt");

    std::string line;
    while (std::getline(input_file, line)) {
        replace_word_with_number(line, "one", '1');
        replace_word_with_number(line, "two", '2');
        replace_word_with_number(line, "three", '3');
        replace_word_with_number(line, "four", '4');
        replace_word_with_number(line, "five", '5');
        replace_word_with_number(line, "six", '6');
        replace_word_with_number(line, "seven", '7');
        replace_word_with_number(line, "eight", '8');
        replace_word_with_number(line, "nine", '9');

        auto first_digit_pos = std::find_if(line.begin(), line.end(), ::isdigit);
        auto last_digit_pos = std::find_if(line.rbegin(), line.rend(), ::isdigit);

        if (first_digit_pos != line.end() && last_digit_pos != line.rend()) {
            output_file << *first_digit_pos << *last_digit_pos << '\n';
        }
    }

    input_file.close();
    output_file.close();

    return 0;
}