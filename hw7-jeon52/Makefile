CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = shuffle
DEBUG = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE
GCC = gcc $(CFLAGS) $(DEBUG)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): shuffle.o main.o
	$(GCC) shuffle.o main.o -o $(EXEC)

%.o : %.c
	$(GCC) -c $<

testall: $(EXEC)
	./$(EXEC) 4 | sort > output4
	diff -w output4 expected/expected4
	./$(EXEC) 8 | sort > output8
	diff -w output8 expected/expected8
	./$(EXEC) 11 | sort > output11
	diff -w output11 expected/expected11

memory: $(EXEC)
	$(VALGRIND) --log-file=log4 ./$(EXEC) 4
	$(VALGRIND) --log-file=log8 ./$(EXEC) 8
	$(VALGRIND) --log-file=log11 ./$(EXEC) 11

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f output? log?
