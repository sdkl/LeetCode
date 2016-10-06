#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void combine(vector<vector<int>>& result, int n, int k)
	{
		if (k == 1)
			while (n) result.push_back(vector<int>(1,n--));
		else
		{
			combine(result, n - 1, k - 1);

			vector<vector<int>> tmpRes;
			for (int i = 0; i < result.size(); i++)
			{
				for (int j = result[i][result[i].size() - 1] + 1; j <= n; j++)
				{
					vector<int> tmp(result[i]);
					tmp.push_back(j);
					tmpRes.push_back(tmp);
				}
			}
			result = tmpRes;
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		if (n >= k && k > 0)
			combine(result, n, k);
		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> p = s.combine(4, 2);
	for (auto i : p)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	getchar();
	return 0;
}