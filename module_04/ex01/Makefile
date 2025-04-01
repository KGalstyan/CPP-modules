NAME = Brain
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98 -fsanitize=address
HEADER = Dog.hpp Animal.hpp Cat.hpp WrongCat.hpp WrongAnimal.hpp Brain.hpp
SRC = main.cpp Dog.cpp Animal.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp

OBJS := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re