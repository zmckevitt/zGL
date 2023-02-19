IDIR =src
CC=gcc
CC_FLAGS=-I $(IDIR)
LIBS=-lm -pthread

la1: test/la1.c src/linalg.c
	$(CC) $(CC_FLAGS) test/la1.c src/linalg.c -o test/la1 $(LIBS)

draw_square: test/draw_square.c src/graphics.c src/linalg.c
	$(CC) $(CC_FLAGS) test/draw_square.c src/graphics.c src/linalg.c -o test/draw_square $(LIBS)

bounce: test/bounce.c src/graphics.c src/linalg.c
	$(CC) $(CC_FLAGS) test/bounce.c src/graphics.c src/linalg.c -o test/bounce $(LIBS)

gas: test/gas.c src/graphics.c src/linalg.c
	$(CC) $(CC_FLAGS) test/gas.c src/graphics.c src/linalg.c -o test/gas $(LIBS)

bbox: test/bbox.c src/graphics.c src/linalg.c
	$(CC) $(CC_FLAGS) test/bbox.c src/graphics.c src/linalg.c -o test/bbox $(LIBS)

.PHONY: clean

clean:
	rm -rf test/la1
	rm -rf test/draw_square
	rm -rf test/bounce
	rm -rf test/gas
	rm -rf test/bbox
