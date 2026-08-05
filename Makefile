CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -MMD -MP

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
TARGET := engine

.PHONY: all clean valgrind

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
ifeq ($(OS),Windows_NT)
	del /Q $(subst /,\,$(OBJS)) $(subst /,\,$(DEPS)) $(TARGET).exe 2>nul || exit 0
else
	rm -f $(OBJS) $(DEPS) $(TARGET)
endif