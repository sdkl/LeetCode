#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> r;

		for (int i = 1; i <= numRows; i++)
		{
			vector<int> o(i, 1);
			r.push_back(o);
			for (int j = 1; j < i - 1; j++)
				r[i - 1][j] = r[i - 2][j] + r[i - 2][j - 1];
		}

		return r;
	}
};

int main()
{
	Solution s;
	auto v = s.generate(5);
	for (auto i : v)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}