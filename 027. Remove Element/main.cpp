#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int cur = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
				nums[cur++] = nums[i];
		}
		return cur;
	}
};


int main()
{
	int iarray[] = { 3, 2,1,3,4,5, 2, 3 ,4};
	size_t count = sizeof(iarray) / sizeof(int);
	vector<int> vec(iarray, iarray + count);

	Solution s;
	int len = s.removeElement(vec,3);
	for (int i = 0; i < len; i++)
		cout << vec[i] << " ";

	getchar();
	return 0;
}