CC = gcc

CFLAGS = -Iinclude

SRC = src/main.c src/input.c src/round_robin.c src/metrics.c src/display.c

OUT = build/rr.exe

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run:
	$(OUT)

clean:
	del build\rr.exe