NAME = bureaucrat28
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address
SRC = main.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
	AForm.cpp
HEADER = Bureaucrat.hpp ShrubberyCreationForm.hpp \
		RobotomyRequestForm.hpp PresidentialPardonForm.hpp \
		AForm.hpp
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