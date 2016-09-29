#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zero = 0, one = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				zero++;
			else if (nums[i] == 1)
				one++;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (zero-- > 0)
				nums[i] = 0;
			else if (one-- > 0)
				nums[i] = 1;
			else
				nums[i] = 2;
		}
	}
};

int main()
{
	Solution s;
	vector<int> p = {0,1,2,0,2,2,1,2,0,0,2};

	s.sortColors(p);
	for (auto i : p)
		cout << i << " ";

	getchar();
	return 0;
}