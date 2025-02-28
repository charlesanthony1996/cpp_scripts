#include <iostream>
#include <vector>

std::vector<std::vector<int>> chunk(std::vector<int> arr, int size) {
    std::vector<std::vector<int>> chunkedArray;
    std::vector<int> temp;

    for (size_t i = 0; i < arr.size(); i++) {
        temp.push_back(arr[i]);

        if (temp.size() == size || i == arr.size() - 1) {
            chunkedArray.push_back(temp);
            temp.clear();
        }
    }
    return chunkedArray;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int size = 3;
    
    auto result = chunk(arr, size);

    for (const auto& group : result) {
        for (int num: group ) std::cout << num << " ";
        std::cout << std::endl;
    }
    return 0;
}