BUILD_DIR := build

.PHONY: all build run clean

all: build

build:
	cmake -B $(BUILD_DIR) -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build $(BUILD_DIR)
	ln -sf $(BUILD_DIR)/compile_commands.json compile_commands.json

run: build
	./$(BUILD_DIR)/tokenizer

clean:
	rm -rf $(BUILD_DIR)
