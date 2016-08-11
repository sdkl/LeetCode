#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid = -1, hi, lo;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (nums[mid] == target)
				break;
			nums[mid] > target ? right = mid - 1 : left = mid + 1;
		}
		if (mid == -1 || nums[mid] != target)
			return vector<int>(2, -1);

		left = 0;
		right = mid;
		lo = (left + right) / 2;
		while (lo >= 0)
		{			
			if (nums[lo] == target && (lo == 0 || nums[lo - 1] != target))
				break;
			nums[lo] != target ? left = lo + 1 : right = lo - 1;
			lo = right >= left ? (left + right) / 2 : -1;
		}

		left = mid;
		right = nums.size() - 1;
		hi = (left + right) / 2;
		while (hi < nums.size())
		{
			if (nums[hi] == target && (hi == nums.size() - 1 || nums[hi + 1] != target))
				break;
			nums[hi] == target ? left = hi + 1 : right = hi - 1;
			hi = right >= left ? (left + right) / 2 : -1;
		}

		vector<int> result(2);
		result[0] = lo;
		result[1] = hi;
		return result;
	}
};

int main()
{
	Solution s;
	int arr[] = { 5, 7, 7, 8, 8, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> p(arr,arr+size);
	vector<int> result = s.searchRange(p,8);
	for (int i : result)
		cout << i << endl;

	getchar();
	return 0;
}