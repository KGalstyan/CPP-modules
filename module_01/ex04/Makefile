NAME = replacing
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
# HEADER =
SRC = main.cpp

OBJS := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) #$(HEADER)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
