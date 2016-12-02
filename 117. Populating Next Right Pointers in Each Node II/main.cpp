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
		TreeLinkNode* cur = root;

		while (cur)
		{
			TreeLinkNode* row = cur;
			while (row)
			{
				if (row->left && row->right)
					row->left->next = row->right;

				TreeLinkNode* next = row->next;
				while (next && !next->left && !next->right)
					next = next->next;
				if (next)
				{
					if (row->right)
						row->right->next = next->left ? next->left : next->right;
					else if (row->left)
						row->left->next = next->left ? next->left : next->right;
				}
				row = next;
			}

			TreeLinkNode* next = cur;
			while (next && !next->left && !next->right)
				next = next->next;
			if (next)
				cur = next->left ? next->left : next->right;
			else
				cur = next;
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
		cout << "(" << root->next->val << ")";
	cout << endl;
	printTree(root->left, space + "  ");
}


int main()
{
	Solution s;
	vector<int> tree = { 1, 2, 3, 4, 5, 6, 7,0,0,0,8,0,0,0,9 };
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