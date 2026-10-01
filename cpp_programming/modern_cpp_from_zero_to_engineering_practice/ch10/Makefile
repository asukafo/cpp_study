# ch10 xlog 测试 Makefile
# 用法：
#   make                # 编译 xlog 静态库 + 全部测试
#   make test/test_xlog # 只编译某一个测试
#   make run            # 编译并依次运行全部测试
#   make clean          # 清理编译产物
#
# 扩展：
#   - xlog/ 下新增 .cpp 自动纳入静态库 libxlog.a，无需修改本文件
#   - test/ 下新增 test_*.cpp 自动纳入构建

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -Ixlog -Itest

# xlog 库：全部源码编译进静态库
XLOG_DIR  = xlog
XLOG_SRCS = $(wildcard $(XLOG_DIR)/*.cpp)
XLOG_OBJS = $(XLOG_SRCS:.cpp=.o)
XLOG_LIB  = $(XLOG_DIR)/libxlog.a

# 测试：test/ 下每个 test_*.cpp 对应一个可执行文件
TEST_SRCS = $(wildcard $(TEST_DIR)/test_*.cpp)
TEST_DIR  = test
TESTS     = $(patsubst $(TEST_DIR)/%.cpp,$(TEST_DIR)/%,$(TEST_SRCS))

all: $(XLOG_LIB) $(TESTS)

$(XLOG_LIB): $(XLOG_OBJS)
	ar rcs $@ $^

$(XLOG_DIR)/%.o: $(XLOG_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TEST_DIR)/%: $(TEST_DIR)/%.cpp $(XLOG_LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< $(XLOG_LIB)

run: all
	@for t in $(TESTS); do \
		echo "=== $$t ==="; \
		./$$t; \
		echo; \
	done

clean:
	rm -f $(XLOG_OBJS) $(XLOG_LIB) $(TESTS)
	rm -rf $(addsuffix .dSYM,$(TESTS))

.PHONY: all run clean
