PROJ_NAME=tp3

CC=gcc

CFLAGS= -Wall -Wextra
 
C_SOURCE=$(wildcard ./source/*.c)

H_SOURCE=$(wildcard ./source/*.h)

OBJ=$(subst .c,.o,$(subst source,objects,$(C_SOURCE)))

all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

./objects/%.o: ./source/%.c
	$(CC) $(CFLAGS) -c $< -o $@

./objects/main.o: ./source/main.c $(H_SOURCE)
	$(CC) $(CFLAGS) -c $< -o $@

objFolder:
	@mkdir -p objects

clean:
	@rm -rf ./objects/*.o $(PROJ_NAME) *~
	@rmdir objects

.PHONY: all clean objFolder