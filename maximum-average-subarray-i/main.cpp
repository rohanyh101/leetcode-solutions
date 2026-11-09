#include <iostream>
#include <vector>

double findMaxAverage(std::vector<int>& nums, int k) {
    int n = nums.size();
    double max_avg = -1e9;
    double current_sum = 0;

    for (int i = 0; i < k; ++i) {
        current_sum += nums[i];
    }
    max_avg = current_sum / k;

    for (int i = k; i < n; ++i) {
        current_sum += nums[i] - nums[i - k];
        max_avg = std::max(max_avg, current_sum / k);
    }

    return max_avg;
}

int main() {
    std::vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result = findMaxAverage(nums, k);
    std::cout << "Maximum average subarray: " << result << std::endl;
    return 0;
}
