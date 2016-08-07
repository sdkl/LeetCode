#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size();
		if (i <= 1)
			return;
		while (--i > 0)
		{
			if (nums[i - 1] < nums[i])
			{
				for (int j = nums.size() - 1; j >= i; j--)
				{
					if (nums[i - 1] < nums[j])
					{
						nums[i - 1] ^= nums[j];
						nums[j] ^= nums[i - 1];
						nums[i - 1] ^= nums[j];

						int first = i, last = nums.size() - 1, mid = (last - first) / 2;
						for (int k = 0; k <= mid && (first + k != last - k); k++)
						{
							nums[first + k] ^= nums[last - k];
							nums[last - k] ^= nums[first + k];
							nums[first + k] ^= nums[last - k];
						}
						return;
					}
				}
			}
		}

		reverse(nums.begin(), nums.end());
	}
};


int main()
{
	Solution s;
	int arr[] = {2, 2, 7, 5, 4, 3, 2, 2, 1};
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> a(arr,arr+size);
	s.nextPermutation(a);
	for (auto i : a)
		cout << i << endl;

	getchar();
	return 0;
}