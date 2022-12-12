# SOURCE	= ./src/main.cpp ./src/parser.cpp ./src/cities.cpp
# HEADER	= ./src/parser.h ./src/cities.h
# OUT	= main
# CC	 = g++
# FLAGS	 = -g -c -Wall
# OBJS = 

# all: $(OBJS)
# 	$(CC) -g $(OBJS) -o $(OUT)

# ./src/main.o: ./src/main.cpp
# 	$(CC) $(FLAGS) ./src/main.cpp 

# ./src/parser.o: ./src/parser.cpp
# 	$(CC) $(FLAGS) ./src/parser.cpp 

# ./src/cities.o: ./src/cities.cpp
# 	$(CC) $(FLAGS) ./src/cities.cpp 

main:
	g++ src/main.cpp src/parser.cpp src/minheap.cpp -g -Wall -Werror  -o main

clean:
	rm -f *.o main $(OBJS) $(OUT)