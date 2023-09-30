NAME=snek
CC=c++
FLAGS=-Wall -Wextra -Werror -g
SRCS=$(wildcard *.cpp) \
	$(wildcard Model/*.cpp) \
	$(wildcard View/*.cpp) \
# 	$(wildcard Controller/*.cpp) \

${NAME} :
	$(CC) -Iincludes $(SRCS) -o $(NAME) -g

all : ${NAME}

clean :
	rm -rf ${NAME}

fclean : clean

re : fclean all