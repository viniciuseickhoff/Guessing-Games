include libconfig/Makefile
IDIR =include
CC=gcc
CFLAGS=-I$(IDIR) -Llibconfig

ODIR=./
LDIR =libconfig/lib/

LIBS=-lm
_DEPS = includes.h GuessGame.c modocpu.c
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.c 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

make: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
