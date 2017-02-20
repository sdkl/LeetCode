#include<iostream>
#include<vector>
#include <algorithm>
#include<string>
using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string result;
		vector<string> strVec(nums.size(), "");
		for (int i = 0; i < nums.size(); i++)
			strVec[i] = to_string(nums[i]);

		sort(strVec.begin(), strVec.end(), [](const string& a, const string& b){return a + b>b + a;});

		if (strVec[0] == "0")
			return "0";
		for (auto s : strVec)
			result += s;

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 3, 30, 34, 5, 9 };//9534330
	//vector<int> nums = { 0,0 };//9534330
	cout << s.largestNumber(nums).c_str() << endl;

	getchar();
	return 0;
}