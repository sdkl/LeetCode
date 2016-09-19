#include<iostream>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		bool oneDot = false, oneE = false, anyNum = false;
		int begin = 0,end = s.length() - 1;
		while (begin < s.length() && s[begin] == ' ')
			begin++;

		while (end > begin && s[end] == ' ')
			end--;

		for (int i = begin; i <= end; i++)
		{
			char c = s[i];
			switch (c)
			{				
				case '+':
				case '-':
				{
					if (i != begin && s[i - 1] != 'e')
						return false;
					
				}
				break;
				case '.':
				{
					if (oneDot)
						return false;
					oneDot = true;
				}
				break;
				case 'e':
				{
					if (oneE || !anyNum)
						return false;
					oneE = true;
					oneDot = true;
					anyNum = false;
				}
				break;
				case ' ':
				{
					return false;
				}
				break;
				default:
				{
					if (c - '0' < 0 || c - '0' > 9)
						return false;
					anyNum = true;
				}
				break;
			}
		}

		return anyNum;
	}
};

int main()
{
	Solution s;
	cout << s.isNumber("0") << endl;
	cout << s.isNumber(" 0.1 ") << endl;
	cout << s.isNumber("2e10") << endl;
	cout << s.isNumber(".1") << endl;
	cout << s.isNumber(" -54.53061") << endl;
	cout << s.isNumber("abc") << endl;
	cout << s.isNumber("1 a") << endl;
	cout << s.isNumber("e") << endl;
	cout << s.isNumber("0e") << endl;
	cout << s.isNumber(".") << endl;
	cout << s.isNumber(" ") << endl;
	cout << s.isNumber(". 1") << endl;
	cout << s.isNumber("5+1") << endl;
	cout << s.isNumber("6e6.5") << endl;

	getchar();
	return 0;
}