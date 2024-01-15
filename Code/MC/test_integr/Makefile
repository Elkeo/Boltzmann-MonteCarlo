OBJS	= particles.o population.o domain.o test_integr.o parameters.o
SOURCE	= ../particles.cpp ../population.cpp ../domain.cpp test_integr.cpp ../parameters.cpp
HEADER	= ../particles.hpp ../population.hpp ../domain.hpp ../parameters.hpp
OUT	= run
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

../particles.o: ../particles.cpp ../particles.hpp
	$(CC) $(FLAGS) ../particles.cpp -o ../particles.o

../population.o: ../population.cpp ../population.hpp
	$(CC) $(FLAGS) ../population.cpp -o ../population.o

../domain.o: ../domain.cpp ../domain.hpp
	$(CC) $(FLAGS) ../domain.cpp -o ../domain.o

../parameters.o: ../parameters.cpp ../parameters.hpp
	$(CC) $(FLAGS) ../parameters.cpp -o ../parameters.o

test_integr.o: test_integr.cpp $(HEADER)
	$(CC) $(FLAGS) test_integr.cpp -o test_integr.o

clean:
	rm -f $(OBJS) $(OUT)
