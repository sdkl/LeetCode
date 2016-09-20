#include<iostream>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		if (b.size() > a.size())
			return addBinary(b, a);

		bool add = false;
		for (int i = 0; i < a.size(); i++)
		{
			int n = add ? 1 : 0;
			if (a[a.size() - 1 - i] == '1')
				n++;
			if (b.size() >= i+1 && b[b.size() - 1 - i] == '1')
				n++;
			a[a.size() - 1 - i] = n % 2 == 0 ? '0' : '1';
			add = n >= 2 ? true : false;
		}

		if (add)
			a = '1' + a;

		return a;
	}
};

int main()
{
	Solution s;
	cout << s.addBinary("1", "11").c_str() << endl;

	getchar();
	return 0;
}