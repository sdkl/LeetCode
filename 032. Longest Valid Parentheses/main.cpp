#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;
		int head = 0,max = 0;
		
		while (true)
		{
			while (head < s.length() - 1 && s[head] != '(') head++;
			if (head >= s.length() - 1)
				break;

			int curLen = 0,val = 0,i;
			vector<int> oldLen;
			for (i = head; i < s.length(); i++)
			{
				if (s[i] == '(')
				{
					val++;
					oldLen.push_back(curLen);
					curLen = 0;
				}
				else
				{
					val--;
					if (val < 0)
						break;
					else if (val >= 0)
					{
						curLen += 2+oldLen.back();
						max = curLen > max ? curLen : max;
						oldLen.pop_back();
					}
				}				
			}
			oldLen.clear();

			head = i;
		}

		return max;
	}
};

int main()
{
	Solution s;
	cout << s.longestValidParentheses("()(())") << endl;

	system("PAUSE");
	return 0;
}