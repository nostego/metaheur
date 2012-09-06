CFLAGS=-W -Wall -Wextra
LINK=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
#LINK=-L /lrde/beyrouth/lrde-2013/lenoir/NostEgo/game -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
CC=g++
TARGET=a.out

all: Makefile.inc ${TARGET}

clean: # Clean the repository
	rm -f `find . -name '*.o'`
	rm -f `find . -name '*~'`
	rm -f `find . -name '*#'`
	rm -f Makefile.inc ${TARGET}

Makefile.inc: # Build the included makefile
	./configure

include Makefile.inc

${TARGET}: ${OBJS} src/main.o
	${CC} ${CFLAGS} ${LINK} $^ -o $@
