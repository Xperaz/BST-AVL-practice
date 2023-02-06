#include <iostream>

struct avl_node
{
	int data;
	avl_node    *left;
	avl_node    *right;
	int         height;
};

void pre_order(avl_node  *root)
{
	if(root != NULL)
	{
		std::cout << root->data << " ";
		pre_order(root->left);
		pre_order(root->right);
	}
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

avl_node    *min_value_node(avl_node* node)
{
	avl_node* current = node;
 
	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;
 
	return current;
}

avl_node    *new_node(int data)
{
	avl_node *new_node = new(std::nothrow) avl_node();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	new_node->height = 1;
	return (new_node);
}

int height(avl_node *node)
{
	if (node == NULL)
		return (0);
	return (node->height);
}

avl_node    *right_rotate(avl_node *y)
{
	avl_node *x = y->left;
	avl_node *t = x->right;

	x->right = y;
	y->left = t;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return (x);
}

avl_node    *left_rotate(avl_node *y)
{
	avl_node *x = y->right;
	avl_node *t = x->left;

	x->left = y;
	y->right = t;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return (x);
}


int get_balance_factor(avl_node *root)
{
	if (root == NULL)
		return 0;
	else
		return (height(root->left) - height(root->right));
}

avl_node    *insert(avl_node *root, int data)
{
	if (root == NULL)
		return(new_node(data));
 
	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	else
		return root;

   root->height = 1 + max(height(root->left), height(root->right));
   
   int bf = get_balance_factor(root);

	if (bf > 1 && data < root->left->data)
		return right_rotate(root);
 

	if (bf < -1 && data > root->right->data)
		return left_rotate(root);
 
	if (bf > 1 && data > root->left->data)
	{
		root->left = left_rotate(root->left);
		return right_rotate(root);
	}
 
	if (bf < -1 && data < root->right->data)
	{
		root->right = right_rotate(root->right);
		return left_rotate(root);
	}
 
	return (root);
}

avl_node* delete_node(avl_node* root, int key)
{
	 
	// STEP 1: PERFORM STANDARD BST DELETE
	if (root == NULL)
		return root;
 
	// If the key to be deleted is smaller
	// than the root's key, then it lies
	// in left subtree
	if ( key < root->data )
		root->left = delete_node(root->left, key);
 
	// If the key to be deleted is greater
	// than the root's key, then it lies
	// in right subtree
	else if( key > root->data )
		root->right = delete_node(root->right, key);
 
	// if key is same as root's key, then
	// This is the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left == NULL) ||
			(root->right == NULL) )
		{
			avl_node *temp = root->left ?
						 root->left :
						 root->right;
 
			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
						   // the non-empty child
			delete temp;
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			avl_node* temp = min_value_node(root->right);
 
			// Copy the inorder successor's
			// data to this node
			root->data = temp->data;
 
			// Delete the inorder successor
			root->right = delete_node(root->right,
									 temp->data);
		}
	}
 
	// If the tree had only one node
	// then return
	if (root == NULL)
	return root;
 
	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),
						   height(root->right));
 
	// STEP 3: GET THE BALANCE FACTOR OF
	// THIS NODE (to check whether this
	// node became unbalanced)
	int balance = get_balance_factor(root);
 
	// If this node becomes unbalanced,
	// then there are 4 cases
 
	// Left Left Case
	if (balance > 1 &&
		get_balance_factor(root->left) >= 0)
		return right_rotate(root);
 
	// Left Right Case
	if (balance > 1 &&
		get_balance_factor(root->left) < 0)
	{
		root->left = left_rotate(root->left);
		return right_rotate(root);
	}
 
	// Right Right Case
	if (balance < -1 &&
		get_balance_factor(root->right) <= 0)
		return left_rotate(root);
 
	// Right Left Case
	if (balance < -1 &&
		get_balance_factor(root->right) > 0)
	{
		root->right = right_rotate(root->right);
		return left_rotate(root);
	}
 
	return root;
}

avl_node *find_node(avl_node *root, int data)
{
	if (root == NULL)
		return (NULL);
	else if (root->data == data)
		return (root);
	avl_node *tmp = root;
	if (data > root->data)
	{
		while (tmp->right != NULL)
		{
		if (root->data == data)
			return (root);
			if (tmp->data == data)
				return (tmp);
			tmp = tmp->right;
		}
	}
	else
	{
		while (tmp->left != NULL)
		{
			if (tmp->data == data)
				return (tmp);
			tmp = tmp->left;
		}
	}
	return (new_node((int)NULL));
}

int main()
{
	avl_node *root = NULL;
 
    /* Constructing tree given in
    the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

	avl_node *find = find_node(root, 8784654);
	std::cout << "[" << find->data << "]"<< std::endl;
 
    /* The constructed AVL Tree would be
            9
        / \
        1 10
        / \ \
    0 5 11
    / / \
    -1 2 6
    */
 
    std::cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    pre_order(root);
 
    root = delete_node(root, 10);
 
    /* The AVL Tree after deletion of 10
            1
        / \
        0 9
        / / \
    -1 5     11
        / \
        2 6
    */
 
    std::cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    pre_order(root);
 
    return 0;
}
