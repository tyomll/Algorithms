#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Interval {
	public:
		int start;
		int end;

		Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> mergeIntervals(vector<Interval> intervals) {
	if (intervals.empty()) {
		return {};
	}

	vector<Interval> result;

	for (int i = 0; i < intervals.size(); ++i) {
		int currentStart = intervals[i].start;
		int currentEnd = intervals[i].end;

		while (i < intervals.size() - 1 && currentEnd >= intervals[i + 1].start) {
			currentEnd = max(currentEnd, intervals[i + 1].end);
			i++;
		}

		result.push_back(Interval(currentStart, currentEnd));
	}

	return result;
}

int main() {
	vector<Interval> intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};

	vector<Interval> mergedIntervals = mergeIntervals(intervals);

	for (const auto& interval : mergedIntervals) {
		cout << "[" << interval.start << ", " << interval.end << "] ";
	}
	cout << endl;

	return 0;
}

