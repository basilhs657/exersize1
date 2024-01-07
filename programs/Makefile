LDFLAGS = -lm
CFLAGS = -g -I.

OBJS = main.o person.o secretary.o student.o professor.o course.o

EXEC = main

ARGS =


main.o: main.cpp 
	g++ -c $(CFLAGS) main.cpp -o main.o

person.o: person.cpp person.h
	g++ -c $(CFLAGS) person.cpp -o person.o

secretary.o: secretary.cpp secretary.h person.h 
	g++ -c $(CFLAGS) secretary.cpp -o secretary.o

student.o: student.cpp person.h 
	g++ -c $(CFLAGS) student.cpp -o student.o
professor.o: professor.cpp professor.h
	g++ -c $(CFLAGS) professor.cpp -o professor.o
course.o: course.cpp course.h
	g++ -c $(CFLAGS) course.cpp -o course.o

all: $(EXEC)

$(EXEC): $(OBJS)
	g++ $(OBJS) -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)