#include <iostream>
#include <vector>
#include <algorithm>

void mergeIntervals(std::vector<std::pair<int, int>>& intervals) {
    if (intervals.empty()) {
        return;
    }
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::pair<int, int>> result;
    result.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
        if (result.back().second >= intervals[i].first) {
            result.back().second = std::max(result.back().second, intervals[i].second);
        } else {
            result.push_back(intervals[i]);
        }
    }

    intervals = result;
}

void print(const std::vector<std::pair<int, int>>& intervals) {
    for (const auto& interval : intervals) {
        std::cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    mergeIntervals(intervals);
    print(intervals);
    return 0;
}
