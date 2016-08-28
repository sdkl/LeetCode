#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
	void dfs(int pos, vector<int> &num, vector<vector<int>> &result){
		if (pos == num.size()){
				result.push_back(num);
		}
		else{
			unordered_set<int> changeOnce;
			for (int i = pos; i < num.size(); i++){
				swap(num[i], num[pos]);
				dfs(pos + 1, num, result);
				swap(num[i], num[pos]);
				changeOnce.insert(num[i]);
				while (i < num.size() - 1 && changeOnce.count(num[i+1]) != 0) i++;
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		dfs(0,nums, result);
		return result;
	}
};



int main()
{
	Solution s;
	vector<vector<int>> result = s.permuteUnique(vector<int>({ 1, 1,3, 3,4}));
	cout << result.size() << endl;
	for (auto arr : result)
	{
		for (auto i : arr)
			cout << i << " ";
		cout << endl;
	}

	getchar();
	return 0;
}