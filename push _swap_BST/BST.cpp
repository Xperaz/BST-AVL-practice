#include <iostream>
#include "push_swap_BST.hpp"

bst_node *insert(bst_node *root, int data)
{
	if (root == NULL)
		root = get_new_node(data);
	else if (data <= root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	return (root);
}

// traverse bst using inorder depth-first
// <left><root><right> => visit order (left first then root, then right)

void pb(bst_node *stack_b, int data)
{
    insert(stack_b, data);
    std::cout << "pb" << std::endl;
}

void inorder_traversal(bst_node *root, bst_node *stack_b)
{
	if (root == NULL) return;
	inorder_traversal(root->left, stack_b);
	pb(stack_b, root->data);
	inorder_traversal(root->right, stack_b);
}

bst_node	*min_value_node(bst_node *root)
{
	bst_node* current = root;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

bst_node *delete_node(bst_node *root, int data)
{
	// the base condition for recursive
	if(root == NULL) return root; 

	// If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
	else if(data < root->data) root->left = delete_node(root->left,data);

	// If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
	else if (data > root->data) root->right = delete_node(root->right,data);

	// if key is same as root's key, then This is the node
    // to be deleted

	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			bst_node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			bst_node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			bst_node *temp = min_value_node(root->right);
			root->data = temp->data;
			root->right = delete_node(root->right,temp->data);
		}
	}
	return root;
}
