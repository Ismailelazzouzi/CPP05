NAME = Bureaucrat
CPP = c++ -Wall -Wextra -Werror
RM = rm -f
FILES = main \
		Bureaucrat \
		AForm \
		ShrubberyCreationForm \
		PresidentialPardonForm \
		RobotomyRequestForm \
		Intern \


SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

%.o: %.cpp Bureaucrat.hpp AForm.hpp
	$(CPP) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean