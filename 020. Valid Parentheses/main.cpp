#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		vector<char> match;
		unordered_map<char,char> charMap;
		charMap['('] = ')';
		charMap['['] = ']';
		charMap['{'] = '}';

		for (int i = 0; i < s.length(); i++)
		{
			if (charMap.find(s[i]) == charMap.end())
			{
				if (match.size() <= 0)
					return false;
				if (s[i] != match.back())
					return false;
				match.pop_back();
			}
			else
			{
				match.push_back(charMap[s[i]]);
			}		
		}

		return match.size() == 0;
	}
};

int main()
{
	Solution s;
	cout << s.isValid("()[]{}") << endl;
	cout << s.isValid("([])") << endl;
	cout << s.isValid("([)]") << endl;
	cout << s.isValid("(") << endl;

	system("PAUSE");
	return 0;
}