#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> map;
		int maxLen = 0;

		for (auto i : nums)
		{
			if (map.count(i) == 0)
			{
				map[i] = 1;

				if (map.count(i + 1) > 0)
					map[i] = map[i] + map[i + 1];
				if (map.count(i - 1) > 0)
					map[i] = map[i - map[i - 1]] = map[i] + map[i - 1];
				if (map.count(i + 1) > 0)
					map[i + map[i + 1]] = map[i];

				if (map[i] > maxLen)
					maxLen = map[i];
			}
		}

		return maxLen;
	}
};

int main()
{
	Solution s;
	vector<int> p = { 1, 3, 5, 2, 4};
	cout << s.longestConsecutive(p) << endl;

	getchar();
	return 0;
}