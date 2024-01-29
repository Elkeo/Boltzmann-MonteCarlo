# Chemins
GTEST_DIR = ../../googletest
GTEST_INCLUDE = $(GTEST_DIR)/googletest/include
GTEST_SRC = $(GTEST_DIR)/googletest/src

LDLIBS = -lgtest -lgtest_main

# Définir le compilateur
CXX = g++

# Définir les options de compilation
CXXFLAGS = -Wall -Wextra -std=c++14 -pthread

# Inclure les en-têtes de Google Test
CPPFLAGS = -isystem $(GTEST_INCLUDE)

# Nom du fichier exécutable
TARGET = run

# Définir les fichiers source
GTEST_SRCS = $(GTEST_SRC)/gtest-all.cc $(GTEST_SRC)/gtest_main.cc
USER_SOURCES =  ../../domain.cpp ../../particles.cpp ../../parameters.cpp
TEST_SOURCES = domain_test.cpp
SOURCES = $(USER_SOURCES) $(TEST_SOURCES) $(GTEST_SRCS)


# Définir les fichiers objets
OBJECTS = $(SOURCES:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Chemins
GTEST_DIR = ../../googletest
GTEST_INCLUDE = $(GTEST_DIR)/googletest/include
GTEST_SRC = $(GTEST_DIR)/googletest/src

# Définir le compilateur
CXX = g++

# Définir les options de compilation
CXXFLAGS = -Wall -Wextra -std=c++14 -pthread

# Inclure les en-têtes de Google Test
CPPFLAGS = -isystem $(GTEST_INCLUDE)

# Nom du fichier exécutable
TARGET = run

# Définir les fichiers source
USER_SOURCES =  ../../domain.cpp ../../particles.cpp ../../parameters.cpp
TEST_SOURCES = domain_test.cpp
GTEST_SOURCES = $(GTEST_SRC)/gtest-all.cc $(GTEST_SRC)/gtest_main.cc
SOURCES = $(USER_SOURCES) $(TEST_SOURCES) $(GTEST_SOURCES)

# Définir les fichiers objets
OBJECTS = $(SOURCES:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Règle pour créer les fichiers objets
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers compilés
clean:
	rm -f $(OBJECTS) $(TARGET)

# Règle pour empêcher les conflits avec des fichiers de même nom
.PHONY: all clean


# Règle pour créer les fichiers objets
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers compilés
clean:
	rm -f $(OBJECTS) $(TARGET)

# Règle pour empêcher les conflits avec des fichiers de même nom
.PHONY: all clean
