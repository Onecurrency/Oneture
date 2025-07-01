
---

### 2. ملف Makefile

```makefile
# Oneture Blockchain Build Configuration

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -I./src/core

SRC_DIR := src
BUILD_DIR := build
TARGET := oneture

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all clean build_dir

all: build_dir $(TARGET)

build_dir:
	@mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR) $(TARGET)
