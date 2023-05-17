CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = hw13
GCC = gcc $(CFLAGS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): hw13.o scanner.o tree.o expressionTree.o
	$(GCC) hw13.o scanner.o tree.o expressionTree.o -o $(EXEC)

%.o : %.c
	$(GCC) -c $<

all: $(EXEC)

testall: $(EXEC)
	./$(EXEC) ./inputs/test1 ./outputs/output1
	./$(EXEC) ./inputs/test2 ./outputs/output2
	./$(EXEC) ./inputs/test3 ./outputs/output3
	./$(EXEC) ./inputs/test4 ./outputs/output4

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) ./inputs/test1 ./outputs/output1
	$(VALGRIND) --log-file=log2 ./$(EXEC) ./inputs/test2 ./outputs/output2
	$(VALGRIND) --log-file=log3 ./$(EXEC) ./inputs/test3 ./outputs/output3
	$(VALGRIND) --log-file=log4 ./$(EXEC) ./inputs/test4 ./outputs/output4

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f outputs/output? log?
