.PHONY: clean # This creates the label which can be called

CC = gcc 
CFLAGS = -Wall -pedantic
DEPS = CommandsParser.h DataManager.h DataPrinter.h Math.h MathParser.h Types.h Utilities.h
OBJ = interpreter.o CommandsParser.o DataManager.o DataPrinter.o Math.o MathParser.o Types.o Utilities.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

interpreter: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(OBJ)