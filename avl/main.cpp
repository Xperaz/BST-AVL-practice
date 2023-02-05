#include <iostream>

struct avl_node
{
    int data;
    avl_node    *left;
    avl_node    *right;
    int         height;
};

/*void inorder_traversal(avl_node *root)
{
	if (root == NULL) return;
	inorder_traversal(root->left);
	std::cout << root->data << std::endl;
	inorder_traversal(root->right);
}*/

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

int main()
{
    avl_node    *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    pre_order(root);
    // 30 20 10 25 40 50 
    return 0;
}