CPP			=	clang++
FLAGS		=	-std=c++98 -g -Wall -Wextra -Werror -D STATUS=1
NAME		=	Containers
SRCS		=	main.cpp \

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

%.o: 		%.cpp Makefile utils.hpp iterator.hpp stack.hpp
			$(CPP) $(FLAGS) -c $<

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re