#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (words.size() == 0 || words[0].length() == 0)
			return result;

		int size = words.size(), len = words[0].length();
		unordered_map<string, int> wMap;
		for (auto i : words)
			wMap[i]++;
		
		for (int i = 0; i < len; i++)
		{
			unordered_map<string, int> match;
			int cur = i,matchCount = 0;
			while (cur + len <= s.length())
			{
				string str = s.substr(cur, len);
				if (wMap.count(str) == 0)
				{
					match.clear();
					matchCount = 0;
				}
				else
				{
					match[str]++;
					matchCount++;
					if (match[str] > wMap[str])
					{
						string tmp = "";
						while (tmp != str)
						{
							tmp = s.substr(cur - ((matchCount - 1)*len), len);
							match[tmp]--;
							matchCount--;
						}						
					}
					else if (match[str] == wMap[str] && matchCount == size)
					{
						result.push_back(cur - ((matchCount - 1)*len));
						match[s.substr(cur - ((matchCount - 1)*len), len)]--;
						matchCount--;
					}
				}
				cur += len;
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<string> param;
	param.push_back("foo");
	param.push_back("bar");
	param.push_back("the");
	vector<int> result = s.findSubstring("barfoofoobarthefoobarman", param);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] <<endl;

	system("PAUSE");
	return 0;
}