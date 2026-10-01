# ch10 Makefile: xlog logging library + tests
# Usage:
#   make                # build xlog static lib + all tests
#   make test/test_xlog # build a single test
#   make run            # build and run all tests
#   make clean          # remove build artifacts
#
# Extensible: new .cpp under xlog/ are added to libxlog.a automatically;
#             new test_*.cpp under test/ are built automatically.

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -MMD -MP -Ixlog -Itest

# xlog library: all sources compiled into a static library
XLOG_DIR  = xlog
XLOG_SRCS = $(wildcard $(XLOG_DIR)/*.cpp)
XLOG_OBJS = $(XLOG_SRCS:.cpp=.o)
XLOG_LIB  = $(XLOG_DIR)/libxlog.a

# tests: each test_*.cpp under test/ corresponds to one executable
TEST_DIR  = test
TEST_SRCS = $(wildcard $(TEST_DIR)/test_*.cpp)
TESTS     = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_DIR)/%,$(TEST_SRCS))

all: $(XLOG_LIB) $(TESTS)

$(XLOG_LIB): $(XLOG_OBJS)
	ar rcs $@ $^

$(XLOG_DIR)/%.o: $(XLOG_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TEST_DIR)/%: $(TEST_DIR)/%.cpp $(XLOG_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(XLOG_LIB)

# auto-generated header dependencies
-include $(XLOG_OBJS:.o=.d) $(TESTS:=.d)

run: all
	@for t in $(TESTS); do \
		echo "=== $$t ==="; \
		./$$t; \
		echo; \
	done

clean:
	rm -f $(XLOG_OBJS) $(XLOG_OBJS:.o=.d) $(XLOG_LIB) $(TESTS) $(TESTS:=.d)
	rm -rf $(addsuffix .dSYM,$(TESTS))

.PHONY: all run clean
