#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isPalindromic(const string& s,int start,int end)
	{
		while (start <= end)
		{
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}

	void partition(const string& s, int start, int end,vector<string>& p,vector<vector<string>>& r)
	{
		int oEnd = end;
		while (start <= end)
		{
			if (isPalindromic(s, start, end))
			{
				p.push_back(s.substr(start, end-start+1));
				if (end >= oEnd)
					r.push_back(p);
				else
					partition(s, end+1, oEnd, p, r);
				p.pop_back();
			}
			end--;
		}
	}

	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> p;
		int len = s.size();
		partition(s, 0, len - 1, p, result);
		return result;
	}
};

int main()
{
	Solution s;
	auto r = s.partition("aab");
	for (auto i : r)
	{
		for (auto j : i)
		{
			cout << j.c_str() << " ";
		}
		cout << endl;
	}

	getchar();
	return 0;
}