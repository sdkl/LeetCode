#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void getSubsets(vector<vector<int>>& result, vector<int>& nums, vector<int>& tmp, int cur)
	{
		result.push_back(tmp);
		for (int i = cur; i < nums.size(); i++)
		{
			if (!(i > cur && nums[i] == nums[i - 1]))
			{
				tmp.push_back(nums[i]);
				getSubsets(result, nums, tmp, i + 1);
				tmp.pop_back();
			}
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> result;
		vector<int> tmp;
		getSubsets(result, nums, tmp , 0);
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> p = { 1, 2,4,5, 2,3 };
	vector<vector<int>> result = s.subsetsWithDup(p);
	for (auto i : result)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	getchar();
	return 0;
}