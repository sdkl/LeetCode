#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char,int> RomanValues;
		RomanValues['M'] = 1000;
		RomanValues['D'] = 500;
		RomanValues['C'] = 100;
		RomanValues['L'] = 50;
		RomanValues['X'] = 10;
		RomanValues['V'] = 5;
		RomanValues['I'] = 1;

		int len = s.size(),result = 0;
		for (int i = 0; i < len; i++)
		{
			if (i != len - 1 && RomanValues[s[i]] < RomanValues[s[i + 1]])
				result -= RomanValues[s[i]];
			else
				result += RomanValues[s[i]];
		}

		return result;
	}
};

int main()
{
	Solution s;
	cout << s.romanToInt("MCMLXXVI") << endl;

	system("PAUSE");
	return 0;
}