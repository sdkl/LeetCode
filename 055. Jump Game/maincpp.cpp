#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxStep = 0;
		for (int i = 0; i <= maxStep && i < nums.size() && maxStep < nums.size() - 1; i++)
		{
			maxStep = max(i + nums[i], maxStep);
		}
		return maxStep >= nums.size() - 1;
	}
};

int main()
{
	Solution s;
	vector<int> p({ 3, 2, 1, 0, 4 });
	cout << s.canJump(p) << endl;

	getchar();
	return 0;
}