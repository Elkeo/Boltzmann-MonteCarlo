OBJS	= particles.o population.o domain.o main.o parameters.o
SOURCE	= particles.cpp population.cpp domain.cpp main.cpp parameters.cpp
HEADER	= particles.hpp population.hpp domain.hpp main.hpp parameters.hpp
OUT	= main
CXX	 = g++
FLAGS	 = -g -c -Wall -std=c++11

all: $(OBJS)
	$(CXX) -g $(OBJS) -o $(OUT) $(LFLAGS)

parametres.o: parametres.cpp
	$(CXX) $(FLAGS) parametres.cpp 

particles.o: particles.cpp
	$(CXX) $(FLAGS) particles.cpp 

population.o: population.cpp
	$(CXX) $(FLAGS) population.cpp 

domain.o: domain.cpp
	$(CXX) $(FLAGS) domain.cpp 

main.o: main.cpp
	$(CXX) $(FLAGS) main.cpp 


clean:
	rm -f $(OBJS) $(OUT)