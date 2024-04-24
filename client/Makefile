CC     = gcc
CFLAGS = -g -Wall
RM     = rm -rf
LIB    = -L/usr/local/lib -lrashunal
INC    = -I/usr/local/include

default: all

all: rash

rash: rash.c
	$(CC) $(CFLAGS) $(LIB) $(INC) -o rash rash.c

run: rash
	DYLD_LIBRARY_PATH=/usr/local/lib ./rash

clean veryclean:
	$(RM) rash rash.dSYM