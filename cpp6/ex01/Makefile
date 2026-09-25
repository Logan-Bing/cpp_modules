NAME = convert
CC = c++
SRCS_DIR = srcs/
INC_DIR = includes/
UTILS_DIR = utils/
BUILD_DIR = build/
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = $(addprefix $(SRCS_DIR), main.cpp Serializer.cpp)
OBJS = $(addprefix $(BUILD_DIR), $(SRCS:.cpp=.o))
HEADERS = $(addprefix $(INC_DIR), header.hpp Serializer.hpp) $(UTILS_DIR)Debug.hpp

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

test: $(SRCS_DIR)test.cpp $(SRCS_DIR)ScalarConverter.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS_DIR)test.cpp $(SRCS_DIR)ScalarConverter.cpp -o test_bin

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME) test_bin

re: fclean all

.PHONY: re clean fclean all debug test
