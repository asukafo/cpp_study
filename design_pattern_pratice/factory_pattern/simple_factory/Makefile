CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET   := simple_factory
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): $(SRC) pizza.h concrete_pizzas.h simple_pizza_factory.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)
