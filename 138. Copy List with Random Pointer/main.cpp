#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	unordered_map<RandomListNode*, RandomListNode*> map;
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return head;
		if (map.count(head) > 0)
			return map[head];

		RandomListNode *copy = new RandomListNode(head->label);
		map[head] = copy;
		copy->next = copyRandomList(head->next);
		copy->random = copyRandomList(head->random);

		return copy;
	}
};

int main()
{
	Solution s;
	RandomListNode a1(1);
	RandomListNode a2(2);
	RandomListNode a3(3);
	RandomListNode a4(4);
	RandomListNode a5(5);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a1.random = &a4;
	a2.random = &a5;

	RandomListNode* r = s.copyRandomList(&a1);
	while (r != NULL)
	{
		cout << r->label;
		if (r->random != NULL)
			cout << "(" << r->random->label << ")";
		cout << "  ";
		r = r->next;
	}

	getchar();
	return 0;
}