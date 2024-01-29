GTEST_DIR=./googletest/googletest
USER_DIR = .
USE = ../MC

CXXFLAGS += -std=c++14

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = sigmas_0

GTEST_HEADERS = ./googletest/googletest/include/gtest/*.h \
				./googletest/googletest/include/gtest/internal/*.h

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

GTEST_SRCS_ = ./googletest/googletest/src/*.cc ./googletest/googletest/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
			$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
			$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

parameters.o: $(USER_DIR)/parameters.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

domain.o: $(USER_DIR)/domain.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

population.o: $(USER_DIR)/population.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

sigmas_0.o: $(USER_DIR)/sigmas_0.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I$(GTEST_DIR) -c $< -o $@

sigmas_0: sigmas_0.o domain.o parameters.o population.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

