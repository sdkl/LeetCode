#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		rowIndex += 1;
		vector<int> r(rowIndex, 1);
		int tmp = 0;

		for (int i = 1; i <= rowIndex; i++)
		{
			tmp = r[0];
			for (int j = 1; j < i - 1; j++)
			{
				tmp = r[j] + tmp;

				tmp ^= r[j];
				r[j] ^= tmp;
				tmp ^= r[j];
			}
		}

		return r;
	}
};

int main()
{
	Solution s;
	auto v = s.getRow(6);
	for (auto i : v)
	{
		cout << i << " ";		
	}
	cout << endl;
	getchar();
	return 0;
}