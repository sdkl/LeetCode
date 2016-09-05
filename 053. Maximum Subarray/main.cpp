#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int imax = nums[0],add = 0;
		for (auto i : nums)
		{
			add = max(add + i, i);
			imax = max(add, imax);
		}
		return imax;
	}
};

int main()
{
	Solution s;
	vector<int> p = {-5, 8, -5, 1, 1, -3, 5, 5, -3, -3, 6, 4, -7, -4, -8, 0, -1, -6};
	cout << s.maxSubArray(p)<<endl;
	for (auto i : p)
		cout << i << " ";

	getchar();
	return 0;
}