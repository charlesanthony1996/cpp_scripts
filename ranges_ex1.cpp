#include <ranges>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::unordered_map<int, std::string> number_to_text = {
        {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"},
        {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"}
    };

    std::vector<int> even_numbers;
    for (int n : numbers | std::views::filter([](int n) { return n % 2 == 0;}))
        even_numbers.push_back(n);

    std::map<int, std::string> text_numbers_map;
    for (int n: even_numbers) {
        text_numbers_map[n] = number_to_text.contains(n) ? number_to_text[n] : "unknown";
    }



    std::cout << "Even numbers: ";
    for (int n : even_numbers) std::cout << n << " ";
    std::cout << "\n Textual numbers:\n";
    for (const auto& [k, v] : text_numbers_map)
        std::cout << k << " -> " << v << "\n";
}