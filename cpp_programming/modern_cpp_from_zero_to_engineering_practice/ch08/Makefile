# ch08 tests Makefile
# Usage:
#   make                 # build all tests (all)
#   make test_class_copy # build a single test
#   make run             # build and run all tests
#   make clean           # remove build artifacts
#
# Extensible: drop in a new test_class_xxx.cpp and it is built automatically.

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# collect all test sources; target name = source name without .cpp
SRCS    = $(wildcard test_class_*.cpp)
TARGETS = $(SRCS:.cpp=)

all: $(TARGETS)

# pattern rule: test_class_copy.cpp -> test_class_copy
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run: all
	@for t in $(TARGETS); do \
		echo "=== $$t ==="; \
		./$$t; \
		echo; \
	done

clean:
	rm -f $(TARGETS)
	rm -rf $(addsuffix .dSYM,$(TARGETS))

.PHONY: all run clean
