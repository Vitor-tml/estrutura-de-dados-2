# Nome do programa
PROGRAMA = saida # colocar nome de saída do programa aqui
FONTE = main.c  # colocar nome do arquivo contendo a main aqui

# Arquivos C
ARQUIVOS_C = trie.c # listar todos os .c (menos a main) separados por espaço aqui

# Arqiovos de Cabeçalhos
CABECALHOS = trie.h # listar todos os .h separados por espaço aqui

# Objetos de saída (compilação da biblioteca)
OBJETOS = $(ARQUIVOS_C:.c=.o)

# Compilador disponível na máquina
COMPILADOR = gcc

# Flags de compilação
CFLAGS = -Wall -Werror -O2

all: $(PROGRAMA)

$(PROGRAMA): $(OBJETOS) $(FONTE)
	$(COMPILADOR) $(FONTE) -o $(PROGRAMA) $(OBJETOS) $(CFLAGS)

# Regras para compilar arquivos fonte em arquivos objeto
%.o: %.c %.h
	$(COMPILADOR) -c $< -o $@ $(CFLAGS)

clear:
	rm $(PROGRAMA) $(OBJETOS)