$OBJECTS := src/main.o
$BINARY := bin/tbsr

all: build clean
bulid: $(OBJECTS)
	$(CC) -c $(OBJECTS) -o $(BINARY)
clean:
	rm -f $(OBJECTS)
