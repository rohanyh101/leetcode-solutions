#include <iostream>
#include <vector>

std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {
    std::vector<bool> result;
    int current = 0;

    for (int num : nums) {
        current = (current << 1 | num) % 5;
        result.push_back(current == 0);
    }

    return result;
}

int main() {
    std::vector<int> nums = {0, 1, 1};
    std::vector<bool> result = prefixesDivBy5(nums);

    for (bool val : result) {
        std::cout << (val ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    return 0;
}