CC=g++
CCFLAGS= -Wall -Werror -std=c++14
LIBFLAGS= -ltgui -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= first

all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) $^ -o $@   $(LIBFLAGS)

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depends:
	g++ -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC)
