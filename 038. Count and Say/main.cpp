#include<iostream>
using namespace std;

class Solution {
public:
	string itoa(int num)
	{
		string result = "";
		int i = num;
		while (true)
		{
			int tmp = i % 10;
			if (tmp < 0)
				tmp = -tmp;
			result.insert(0, 1, (tmp + '0'));
			if (!(i /= 10))
				break;
		}
		if (num < 0)
			result.insert(0, 1, '-');
		return result;
	}

	string countAndSay(int n) {
		string result = "1", origin;		

		while (--n > 0)
		{
			origin = result;
			result = "";
			char last = ' ';
			int num = 0;
			for (int i = 0; i < origin.size(); i++)
			{
				if (origin[i] != last)
				{
					if (num != 0)
						result += itoa(num) + last;
					num = 0;
					last = origin[i];
				}
				num++;
				if (i == origin.size() - 1)
					result += itoa(num) + last;
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	cout << s.countAndSay(20).c_str() << endl;
	getchar();
	return 0;
}