#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

class Solution {
public:
	void checkSum(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& cur,int curI)
	{
		for (int i = curI; i >= 0; i--)
		{
			if (candidates[i] > target)
				continue;

			cur.push_back(candidates[i]);

			if (candidates[i] == target)
				result.push_back(cur);
			else
				checkSum(candidates, target - candidates[i], result,cur,i);

			cur.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> cur;
		checkSum(candidates, target, result, cur, candidates.size() - 1);
		return result;
	}
};


int main()
{
	Solution s;
	vector<int> p = {2,3,6,7};
	vector<vector<int>> result = s.combinationSum(p, 7);
	for (auto i : result)
	{
		cout << "[";
		for (auto j : i)
			cout << j << " ";
		cout << "]" << endl;
	}
	cout << "............" << endl;
	getchar();
	return 0;
}