CC = clang++

OBJ = obj
LIB = lib
SRC = src

CFLAGS = -Wall -Wextra -Wshadow -Wpedantic -std=c++20 -g -fstandalone-debug -I$(LIB) -c
LFLAGS = -lncurses

TARGET = binary

$(TARGET): obj $(OBJ)/board.o $(OBJ)/drawable.o $(OBJ)/ball.o $(OBJ)/bar.o $(OBJ)/player.o $(OBJ)/pong.o $(OBJ)/main.o 
		$(CC) $(LFLAGS) -o $(TARGET) $(OBJ)/*.o

$(OBJ)/board.o: $(LIB)/board.hpp $(SRC)/board.cpp
		$(CC) $(CFLAGS) $(SRC)/board.cpp -o $(OBJ)/board.o

$(OBJ)/drawable.o: $(LIB)/board.hpp $(LIB)/drawable.hpp $(SRC)/drawable.cpp
		$(CC) $(CFLAGS) $(SRC)/drawable.cpp -o $(OBJ)/drawable.o

$(OBJ)/ball.o: $(LIB)/drawable.hpp $(LIB)/ball.hpp $(SRC)/ball.cpp
		$(CC) $(CFLAGS) $(SRC)/ball.cpp -o $(OBJ)/ball.o

$(OBJ)/bar.o: $(LIB)/drawable.hpp $(LIB)/bar.hpp $(SRC)/bar.cpp
		$(CC) $(CFLAGS) $(SRC)/bar.cpp -o $(OBJ)/bar.o

$(OBJ)/player.o: $(LIB)/bar.hpp $(LIB)/player.hpp $(SRC)/player.cpp
		$(CC) $(CFLAGS) $(SRC)/player.cpp -o $(OBJ)/player.o

$(OBJ)/pong.o: $(LIB)/board.hpp $(LIB)/ball.hpp $(LIB)/player.hpp $(LIB)/pong.hpp $(SRC)/pong.cpp
		$(CC) $(CFLAGS) $(SRC)/pong.cpp -o $(OBJ)/pong.o

$(OBJ)/main.o: $(LIB)/pong.hpp $(SRC)/main.cpp
		$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o
obj:
	@ test -d $(OBJ) && true || mkdir -p $(OBJ)

clean:
	rm -rf ./$(OBJ)/*.o $(TARGET) *~
	test -d $(OBJ) && rmdir $(OBJ) || true
	test -f $(TARGET) && rm $(TARGET) || true
