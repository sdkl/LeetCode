#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int start = 0, end = nums.size() - 1, mid = 0;

		while (start < end)
		{
			mid = (start + end) / 2;
			int l = mid > 0 ? nums[mid - 1] : INT_MIN;
			int r = mid < end ? nums[mid + 1] : INT_MIN;

			if (nums[mid] >= l && nums[mid] >= r)
				break;
			else if (nums[mid] >= l)
				start = mid + 1;
			else
				end = mid - 1;
		}

		mid = (start + end) / 2;
		return mid;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1, 2,3,1};
	cout << s.findPeakElement(v) << endl;

	getchar();
	return 0;
}