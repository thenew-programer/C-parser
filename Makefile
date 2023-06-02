#Usage:

#make			# Compile all the binary

#make clean		# remove all objects

CC = gcc

LDFLAGS = 

CFLAGS = -Wall -Werror -Wextra -pedantec -c -I./src/include

SOURCE = $(wildcard src/*.c)

OBJECT = $(SOURCE:%.c=%.o)

BINARY = parser


default: all

all: $(BINARY)

$(BINARY): $(OBJECT)
	@echo "Checking..."
	$(CC)  $<

%.o: %.c
	@echo "Creating object..."
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	@echo "Cleaning up..."
	@rm -f *.o
