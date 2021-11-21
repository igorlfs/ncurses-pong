CC = clang++

# -fstandalone-debug -> debug with gdb but compiled with clang
CFLAGS = -Wall -Wextra -std=c++17 -g -fstandalone-debug
LFLAGS = -lncurses

OBJ = obj
LIB = include
SRC = src

TARGET = binary

$(TARGET): $(OBJ)/board.o $(OBJ)/drawable.o $(OBJ)/ball.o $(OBJ)/bar.o $(OBJ)/player.o $(OBJ)/game.o $(OBJ)/pong.o $(OBJ)/main.o 
		$(CC) $(LFLAGS) -o $(TARGET) $(OBJ)/*.o

$(OBJ)/board.o: $(LIB)/board.hpp $(SRC)/board.cpp
		$(CC) $(CFLAGS) -I$(LIB) -c $(SRC)/board.cpp -o $(OBJ)/board.o

$(OBJ)/drawable.o: $(LIB)/board.hpp $(LIB)/drawable.hpp $(SRC)/drawable.cpp
		$(CC) $(CFLAGS) -I$(LIB) -c $(SRC)/drawable.cpp -o $(OBJ)/drawable.o

$(OBJ)/ball.o: $(LIB)/drawable.hpp $(LIB)/ball.hpp $(SRC)/ball.cpp
		$(CC) $(CFLAGS) -I$(LIB) -c $(SRC)/ball.cpp -o $(OBJ)/ball.o

$(OBJ)/bar.o: $(LIB)/drawable.hpp $(LIB)/bar.hpp $(SRC)/bar.cpp
		$(CC) $(CFLAGS) -I$(LIB) -c $(SRC)/bar.cpp -o $(OBJ)/bar.o

$(OBJ)/player.o: $(LIB)/bar.hpp $(LIB)/player.hpp $(SRC)/player.cpp
		$(CC) $(CFLAGS) -I$(LIB) -c $(SRC)/player.cpp -o $(OBJ)/player.o

$(OBJ)/game.o: $(LIB)/board.hpp $(LIB)/game.hpp $(SRC)/game.cpp
		$(CC) $(CFLAGS) -I$(LIB) -c $(SRC)/game.cpp -o $(OBJ)/game.o

$(OBJ)/pong.o: $(LIB)/board.hpp $(LIB)/ball.hpp $(LIB)/player.hpp  $(LIB)/game.hpp $(LIB)/pong.hpp $(SRC)/pong.cpp
		$(CC) $(CFLAGS) -I$(LIB) -c $(SRC)/pong.cpp -o $(OBJ)/pong.o

$(OBJ)/main.o: $(LIB)/pong.hpp $(SRC)/main.cpp
		$(CC) $(CFLAGS)  -I$(LIB) -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean:
	rm -rI $(OBJ)/*
	rm $(TARGET)
