#include <iostream>
#include <vector>

std::vector<std::vector<int>> powerset(const std::vector<int>& arr) {
    std::vector<std::vector<int>> result;
    result.push_back({});

    for (int i = 0; i < arr.size(); i++) {
        int current = arr[i];
        
        std::vector<std::vector<int>> newsubsets;

        for (int j = 0; j < result.size(); j++) {
            std::vector<int> subset = result[j];

            std::vector<int> newsubset;

            for (int k = 0; k < subset.size(); k++) {
                newsubset.push_back(subset[k]);
            }

            newsubset.push_back(current);
            newsubsets.push_back(newsubset);
        }

        for (int m = 0; m < newsubsets.size(); m++) {
            result.push_back(newsubsets[m]);
        }
    }

    return result;
}

int main() {
    std::vector<int> input = {1, 2};
    std::vector<std::vector<int>> result = powerset(input);

    std::cout << "Powerset:\n";
    for (int i = 0; i < result.size(); i++) {
        std::cout << "{";
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << "}\n";
    }
    return 0;
}