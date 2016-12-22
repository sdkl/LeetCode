#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		vector<UndirectedGraphNode *> s;
		unordered_map<int, UndirectedGraphNode *> viewed;
		s.push_back(node);
		viewed[node->label] = new UndirectedGraphNode(node->label);

		while (s.size() > 0)
		{
			UndirectedGraphNode* cur = s.back();
			s.pop_back();			

			for (auto i : cur->neighbors)
			{
				if (viewed.count(i->label) == 0)
				{
					viewed[i->label] = new UndirectedGraphNode(i->label);
					s.push_back(i);
				}
				viewed[cur->label]->neighbors.push_back(viewed[i->label]);
			}
		}
		return viewed[node->label];
	}
};

int main()
{
	Solution s;
	UndirectedGraphNode* a1 = new UndirectedGraphNode(1);
	UndirectedGraphNode* a2 = new UndirectedGraphNode(2);
	UndirectedGraphNode* a3 = new UndirectedGraphNode(3);
	a1->neighbors = {a2,a3};
	a2->neighbors = { a3 };
	a3->neighbors = { a3 };

	s.cloneGraph(a1);
	getchar();
	return 0;
}