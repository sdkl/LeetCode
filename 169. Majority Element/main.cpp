#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int major = nums[0], num = 0;

		for (auto i : nums)
		{
			if (i == major)
				num++;
			else
			{
				num--;
				if (num == 0)
				{
					major = i;
					num = 1;
				}					
			}
		}

		return major;
	}
};

int main()
{
	Solution s;
	vector<int> v = {1,2,1};
	cout << s.majorityElement(v) << endl;

	getchar();
	return 0;
}