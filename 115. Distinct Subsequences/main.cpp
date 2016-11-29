#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int size_s = s.size(), size_t = t.size();
		vector<vector<int>> dp(size_t + 1, vector<int>(size_s + 1, 0));
		for (int j = size_s; j >= 0; j--)
			dp[size_t][j] = 1;
		dp[0][0] = 0;

		for (int i = size_t - 1; i >= 0; i--)
		{
			int cur = 0;
			for (int j = size_s - (size_t-i); j >= 0; j--)
			{
				if (t[i] == s[j])
					cur += dp[i + 1][j + 1];
				dp[i][j] = cur;				
			}
		}

		return dp[0][0];
	}
};

int main()
{
	Solution s;
	cout << s.numDistinct("rabbbit", "rabbit")<<endl;
	cout << s.numDistinct("ddd", "dd") << endl;
	cout << s.numDistinct("ddd", "d") << endl;

	getchar();
	return 0;
}