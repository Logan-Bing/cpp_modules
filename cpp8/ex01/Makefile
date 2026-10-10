NAME = exec
CC = c++
SRCS_DIR = srcs/
INC_DIR = includes/
UTILS_DIR = utils/
BUILD_DIR = build/
STD = -std=c++98
CFLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix $(SRCS_DIR), main.cpp Span.cpp)
OBJS = $(addprefix $(BUILD_DIR), $(SRCS:.cpp=.o))
HEADERS = $(addprefix $(INC_DIR), header.hpp Span.hpp) $(UTILS_DIR)Debug.hpp

DEBUG ?= 0
ifeq ($(DEBUG),1)
	STD = -std=c++2c
	CFLAGS += -D DEBUG
endif

CFLAGS += $(STD)

LEAKS ?= 0
ifeq ($(LEAKS),1)
	CFLAGS += -g3 -O0 -fno-omit-frame-pointer
endif

VALGRIND_FLAGS = --leak-check=full \
				 --show-leak-kinds=all \
				 --errors-for-leak-kinds=all \
				 --track-origins=yes \
				 --track-fds=yes \
				 --show-mismatched-frees=yes \
				 --read-var-info=yes \
				 --error-exitcode=42

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BUILD_DIR)%.o: %.cpp $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

debug:
	$(MAKE) re DEBUG=1

leaks:
	$(MAKE) re LEAKS=1
	@if command -v valgrind >/dev/null 2>&1; then \
		valgrind $(VALGRIND_FLAGS) ./$(NAME); \
	else \
		echo "valgrind introuvable, fallback sur leaks (macOS)"; \
		MallocStackLogging=1 leaks --atExit -- ./$(NAME); \
	fi

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re clean fclean all debug leaks
