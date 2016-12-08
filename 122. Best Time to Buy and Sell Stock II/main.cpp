#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxP = 0, minP = INT_MAX, pre = INT_MAX;

		prices.push_back(0);
		for (auto i:prices)
		{
			if (i < pre)
			{
				maxP += pre - minP;
				minP = i;
			}
			pre = i;
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