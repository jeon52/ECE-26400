CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = hw11
GCC = gcc $(CFLAGS)
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): maze.o mazehelper.o path.o solver.o list.o hw11.o
	$(GCC) maze.o mazehelper.o path.o solver.o list.o hw11.o -o $(EXEC)

%.o : %.c
	$(GCC) -c $<

testall: $(EXEC)
	./$(EXEC) ./inputs/maze1 ./outputs/output1
	diff -w expected/path_out1 outputs/output1
	./$(EXEC) ./inputs/maze2 ./outputs/output2
	diff -w expected/path_out2 outputs/output2
	./$(EXEC) ./inputs/maze3 ./outputs/output3
	diff -w expected/path_out3 outputs/output3

testone: $(EXEC)
	./$(EXEC) ./inputs/maze1 ./outputs/output1
	diff -w expected/path_out1 outputs/output1

testtwo: $(EXEC)
	./$(EXEC) ./inputs/maze2 ./outputs/output2
	diff -w expected/path_out2 outputs/output2

testthree: $(EXEC)
	./$(EXEC) ./inputs/maze3 ./outputs/output3
	diff -w expected/path_out3 outputs/output3

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) ./inputs/maze1 ./outputs/output1
	$(VALGRIND) --log-file=log2 ./$(EXEC) ./inputs/maze2 ./outputs/output2
	$(VALGRIND) --log-file=log3 ./$(EXEC) ./inputs/maze3 ./outputs/output3

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f outputs/output? log?
