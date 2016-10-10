#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int c = 1;
		for (int i = 2; i < nums.size(); i++)
		{
			if (nums[c] != nums[i] || nums[c - 1] != nums[i])
				nums[++c] = nums[i];
		}
		return min(c+1,(int)nums.size());
	}
};

int main()
{
	Solution s;
	//vector<int> v = {1,1,1,2,2,3};
	vector<int> v = { 1, 1, 2 };
	cout << s.removeDuplicates(v)<<endl;
	for (auto i : v)
		cout << i << " ";

	getchar();
	return 0;
}