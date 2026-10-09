CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = calc
SRCS = main.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
