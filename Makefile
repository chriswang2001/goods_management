sources = *.c
target = management
CC = gcc
CCFLAG = -g

all:
	$(CC) $(CCFLAG) $(sources) -o $(target)

clean:
	rm -f $(target)