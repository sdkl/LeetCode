#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		vector<int> s;
		int r = 0, a = 0, b = 0;

		for (auto str : tokens)
		{
			if (str.size() > 1 || (str[0] - '0' >= 0 && str[0] - '9' <= 0))
			{
				r = atoi(str.c_str());
				s.push_back(r);			
			}
			else
			{
				a = s.back();
				s.pop_back();
				b = s.back();
				s.pop_back();
				if (str[0] == '+')
					r = b + a;
				else if (str[0] == '-')
					r = b - a;
				else if (str[0] == '*')
					r = b * a;
				else if (str[0] == '/')
					r = b / a;
				s.push_back(r);
			}
		}

		return r;
	}
};

int main()
{
	Solution s;
	vector<string> t = { "2", "1", "+", "3", "*" };
	vector<string> t2 = { "4", "13", "5", "/", "+" };
	cout << s.evalRPN(t) << endl;
	cout << s.evalRPN(t2) << endl;

	getchar();
	return 0;
}