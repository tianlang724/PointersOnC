#include<assert.h>
#include<stdio.h>
#include<malloc.h>
#define TREE_TYPE int
typedef struct TREE_NODE {
	TREE_TYPE value;
	TREE_NODE *left;
	TREE_NODE *right;
}TreeNode;

int insert_node(TreeNode **ptree, TREE_TYPE value);
TREE_TYPE* find_node(TreeNode *tree, TREE_TYPE value);
void mid_order_traverse(TreeNode *tree ,void(*callback)(TREE_TYPE value));
int delete_node(TreeNode **ptree, TREE_TYPE value);



int insert_node(TreeNode **ptree, TREE_TYPE value) {
	TreeNode *current = *ptree;
	while ((current = *ptree) != NULL&&current->value != value) {
		if (current->value < value) {
			ptree = &current->right;
		}
		else {
			ptree = &current->left;
		}
	}
	if (current!=NULL&&current->value == value) {
		perror("has the same value");
		return 0;
	}
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node == NULL) {
		perror("malloc error");
		return 0;
	}
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	*ptree = node;
	return 1;
}
TREE_TYPE* find_node(TreeNode *tree, TREE_TYPE value) {
	TreeNode *current = tree;
	while (current != NULL&&current->value != value) {
		if (current->value < value) {
			current = current->right;
		}
		else {
			current = current->left;
		}
	}
	if (current == NULL) {
		return NULL;
	}
	else {
		return &current->value;
	}
}
static void do_mid_order_traverse(TreeNode* tree, void(*callback)(TREE_TYPE value)) {
	if (tree != NULL) {
		do_mid_order_traverse(tree->left, callback);
		callback(tree->value);
		do_mid_order_traverse(tree->right, callback);
	}
}
void mid_order_traverse(TreeNode *tree,void(*callback)(TREE_TYPE value)) {
	do_mid_order_traverse(tree, callback);
}
int delete_node(TreeNode **ptree, TREE_TYPE value) {
	TreeNode *cur;
	while ((cur = *ptree) != NULL&&cur->value != value) {
		if (cur->value < value)
			ptree = &cur->right;
		else
			ptree = &cur->left;
	}
	if (cur == NULL) {
		perror("no such value");
		return 0;
	}
	if (cur->left == NULL&cur->right == NULL) {
		*ptree = NULL;
		free(cur);
	}
	else if (cur->left == NULL&&cur->right != NULL) {
		*ptree = cur->right;
		free(cur);
	}
	else if (cur->left != NULL&&cur->right == NULL) {
		*ptree = cur->left;
		free(cur);
	}
	else {
		TreeNode **pleftbig = &cur->left;
		TreeNode *leftbig = *pleftbig;
		while ((leftbig->right) != NULL) {
			pleftbig = &leftbig->right;
			leftbig = *pleftbig;
		}
		if (leftbig->left == NULL) {
			cur->value = leftbig->value;
			*pleftbig = NULL;
		}
		else {
			cur->value = leftbig->value;
			*pleftbig = leftbig->left;
		}
		free(leftbig);
	}
	return 1;
}
