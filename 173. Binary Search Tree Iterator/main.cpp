#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
	vector<TreeNode*> preVec;
	TreeNode* cur;
public:
	BSTIterator(TreeNode *root) {
		cur = root;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return cur != NULL || !preVec.empty();
	}

	/** @return the next smallest number */
	int next() {
		if (cur == NULL)
		{
			int r = preVec.back()->val;
			cur = preVec.back()->right;
			preVec.pop_back();
			return r;
		}

		if (cur->left != NULL)
		{
			preVec.push_back(cur);
			cur = cur->left;
			return next();
		}

		int r = cur->val;
		cur = cur->right;
		return r;
	}
};


int main()
{
	TreeNode* root = new TreeNode(5);
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	TreeNode* d = new TreeNode(4);
	TreeNode* e = new TreeNode(6);
	root->left = c;
	c->left = a;
	c->right = d;
	a->right = b;
	root->right = e;

	BSTIterator i = BSTIterator(root);
	while (i.hasNext()) cout << i.next();

	getchar();
	return 0;
}