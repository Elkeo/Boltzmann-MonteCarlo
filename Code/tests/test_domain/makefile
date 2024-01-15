GTEST_DIR=./googletest/googletest
USER_DIR = .
USE = ../MC

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = domain_test

GTEST_HEADERS = ../googletest/googletest/include/gtest/*.h \
				../googletest/googletest/include/gtest/internal/*.h

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

parametres.o: $(USER_DIR)/parametres.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

domain.o: $(USER_DIR)/domain.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $<

domain_test.o: $(USER_DIR)/domain_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/domain_test.cpp

domain_test: domain_test.o domain.o parametres.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

