#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int r = 0;
		for (auto i : nums)
			r ^= i;
		return r;
	}
};

int main()
{
	Solution s;
	vector<int> p = {3,2,3,5,2,1,1};
	cout << s.singleNumber(p) << endl;

	getchar();
	return 0;
}