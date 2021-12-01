export SDL_MOUSEDEV="/dev/null"
export SDL_NOMOUSE="1"

CROSS_COMPILE=arm-linux-gnueabihf-
CFLAGS+="-I/home/sjlee/MS-204/src/SDL1.2/SDL-1.2.15/include"
CFLAGS+="-I/home/sjlee/MS-204/src/SDL1.2/SDL_ttf-2.0.11"
LDFLAGS+="-L/home/sjlee/MS-204/src/SDL1.2/SDL-1.2.15/build/.libs"
LDFLAGS+="-L/home/sjlee/MS-204/src/SDL1.2/SDL_ttf-2.0.11/.libs"
LDFLAGS+="-L/home/sjlee/MS-204/src/SDL1.2/freetype-2.11.0/objs/.libs"
LIBS+="-lSDL"
LIBS+="-lSDL_ttf"
LIBS+="-lfreetype"

default:
	$(CROSS_COMPILE)gcc -c main.c $(CFLAGS)
	$(CROSS_COMPILE)gcc main.o $(LDFLAGS) $(LIBS) -o sdl_test.out

clean:
	rm -rf *.o
	rm -rf *.out
