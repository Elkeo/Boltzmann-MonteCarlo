OBJS	= particles.o population.o domain.o main.o parametres.o
SOURCE	= particles.cpp population.cpp domain.cpp main.cpp parametres.cpp
HEADER	= particles.hpp population.hpp domain.hpp main.hpp parametres.hpp
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

parametres.o: parametres.cpp
	$(CC) $(FLAGS) parametres.cpp 

particles.o: particles.cpp
	$(CC) $(FLAGS) particles.cpp 

population.o: population.cpp
	$(CC) $(FLAGS) population.cpp 

domain.o: domain.cpp
	$(CC) $(FLAGS) domain.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)