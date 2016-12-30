#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
	unordered_set<string> badDict;
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		if (wordDict.count(s) > 0)
			return true;
		for (int i = 1; i < s.size(); i++)
		{
			if (badDict.count(s.substr(0, i)) == 0 && badDict.count(s.substr(i, s.size() - i)) == 0 && wordBreak(s.substr(0, i), wordDict) && wordBreak(s.substr(i, s.size() - i), wordDict))
			{
				wordDict.insert(s);
				return true;
			}
			else
				badDict.insert(s);
		}
		return false;
	}
};

int main()
{
	Solution s;
	unordered_set<string> wordDict = { "fohhemkkaecojceoaejkkoedkofhmohkcjmkggcm", "nami", "hkcjmkggcmna", "mi" };
	cout << s.wordBreak("fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami",wordDict) << endl;

	getchar();
	return 0;
}