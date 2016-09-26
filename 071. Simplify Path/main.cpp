#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> strs;

		int start = 0;
		for (int i = 0; i < path.length(); i++)
		{
			while (path[i] == '/' && i < path.length())	i++;
			start = i;
			while (path[i] != '/' && i < path.length())	i++;
			i--;
			string str = path.substr(start, i - start + 1);
			if (str == "." || str.empty())
				continue;
			else if (str == "..")
			{
				if (strs.size() > 0)
					strs.pop_back();
			}				
			else
				strs.push_back(str);
		}

		string result = "";
		for (auto i : strs)
			result += "/"+i;
		return result == "" ? "/" : result;
	}
};

int main()
{
	Solution s;
	cout << s.simplifyPath("/a/./b/../../c/").c_str() << endl;
	cout << s.simplifyPath("/../").c_str() << endl;
	cout << s.simplifyPath("/home/foo").c_str() << endl;
	getchar();
	return 0;
}