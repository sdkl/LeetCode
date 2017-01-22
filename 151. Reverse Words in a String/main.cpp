#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		vector<int> v;
		for (int i = 0; i < s.size(); i++)
		{
			if ((i == 0 && s[i] != ' ') || (s[i] != ' ' && s[i - 1] == '\0'))
				v.insert(v.begin(),i);
			else if (s[i] == ' ')
				s[i] = '\0';
		}
		string s1 = "";

		for (auto i : v)
		{
			s1.append(&s[i]);
			s1.append(" ");
		}
		if(!s1.empty())
			s1.pop_back();

		s = s1;
	}
};

int main()
{
	Solution s;
	string str = "  the sky is  blue  ";
	s.reverseWords(str);
	cout << str.c_str() << endl;
	getchar();
	return 0;
}