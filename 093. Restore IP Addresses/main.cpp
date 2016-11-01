#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		if (s.length() > 12 || s.length() < 4)
			return{};
		vector<string> result;
		vector<vector<int>> dp(s.length()+2, vector<int>(3,0));
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < dp.size() - 2; j++)
			{
				dp[j][i] = i == 0 ? s[j] - '0' : dp[j][i - 1] * 10 + dp[j + i][0];

				if (i != 0 && dp[j][i - 1] == 0)
					dp[j][i] = 256;
			}				
		}

		for (int i = 1; i <= 3 && i < s.length(); i++)
		{
			for (int j = 1; j <= 3 && j + i < s.length(); j++)
			{
				for (int k = 1; k <= 3 && k + j + i < s.length(); k++)
				{
					int l = s.length() - i - j - k;
					if (l > 3)
						continue;

					if (dp[0][i - 1] < 256 && dp[i][j - 1] < 256 && dp[i + j][k - 1] < 256 && dp[i + j + k][l - 1] < 256)
					{
						string t(s);
						t.insert(i + j + k, ".");
						t.insert(i + j, ".");
						t.insert(i , ".");
						result.push_back(t);
					}
				}
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	//vector<string> v = s.restoreIpAddresses("25525511135");
	vector<string> v = s.restoreIpAddresses("010010");
	for (auto i : v)
		cout << i.c_str() << endl;

	getchar();
	return 0;
}