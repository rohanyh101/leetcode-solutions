#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> two_sum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        
        mp[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = two_sum(nums, target);
    cout << "Indices of the two numbers that add up to " << target << ": [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}