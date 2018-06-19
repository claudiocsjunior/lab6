
#Makefile for "mathBasic" C++ application (Cont.)
#Created by Claudio da Cruz Silva Junior 03/04/2018 main.o :
PROG = executavel
INC_DIR = include
SRC_DIR = src
OBJ_DIR = build
LIB_DIR = lib
BIN_DIR = bin

CC = g++
CFLAGS = -Wall -pedantic -std=c++11 -I./$(INC_DIR)
ARQUIVE = ar

linux: contas.a contas.so produtos.a produtos.so prog_estatico prog_dinamico 

produtos.a: $(SRC_DIR)/bebida.cpp $(SRC_DIR)/fruta.cpp $(SRC_DIR)/produto.cpp $(INC_DIR)/bebida.h $(INC_DIR)/fruta.h $(INC_DIR)/produto.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/bebida.cpp -o $(OBJ_DIR)/bebida.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/fruta.cpp -o $(OBJ_DIR)/fruta.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/produto.cpp -o $(OBJ_DIR)/produto.o
	$(ARQUIVE) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/bebida.o $(OBJ_DIR)/fruta.o $(OBJ_DIR)/produto.o
	@echo "+++ [Biblioteca estatica para produtos criada em $(LIB_DIR)/$@]+++"

produtos.so: $(SRC_DIR)/bebida.cpp $(SRC_DIR)/fruta.cpp $(SRC_DIR)/produto.cpp $(INC_DIR)/bebida.h $(INC_DIR)/fruta.h $(INC_DIR)/produto.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/bebida.cpp -o $(OBJ_DIR)/bebida.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/fruta.cpp -o $(OBJ_DIR)/fruta.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/produto.cpp -o $(OBJ_DIR)/produto.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/bebida.o $(OBJ_DIR)/fruta.o $(OBJ_DIR)/produto.o
	@echo "+++ [Biblioteca dinâmica para produtos criada em $(LIB_DIR)/$@]+++"

contas.a: $(SRC_DIR)/contaCorrente.cpp $(SRC_DIR)/movimentacao.cpp $(INC_DIR)/contaCorrente.h $(INC_DIR)/movimentacao.h 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/movimentacao.cpp -o $(OBJ_DIR)/movimentacao.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/contaCorrente.cpp -o $(OBJ_DIR)/contaCorrente.o
	$(ARQUIVE) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/contaCorrente.o $(OBJ_DIR)/movimentacao.o
	@echo "+++ [Biblioteca estatica para contas criada em $(LIB_DIR)/$@]+++"

contas.so: $(SRC_DIR)/contaCorrente.cpp $(SRC_DIR)/movimentacao.cpp $(INC_DIR)/contaCorrente.h $(INC_DIR)/movimentacao.h 
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/movimentacao.cpp -o $(OBJ_DIR)/movimentacao.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/contaCorrente.cpp -o $(OBJ_DIR)/contaCorrente.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/contaCorrente.o $(OBJ_DIR)/movimentacao.o
	@echo "+++ [Biblioteca dinâmica para contas criada em $(LIB_DIR)/$@]+++"

prog_estatico:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/produtos.a $(LIB_DIR)/contas.a -o $(BIN_DIR)/$@

prog_dinamico:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/produtos.so $(LIB_DIR)/contas.so -o $(BIN_DIR)/$@  

clean:
	@echo "Removendo arquivos objetos e executáveis/binários..."
	@rm -rf $(OBJ_DIR)/* 