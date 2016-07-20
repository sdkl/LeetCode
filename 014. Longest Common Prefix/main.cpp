#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";

		int len = strs.size(), max = strs[0].length(), i, j;
		for (i = 1; i < len; i++)
		{
			for (j = 0; j < strs[i].length() && j < max; j++)
			{
				if (strs[0][j] != strs[i][j])
				{
					max = j;
					break;
				}
			}

			if (j == strs[i].length() && strs[0][j-1] == strs[i][j-1] && j < max)
				max = j;
		}

		return strs[0].substr(0, max);
	}
};

int main()
{
	string arr[] = {"aa","a"};
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<string> h(size);
	for (int i = 0; i < size; i++)
		h[i] = arr[i];

	Solution s;
	cout << s.longestCommonPrefix(h).c_str() << endl;

	system("PAUSE");
	return 0;
}