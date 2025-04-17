CC = clang
SERVER = src/server.c
CLIENT = src/client.c
TARGET_S = server
TARGET_C = client
CFLAGS = -Wall -Wextra -pedantic -std=c11

default:
	$(CC) $(CFLAGS) -o $(TARGET_S) $(SERVER)
	$(CC) $(CFLAGS) -o $(TARGET_C) $(CLIENT)

clean:
	rm -f $(TARGET_S) $(TARGET_C)
