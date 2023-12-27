LDFLAGS = -lm
CFLAGS = -g -I.

OBJS = main.o person.o secretary.o

EXEC = main

ARGS =


main.o: main.cpp 
	g++ -c $(CFLAGS) main.cpp -o main.o

person.o: person.cpp person.h
	g++ -c $(CFLAGS) person.cpp -o person.o

secretary.o: secretary.cpp secretary.h person.h 
	g++ -c $(CFLAGS) secretary.cpp -o secretary.o

all: $(EXEC)

$(EXEC): $(OBJS)
	g++ $(OBJS) -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)