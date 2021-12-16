
CC := gcc

CFLAGS := -g

all:


test:instrument.c test.c
	$(CC) $(CFLAGS) -finstrument-functions $^ -o $@

clean:
	rm -f test trace.txt

