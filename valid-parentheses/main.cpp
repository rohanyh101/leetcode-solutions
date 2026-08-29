#include <iostream>
#include <vector>

bool isValid(const std::string& s) {
    std::vector<char> stack;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push_back(c);
        } else {
            if (stack.empty()) {
                return false;
            }
            char top = stack.back();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') ||(c == ']' && top != '[')) {
                return false;
            }
            stack.pop_back();
        }
    }

    return stack.empty();
}

int main() {
    // Test cases
    std::vector<std::string> tests = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
    };

    for (const std::string& test : tests) {
        if (isValid(test)) {
            std::cout << "\"" << test << "\" is valid\n";
        } else {
            std::cout << "\"" << test << "\" is invalid\n";
        }
    }

    return 0;
}