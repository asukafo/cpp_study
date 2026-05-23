CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET   := observer_pattern
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): $(SRC) iobserver.h isubject.h weather_data.h displays.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean: 
	rm -f $(TARGET) $(OBJ)