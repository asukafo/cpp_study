# ch09 tests Makefile
# Usage:
#   make                        # build all programs
#   make 2test_function_ptr     # build one program (name = file name without .cpp)
#   make run-2test_function_ptr # build and run one program
#   make run-all                # build and run every program in turn
#   make clean                  # remove build artifacts
#
# Extensible: every .cpp in this directory becomes its own program.
# Drop in a new file and it is picked up automatically.

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -pthread

SRCS    = $(wildcard *.cpp)
TARGETS = $(SRCS:.cpp=)

all: $(TARGETS)

# pattern rule: xxx.cpp -> xxx executable
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# run a single program: make run-<name>
run-%: %
	./$<

run-all: all
	@for t in $(TARGETS); do \
		echo "=== $$t ==="; \
		./$$t; \
		echo; \
	done

clean:
	rm -f $(TARGETS)
	rm -rf $(addsuffix .dSYM,$(TARGETS))

.PHONY: all run-all clean
