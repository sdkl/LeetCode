#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		size_t size = nums.size();
		vector<int> result;

		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (nums[i] + nums[j] == target)
				{					
					result.push_back(i);
					result.push_back(j);
					return result;
				}									
			}
		}

		return result;
	}
};

int main()
{
	int iarray[] = { 2, 7, 11, 15 };
	int target = 9;
	size_t count = sizeof(iarray) / sizeof(int);
	vector<int> ivec(iarray, iarray + count);

	Solution s;
	vector<int> result = s.twoSum(ivec, target);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<< endl;
	}

	cin >> target;
}