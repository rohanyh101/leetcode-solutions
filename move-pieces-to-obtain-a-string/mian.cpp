#include <iostream>
#include <vector>

bool canChange(std::string start, std::string target) {
    int n = start.size();
    int i = 0, j = 0;

    while (i < n || j < n) {
        while (i < n && start[i] == '_') i++;
        while (j < n && target[j] == '_') j++;

        if (i == n && j == n) return true;
        if (i == n || j == n) return false;
        if (start[i] != target[j]) return false;

        if (start[i] == 'L' && i < j) return false;
        if (start[i] == 'R' && i > j) return false;

        i++;
        j++;
    }

    return true;
}


int main() {
    std::vector<std::pair<std::string, std::string>> test_cases = {
        {"R_L_", "__LR"},
        {"_L__R__R_", "L______RR"},
        {"_R", "R_"},
        {"L_R_", "_LR_"},
        {"_L__R__R_", "L______RR"},
        {"R_L_", "__LR"},
        {"_R", "R_"},
        {"L_R_", "_LR_"}
    };

    for (const auto& [start, target] : test_cases) {
        std::cout << (canChange(start, target) ? "true" : "false") << std::endl;
    }
}