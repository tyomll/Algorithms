#include <iostream>
#include <vector>

std::vector<std::vector<int>> merge_intervals(const std::vector<std::vector<int>>& intervals) {

    std::vector<std::vector<int>> merged;
    merged.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= merged.back()[1]) {
            merged.back()[1] = std::max(intervals[i][1], merged.back()[1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}


int main() {
    
    std::vector<std::vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> merged_intervals1 = merge_intervals(intervals1);
    std::cout << "Merged Intervals 1: ";
    
    for (const auto& interval : merged_intervals1) {
        std::cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}

