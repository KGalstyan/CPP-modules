NAME = bureaucrat
CPP = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
SRC = main.cpp Bureaucrat.cpp Form.cpp
HEADER = Bureaucrat.hpp Form.hpp
OBJS = $(SRC:.cpp=.o)

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