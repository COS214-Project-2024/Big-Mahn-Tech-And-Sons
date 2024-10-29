# Define the compiler and the flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra -pedantic

# Define the unit test target executable
UNIT_TEST_TARGET = unit

# Find all .cpp files excluding main and Test.cpp
COMMON_SRCS = $(filter-out Test.cpp, $(wildcard *.cpp))
COMMON_OBJS = $(COMMON_SRCS:.cpp=.o)

# Default target
all: $(UNIT_TEST_TARGET)

# Build the unit test executable
$(UNIT_TEST_TARGET): Test.o $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $(UNIT_TEST_TARGET) Test.o $(COMMON_OBJS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the unit test executable with valgrind
unit_run: $(UNIT_TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(UNIT_TEST_TARGET) 2> valgrind_log.txt

# Run the unit test executable with gdb
unit_debug: $(UNIT_TEST_TARGET)
	gdb -ex run --args ./$(UNIT_TEST_TARGET) 2>&1 | tee gdb_log.txt

# Clean up the build files
clean:
	rm -f $(COMMON_OBJS) Test.o $(UNIT_TEST_TARGET) valgrind_log.txt gdb_log.txt

# Phony targets
.PHONY: all unit_run unit_debug clean
