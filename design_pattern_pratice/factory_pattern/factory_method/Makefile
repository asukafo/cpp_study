CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET   := factory_method
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): $(SRC) pizza.h ny_style_pizzas.h chicago_style_pizzas.h pizza_store.h concrete_pizza_stores.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)
