NAME = exec
CC = c++
CFLAGS = -g -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = $(wildcard *.hpp)

DEBUG ?= 0
ifeq ($(DEBUG),1)
	CFLAGS += -D DEBUG
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

debug:
	$(MAKE) re DEBUG=1

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re clean fclean all debug
