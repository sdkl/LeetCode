#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) return 0;

		int min = nums[0], start = 0, end = nums.size() - 1, mid = 0;

		while (start < end - 1)
		{
			while (start < end - 1 && nums[start] == nums[start+1])
			{
				start++;
			}
			if (start < end - 1)
			{
				mid = (start + end) / 2;
				if (nums[mid] > min)
					start = mid;
				else
					end = mid;
			}			
		}

		mid = nums[start] < nums[end] ? start : end;
		if (nums[mid] < min)
			min = nums[mid];

		return min;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2, 2, 2, 4, 5, 0, 1 };
	//vector<int> v = { 2, 1, 2, 2, 2 };
	//vector<int> v = { 3,3,1 };
	cout << s.findMin(v) << endl;

	getchar();
	return 0;
}