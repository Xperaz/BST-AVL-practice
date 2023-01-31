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

// level Order bst traverse

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
	print(root);
	return 0;
}