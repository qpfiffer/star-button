CFLAGS=`pkg-config --cflags gtk+-3.0 cairo`
CLIBS=`pkg-config --libs gtk+-3.0 cairo`

all:
	gcc $(CFLAGS) -o star_button star_button.c -O0 -g $(CLIBS)
