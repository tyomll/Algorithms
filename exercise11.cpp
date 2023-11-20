#include <iostream>
#include <vector>

struct range {
    int start;
    int end;
};
std::vector<range> merge(std::vector<range>& input_ranges) {
    std::vector<range> merged;
    if (input_ranges.empty()) {
        return merged;
    }
    range current_range = input_ranges[0];
    for (int i = 1; i < input_ranges.size(); ++i) {
        if (input_ranges[i].start <= current_range.end) {
            current_range.end = std::max(current_range.end, input_ranges[i].end);
        } else {
            merged.push_back(current_range);

            current_range = input_ranges[i];
        }
    }
    merged.push_back(current_range);
    return merged;
}

int main() {
    std::vector<range> input = {{1, 3}, {2, 6}, {8, 13}, {15, 18}};
    std::vector<range> result = merge(input);
    for (const auto& range : result) {
        std::cout << "[" << range.start << ", " << range.end << "] ";
    }
    std::cout << "\n";
    return 0;
}
