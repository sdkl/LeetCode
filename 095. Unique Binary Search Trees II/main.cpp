#include<iostream>
#include<algorithm>
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
	TreeNode * copyTree(TreeNode* root)
	{
		if (root == NULL)
			return NULL;

		TreeNode *nNode = new TreeNode(root->val);
		nNode->left = copyTree(root->left);
		nNode->right = copyTree(root->right);
		return nNode;
	}

	void deleteTree(TreeNode* root)
	{
		if (root == NULL)
			return;
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}

	vector<TreeNode*> generateTrees(int n) {
		if (n <= 0)
			return{};

		if (n == 1)
		{
			return{new TreeNode(1)};
		}
		else
		{
			vector<TreeNode*> t = generateTrees(n - 1);
			vector<TreeNode*> result;
			TreeNode *nNode = new TreeNode(n);
			for (auto i : t)
			{
				nNode->left = i;
				result.push_back(copyTree(nNode));

				TreeNode *cur = i;
				while (cur != NULL)
				{
					nNode->left = cur->right;
					cur->right = nNode;
					result.push_back(copyTree(i));
					cur->right = nNode->left;
					cur = cur->right;
				}
				deleteTree(i);
			}
			delete nNode;
			return result;
		}
	}
};


void space(int n)
{
	for (int i = 0; i<n; i++)
		cout << ' ';
}

void printTree(TreeNode* t,int n)
{
	if (t == NULL)
		return;	

	printTree(t->right, n + 2);
	space(n);
	cout << t->val <<endl;
	printTree(t->left, n + 2);
	
}

int main()
{
	Solution s;
	vector<TreeNode*> r = s.generateTrees(3);
	for (auto i : r)
	{
		printTree(i,0);
		cout << endl;
	}

	getchar();
	return 0;
}