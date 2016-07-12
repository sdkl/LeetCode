#include<iostream>
using namespace std;


class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int hDiv = 1,lDiv = 1;
		while (x / 10 >= hDiv)
			hDiv *= 10;

		while (hDiv > lDiv)
		{
			if ((x / hDiv) % 10 != (x / lDiv) % 10)
				return false;
				
			hDiv /= 10;
			lDiv *= 10;
		}

		return true;
	}
};

int main()
{
	Solution s;
	cout << s.isPalindrome(10) << endl;
	system("PAUSE");
	return 0;
}