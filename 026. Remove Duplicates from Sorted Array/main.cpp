#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int diff = 1,unique,size = nums.size();

		while (diff < size && nums[diff] != nums[diff - 1])
			diff++;

		if (diff >= size)
			return size;

		unique = diff + 1;
		while (true)
		{
			while (unique < size && nums[unique] == nums[unique - 1])
				unique++;

			if (unique >= size)
				break;
			else
				nums[diff++] = nums[unique++];
		}
		
		return diff;
	}
};


int main()
{
	int iarray[] = { 1, 1, 1, 1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	size_t count = sizeof(iarray) / sizeof(int);
	vector<int> vec(iarray, iarray + count);
	vector<int> vec2;
	cout << vec2.size() - 1 << endl;
	Solution s;
	int len = s.removeDuplicates(vec);
	for (int i = 0; i < len; i++)
		cout << vec[i] <<" ";

	getchar();
	return 0;
}