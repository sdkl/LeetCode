#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	vector<string> getVector(int e, vector<vector<int>>& splite, string& s)
	{
		if (e < 0)	return {};

		vector<string> result;
		for (auto i : splite[e])
		{
			if (i == 0)
				result.push_back(s.substr(0, e));
			else
			{
				vector<string> l = getVector(i, splite, s);
				for (auto j : l)
					result.push_back(j + " " + s.substr(i, e-i));
			}
		}

		return result;
	}

	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> isInDict(s.size() + 1);
		vector<string> result;
		vector<vector<int>> splite(s.size() + 1);
		isInDict[0] = true;

		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (isInDict[j])
				{
					string str = s.substr(j,i-j);
					if (wordDict.count(str) > 0)
					{
						isInDict[i] = true;
						splite[i].push_back(j);
					}						
				}
			}
		}

		result = getVector(s.size(), splite,s);

		return result;
	}
};

int main()
{
	Solution s;
	unordered_set<string> w = { "cat", "cats", "and", "sand", "dog" };
	auto a = s.wordBreak("catsanddog", w);
	for (auto i : a)
		cout << i.c_str() << endl;

	getchar();
	return 0;
}