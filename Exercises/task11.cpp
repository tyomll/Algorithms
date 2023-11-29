#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

void printList(std::list<std::pair<int, int>>& list) {
    std::cout << "[";
    for (auto element = list.begin(); element != list.end(); ++element) {
        std::cout << "[" << element->first << ", " << element->second << "]";
        if (std::next(element) != list.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

std::list<std::pair<int, int>> mergeIntervals(const std::list<std::pair<int, int>>& intervals) {
    if (intervals.empty()) {
        return intervals;
    }

    std::list<std::pair<int, int>> result;
    std::vector<std::pair<int, int>> sortedIntervals(intervals.begin(), intervals.end());
    for (const auto& interval : sortedIntervals) {
        if (result.empty() || result.back().second < interval.first) {
            result.push_back(interval);
        } else {
            result.back().second = std::max(result.back().second, interval.second);
        }
    }

    return result;
}

int main() {
    std::list<std::pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::list<std::pair<int, int>> result = mergeIntervals(intervals);
    printList(result);

    return 0;
}