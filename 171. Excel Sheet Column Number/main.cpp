#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int r = 0;

		for (int i = 0; i < s.size(); i++)
		{
			r *= 26;
			r += s[i] - 'A' + 1;
		}

		return r;
	}
};

int main()
{
	Solution s;
	cout << s.titleToNumber("A")<<endl;
	cout << s.titleToNumber("Z")<<endl;
	cout << s.titleToNumber("AA")<<endl;
	cout << s.titleToNumber("AB") << endl;
	cout << s.titleToNumber("BA") << endl;

	getchar();
	return 0;
}