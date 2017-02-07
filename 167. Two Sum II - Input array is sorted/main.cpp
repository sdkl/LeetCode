#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		unordered_map<int, int> nMap;
		vector<int> result;

		for (int i = 0; i < numbers.size(); i++)
		{
			int t = target - numbers[i];
			if (nMap.find(t) != nMap.end())
			{
				result.push_back(nMap[t]);
				result.push_back(i + 1);
				break;
			}
			nMap[numbers[i]] = i + 1;
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2, 7, 11, 15 };
	vector<int> r = s.twoSum(v, 9);
	cout << r[0] << " " << r[1] << endl;

	getchar();
	return 0;
}