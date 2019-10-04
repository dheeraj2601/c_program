CC=gcc
CFLAGS=-I. -g -Wall
DEPS = mytimer.h
OBJ = timer_main.o mytimer.o
EXECUTABLE = hellomake

LIBS=-lpthread

%.o: %.c $(DEPS)
        $(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ)
        $(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
        rm -f *.o *~ $(EXECUTABLE)
