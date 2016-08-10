#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;

		int min = 0, max = nums.size()-1,mid=0,maxIndex=0;
		while (min < max)
		{
			mid = (min + max)/2;
			if (nums[mid] > nums[0])
			{
				maxIndex = mid;
				min = mid + 1;
			}
			else
				max = mid;
			if (min == max && nums[max] > nums[0])
				maxIndex = max;
		}

		if (target >= nums[0] && target <= nums[maxIndex])
		{
			min = 0;
			max = maxIndex;
		}
		else if (maxIndex == nums.size() - 1)
			return -1;
		else
		{
			min = maxIndex + 1;
			max = nums.size() - 1;
		}

		while (min <= max)
		{
			mid = (min + max) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				min = mid + 1;
			else
				max = mid - 1;

		}

		return -1;
	}
};

int main()
{
	Solution s;
	int arr[] = { 2, 3, 4,8, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> a(arr, arr + size);
	cout << s.search(a,9) << endl;

	system("PAUSE");
	return 0;
}