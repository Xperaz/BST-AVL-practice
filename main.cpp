#include <iostream>
#include <queue>

struct bst_node
{
	int 		data;
	bst_node	*left;
	bst_node	*right;
};

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

// level Order bst traverse (breadth first traversal)

void	print(bst_node *root)
{
	if (root == NULL) return;
	std::queue<bst_node*> Q;
	std::cout << "\n-------------------------\n" << "the BST content: " << std::endl;
	Q.push(root);
	// while there is at least one node 
	while (!Q.empty())
	{
		bst_node *tmp = Q.front();
		std::cout << tmp->data << std::endl;
		if (tmp->left != NULL)
			Q.push(tmp->left);
		if (tmp->right != NULL)
			Q.push(tmp->right);
		Q.pop();//remove the element at front
	}
	
}

// traverse bst using preorder depth-first
// <root><left><right> => visit order (root first then left, then right)

void preorder_traversal(bst_node *root)
{
	if (root == NULL) return;
	std::cout << root->data << std::endl;
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

// traverse bst using inorder depth-first
// <left><root><right> => visit order (left first then root, then right)

void inorder_traversal(bst_node *root)
{
	if (root == NULL) return;
	inorder_traversal(root->left);
	std::cout << root->data << std::endl;
	inorder_traversal(root->right);
}

// traverse bst using postorder depth-first
// <left><right><root> => visit order (left first then right, then root)
/* notice that always left come before right */

void postorder_traversal(bst_node *root)
{
	if (root == NULL) return;
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	std::cout << root->data << std::endl;
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

int main()
{
	bst_node *root = NULL;

	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 100);
	root = insert(root, 300);
	root = insert(root, 5);
	root = insert(root, 150);
	root = insert(root, 400);
	std::cout << "min of this bst is: " << min(root) << std::endl; 
	std::cout << "max of this bst is: " << max(root) << std::endl;
	std::cout << "the height of this bst is: " << find_height(root) << std::endl;
	inorder_traversal(root);
	root = delete_node(root, 5);
	root = delete_node(root, 10);
	root = delete_node(root, 15);
	root = delete_node(root, 20);
	root = delete_node(root, 100);
	root = delete_node(root, 150);
	root = delete_node(root, 300);
	root = delete_node(root, 400);
	std::cout << "\n------------------ BST Content After deletion -------------------\n";
	inorder_traversal(root);
	//postorder_traversal(root);
	return 0;
}