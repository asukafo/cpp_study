CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET   := facade_pattern
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): $(SRC) home_theater.h home_theater_facade.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)
