CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET   := decorator_pattern
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): $(SRC) beverage.h condiment_decorator.h concrete_beverages.h concrete_decorators.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)
