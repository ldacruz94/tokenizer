BUILD_DIR := build

.PHONY: all build run test clean

all: build

build:
	@cmake -B $(BUILD_DIR) -DCMAKE_EXPORT_COMPILE_COMMANDS=ON > /dev/null
	@cmake --build $(BUILD_DIR) > /dev/null
	@ln -sf $(BUILD_DIR)/compile_commands.json compile_commands.json

run: build
	./$(BUILD_DIR)/tokenizer

test: build
	./$(BUILD_DIR)/tokenizer_tests

clean:
	rm -rf $(BUILD_DIR)
