#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> v1, v2;
		int s = 0;
		for (int i = 0; i < version1.size(); i++)
		{
			if (version1[i] == '.')
			{
				v1.push_back(s);
				s = 0;
			}
			else
				s = s * 10 + version1[i] - '0';
		}
		v1.push_back(s);
		s = 0;
		for (int i = 0; i < version2.size(); i++)
		{
			if (version2[i] == '.')
			{
				v2.push_back(s);
				s = 0;
			}
			else
				s = s * 10 + version2[i] - '0';
		}
		v2.push_back(s);

		if (v1.size() != v2.size())
		{
			int n = abs((int)v1.size() - (int)v2.size());
			vector<int>* p = &v1;
			if (v1.size() > v2.size())
				p = &v2;
			while (n-- > 0)
				p->push_back(0);
		}

		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i] > v2[i])
				return 1;
			else if (v1[i] < v2[i])
				return -1;
		}

		return 0;
	}
};

int main()
{
	Solution s;
	cout << s.compareVersion("1.2","13.37") << endl;
	cout << s.compareVersion("1.2", "1.2.0") << endl;

	getchar();
	return 0;
}