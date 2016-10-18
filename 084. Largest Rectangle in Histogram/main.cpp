#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int max = 0;
		vector<int> v;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); i++)
		{
			while (!v.empty() && heights[v.back()] > heights[i])
			{
				int cur = v.back();
				v.pop_back();
				int b = v.empty() ? -1 : v.back();
				max = std::max(max, (i - b - 1)*heights[cur]);
			}
			v.push_back(i);
		}
		return max;
	}
};

int main()
{
	Solution s;
	//vector<int> v = { 2, 1, 5, 6, 2, 3 };
	vector<int> v = { 2, 1, 2 };
	cout << s.largestRectangleArea(v) << endl;

	getchar();
	return 0;
}