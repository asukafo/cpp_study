
enum : enum.o
	g++ -o enum enum.o

enum.o : enum.cpp
	g++ -c enum.cpp

enum.i: enum.cpp
	g++ -E enum.cpp -o enum.i
	# 不指定输出文件, 默认输出到stdout中
	# g++ -E enum.cpp 

enum.s : enum.cpp
	g++ -S enum.cpp -o enum.s
	# 使用优化
	# g++ -S enum.cpp -O2 -o enum.s

clean:
	rm -f enum enum.o enum.i enum.s
	rm -f struct_test struct_test.o
	rm -f static static.o 

# 1. 预处理：展开头文件和宏
# g++ -E demo.cpp -o demo.i

# 2. 编译到汇编：生成汇编代码
# g++ -S demo.cpp -o demo.s

# 3. 汇编：生成目标文件
# g++ -c demo.cpp -o demo.o

# 4. 链接：生成可执行文件
# g++ demo.cpp -o demo

# 或者一步到位
# g++ demo.cpp -o demo

# 包含调试信息
# g++ -S -g demo.cpp -o demo_debug.s

# 包含源代码行号
# g++ -S -g -Wa,-alh demo.cpp -o demo_verbose.s

# 无优化
# g++ -S -O0 demo.cpp -o demo_O0.s

# 基本优化
# g++ -S -O1 demo.cpp -o demo_O1.s

# 标准优化
# g++ -S -O2 demo.cpp -o demo_O2.s

# 激进优化
# g++ -S -O3 demo.cpp -o demo_O3.s


struct_test : struct_test.o 
	g++ -o struct_test struct_test.o

struct_test.o : struct_test.cpp
	g++ -c struct_test.cpp

static : static.o 
	g++ -o static static.o 

static.o : static.cpp 
	g++ -c static.cpp
