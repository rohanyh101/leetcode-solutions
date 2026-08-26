#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>

int minAreaRect(std::vector<std::vector<int>>& points) {
    std::unordered_set<std::string> pointSet;
    for (const auto& point : points) {
        pointSet.insert(std::to_string(point[0]) + "," + std::to_string(point[1]));
    }

    int minArea = INT_MAX;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                std::string p1 = std::to_string(points[i][0]) + "," + std::to_string(points[j][1]);
                std::string p2 = std::to_string(points[j][0]) + "," + std::to_string(points[i][1]);
                if (pointSet.count(p1) && pointSet.count(p2)) {
                    int area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
                    minArea = std::min(minArea, area);
                }
            }
        }
    }

    return minArea == INT_MAX ? 0 : minArea;
}

int main() {
    std::vector<std::vector<int>> points = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
    std::cout << minAreaRect(points) << std::endl;
    return 0;
}