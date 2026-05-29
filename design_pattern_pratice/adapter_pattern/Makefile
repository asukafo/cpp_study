CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET   := adapter_pattern
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): $(SRC) duck.h turkey.h turkey_adapter.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)
