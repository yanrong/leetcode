#include <vector>
#include<iostream>

using namespace std;

struct binary_tree_node{
	int data;
	binary_tree_node* left_child;
	binary_tree_node* right_child;
};

void create_tree(binary_tree_node* &tree, vector<int>& a, int index)
{
	if (index >= a.size())
		return;
	tree = new binary_tree_node;
	tree->data = a[index];
	tree->left_child = nullptr;
	tree->right_child = nullptr;
	create_tree(tree->left_child, a, 2 * index + 1);
	create_tree(tree->right_child, a, 2 * index + 2);
}
//?? segmentation fault
void create_tree_1(binary_tree_node* &node){
	char val;
	cin>>val;
	if(-1 == val){
		node = nullptr;
		return;
	}else{
		node = new binary_tree_node;
		node->data = val;
		create_tree_1(node->left_child);
		create_tree_1(node->right_child);
	}
}

void create_tree_2(binary_tree_node* &head, vector<int>& v, int index)
{
	if(index < v.size())
	{
		if(v[index] == -1){
			head = nullptr;
			return;
		}
		head = new binary_tree_node;
		head->data = v[index];
		create_tree_2(head->left_child, v, 2 * index + 1);
		create_tree_2(head->right_child, v, 2 * index + 2);
	}
}

void inorder(binary_tree_node* root)
{
	if (nullptr == root)
		return;
	cout << root->data << " ";
	inorder(root->left_child);
	inorder(root->right_child);
}

int main()
{
	vector<int> p{ 0, 1, 2, 3, 4, 5, 6 };
	binary_tree_node* tree;
	binary_tree_node* root;
	/*
	create_tree(tree, p, 0);
	inorder(tree);
	*/
	create_tree_1(root);
	inorder(root);
	return 0;
}

