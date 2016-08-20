#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = 0,result = 0;
		while (height.size() > 2 && left < height.size() - 2)
		{
			for (int i = right = left + 1; i < height.size(); i++)
			{
				if (height[i] >= height[left])
				{
					right = i;
					break;
				}
				if (height[i] > height[right])
					right = i;
			}

			result += (right - left - 1) * min(height[left], height[right]);
			for (int i = left + 1; i < right; i++)
				result -= height[i];
			left = right;
		}
		return result;
	}
};


int main()
{
	Solution s;
	vector<int> p = { };
	cout << s.trap(p) << endl;
	getchar();
	return 0;
}