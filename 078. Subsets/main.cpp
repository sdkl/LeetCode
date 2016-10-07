#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void dSubsets(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp,int cur)
	{
		for (int i = cur; i < nums.size(); i++)
		{
			tmp.push_back(nums[i]);
			res.push_back(tmp);
			dSubsets(res, nums, tmp, i + 1);
			tmp.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> tmp;
		res.push_back(vector<int>());
		dSubsets(res, nums, tmp, 0);
		return res;
	}
};


int main()
{
	Solution s;
	vector<int> v({1,2,3});
	vector<vector<int>> p = s.subsets(v);
	for (auto i : p)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	getchar();
	return 0;
}