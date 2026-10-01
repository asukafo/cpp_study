# ch08 测试 Makefile
# 用法：
#   make                # 编译全部测试（all）
#   make test_class_copy # 只编译某一个测试
#   make run            # 编译并依次运行全部测试
#   make clean          # 清理编译产物
#
# 扩展：新增 test_class_xxx.cpp 后无需修改本文件，会被自动纳入构建。

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# 自动收集所有测试源文件，目标名 = 去掉 .cpp 后缀
SRCS    = $(wildcard test_class_*.cpp)
TARGETS = $(SRCS:.cpp=)

all: $(TARGETS)

# 模式规则：test_class_copy.cpp -> test_class_copy
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
