#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string result = "";
		vector<int> value(num1.size() + num2.size() + 2,0);
		for (int i = 0; i < num1.size(); i++)
		{
			int curI = num1[num1.size() - i - 1] - '0';
			for (int j = 0; j < num2.size(); j++)
			{
				int curJ = num2[num2.size() - j - 1] - '0';
				int mul = curI * curJ;

				value[j + i] += mul;
			}
		}

		for (int i = 0; i < value.size(); i++)
		{
			int up = value[i] / 10;
			value[i] %= 10;
			if (up > 0)
				value[i + 1] += up;
			result.insert(0,1,value[i] + '0');
		}

		while (result.size() > 0 && result[0] == '0')
			result.erase(0, 1);

		return result == "" ? "0":result;
	}
};


int main()
{
	Solution s;
	cout << s.multiply("0","0").c_str() << endl;

	getchar();
	return 0;
}