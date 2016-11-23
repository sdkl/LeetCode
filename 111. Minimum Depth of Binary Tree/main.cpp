#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		vector<TreeNode*> nodes;
		int d = 0;
		if (root != NULL)
			nodes.push_back(root);

		while (nodes.size() > 0)
		{
			d++;
			int num = nodes.size();
			while (num-- > 0)
			{
				TreeNode *cur = nodes[0];
				nodes.erase(nodes.begin());
				if (cur->left == NULL && cur->right == NULL)
					return d;

				if (cur->left != NULL)
					nodes.push_back(cur->left);
				if (cur->right != NULL)
					nodes.push_back(cur->right);
			}			
		}

		return d;
	}
};

int main()
{
	Solution s;
	vector<int> tree = { 1, 2, 2, 3, 0, 0, 3, 4 };
	vector<TreeNode*> treeV;
	TreeNode* head = NULL, *cur;
	for (int i = 0; i < tree.size(); i++)
	{
		if (tree[i] != 0)
		{
			cur = new TreeNode(tree[i]);
			if (head == NULL)
				head = cur;
		}
		else
			cur = NULL;
		int p = (i - 1) / 2;
		if (p >= 0 && p < treeV.size() && treeV[p] != NULL)
		{
			if (p * 2 + 1 == i)
				treeV[p]->left = cur;
			else
				treeV[p]->right = cur;
		}

		treeV.push_back(cur);
	}

	cout << s.minDepth(head) << endl;

	getchar();
	return 0;
}