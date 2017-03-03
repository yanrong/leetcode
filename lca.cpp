#include <iostream>
#include <vector>

using namespace std;

struct node{
	int key;
	struct node *left, *right;
};


node* new_node(int k)
{
	node *tmp = new node;
	tmp->key = k;
	tmp->left = tmp->right = nullptr;
}

bool find_path(node *root, vector<int> path; int k)
{
	if (!root) return false;
	path.push_back(root_key);
}