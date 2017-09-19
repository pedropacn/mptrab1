IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = string_soma.hpp catch.hpp lista_func.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o testa_string_soma.o string_soma.o lista_func.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testmake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	./testmake
	rm testmake

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~