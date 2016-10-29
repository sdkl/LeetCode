#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {	
		if (s.empty())
			return 0;
		
		int len = s.length();
		vector<int> dp(len+1,0);
		dp[len] = 1;
		dp[len - 1] = s[len-1] != '0' ? 1 : 0;		
		for (int i = len - 2; i >= 0; i--)
		{
			if (s[i] != '0')
				dp[i] = ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26) ? dp[i + 1] + dp[i + 2] : dp[i + 1];
		}

		return dp[0];
	}
};

int main()
{
	Solution s;
	cout << s.numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565") << endl;
	cout << s.numDecodings("10") << endl;

	getchar();
	return 0;
}