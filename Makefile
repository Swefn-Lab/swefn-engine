C = clang

CFLAGS = -Iext/SDL/include
LDFLAGS = $(shell pkg-config --libs sdl3)

all:
	$(C) $(CFLAGS) src/main.c $(LDFLAGS) -o build/main
