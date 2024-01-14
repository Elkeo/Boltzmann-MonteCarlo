OBJS	= parameters.o particles.o population.o domain.o main.o
SOURCE	= parameters.cpp particles.cpp population.cpp domain.cpp main.cpp
HEADER	= parameters.hpp particles.hpp population.hpp domain.hpp main.hpp
OUT	= main
CC	 = g++
FLAGS	 = -std=c++20
#-g -c -Wall
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