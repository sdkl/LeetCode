#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> winMap;
		for (auto i : t)
			winMap[i]--;
				
		int start = 0, len = -1;
		for (int j = 0, tNum = t.length(); j < s.length() && tNum > 0; j++)
		{
			if (winMap.count(s[j]) > 0)
			{
				winMap[s[j]]++;
				if (winMap[s[j]] <= 0)
					tNum--;				
			}
			len++;
			if (j + 1 == s.length() && tNum > 0)
				return "";
		}

		while (winMap.count(s[start]) == 0 || (winMap.count(s[start]) > 0 && winMap[s[start]] > 0))
		{
			if (winMap.count(s[start]) > 0)
				winMap[s[start]]--;
			start++;
			len--;
		}
				
		int left = start, right = start + len;
		bool finish = false;
		do{			
			int old = right;
			while (!finish && right + 1 < s.length())
			{
				if (winMap.count(s[++right])> 0)
				{
					winMap[s[right]]++;
					if (s[right] == s[left])
						break;	
				}
				if (right + 1 == s.length() && (winMap.count(s[right]) > 0 || s[right] != s[left]))
				{
					finish = true;
					right = old;
				}
			}

			while (winMap.count(s[left]) == 0 || (winMap.count(s[left]) > 0 && winMap[s[left]] > 0))
			{
				if (winMap.count(s[left]) > 0)
					winMap[s[left]]--;
				left++;
			}	

			if (len > right - left)
			{
				len = right - left;
				start = left;
			}
		} while (!finish && right + 1 < s.length());

		return s.substr(start,len+1);
	}
};

int main()
{
	Solution s;
	cout << s.minWindow("A1OBECO2EBANC", "ABC").c_str() << endl;
	cout << s.minWindow("aa", "aa").c_str() << endl;
	cout << s.minWindow("cabefgecdaecf","cae").c_str() << endl;
	cout << s.minWindow("bba", "ab").c_str() << endl;
	cout << s.minWindow("bbaac","aba").c_str() << endl;
	cout << s.minWindow("abcabdebac","cda").c_str() << endl;

	getchar();
	return 0;
}