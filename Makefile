OBJECTS := src/main.o src/tbsr.o
BINARY := bin/tbsr
CFLAGS :=

all: build clean
build: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARY)
clean:
	rm -f $(OBJECTS)
