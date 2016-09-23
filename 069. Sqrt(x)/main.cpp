#include<iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		double result = x;

		while (abs(result*result - x) > 0.1)
		{			
			result = (result + x / result) / 2;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.mySqrt(2147395599) << endl;

	getchar();
	return 0;
}