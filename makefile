CC = clang
SERVER = src/server.c
CLIENT = src/client.c
TARGET_S = server
TARGET_C = client

default:
	$(CC) -o $(TARGET_S) $(SERVER)
	$(CC) -o $(TARGET_C) $(CLIENT)

clean:
	rm -f $(TARGET_S) $(TARGET_C)
