#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) return 0;

		int min = nums[0], start = 0, end = nums.size() - 1, mid = 0;

		while (start < end-1)
		{
			mid = (start + end) / 2;
			if (nums[mid] > min)
				start = mid;
			else
				end = mid;
		}

		mid = nums[start] < nums[end] ? start : end;
		if (nums[mid] < min)
			min = nums[mid];

		return min;
	}
};

int main()
{
	Solution s;
	vector<int> v = { -1, 1, 2 ,4,5,6,7};
	//vector<int> v = { 4, 5, 1, 2, 3 };
	cout << s.findMin(v) << endl;

	getchar();
	return 0;
}