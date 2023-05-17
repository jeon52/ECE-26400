CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
LIBS = -lm
EXEC = hw3
DEBUG = -DTEST_INTEGRATE -DRUN_INTEGRATE
GCC = gcc $(CFLAGS) $(DEBUG)
FUNC = func1.o func2.o func3.o func4.o func5.o

$(EXEC): answer3.o hw3.o $(FUNC)
	$(GCC) answer3.o hw3.o $(FUNC) $(LIBS) -o $(EXEC)

%.o : %.c
	$(GCC) -c $<

testall: $(EXEC)
	./$(EXEC) ./testdir/test1 ./testdir/output1
	./$(EXEC) ./testdir/test2 ./testdir/output2
	./$(EXEC) ./testdir/test3 ./testdir/output3
	./$(EXEC) ./testdir/test4 ./testdir/output4
	./$(EXEC) ./testdir/test5 ./testdir/output5

clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f testgen 
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f hw3 hw3.prof
	/bin/rm -f -r testdir
