INC=./includes
SRC=./src
OBJ=./obj
LIB=./lib
SRCLIB=./srclib

CC = g++
CFLAGS = -Wall -g
LIBS = -lm

.PHONY: clean_obj clean_lib clean_exe clean

all: clean setup render.exe

setup:
	mkdir -p lib obj 

#~~~~~~~~~~~~~ Ejecutable ~~~~~~~~~~~~~#

render.exe: $(OBJ)/main.o $(LIB)/render.o
	@echo "Building render executable..."
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

cube.exe: $(OBJ)/cube.o $(LIB)/render.o $(LIB)/utils.o
	@echo "Building cube executable..."
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

#~~~~~~~~~~~~~ lib ~~~~~~~~~~~~~#
$(LIB)/render.o: $(SRCLIB)/render.cpp $(INC)/render.h
	@echo "Compiling render module..."
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

$(LIB)/utils.o: $(SRCLIB)/utils.cpp $(INC)/utils.h
	@echo "Compiling utils module..."
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

#~~~~~~~~~~~~~ obj ~~~~~~~~~~~~~#
$(OBJ)/main.o: $(SRC)/main.cpp
	@echo "Compiling main module..."
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

$(OBJ)/cube.o: $(SRC)/cube.cpp
	@echo "Compiling cube module..."
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

#~~~~~~~~~~~~~ cleanup ~~~~~~~~~~~~~#
clean: clean_obj clean_lib clean_exe

clean_obj:
	@echo "Cleaning $(OBJ)/..."
	rm -f $(OBJ)/*.o

clean_lib:
	@echo "Cleaning $(LIB)/..."
	rm -f $(LIB)/*.a $(LIB)/*.o

clean_exe:
	@echo "Cleaning exe..."
	rm -f *.exe

#~~~~~~~~~~~~~ test ~~~~~~~~~~~~~#
test:
	@echo "Testing $(EXE)..."
	./$(EXE)

test_valgrind:
	@echo "Testing with valgrind $(EXE)..."
	valgrind --leak-check=full ./$(EXE)