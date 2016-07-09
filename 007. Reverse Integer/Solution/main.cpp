#include<iostream>
#include<cmath>
using namespace std;


class Solution {
public:
	int reverse(int x) {
		int negative = x < 0;
		int absX = abs(x);
		int result = 0;

		while (absX > 0)
		{
			if (result  > INT_MAX / 10 || (result == INT_MAX / 10 && absX % 10 >8) || (result == INT_MAX / 10 && negative && absX % 10 >7))
			{
				result = 0;
				break;
			}
			result = result * 10 + absX % 10;
					
			absX /= 10;
		}

		if (negative)
			result *= -1;

		return result;
	}
};

int main()
{
	Solution s;
	cout << s.reverse(1534236469) << endl;
	system("PAUSE");
	return 0;
}