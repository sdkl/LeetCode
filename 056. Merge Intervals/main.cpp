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
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;

		for (auto i : intervals)
		{
			if (result.empty())
				result.push_back(i);
			else
			{
				int j = 0, del = -1, s = i.start, e = i.end;
				for (; j < result.size(); j++)
				{
					if (i.end < result[j].start)
						break;
					else if (i.start > result[j].end)
						continue;
					else
					{
						if (del < 0)
							del = j;
						if (result[j].start < s) s = result[j].start;
						if (result[j].end > e) e = result[j].end;
					}
				}

				result.insert(result.begin()+j, Interval(s, e));
				if (del >= 0)
					result.erase(result.begin() + del, result.begin() + j);
			}
		}

		return result;
	}
};


int main()
{
	Solution s;
	vector<Interval> result = s.merge(vector<Interval>({ Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18) }));
	for (auto i : result)
	{
		cout << "[" << i.start << "," << i.end << "] ";
	}

	getchar();
	return 0;
}