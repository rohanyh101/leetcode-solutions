#include <iostream>
#include <vector>

int heightChecker(std::vector<int>& heights) {
    std::vector<int> expected = heights;
    std::sort(expected.begin(), expected.end());
    
    int count = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
        if (heights[i] != expected[i]) {
            count++;
        }
    }
    
    return count;
}

int main() {
    std::vector<int> heights = {1, 1, 4, 2, 1, 3};
    std::cout << heightChecker(heights) << std::endl;
    return 0;
}