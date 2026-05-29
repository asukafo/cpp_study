CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET   := iterator_pattern
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): $(SRC) iterator.h menu_item.h pancake_house_menu.h diner_menu.h waitress.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)
