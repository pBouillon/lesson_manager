CC	= 	g++ 

LIB	=	-lsqlite3

CFLAGS	=	-std=c++11 -Wextra -Wall $(LIB)

HEAD	=	-I./header

SRCS	=	lesson_manager.cpp\
		manager/database.cpp\
		users/person.cpp\
		users/student.cpp\
		users/teacher.cpp\
		users/admin.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	lesson_manager

all: 		$(NAME)

.cpp.o:
		$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(NAME): 	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(HEAD) -o $(NAME)


clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		clean fclean all re
