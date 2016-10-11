#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int z = nums.size() - 1;
		while (z > 0 && nums[z] <= nums[(z+1)%nums.size()]) z--;
		z++;
		if (nums.empty() || nums[0] < nums[nums.size() - 1])
			z = 0;

		int min = 0, max = nums.size() - 1;
		while (min <= max)
		{
			int mid = (min + max) / 2;
			int val = nums[(mid + z) % nums.size()];
			if (val == target)
				return true;
			
			val > target ? 	max = mid - 1 : min = mid + 1;
		}

		return false;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 2,2,0,1,1 };
	cout << s.search(nums, 0) << endl;

	getchar();
	return 0;
}