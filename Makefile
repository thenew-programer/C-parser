#Usage:

#make			# Compile all the binary

#make clean		# remove all objects

CC = gcc

LDFLAGS = -lm

CFLAGS = -Wall -c 

SOURCE = $(wildcard src/*.c)

OBJECT = $(SOURCE:%.c=%.o)

BINARY = parser


default: all

all: $(BINARY)

$(BINARY): $(OBJECT)
	@echo "Checking..."
	$(CC)  $< -o $(BINARY)

%.o: %.c
	@echo "Creating object..."
	$(CC) $(CFLAGS) $<
	
clean:
	@echo "Cleaning up..."
	@rm -f *.o
