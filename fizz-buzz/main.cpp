#include <iostream>
#include <vector>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> result;
    
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            result.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
            result.push_back("Fizz");
        } else if (i % 5 == 0) {
            result.push_back("Buzz");
        } else {
            result.push_back(std::to_string(i));
        }
    }

    return result;
}

int main() {
    int n = 15;
    std::vector<std::string> result = fizzBuzz(n);
    for (const std::string& str : result) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}