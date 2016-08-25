#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
		int step = 0,curIndex = 0,lastCheck = 1,maxIndex = 0,size = nums.size();
		for (int i = 0; i < nums.size(); i++)
			nums[i] += i;

		while (curIndex < size - 1)
		{
			step++;

			if (nums[curIndex] >= size - 1)
				break;

			maxIndex = nums[curIndex];
			while (lastCheck < nums[curIndex])
			{				
				if (nums[lastCheck] > nums[maxIndex])
					maxIndex = lastCheck;
				lastCheck++;
			}
			curIndex = maxIndex;
		}

		return step;
    }
};

int main()
{
	Solution s;
	cout << s.jump(vector<int>({ 2, 3, 1, 1, 4 })) << endl;
	getchar();
	return 0;
}