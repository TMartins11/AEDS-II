# Definindo o nome do executável que será gerado.
PROJ_NAME=tp3

# Definindo o compilador que será usado.
CC=gcc

# Definindo as flags que serão passadas para o compilador.
CFLAGS=-Wall -Wextra -Werror -std=c99 -pedantic -g

# Arquivos .c 
C_SOURCE=$(wildcard ./source/*.c)

# Arquivos .h
H_SOURCE=$(wildcard ./source/*.h)

# Arquivos objeto
OBJ=$(subst .c,.o,$(subst source,objects,$(C_SOURCE)))

# Definindo o target de make all.
all: $(PROJ_NAME)

# Definindo o target de make para o executável.
$(PROJ_NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Definindo as regras de compilação para os arquivos objetos.
./objects/%.o: ./source/%.c ./source/%.h
	$(CC) $(CFLAGS) -c $< -o $@

# Definindo as regras de compilação para o arquivo main.o.
./objects/main.o: ./source/main.c $(H_SOURCE)
	$(CC) $(CFLAGS) -c $< -o $@

# Criando a pasta objects.
objFolder:
	@ mkdir -p objects

# Definindo o target de clean, limpa os arquivos objetos e o executável.
clean:
	@ rm -rf ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects

# Adicionando os targets all e clean como não arquivos.
.PHONY: all clean