# Nome do programa
PROGRAMA = ./bin/saida
FONTE = main.c

# Arquivos C
ARQUIVOS_C = ./src/grafo.c ./src/fila.c

# Arquivos de Cabeçalhos
CABECALHOS = ./include/grafo.h ./include/fila.h

# Diretório para arquivos objeto
OBJDIR = ./obj

# Objetos de saída (compilação da biblioteca)
OBJETOS = $(ARQUIVOS_C:./src/%.c=$(OBJDIR)/%.o)

# Compilador disponível na máquina
COMPILADOR = gcc

# Flags de compilação
CFLAGS = -Wall -Werror -O2 -I./include

all: $(PROGRAMA)

$(PROGRAMA): $(OBJETOS) $(FONTE)
	$(COMPILADOR) $(FONTE) -o $(PROGRAMA) $(OBJETOS) $(CFLAGS)

# Regras para compilar arquivos fonte em arquivos objeto
$(OBJDIR)/%.o: ./src/%.c ./include/%.h
	$(COMPILADOR) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(PROGRAMA) $(OBJETOS)