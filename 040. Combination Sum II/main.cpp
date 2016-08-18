#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void checkSum(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& cur, int curI)
	{
		for (int i = curI - 1; i >= 0; i--)
		{
			if (candidates[i] > target || (i != curI - 1 && candidates[i] == candidates[i + 1]))
				continue;

			cur.push_back(candidates[i]);

			if (candidates[i] == target)
				result.push_back(cur);
			else
				checkSum(candidates, target - candidates[i], result, cur, i);

			cur.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> cur;
		checkSum(candidates, target, result, cur, candidates.size());
		return result;
	}
};


int main()
{
	Solution s;
	vector<int> p = { 10, 1, 2, 7, 6, 1, 5 };
	vector<vector<int>> result = s.combinationSum2(p, 8);
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