#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string r = "";
		while (--n >= 0){
			int i = n % 26;
			r.insert(r.begin(),i + 'A');
			n /= 26;
		};
		return r;
	}
};

int main()
{
	Solution s;
	cout << s.convertToTitle(1).c_str() << endl;
	cout << s.convertToTitle(26).c_str() << endl;
	cout << s.convertToTitle(505225).c_str() << endl;

	getchar();
	return 0;
}