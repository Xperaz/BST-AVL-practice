#include "push_swap_BST.hpp"

void print(bst_node *root)
{
	if (root == NULL) return;
	inorder_traversal(root->left, NULL);
	std::cout << "\n" << root->data << " ";
	inorder_traversal(root->right, NULL);
}

char **ft_parse(int ac, char **av)
{
    char *merge;
    char **tok;
    std::string str = " ";
    char *sep = new char[2];
    strcpy(sep, str.c_str());
    merge = ft_strdup(sep);
    for (size_t i = 0; i < ac; i++)
    {
        char *tok = ft_strjoin(av[i], sep);
        merge = ft_strjoin(merge,tok);
    }

    tok = ft_split(merge, ' ');
    return (tok);
}

bst_node    *fill_bst(bst_node *bst, char **tab)
{
   int i = 0;
    while (tab[i])
    {
        bst = insert(bst, atoi(tab[i]));
        i++;
    }
    return (bst);
}

int main(int ac, char **av)
{
    bst_node *stack_a =  NULL;
    bst_node *stack_b = NULL;

    char **tab;
    if (!av[0] || ac < 2 || !av)
        return 0;
    tab = ft_parse(ac - 1, av + 1);
    stack_a = fill_bst(stack_a, tab);
    inorder_traversal(stack_a, stack_b);
    print(stack_a);
    return 0;
}