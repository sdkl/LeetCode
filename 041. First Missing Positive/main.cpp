#include<iostream>
#include<memory>
#include<vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size();)
		{
			if (nums[i] <= 0 || nums[i] >= nums.size() || nums[i] == nums[nums[i] - 1])
			{
				i++;
				continue;
			}				
				
			int index = nums[i];
			nums[index - 1] ^= nums[i];
			nums[i] ^= nums[index - 1];
			nums[index - 1] ^= nums[i];
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (i + 1 != nums[i])
				return i + 1;
		}

		return nums.size() + 1;
	}
};


int main()
{
	Solution s;
	vector<int> p = { -1, 4, 2, 1, 9, 10 };
	cout << s.firstMissingPositive(p)<<endl;
	getchar();
	return 0;
}