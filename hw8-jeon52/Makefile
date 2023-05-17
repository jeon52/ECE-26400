CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = shuffle
GCC = gcc $(CFLAGS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): shuffle.o main.o
	$(GCC) shuffle.o main.o -o $(EXEC)

%.o : %.c
	$(GCC) -c $<

testall: $(EXEC)
	./$(EXEC) 3 1 | sort > output3_1
	diff -w output3_1 expected/expected_3_1
	./$(EXEC) 3 2 | sort > output3_2
	diff -w output3_2 expected/expected_3_2
	./$(EXEC) 4 2 | sort > output4_2
	diff -w output4_2 expected/expected_4_2
	./$(EXEC) 6 2 | sort > output6_2
	diff -w output6_2 expected/expected_6_2

testtwo: $(EXEC)
	./$(EXEC) 3 2 | sort > output3_2
	diff -w output3_2 expected/expected_3_2

testthree: $(EXEC)
	./$(EXEC) 4 2 | sort > output4_2
	diff -w output4_2 expected/expected_4_2

memory: $(EXEC)
	$(VALGRIND) --log-file=log3_1 ./$(EXEC) 3 1
	$(VALGRIND) --log-file=log3_2 ./$(EXEC) 3 2
	$(VALGRIND) --log-file=log4_2 ./$(EXEC) 4 2
	$(VALGRIND) --log-file=log6_2 ./$(EXEC) 6 2

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f output?_? log?_?
