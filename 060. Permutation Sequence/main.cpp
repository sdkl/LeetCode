#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {		
		vector<int> pNum({ 1, 1, 2, 3 * 2, 4 * 3 * 2, 5 * 4 * 3 * 2, 6 * 5 * 4 * 3 * 2, 7 * 6 * 5 * 4 * 3 * 2, 8 * 7 * 6 * 5 * 4 * 3 * 2, 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 });
		vector<int> order(n);
		for (int i = 0; i < n; i++)
			order[i] = i + 1;
		k--;
		string result = "";
		while (--n >= 0)
		{
			int p = pNum[n];
			if ((k / p) > order.size())
				return "";
			result += order[k / p] + '0';
			order.erase(order.begin() + (k / p));
			k %= p;			
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.getPermutation(3, 4).c_str() << endl;

	getchar();
	return 0;
}