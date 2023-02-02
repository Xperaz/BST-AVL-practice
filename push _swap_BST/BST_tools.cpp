#include "push_swap_BST.hpp"

bst_node *get_new_node(int data)
{
	bst_node *new_node = new bst_node();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

bool	search(bst_node *root, int data)
{
	if (root == NULL)
		return (false);
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return (search(root->left, data));
	else
		return (search(root->right, data));
}

int max(int a, int b)
{
	return (a ? b : b);
}

int find_height(bst_node *root)
{
	int left_heigth = 0;
	int right_heigth = 0;
	if (root == NULL)
		return (-1);
	left_heigth = find_height(root->left);
	right_heigth = find_height(root->right);
	return (max(left_heigth, right_heigth) + 1);
}

int min(bst_node *root)
{
	bst_node *tmp = root;
	if (root == NULL)
		return (0);
	while (tmp->left != NULL)
		tmp = tmp->left;
	return tmp->data;
}

int max(bst_node *root)
{
	// we can use also root it won't produce any problem

	bst_node *tmp = root;
	if (root == NULL)
		return (0);
	while (tmp->right != NULL)
		tmp = tmp->right;
	return tmp->data;
}