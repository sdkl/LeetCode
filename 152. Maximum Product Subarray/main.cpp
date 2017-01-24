#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums,int start,int end) {
		int zeroIndex = start, iNum = 0;
		while (nums[zeroIndex] != 0 && zeroIndex != end)
		{
			if (nums[zeroIndex] < 0)
				iNum++;
			zeroIndex++;			
		}		
		if (nums[zeroIndex] < 0)
			iNum++;

		int m = 0;
		if (nums[zeroIndex] != 0)
		{
			int k = 1, i = start, left = 1, right = 1;
			for (; i <= end; i++)
				k *= nums[i];

			if (iNum % 2 != 0 && start != end)
			{
				i = start;
				while (left > 0)
					left *= nums[i++];
				i = end;
				while (right > 0)
					right *= nums[i--];
				
			}
			m = k / max(left, right);
		}
		else
		{			
			if(zeroIndex - 1 >= start)
				m = max(m, maxProduct(nums, start, zeroIndex - 1));
			if (zeroIndex + 1 <= end)
				m = max(m, maxProduct(nums, zeroIndex + 1, end));
		}
		return m;
	}

	int maxProduct(vector<int>& nums) {
		return maxProduct(nums, 0, nums.size() - 1);
	}
};

int main()
{
	Solution s;
	//vector<int> v = { 2, 3, -2, 4 };
	vector<int> v = { -4 };
	cout << s.maxProduct(v) << endl;

	getchar();
	return 0;
}