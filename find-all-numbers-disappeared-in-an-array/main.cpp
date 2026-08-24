#include <iostream>
#include <vector>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    std::vector<int> result;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        int index = std::abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> result = findDisappearedNumbers(nums);
    for (int num : result) {
        std::cout << num << " ";
    }
    
    return 0;
}