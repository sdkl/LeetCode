#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
		for (int i = 0; i < dp.size(); i++)
			dp[i][0] = i;
		for (int j = 0; j < dp[0].size(); j++)
			dp[0][j] = j;

		for (int i = 1; i < dp.size(); i++)
		{
			for (int j = 1; j < dp[i].size(); j++)
			{
				if (word1[i-1] == word2[j-1])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}

		return dp[word1.length()][word2.length()];
	}
};

int main()
{
	Solution s;
	cout << s.minDistance("a", "b") << endl;
	cout << s.minDistance("sea","ate") << endl;
	cout << s.minDistance("sea", "eat") << endl;
	cout << s.minDistance("dinitrophenylhydrazine","acetylphenylhydrazine") << endl;

	getchar();
	return 0;
}