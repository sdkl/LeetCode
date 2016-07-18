#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;

		sort(nums.begin(), nums.end());

		int size = nums.size(), min, max, add;
		for (int i = 0; i < size - 2;)
		{
			min = i + 1;
			max = size - 1;

			while (min < max)
			{
				add = nums[min] + nums[i] + nums[max];
				if (add == 0)
				{
					vector<int> item;
					item.push_back(nums[i]);
					item.push_back(nums[min]);
					item.push_back(nums[max]);
					result.push_back(item);
				}

				while (add >= 0 && max-- > min && nums[max] == nums[max + 1]);
				while (add <= 0 && min++ < max && nums[min] == nums[min - 1]);
			}

			while (i++ < size - 2 && nums[i] == nums[i - 1]);
		}

		return result;
	}
};

int main()
{
	int a[] = { -1, 0, 1, 2, -1, -4 };
	//int a[] = { 1,-1,-1,0 };
	//int a[] = { -1, 0, 0, 1 };
	//int a[] = { -1, 0, 0, 0 };
	int size = sizeof(a) / sizeof(a[0]);
	vector<int> p;
	for (int i = 0; i < size; i++)
		p.push_back(a[i]);

	Solution s;
	vector<vector<int>> result = s.threeSum(p);
	for (int i = 0; i < result.size(); i++)
	{
		vector<int> item = result[i];
		cout << item[0] << "," << item[1] << "," << item[2] << endl;
	}

	system("PAUSE");
	return 0;
}