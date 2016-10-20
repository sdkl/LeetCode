#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {	
		int max = 0;
		if (matrix.empty()) return max;		
		vector<int> h(matrix[0].size()+1, 0),s;
		for (int i = 0; i < matrix.size(); i++)
		{
			s.clear();
			matrix[i].push_back('0');
			for (int j = 0; j < matrix[i].size(); j++)
			{
				matrix[i][j] == '1' ? h[j]++ : h[j] = 0;

				while (!s.empty() && h[j] < h[s.back()])
				{
					int k = s.back();
					s.pop_back();

					int len = s.empty() ? j : j - s.back() - 1;
					max = std::max(max, h[k] * len);
				}
				s.push_back(j);
			}			
		}
		return max;
	}
};

int main()
{
	Solution s;
	vector<vector<char>> v = {
			{ '1', '0', '1', '0', '0' }
		,	{ '1', '0', '1', '1', '1' }
		,	{ '1', '1', '1', '1', '1' }
		,	{ '1', '0', '0', '1', '0' }
	};

	cout << s.maximalRectangle(v) << endl;

	getchar();
	return 0;
}