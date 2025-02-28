#include <string>
#include <iostream>
#include <unordered_map>

bool matches(const std::unordered_map<std::string, std::string>& obj,const std::unordered_map<std::string, std::string>& source) {
    for (const auto& pair: source) {
        auto it = obj.find(pair.first);
        if (it == obj.end() || it-> second != pair.second) {
            return false;
        }
    }
    return true;
}


int main() {
    std::unordered_map<std::string, std::string> obj1 = { {"age", "25"}, {"hair", "long"}, {"beard", "true"}};
    std::unordered_map<std::string, std::string> obj2 = { {"age", "25"}, {"hair", "short"}, {"beard", "true"}};
    std::unordered_map<std::string, std::string> obj3 = { {"hair", "short"}, {"beard", "true"}};


    std::cout << std::boolalpha;
    std::cout << matches(obj1, obj2) << std::endl;
    std::cout << matches(obj2, obj3) << std::endl;
    return 0;


}