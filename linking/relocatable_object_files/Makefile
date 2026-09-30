# Makefile for building ELF relocatable object files on macOS
# Uses colima + docker (Linux GCC) for ELF with full libc (printf etc.)
# Uses GNU readelf from binutils to inspect the ELF output

READELF := /opt/homebrew/opt/binutils/bin/readelf
DOCKER  := docker
TARGET  := main_elf.o
SRC     := main.c

.PHONY: all clean sections symbols headers relocs

all: $(TARGET) sections symbols headers relocs

# 通过 Linux GCC 容器编译出真正的 ELF 目标文件（支持 printf）
$(TARGET): $(SRC)
	$(DOCKER) run --rm -v "$(PWD)":/work -w /work gcc:latest gcc -c $(SRC) -o $(TARGET)
	@echo ""
	@echo "=== File type ==="
	file $(TARGET)

# Section headers — 查看每个段的地址/偏移/大小
sections: $(TARGET)
	@echo ""
	@echo "=== ELF Section Headers (readelf -S) ==="
	$(READELF) -S $(TARGET)

# Symbol table — 查看全局/局部/未定义符号
symbols: $(TARGET)
	@echo ""
	@echo "=== ELF Symbol Table (readelf -s) ==="
	$(READELF) -s $(TARGET)

# ELF file header — 查看魔数/架构/端序等基本信息
headers: $(TARGET)
	@echo ""
	@echo "=== ELF File Header (readelf -h) ==="
	$(READELF) -h $(TARGET)

# Relocation entries — 查看需要重定位的地方
relocs: $(TARGET)
	@echo ""
	@echo "=== ELF Relocations (readelf -r) ==="
	$(READELF) -r $(TARGET)

clean:
	rm -f $(TARGET)
