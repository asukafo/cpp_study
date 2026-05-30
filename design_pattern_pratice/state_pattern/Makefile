CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET   := state_pattern
SRC      := main.cpp gumball_machine.cpp concrete_states.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp gumball_machine.h state.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

gumball_machine.o: gumball_machine.cpp gumball_machine.h concrete_states.h state.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

concrete_states.o: concrete_states.cpp concrete_states.h gumball_machine.h state.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)
