#include"tree.h"
#include<stdio.h>
void processNode(TREE_TYPE value) {
	printf("%d ", value);
}
int main() {
	TreeNode* tree = NULL;
	insert_node(&tree, 5);
	insert_node(&tree, 3);
	insert_node(&tree, 1);
	insert_node(&tree, 4);
	insert_node(&tree, 7);
	insert_node(&tree, 2);
	insert_node(&tree, 9);
	insert_node(&tree, 6);
	mid_order_traverse(tree, processNode);
	printf("\n");
	int *pi = find_node(tree, 7);
	*pi = 8;
	mid_order_traverse(tree, processNode);
	printf("\n");
	delete_node(&tree, 9);
	mid_order_traverse(tree, processNode);
	printf("\n");
	delete_node(&tree, 5);
	mid_order_traverse(tree, processNode);
	printf("\n");

}