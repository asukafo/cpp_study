CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET   := abstract_factory
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): $(SRC) ingredients.h pizza_ingredient_factory.h concrete_ingredient_factories.h pizza.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)
