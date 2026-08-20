NAME = exec
CC = c++
SRCS_DIR = srcs/
INC_DIR = includes/
UTILS_DIR = utils/
BUILD_DIR = build/
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = $(addprefix $(SRCS_DIR), main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp)
OBJS = $(addprefix $(BUILD_DIR), $(SRCS:.cpp=.o))
HEADERS = $(addprefix $(INC_DIR), Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp header.hpp) $(UTILS_DIR)Debug.hpp

DEBUG ?= 0
ifeq ($(DEBUG),1)
	CFLAGS += -D DEBUG
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BUILD_DIR)%.o: %.cpp $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

debug:
	$(MAKE) re DEBUG=1

leaks:
	$(MAKE) && valgrind --leak-check=full ./$(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re clean fclean all debug
