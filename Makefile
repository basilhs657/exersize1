
CFLAGS = -Wall -Werror -g3 
LDFLAGS = -lm


CC = g++

OBJS = exercise1.o

EXEC = exercise1

ARGS =

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC) $(ARGS)
