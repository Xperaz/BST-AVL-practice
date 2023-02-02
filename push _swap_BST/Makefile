HEADER= push_swap_BST.hpp

CC = c++

FLAGS= -std=c++98

SRCS = main.cpp parse.cpp split.cpp BST.cpp BST_tools.cpp\

NAME=push_swap

OBJ=$(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME) clean
.PHONY: clean fclean re all