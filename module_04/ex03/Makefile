NAME = Interface
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
HEADER = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp \
			IMateriaSource.hpp MateriaSource.hpp
SRC = AMateria.hpp Character.cpp Cure.cpp Ice.cpp ICharacter.cpp \
			IMateriaSource.cpp MateriaSource.cpp main.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
