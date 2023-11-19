#include <iostream>
#include <vector>

using IntervalsType = std::vector<std::vector<int>>;

IntervalsType mergeIntervals(const IntervalsType& intervals) {
    IntervalsType result;

    for (int i = 0; i < intervals.size() - 1; i++) {
        for (int j = 1; j < intervals.size(); j++) {
            if (intervals[i][0] <= intervals[j][0] &&
                intervals[i][1] >= intervals[j][0]) {
                std::vector<int> newInterval = {intervals[i][0],
                                                intervals[j][1]};
                result.push_back(newInterval);
            } else {
                result.push_back(intervals[j]);
            }
            i = j;
        }
    }

    return result;
}

void printIntervals(const IntervalsType& intervals) {
    for (size_t i = 0; i < intervals.size(); i++) {
        std::cout << "[ ";
        for (size_t j = 0; j < intervals[i].size(); j++) {
            std::cout << intervals[i][j] << ", ";
        }
        std::cout << "]";
    }
    std::cout << std::endl;
}

int main() {
    IntervalsType intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    printIntervals(mergeIntervals(intervals));
    return 0;
}