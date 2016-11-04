#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n+1, 0);
		dp[0] = dp[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}		

		return dp[n];
	}
};

int main()
{
	Solution s;
	int r = s.numTrees(8);
	cout << r<<endl;

	getchar();
	return 0;
}