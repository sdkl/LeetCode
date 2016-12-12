#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		vector<char> p;
		for (int i = 0; i < s.size(); i++)
		{
			if ((s[i] - 'a' >= 0 && s[i] - 'z' <= 0) || (s[i] - '0' >= 0 && s[i] - '9' <= 0))
				p.push_back(s[i]);
			else if (s[i] - 'A' >= 0 && s[i] - 'Z' <= 0)
				p.push_back(s[i] - 'A' + 'a');
		}

		int pSize = p.size() - 1;
		for (int i = 0; i <= pSize; i++)
		{
			if (p[i] != p[pSize - i])
				return false;
		}

		return true;
	}
};

int main()
{
	Solution s;
	cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << s.isPalindrome("0p") << endl;

	getchar();
	return 0;
}