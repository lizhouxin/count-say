//typedef long long ll;
//typedef vector<int> VI;
//typedef pair<int, int> PII;
//
//#define REP(i,s,t) for(int i=(s);i<(t);i++)
//#define FILL(x,v) memset(x,v,sizeof(x))
//
//const int INF = (int)1E9;
//#define MAXN 100005
//
//map<int, VI> adj;
//VI ans;
//class Solution {
//public:
//	void edge(int x, int y) {
//		adj[x].push_back(y);
//		adj[y].push_back(x);
//	}
//	void dfs(TreeNode *x) {
//		if (x == NULL) return;
//		dfs(x->left);
//		if (x->left) edge(x->val, x->left->val);
//		dfs(x->right);
//		if (x->right) edge(x->val, x->right->val);
//	}
//	void find(int x, int p, int K, int d) {
//		if (d == K) ans.push_back(x);
//		REP(i, 0, adj[x].size()) {
//			int y = adj[x][i];
//			if (y == p) continue;
//			find(y, x, K, d + 1);
//		}
//	}
//	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//		adj.clear();
//		dfs(root);
//		ans.clear();
//		if (root == NULL) return ans;
//		find(target->val, -1, K, 0);
//		return ans;
//	}
//};
#include<vector>
#include<iostream>
#include<map>

using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x),left(NULL),right(NULL){}
//}*tree,node;
template<typename T>
struct binaryTreeNode
{
	T val;
	binaryTreeNode<T>* left;
	binaryTreeNode<T>* right;
	binaryTreeNode() { left = NULL; right = NULL; }
};

map<binaryTreeNode<int>*, binaryTreeNode<int>*> fa;
template<typename T>
void dfs(binaryTreeNode<T> *r, binaryTreeNode<T> *f)
{
	if (r == NULL)
		return;
	if (r != f)
	{
		fa[r] = f;
	}
	dfs(r->left, r);
	dfs(r->right, r);
}
vector<int> ans;
template<typename T>
void dfs2(binaryTreeNode<T> *r, binaryTreeNode<T> *f, int d)
{
	if (r == NULL)return;
	if (d == 0)
	{
		ans.push_back(r->val);
		return;
	}
	if (r->left != f)dfs2(r->left, r, d - 1);
	if (r->right != f)dfs2(r->right, r, d - 1);
	if (fa.find(r) != fa.end() and fa[r] != f)dfs2(fa[r], r, d - 1);
}


template<typename T>
class binaryTree
{
private:
	binaryTreeNode<T> * mRoot;
public:
	binaryTree() {};
	virtual  ~binaryTree() {};
	binaryTreeNode<T>* create();
};

template<typename T>
binaryTreeNode<T>* binaryTree<T>::create()
{
	binaryTreeNode<T>* current = NULL;
	T val;
	cin >> val;
	if (val == -1)
		return NULL;
	else
	{
		current = new binaryTreeNode<T>;
		current->val = val;
		current->left = create();
		current->right = create();
		return current;
	}
}

//int main()
//{
//dfs(root, root);
//dfs2(target, target, K);

//	binaryTree<int> mtree;
//	mtree.create();
//	system("pause");
//}