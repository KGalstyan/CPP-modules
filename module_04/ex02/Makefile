NAME = AAnimal
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
HEADER = Dog.hpp AAnimal.hpp Cat.hpp WrongCat.hpp WrongAnimal.hpp Brain.hpp
SRC = main.cpp Dog.cpp AAnimal.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp
OBJS := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re