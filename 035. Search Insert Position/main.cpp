#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1, mid = 0;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (nums[mid] == target)
				return mid;

			nums[mid] > target ? hi = mid - 1 : lo = mid + 1;
		}
		return nums[mid] > target ? mid : mid + 1;
	}
};

int main()
{
	Solution s;
	int arr[] = {1,3,5,6};
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> p(arr, arr + size);
	cout << s.searchInsert(p, 5) << endl;
	cout << s.searchInsert(p, 2) << endl;
	cout << s.searchInsert(p, 7) << endl;
	cout << s.searchInsert(p, 0) << endl;

	getchar();
	return 0;
}