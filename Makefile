# Makefile für mini_db

# Compiler und Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Zielname
TARGET = mini_db

# Quelldateien
SRCS = mini_db.c
SRCS_ERROR = error_input.c

# Standart Ziel
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(SRCS_ERROR)

# Aufräumen
clean:
	rm -f $(TARGET) db.txt

# Nur DB entfernen
clean_db:
	rm -f db.txt

clean_bin:
	rm -f $(TARGET)
