#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		int len = 1 << n;
		vector<int> result(len);		
		for (int i = 0; i < len; i++)
			result[i] = i ^ (i>>1);
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> r = s.grayCode(10);
	for (auto i : r)
		cout << i << " ";

	getchar();
	return 0;
}