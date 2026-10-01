# ch10 xvideo_edit video editor project Makefile
# Usage:
#   make        # build xvideo_edit (builds the xlog static lib first)
#   make run    # build and run
#   make clean  # remove local build artifacts
#
# Extensible: new .cpp in this directory are added automatically.

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -MMD -MP -I. -I../xlog

TARGET = xvideo_edit
XLOG_LIB = ../xlog/libxlog.a

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

# Phony: always let the parent Makefile decide whether the xlog lib needs rebuild
.PHONY: $(XLOG_LIB)
$(XLOG_LIB):
	$(MAKE) -C .. xlog/libxlog.a

$(TARGET): $(OBJS) $(XLOG_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(XLOG_LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# auto-generated header dependencies
-include $(OBJS:.o=.d)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS) $(OBJS:.o=.d)
	rm -rf $(TARGET).dSYM

.PHONY: all run clean
