NAME = serena
CPP = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJS := $(SRC:.cpp=.o)

RM = del /Q

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
