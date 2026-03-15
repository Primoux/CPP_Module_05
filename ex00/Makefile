.PHONY : all re fclean clean run

NAME			= Desk

MAKEFLAGS		+= -j $$(nproc)

CC				= c++
CFLAGS			= -std=c++98 -Wall -Wextra -Werror
DEPS			= -MMD -MP

OBJ_DIR			= .build/
INCLUDE_DIR		= -Iinc/ -Iclass/Bureaucrat/
INCLUDES 		= $(INCLUDE_DIR)

SRCS			=	src/main.cpp \
					class/Bureaucrat/Bureaucrat.cpp


OBJS			= $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRCS))
DEPENDENCIES	= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEPS) -c $< -o $@

-include $(DEPENDENCIES)

run: all
	./$(NAME)
	
valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

re: fclean all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
