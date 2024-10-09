PROJ_NAME=hello

CC=gcc

CC_FLAGS= -Wall -Wextra -g -O3

all: $(PROJ_NAME)

$(PROJ_NAME): hello.c
	$(CC) $(CC_FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CC_FLAGS) $^ -o $@

clean:
	rm -rf $(PROJ_NAME) *.o

PHONY: all clean