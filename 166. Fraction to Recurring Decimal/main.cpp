#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string s = "";
		char sp[100];
		long long num = numerator, dev = denominator;
		if (num != 0 && ((num > 0) ^ (dev > 0)))
			s.push_back('-');
		num = abs(num);
		dev = abs(dev);

		long long a = num / dev;
		num -= dev * a;
		sprintf(sp, "%lld", a);
		s.append(sp);		
		
		if (num != 0)
		{
			unordered_map<long long, int> nMap;
			s.push_back('.');
			num *= 10;
			while (num != 0)
			{				
				a = 0;
				if (num >= dev)
					a = num / dev;

				if (nMap.find(num) != nMap.end())
				{
					s.insert(nMap[num] - 1, "(");
					s.push_back(')');
					break;
				}
				else
				{
					s.push_back((int)a + '0');
					nMap[num] = s.size();
				}

				num -= dev * a;
				num *= 10;
			}
		}		

		return s;
	}
};

int main()
{
	Solution s;
	cout << s.fractionToDecimal(INT_MIN, 1).c_str() << endl;
	cout << s.fractionToDecimal(10,-3).c_str() << endl;
	cout << s.fractionToDecimal(2, 1).c_str() << endl;
	cout << s.fractionToDecimal(1, 2).c_str() << endl;
	cout << s.fractionToDecimal(1, 99).c_str() << endl;
	cout << s.fractionToDecimal(1, 6).c_str() << endl;
	cout << s.fractionToDecimal(-1, INT_MIN).c_str() << endl;
	
	getchar();
	return 0;
}