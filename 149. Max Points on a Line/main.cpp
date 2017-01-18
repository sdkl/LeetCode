#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		unordered_map<double, int> lineMap;
		int maxPoint = 0;

		for (auto p : points)
		{
			int same = 0, xZero = 0;
			lineMap.clear();
			for (auto i : points)
			{
				if (i.x == p.x && i.y == p.y)
					same++;
				else if (i.x == p.x)
					xZero++;
				else
					lineMap[(i.y - p.y) / (double)(i.x - p.x)]++;
			}
			maxPoint = max(maxPoint, xZero + same);
			for (auto m:lineMap)
				maxPoint = max(maxPoint, m.second + same);
		}

		return maxPoint;
	}
};

int main()
{
	Solution s;
	vector<Point> p = { Point(0, 0), Point(3, -3), Point(3, -3), Point(-3, 3) };
	cout << s.maxPoints(p) << endl;

	getchar();
	return 0;
}