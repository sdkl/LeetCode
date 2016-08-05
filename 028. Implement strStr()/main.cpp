#include<iostream>
using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1 = haystack.size(), len2 = needle.size(),i=0,j=0;

		while (i <= len1 - len2 && len1 > 0 && len2 > 0)
		{
			if (haystack[i] == needle[0])
			{
				j = 1;
				while (j<len2 && haystack[i + j] == needle[j])
					j++;
				if (j >= len2)
					return i;
			}
			i++;
		}

		return len2 == 0 ? 0 : -1;
	}
};

int main()
{
	Solution s;
	cout << s.strStr("mxcxibxicbi","a") << endl;

	getchar();
	return 0;
}