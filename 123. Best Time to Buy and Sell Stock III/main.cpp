#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<vector<int>> dp(2, vector<int>(prices.size()+1, 0));

		int maxP = 0, minP = INT_MAX,size = prices.size();
		for (int i = 0; i < size; i++)
		{
			maxP = max(maxP, prices[i] - minP);
			minP = min(minP, prices[i]);
			dp[0][i+1] = maxP;
		}

		maxP = 0, minP = 0;
		for (int i = size - 1; i >= 0; i--)
		{
			maxP = max(maxP, minP - prices[i]);
			minP = max(minP, prices[i]);
			dp[1][i] = maxP;
		}
		maxP = 0;
		for (int i = 0; i <= size; i++)
		{
			maxP = max(maxP, dp[0][i] + dp[1][i]);
		}

		return maxP;
	}
};

int main()
{
	Solution s;
	//vector<int> p = { 1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
	vector<int> p = { 7, 1, 5, 3, 6, 4 };
	cout << s.maxProfit(p) << endl;

	getchar();
	return 0;
}