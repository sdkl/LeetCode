#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int a=0,b=0,c=0;

		for (auto i : nums)
		{
			c = a;
			a = (a | i) & ~(b & i);
			b = (c & (i | b)) & ~(b & i);
		}

		return a;
	}
};


int main()
{
	Solution s;
	vector<int> p = { -2, -2, 1, 1, -3, 1, -3, -3, -4, -2};
	cout << s.singleNumber(p) << endl;

	getchar();
	return 0;
}