CC=g++
CFLAGS= -O2 -Wall -Wextra -Wpedantic
DEPS=
OBJS=MainV2.o
OUT=wordle

$(OUT): $(OBJS)
	$(CC)  -o $@  $^ $(CFLAGS)
	
.c.o:
	$(CC) -c -o $@ $< $(CFLAGS) 
	
.PHONY: clean	
clean:
	rm -f *o
	rm -f *~
	rm -f $(OUT)
	
run:
	./main