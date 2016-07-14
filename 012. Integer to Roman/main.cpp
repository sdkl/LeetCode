#include<iostream>
using namespace std;


class Solution {
public:
	string intToRoman(int num) {
		string result = "";
		char RomanChars[] = {'I','V','X','L','C','D','M'};
		int RomanValues[] = {1,5,10,50,100,500,1000};
		int subValue = 0;
		char subChar;

		for (int i = 6; i >= 0; i--)
		{		
			while (num >= RomanValues[i])
			{
				result += RomanChars[i];
				num -= RomanValues[i];
			}		
			
			if (RomanValues[i] != 1)
			{
				subValue = RomanValues[i] / RomanValues[i-1] == 2 ? RomanValues[i] * 9 / 10 : RomanValues[i] - RomanValues[i] / 5;
				subChar = RomanValues[i] / RomanValues[i-1] == 2 ? RomanChars[i - 2] : RomanChars[i - 1];
				if (num >= subValue)
				{
					result.append(1, subChar).append(1, RomanChars[i]);
					return result + intToRoman(num - subValue);
				}
			}
		}

		return result;		
	}
};

int main()
{
	Solution s;
	cout << s.intToRoman(1900).c_str() << endl;

	system("PAUSE");
	return 0;
}