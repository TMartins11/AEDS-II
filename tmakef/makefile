PROJ_NAME=main

CC=gcc

CC_FLAGS= -Wall -Wextra -g -O3

# Lista de arquivos .c
C_SOURCE=$(wildcard ./source/*.c)

# Substitui todos os arquivos .c do target especificado (C_SOURCE nesse caso) por .o, mesmo esquema de pathsubst, cria de novo e renomeia, sem perder o original.
OBJ=$(C_SOURCE:.c=.o)

# Define all como padrão para a execução do Target principal.
all:$(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ -o $@

# Compila arquivos .c em .o e considera arquivos .h como dependências.
./source/%.o: ./source/%.c  ./source/%.h
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -rf $(PROJ_NAME) *.o

.PHONY: all clean
