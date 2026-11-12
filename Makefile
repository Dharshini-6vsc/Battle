CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
SOURCES = main.c bst.c avl.c hashing.c dataset.c experiment.c
TARGET = student_search

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe
