CXX = claang++
CXX_FLAGS=-std=c++20 -Iincludes -g -fstandalone-debug -O0 -Wall -Wextra -Werror

exec: entry/main

bin/exec: ./src/parser.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec bin

clean:
	rm -f bin/*