#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		unordered_map<string, int> sMap;

		for (int i = 9; i < s.size(); i++)
		{
			string subStr = s.substr(i - 9, 10);
			sMap[subStr]++;
		}

		for (auto i : sMap)
		{
			if (i.second > 1)
				result.push_back(i.first);
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<string> v = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for (auto i : v)
		cout << i.c_str() << endl;

	getchar();
	return 0;
}