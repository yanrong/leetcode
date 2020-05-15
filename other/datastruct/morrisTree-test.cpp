#include <iostream>
#include <vector>

using namespace std;

typedef int dataType;
typedef struct Node
{
	dataType val;
	struct Node *left;
	struct Node *right;
	Node():val(-1), left(nullptr), right(nullptr){}
	Node(dataType _val): val(_val), left(nullptr), right(nullptr){}
}TreeNode;


// Morris中序遍历 (左 -> 根 -> 右)
void MorrisInOrderTraverse(Node *head)
{
	if (head == NULL)
	{
		return;
	}

	Node *p1 = head;
	Node *p2 = NULL;

	while (p1 != NULL)
	{
		p2 = p1->left;
		if (p2 != NULL)
		{
			while(p2->right != NULL && p2->right != p1)
			{
				p2 = p2->right;
			}
			if (p2->right == NULL)
			{
				p2->right = p1;		// 空闲指针
				p1 = p1->left;
				continue;
			}
			else
			{
				p2->right = NULL;
			}
		}
		cout<<p1->val<<" ";
		p1 = p1->right;
	}
}

// Morris前序遍历 (根 -> 左 -> 右)
void MorrisPreOrderTraverse(Node *head)
{
	if (head == NULL)
	{
		return;
	}

	Node *p1 = head;
	Node *p2 = NULL;

	while (p1 != NULL)
	{
		p2 = p1->left;
		if (p2 != NULL)
		{
			while(p2->right != NULL && p2->right != p1)
			{
				p2 = p2->right;
			}
			if (p2->right == NULL)
			{
				p2->right = p1;		// 空闲指针
				cout<<p1->val<<" ";	// 打印结点值的顺序稍微调整
				p1 = p1->left;
				continue;
			}
			else
			{
				p2->right = NULL;
			}
		}
		else
		{
			cout<<p1->val<<" ";
		}
		p1 = p1->right;
	}
}

// 逆序右边界
Node* reverseEdge(Node *head)
{
	Node *pre = NULL;
	Node *next = NULL;

	while(head != NULL)
	{
		next = head->right;
		head->right = pre;
		pre = head;
		head = next;
	}

	return pre;
}

// 逆序打印左子树右边界
void printEdge(Node *head)
{
	Node *lastNode = reverseEdge(head);
	Node *cur = lastNode;
	
	while (cur != NULL)
	{
		cout<<cur->val<<" ";
		cur = cur->right;
	}
	reverseEdge(lastNode);
}
	
// Morris后序遍历 (左 -> 右 -> 根)
void MorrisPostOrderTraverse(Node *head)
{
	if (head == NULL)
	{
		return;
	}
	
	Node *p1 = head;
	Node *p2 = NULL;
	
	while (p1 != NULL)
	{
		p2 = p1->left;
		if (p2 != NULL)
		{
			while(p2->right != NULL && p2->right != p1)
			{
				p2 = p2->right;
			}
			if (p2->right == NULL)
			{
				p2->right = p1;		// 空闲指针
				p1 = p1->left;
				continue;
			}
			else
			{
				p2->right = NULL;
				printEdge(p1->left);
			}
		}
		p1 = p1->right;
	}
	printEdge(head);
}

void buildBinTree(Node **head)
{
	dataType _val;
	cin>>_val;

	if (_val == -1)
	{
		*head = NULL;
	}
	else
	{
		*head = (Node*)malloc(sizeof(Node));
		(*head)->val = _val;
		buildBinTree(&(*head)->left);
		buildBinTree(&(*head)->right);
	}
}

class morrisTree{
public:
    void morrisPreorder(TreeNode* root){
        if(root == nullptr){
            return ;
        }
        TreeNode *cur = root;
        TreeNode *mostRight = nullptr;
        while (cur != nullptr)
        {
            mostRight = cur->left;
            if(mostRight != nullptr){
                while(mostRight->right != nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == nullptr){
                    mostRight->right = cur; // right point to parent
                    //get the value, next step will visit right child
                    cout<< cur->val<< " ";
                    cur = cur->left;
                    //why continue, we have been reach the left-right most, 
                    //next step visit left child
                    continue;
                }else{
                    mostRight->right = nullptr;
                }
            }else{//if the left child is empty, visit parent node
                cout<<cur->val<<" ";
            }
            cur = cur->right;
        }
    }

    void morrisInorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        TreeNode *cur = root, *mostRight = nullptr;
        while(cur != nullptr){
            mostRight = cur->left; //visit the left tree
            if(mostRight != nullptr){
                while(mostRight->right != nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == nullptr){
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }else{
                    mostRight->right = nullptr;
                }
            }
            cout<<cur->val<<" ";
            cur = cur->right;
        }
    }

    void morrisPostorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        TreeNode *cur = root, *mostRight = nullptr;
        while(cur != nullptr){
            mostRight = cur->left;
            if(mostRight != nullptr){
                while(mostRight->right != nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == nullptr){
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }else{
                    mostRight->right = nullptr;
                    printEdge(cur->left);
                }
            }
            cur = cur->right;
        }
        printEdge(root);
    }

    void printEdge(TreeNode *root){
        root = rightReverse(root);
        TreeNode *cur = root;
        while(cur != nullptr){
            cout<<cur->val<< " ";
            cur = cur->right;
        }
        root = rightReverse(root);
    }

    TreeNode* rightReverse(TreeNode *root){
        TreeNode *cur = root->right, *prev = root;
        prev->right = nullptr;
        while(cur != nullptr){
            TreeNode *tmp = cur;
            cur = cur->right;
            tmp->right = prev;
            prev = tmp;
        }
        return prev;
    }
};

void buildBinTree(Node* &head, vector<int>& v, int index)
{
	if(index < v.size())
	{
		if(v[index] == -1){
			head = nullptr;
			return;
		}
		head = new Node;
		head->val = v[index];
		buildBinTree(head->left, v, 2 * index + 1);
		buildBinTree(head->right, v, 2 * index + 2);
	}
}
/********************************************************************
***** Classic traverse
********************************************************************/
void preOrder(Node* root){
	if (nullptr == root)
		return;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node* root){
	if(root == nullptr){
		return;
	}
	inOrder(root->left);
	cout <<root->val << " ";
	inOrder(root->right);
}

void postOrder(Node* root){
	if(root == nullptr){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->val << " ";
}

int main(void)
{
	Node *head;
	vector<int> nums{1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8};
	vector<int> ret;
	morrisTree T;
	
	buildBinTree(head, nums, 0);
	cout <<"----------morris traverse--------------" <<endl;
	cout<<"前序遍历序列为:";
	MorrisPreOrderTraverse(head);
	cout<<endl;
 
	cout<<"中序遍历序列为:";
	MorrisInOrderTraverse(head);
	cout<<endl;
 
	cout<<"后序遍历序列为:";
	MorrisPostOrderTraverse(head);
	cout<<endl;

	cout <<"-----------classic traverse--------------" <<endl;
	cout<<"前序遍历序列为:";
	preOrder(head);
	cout<<endl;
 
	cout<<"中序遍历序列为:";
	inOrder(head);
	cout<<endl;
 
	cout<<"后序遍历序列为:";
	postOrder(head);
	cout<<endl;

	return 0;
}

