# Define the compiler and the flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra -pedantic

# Define the target executables
TESTING_TARGET = test
DEMO_TARGET = demo
UNIT_TEST_TARGET = unit

# Find all .cpp files excluding main files
COMMON_SRCS = $(filter-out TestMain.cpp DemoMain.cpp Test.cpp, $(wildcard *.cpp))
COMMON_OBJS = $(COMMON_SRCS:.cpp=.o)

# Default target
all: $(TESTING_TARGET) $(DEMO_TARGET) $(UNIT_TEST_TARGET)

# Build the testing executable
$(TESTING_TARGET): TestMain.o $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TESTING_TARGET) TestMain.o $(COMMON_OBJS)

# Build the demo executable
$(DEMO_TARGET): DemoMain.o $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) DemoMain.o $(COMMON_OBJS)

# Build the unit test executable
$(UNIT_TEST_TARGET): Test.o $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $(UNIT_TEST_TARGET) Test.o $(COMMON_OBJS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the testing executable with valgrind
run: $(TESTING_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TESTING_TARGET) 2> valgrind_log.txt

# Run the demo executable with valgrind
demo_run: $(DEMO_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(DEMO_TARGET) 2> valgrind_log.txt

# Run the unit test executable with valgrind
unit_run: $(UNIT_TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(UNIT_TEST_TARGET) 2> valgrind_log.txt

# Run the testing executable with gdb
debug: $(TESTING_TARGET)
	gdb -ex run --args ./$(TESTING_TARGET) 2>&1 | tee gdb_log.txt

# Run the demo executable with gdb
demo_debug: $(DEMO_TARGET)
	gdb -ex run --args ./$(DEMO_TARGET) 2>&1 | tee gdb_log.txt

# Run the unit test executable with gdb
unit_debug: $(UNIT_TEST_TARGET)
	gdb -ex run --args ./$(UNIT_TEST_TARGET) 2>&1 | tee gdb_log.txt

# Clean up the build files
clean:
	rm -f $(COMMON_OBJS) TestMain.o DemoMain.o Test.o $(TESTING_TARGET) $(DEMO_TARGET) $(UNIT_TEST_TARGET) valgrind_log.txt gdb_log.txt

# Phony targets
.PHONY: all run demo_run unit_run debug demo_debug unit_debug clean