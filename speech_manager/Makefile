CXX = g++ 
ifneq ($(TERMUX_VERSION),)
	CXX = clang++
endif

CXXFLAGS = -std=c++11 -Wall -Iinc
ifneq ($(DEBUG),1)
	CXXFLAGS += -g
endif

TARGET = speech_manager

SRCS = main.cpp $(wildcard src/*.cpp)

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJS)
