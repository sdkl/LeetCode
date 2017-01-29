#include<iostream>
#include<vector>
#include<map>
using namespace std;

class MinStack {
private:
	vector<int> s;
	map<int,int> m;
public:
	MinStack() {
	}

	void push(int x) {
		s.push_back(x);
		m[x]++;
	}

	void pop() {
		if (s.empty()) return;

		int x = s.back();
		s.pop_back();
		m[x]--;
		if (m[x] <= 0)
			m.erase(x);
	}

	int top() {
		return s.back();
	}

	int getMin() {
		return m.begin()->first;
	}
};


int main()
{
	MinStack obj;
	obj.push(-2);
	obj.push(0);
	obj.push(-3);
	cout << obj.getMin() << endl;
	obj.pop();
	cout << obj.top() << endl;
	cout << obj.getMin() << endl;

	getchar();
	return 0;
}