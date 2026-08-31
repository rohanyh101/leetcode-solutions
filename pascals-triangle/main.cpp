#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> triangle;

    for (int i = 0; i < numRows; ++i) {
        std::vector<int> row(i + 1, 1); // Initialize the row with 1s

        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; // Calculate the value based on the previous row
        }

        triangle.push_back(row);
    }

    return triangle;
}

int main() {
    int n = 5;
    std::vector<std::vector<int>> triangle = generate(n);

    for (const auto& row : triangle) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}