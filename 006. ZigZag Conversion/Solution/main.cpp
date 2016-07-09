#include<iostream>
using namespace std;


class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		string result = "";
		int sLen = s.length(),cur,step1,step2,turn;
		
		for (int i = 0; i < numRows; i++)
		{
			cur = i;
			step1 = 2 * numRows - 2 - 2 * (i % (numRows - 1));
			step2 = 2 * (i % (numRows - 1));
			turn = 1;

			while (cur < sLen)
			{
				result.push_back(s[cur]);

				if (turn == 1)
				{
					cur += step1;
					if (step2 != 0)
						turn = 2;
				}
				else
				{
					cur += step2;
					turn = 1;
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.convert("PAYPALISHIRING", 3).c_str() << endl;
	system("PAUSE");
	return 0;
}