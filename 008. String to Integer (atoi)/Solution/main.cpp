#include<iostream>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int result = 0;
		if (str == "")
			return result;
		bool negative = str[0] == '-';
		bool firstNum = true;
		int zero = '0',blank = ' ',maxMod = INT_MAX % 10,minMod = INT_MIN % 10 * -1;

		for (int i = 0; i < str.length(); i++)
		{
			int ascii = str[i];
			if (ascii == blank && firstNum)
				continue;

			if (firstNum)
			{
				firstNum = false;
				negative = str[i] == '-';
				if (negative || str[i] == '+')
					continue;
			}			

			if (ascii < zero || ascii > zero + 9)
				break;

			ascii -= zero;

			if ((negative && (result < INT_MIN / 10 || (result == INT_MIN / 10 && ascii > minMod))) || (!negative && (result > INT_MAX / 10 || (result == INT_MAX / 10 && ascii > maxMod))))
				return negative ? INT_MIN : INT_MAX;
			result = negative ? result * 10 - ascii : result * 10 + ascii;
		}

		return result;
	}
};

int main()
{
	Solution s;
	cout << s.myAtoi("") << endl;
	cout << s.myAtoi("123g") << endl;
	cout << s.myAtoi("g123") << endl;	
	cout << s.myAtoi("-2147483649") << endl;
	cout << s.myAtoi("    10522545459") << endl;
	cout << s.myAtoi("   -010a12") << endl;
	cout << s.myAtoi("   +010") << endl;
	cout << s.myAtoi("123.15") << endl;
	cout << s.myAtoi("-123") << endl;
	cout << s.myAtoi("+123") << endl;
	cout << s.myAtoi("2364") << endl;
	cout << s.myAtoi("   +0 123") << endl;

	system("PAUSE");
	return 0;
}