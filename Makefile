CXX = clang++
INCLUDES=-Iincludes/
CXX_FLAGS=-std=c++20 -g $(INCLUDES)

exec: src/entry/main

bin/exec:  src/main.cc src/parser.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: clean

clean:
	rm -f bin/* obj/*