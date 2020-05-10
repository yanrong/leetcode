#include <stdio.h>

typedef struct BNode {
    int data;
    struct BNode *left, *right;
} BNode, *BiTree;

/**
 *morris中序遍历二叉树
 */
void morris_inorder(BiTree T) {
    BNode *p, *temp;
    p = T;
    while(p) {
        if(p->left == NULL) {
            printf("%4d", p->data);
            p = p->right;
        } else {
            temp = p->left;
            //找到左子树的最右子节点
            while(temp->right != NULL && temp->right != p) {
                temp = temp->right; 
            }
            if(temp->right == NULL) {
                temp->right = p;
                p = p->left;
            } else {
                printf("%4d", p->data);
                temp->right = NULL;
                p = p->right;
            }
        }
    }
}

void morris_preOrder(BiTree T) {
    BNode *p = T, *temp;
    while(p != NULL) {
        if(p->left == NULL) {
            printf("%4d",p->data);
            p = p->right;
        } else {
            temp = p->left;
            while(temp->right != NULL && temp->right != p) {
                temp = temp->right;
            }
            if(temp->right == NULL) {
                printf("%4d", p->data);
                temp->right = p;
                p = p->left;
            } else {
                temp->right = NULL;
                p = p->right;
            }
        }
    }    
}

/**
 * morris后序遍历算法 
 */
void morris_postOrder(BiTree T) {
    BNode *dump = malloc(sizeof(BNode));
    BNode *p, *temp;
    dump->left = T;
    p = dump;
    while(p) {
        if(p->left == NULL) {
            p = p->right;
        } else {
            temp = p->left;
            while(temp->right != NULL && temp->right != p) {
                temp = temp->right;
            }
            if(temp->right == NULL) {
                temp->right = p;
                p = p->left;
            } else {
                printReverse(p->left, temp);
                temp->right = NULL;
                p = p->right;
            }
        }
    }
    free(dump);
}

/**
 * 相当于单链表的反转
 */
void reverse(BNode *from, BNode *to) {
    BNode *x, *y, *z;
    if(from == to) {
        return;
    }
    x = from;
    y = from->right;
    while(x != to) {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
    }
}
 
void printReverse(BNode *from , BNode *to) {
    BNode *p;
    reverse(from, to);
    p = to;
    while(1) {
        printf("%4d", p->data);
        if(p == from) {
            break;
        }
        p = p->right;
    }
    reverse(to, from);
}


/**
 * 递归先序遍历
 */
void preOrder_traverse_recur(BiTree T) {
    if(T == NULL) {
        return;
    } else {
        printf("%4d", T->data);
        preOrder_traverse_recur(T->left);
        preOrder_traverse_recur(T->right);
    }
}

/**
 * 递归中序遍历
 */
void inOrder_traverse_recur(BiTree T) {
    if(T == NULL) {
        return;
    } else {
        inOrder_traverse_recur(T->left);
        printf("%4d", T->data);
        inOrder_traverse_recur(T->right);
    }
}

/**
 * 递归后序遍历
 */
void postOrder_traverse_recur(BiTree T) {
    if(T == NULL) {
        return;
    } else {
        postOrder_traverse_recur(T->left);
        postOrder_traverse_recur(T->right);
        printf("%4d", T->data);
    }
}
//create tree
BiTree create_tree(int a[], int len, int index)
{
	if (index >= len || a[index] == -1){
		return NULL;
	}
	BiTree tree = (BiTree)malloc(sizeof(BNode));
	tree->data = a[index];
	tree->left = create_tree(a, len, 2 * index + 1);
	tree->right = create_tree(a, len, 2 * index + 2);
	return tree;
}

int main(void)
{
	BiTree head;
	int nums[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8};
	int length = sizeof(nums)/ sizeof(nums[0]);
	
	head = create_tree(nums, length, 0);
	printf("----------morris traverse 2 --------------\n");
	printf("前序遍历序列为:");
	morris_preOrder(head);
	printf("\n");
 
	printf("中序遍历序列为:");
	morris_inorder(head);
	printf("\n");
 
	printf("后序遍历序列为:");
	morris_postOrder(head);
	printf("\n");

	printf("-----------classic traverse 2--------------\n");
	printf("前序遍历序列为:");
	preOrder_traverse_recur(head);
	printf("\n");
 
	printf("中序遍历序列为:");
	inOrder_traverse_recur(head);
	printf("\n");
 
	printf("后序遍历序列为:");
	postOrder_traverse_recur(head);
	printf("\n");

	return 0;
}