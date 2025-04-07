PROJ_NAME=bbsort

CC=gcc

all: $(PROJ_NAME)

$(PROJ_NAME): main.c
	$(CC)  $^ -o $@

*.o: *.c
	$(CC) $^ -o $@

clean:
	rm -rf $(PROJ_NAME) *.o

.PHONY: all clean