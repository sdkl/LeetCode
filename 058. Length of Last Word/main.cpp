#include<iostream>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0, i = s.length() - 1;
		while (i >= 0 && s[i] == ' ')
			i--;
		for (; i >= 0 && s[i] != ' '; i--, len++);
		return len;
	}
};


int main()
{
	Solution s;
	cout << s.lengthOfLastWord("Hello World") << endl;
	cout << s.lengthOfLastWord("H ") << endl;

	getchar();
	return 0;
}