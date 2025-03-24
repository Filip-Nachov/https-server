CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g
SERVER = src/server.c
CLIENT = src/client.c
TARGET_S = server
TARGET_C = client

default:
	$(CC) $(CFLAGS) -o $(TARGET_S) $(SERVER)
	$(CC) $(CFLAGS) -o $(TARGET_C) $(CLIENT)

clean:
	rm -f $(TARGET)
