SRC			=	src/sudokuException.cpp		\
				src/sudoku.cpp				\
				src/lp.cpp					\
				src/main.cpp

OBJS		=	$(SRC:.cpp=.o)

NAME		=	sudoku

CXXFLAGS	+=	-llpsolve55 -I./include
CXXFLAGS	+=	-W -Wall

GXX			=	g++

all:			$(NAME)

$(NAME):		$(OBJS)
				$(GXX) $(CXXFLAGS) -o $@ $^

clean:			
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
