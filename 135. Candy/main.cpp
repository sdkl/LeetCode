#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		int rSize = ratings.size();
		vector<int> candies(rSize, 1);

		for (int i = 1; i < rSize; i++)
		{
			if (ratings[i] > ratings[i - 1])
				candies[i] = candies[i - 1] + 1;
		}
		
		for (int i = rSize - 2; i >= 0; i--)
		{
			if (ratings[i] > ratings[i + 1])
				candies[i] = max(candies[i],candies[i + 1] + 1);
		}

		int all = 0;
		for (auto i : candies)
			all += i;

		return all;
	}
};

int main()
{
	Solution s;
	vector<int> p = { 1, 2, 5, 4, 3, 0, 200, 300 };//
	cout << s.candy(p) << endl;

	getchar();
	return 0;
}