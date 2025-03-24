CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g
SRC = src/server.c
TARGET = server

default:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
