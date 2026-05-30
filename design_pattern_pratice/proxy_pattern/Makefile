CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

TARGET   := proxy_pattern
SRC      := main.cpp
OBJ      := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ): $(SRC) image.h real_image.h image_proxy.h document.h protection_proxy.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)
