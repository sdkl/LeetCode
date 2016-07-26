#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		genOne(result, "", n, n);

		return result;
	}

	void genOne(vector<string>& result,string cur, int left, int right)
	{
		if (left == 0 && right == 0)
			result.push_back(cur);
		else if (left >= right)
			genOne(result, cur + "(", left - 1, right);
		else
		{
			if (left != 0)
				genOne(result, cur + "(", left - 1, right);				
			genOne(result, cur + ")", left , right - 1);
		}
	}
};

int main()
{
	Solution s;
	vector<string> result = s.generateParenthesis(3);
	for (int i = 0; i < result.size(); i++)
		cout << result[i].c_str() << endl;

	system("PAUSE");
	return 0;
}