#include<iostream>
using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		int strLen = s.length();
		int maxLen = 1, start = 0, left, right;

		for (int i = 0; i < strLen - 1; i++)
		{			
			int num = 2;
			
			do{		
				if (num == 2)
					left = i;
				else
					left = i - 1;
				right = i + 1;
				
				while (left >= 0 && right < strLen)
				{
					if (s[left] != s[right] || (left == 0 || right == strLen - 1))
					{
						if (s[left] == s[right])
						{
							left--;
							right++;
						}
						if (maxLen < (right - left -1))
						{
							maxLen = right - left - 1;
							start = left + 1;
						}
						break;
					}

					left--;
					right++;
				}				
				num--;
			} while (num > 0);
		}

		return s.substr(start, maxLen);
	}

};

int main()
{
	Solution s;
	cout << s.longestPalindrome("ccc").c_str() << endl;

	system("PAUSE");
	return 0;
}