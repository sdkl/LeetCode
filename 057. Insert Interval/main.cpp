#include<iostream>
#include<vector>
using namespace std;


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {		
		if (intervals.empty())
			intervals.push_back(newInterval);
		else
		{
			int j = 0, del = -1, s = newInterval.start, e = newInterval.end;
			for (; j < intervals.size(); j++)
			{
				if (newInterval.end < intervals[j].start)
					break;
				else if (newInterval.start > intervals[j].end)
					continue;
				else
				{
					if (del < 0)
						del = j;
					if (intervals[j].start < s) s = intervals[j].start;
					if (intervals[j].end > e) e = intervals[j].end;
				}
			}

			intervals.insert(intervals.begin() + j, Interval(s, e));
			if (del >= 0)
				intervals.erase(intervals.begin() + del, intervals.begin() + j);
		}

		return intervals;
	}
};


int main()
{
	Solution s;
	vector<Interval> result = s.insert(vector<Interval>({ Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) }), Interval(4, 9));
	for (auto i : result)
	{
		cout << "[" << i.start << "," << i.end << "] ";
	}

	getchar();
	return 0;
}