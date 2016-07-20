#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int size = nums.size(), min, max, add, result;
		if (nums.size() < 3)
			return 0;	

		sort(nums.begin(), nums.end());

		result = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < size - 2;)
		{
			min = i + 1;
			max = size - 1;

			while (min < max)
			{
				add = nums[min] + nums[i] + nums[max];
				if (abs(target - add) < abs(target - result))
					result = add;

				while (add >= target && max-- > min && nums[max] == nums[max + 1]);
				while (add <= target && min++ < max && nums[min] == nums[min - 1]);
			}

			while (i++ < size - 2 && nums[i] == nums[i - 1]);
		}

		return result;
	}
};


int main()
{
	int a[] = {1, 1, -1, -1, 3 };
	int size = sizeof(a) / sizeof(a[0]);
	vector<int> p;
	for (int i = 0; i < size; i++)
		p.push_back(a[i]);

	Solution s;
	cout << s.threeSumClosest(p,3) << endl;


	system("PAUSE");
	return 0;
}