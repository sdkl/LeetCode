#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;

		sort(nums.begin(), nums.end());

		int size = nums.size(), min, max, add;
		for (int i = 0; i < size - 3;)
		{
			for (int j = size - 1; j - i > 2;)
			{
				min = i + 1;
				max = j - 1;

				while (min < max)
				{
					add = nums[i] + nums[j] + nums[min] + nums[max];
					if (add == target)
					{
						vector<int> item;
						item.push_back(nums[i]);
						item.push_back(nums[min]);
						item.push_back(nums[max]);
						item.push_back(nums[j]);
						result.push_back(item);
					}

					while (add >= target && max-- > min && nums[max] == nums[max + 1]);
					while (add <= target && min++ < max && nums[min] == nums[min - 1]);
				}

				while ((j--) - i > 2 && nums[j] == nums[j + 1]);
			}			

			while (i++ < size - 3 && nums[i] == nums[i - 1]);
		}

		return result;
	}
};


int main()
{
	int a[] = { 1, 0, -1, 0, -2, 2 };
	int size = sizeof(a) / sizeof(a[0]);
	vector<int> p;
	for (int i = 0; i < size; i++)
		p.push_back(a[i]);

	Solution s;
	vector<vector<int>> result = s.fourSum(p,0);
	for (int i = 0; i < result.size(); i++)
	{
		vector<int> item = result[i];
		cout << item[0] << "," << item[1] << "," << item[2] << "," << item[3] << endl;
	}

	system("PAUSE");
	return 0;
}