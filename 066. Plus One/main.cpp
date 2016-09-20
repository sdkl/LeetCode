#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> result(digits);
		if (result.empty())
			return result;
		bool add = true;
		for (int i = result.size() - 1; i >= 0 && add; i--)
		{
			add = result[i] == 9;
			result[i] = (result[i] + 1) % 10;
		}
		if (add)
			result.insert(result.begin(), 1);

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> p({9,9,9,9,9});
	vector<int> result = s.plusOne(p);
	for (auto i : result)
		cout << i << "";

	getchar();
	return 0;
}