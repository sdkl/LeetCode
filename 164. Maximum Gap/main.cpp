#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void radixSort(vector<int>& nums)
	{
		vector<vector<int>> buckets(10,vector<int>());
		for (int r = 0; r < 10; r++)
		{
			for (int i = 0; i < buckets.size();i++)
				buckets[i].clear();

			int n = pow(10, r);
			for (auto j : nums)
				buckets[j / n % 10].push_back(j);

			int t = 0;
			for (auto b : buckets)
			{
				for (auto c : b)
					nums[t++] = c;
			}
		}
	}

	int maximumGap(vector<int>& nums) {
		radixSort(nums);
		
		for (auto i : nums)
			cout << i << " ";
		cout << endl;

		int maxGap = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] - nums[i - 1] > maxGap)
				maxGap = nums[i] - nums[i - 1];
		}

		return maxGap;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 15252, 16764, 27963, 7817, 26155, 20757, 3478, 22602, 20404, 6739, 16790, 10588, 16521, 6644, 20880, 15632, 27078, 25463, 20124, 15728, 30042, 16604, 17223, 4388, 23646, 32683, 23688, 12439, 30630, 3895, 7926, 22101, 32406, 21540, 31799, 3768, 26679, 21799, 23740};
	cout << s.maximumGap(v) << endl;

	getchar();
	return 0;
}