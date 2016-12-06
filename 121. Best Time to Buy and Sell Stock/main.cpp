#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxP = 0,minP = INT_MAX;

		for (auto i : prices)
		{
			maxP = max(maxP, i - minP);
			minP = min(minP, i);
		}

		return maxP;
	}
};

int main()
{
	Solution s;
	vector<int> p = { 7, 1, 5, 3, 6, 4 };
	cout << s.maxProfit(p) << endl;

	getchar();
	return 0;
}