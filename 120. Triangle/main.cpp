#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> m(triangle.size() + 2, INT_MAX);
		m[1] = triangle[0][0];

		for (int i = 1; i < triangle.size(); i++)
		{
			for (int j = triangle[i].size()-1; j >= 0; j--)
			{
				m[j+1] = min(m[j],m[j+1]) + triangle[i][j];
			}
		}

		int result = INT_MAX;
		for (auto i : m)
		{
			if (i < result)
				result = i;
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> p = { vector<int>({ 2 }), vector<int>({ 3, 4 }), vector<int>({ 6, 5, 7 }), vector<int>({ 4, 1, 8, 3 }) };
	cout << s.minimumTotal(p) << endl;

	getchar();
	return 0;
}