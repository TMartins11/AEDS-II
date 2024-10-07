PROJ_NAME=avl

CC=gcc

CC_FLAGS=-Wall -Wextra -g

TARGET=$(PROJ_NAME)

all: $(TARGET)

avl: avl.o
	$(CC) $(CC_FLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CC_FLAGS) -c $^ -o $@

clean:
	rm -rf $(TARGET) *.o

.PHONY: all clean