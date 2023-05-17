CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = hw12
GCC = gcc $(CFLAGS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): hw12.o
	$(GCC) hw12.o -o $(EXEC)

%.o : %.c
	$(GCC) -c $<

all: $(EXEC)

testall: $(EXEC)
	./$(EXEC) ./inputs/test1 
	./$(EXEC) ./inputs/test2 
	./$(EXEC) ./inputs/test3 
	./$(EXEC) ./inputs/test4 
	./$(EXEC) ./inputs/test5 

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) inputs/test1 
	$(VALGRIND) --log-file=log2 ./$(EXEC) inputs/test2 
	$(VALGRIND) --log-file=log3 ./$(EXEC) inputs/test3
	$(VALGRIND) --log-file=log4 ./$(EXEC) inputs/test4
	$(VALGRIND) --log-file=log5 ./$(EXEC) inputs/test5

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f log?
