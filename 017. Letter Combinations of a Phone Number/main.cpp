#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		string charSet[]{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string> result(1, "");

		for (int i = 0; i < digits.length(); i++)
		{
			int index = digits[i] - '2';
			if (index <0 || index > 7)
				continue;
			string chars = charSet[index];
			vector<vector<string>> addVcts(chars.length(),vector<string>(result));
			for (int j = 0; j < chars.length(); j++)
			{
				vector<string> addVct = addVcts[j];
				for (int k = 0; k < addVct.size(); k++)
				{
					addVct[k] += chars[j];
				}

				if (j == 0)
					result.clear();
				result.insert(result.end(), addVct.begin(), addVct.end());
			}
		}

		if (result.size() == 1)
			result.clear();
		return result;
	}
};


int main()
{
	Solution s;
	vector<string> result = s.letterCombinations("23");
	for (int i = 0; i < result.size(); i++)
		cout << result[i].c_str() << " ";

	system("PAUSE");
	return 0;
}