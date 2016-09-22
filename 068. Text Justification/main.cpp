#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		int i = 0, n = words.size();
		while (i < n)
		{
			int j = i, curLen = 0;
			string s = "";

			for (; j < n && curLen + words[j].size() + (j - i) <= maxWidth; j++)
				curLen += words[j].size();

			j--;
			if (j == i)
			{
				result.push_back(words[i] + string(maxWidth - words[i].size(), ' '));
				i++;
			}
			else
			{
				int spaceNum = (maxWidth - curLen) / (j - i), addOne = (maxWidth - curLen) % (j - i);
				for (; i <= j; i++)
				{
					s += words[i];
					if (i != j)
					{
						if (j + 1 != n)
						{
							s += string(spaceNum, ' ');
							if (addOne-- > 0)
								s += ' ';
						}else
							s += ' ';
						
					}
				}
				if (i == n)
					result.push_back(s + string(maxWidth - s.size(), ' '));
				else
					result.push_back(s);
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<string> result = s.fullJustify(vector<string>({ "This", "is", "an", "example", "of", "text", "justification." }), 16);
	//vector<string> result = s.fullJustify(vector<string>({ "a", "b", "c", "d", "e" }), 1);
	//vector<string> result = s.fullJustify(vector<string>({ "What", "must", "be", "shall", "be." }), 12);
	for (auto i : result)
		cout << "'" << i.c_str() << "'" << endl;

	getchar();
	return 0;
}