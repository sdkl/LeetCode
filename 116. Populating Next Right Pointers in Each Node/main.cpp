#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeLinkNode {  
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		queue<TreeLinkNode*> q;
		if (root != NULL)
			q.push(root);

		while (!q.empty())
		{
			int n = q.size();
			while (n-- > 0)
			{
				TreeLinkNode* cur = q.front();
				q.pop();
				if (n > 0)
					cur->next = q.front();

				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
		}
	}
};

void printTree(TreeLinkNode* root, string space)
{
	if (root == NULL)
		return;

	printTree(root->right, space + "  ");
	cout << space.c_str() << root->val;
	if (root->next != NULL)
		cout << "("<<root->next->val<<")";
	cout << endl;
	printTree(root->left, space + "  ");
}


int main()
{
	Solution s;
	vector<int> tree = { 1, 2, 3, 4, 5, 6, 7 };
	vector<TreeLinkNode*> treeV;
	TreeLinkNode* head = new TreeLinkNode(tree[0]), *cur;
	treeV.push_back(head);
	for (int i = 1; i < tree.size(); i++)
	{
		cur = tree[i] != 0 ? new TreeLinkNode(tree[i]) : NULL;
		int p = (i - 1) / 2;
		if (treeV[p] != NULL)
			i % 2 != 0 ? treeV[p]->left = cur : treeV[p]->right = cur;
		treeV.push_back(cur);
	}

	printTree(head, "");
	s.connect(head);
	cout << endl;
	printTree(head, "");

	getchar();
	return 0;
}