#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, vector<string>> map;

		for (auto& s : strs)
		{
			string str = s;
			sort(str.begin(), str.end());
			map[str].push_back(s);
		}

		for (auto& i : map)
			result.push_back(map[i.first]);

		return result;
	}
};


int main()
{
	Solution s;
	vector<vector<string>> result = s.groupAnagrams(vector<string>({ "eat", "tea", "tan", "ate", "nat", "bat" }));
	for (auto& i : result)
	{
		for (auto& j : i)
		{
			cout << j.c_str() << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}