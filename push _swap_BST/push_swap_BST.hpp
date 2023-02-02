#ifndef PUSH_SWAP_BST_HPP
# define PUSH_SWAP_BST_HPP


struct bst_node
{
	int 		data;
	bst_node	*left;
	bst_node	*right;
};

typedef struct node
{
	int data;
	struct node *next;
} t_list;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>

// parsing

int	    ft_strlen(char *str);
char	*ft_strcat(char *tab, char *src);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *str, char delim);
char	*ft_strdup(char *s1);

// BST Methodes
bst_node	*delete_node(bst_node *root, int data);
bst_node	*min_value_node(bst_node *root);
void		inorder_traversal(bst_node *root, bst_node *stack_b);
bst_node	*insert(bst_node *root, int data);
int			max(bst_node *root);
int			min(bst_node *root);
int			find_height(bst_node *root);
int			max(int a, int b);
bool		search(bst_node *root, int data);
bst_node	*get_new_node(int data);

#endif