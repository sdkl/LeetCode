#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void genOne(vector<int>& nums, vector<vector<int>>& result)
	{
		if (nums.size() == 1)
			result.push_back(vector<int>(1, nums[0]));
		else if (nums.size() > 1)
		{
			int n = *nums.begin();
			nums.erase(nums.begin());
			genOne(nums, result);
			int size = result.size();
			for (int i = 0; i < size;i++)
			{
				vector<int> newVec(result[i]);
				for (int i = 0; i < newVec.size(); i++)
				{
					newVec.insert(newVec.begin() + i, n);
					result.push_back(newVec);
					newVec.erase(newVec.begin()+i);
				}
				result[i].push_back(n);				
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		genOne(nums, result);
		return result;
	}
};


int main()
{
	Solution s;
	vector<vector<int>> result = s.permute(vector<int>({ 1,2,3,4,5}));
	for (auto arr : result)
	{
		for (auto i : arr)
			cout << i << " ";
		cout << endl;
	}	

	getchar();
	return 0;
}