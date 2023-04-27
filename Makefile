# Nome do seu programa
PROG = meu_programa

# Compilador a ser usado
CC = gcc

# Flags de compilação
CFLAGS = -Wall `pkg-config --cflags gtk+-3.0`

# Bibliotecas a serem linkadas
LIBS = `pkg-config --libs gtk+-3.0`

# Arquivos-fonte do seu programa
SRCS = src/main.c

# Arquivos-objeto gerados a partir dos arquivos-fonte
OBJS = $(SRCS:.c=.o)

# Regra padrão (depende de todas as outras regras)
$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LIBS)

# Regra para cada arquivo-fonte
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos-objeto e o executável
clean:
	rm -f $(OBJS) $(PROG)

# Regra para compilar apenas o main.c
main.o: main.c meu_programa.h
	$(CC) $(CFLAGS) -c main.c -o main.o
