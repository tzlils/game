INCLUDES=-I/usr/include/freetype2 -Iinclude/
CXXFLAGS=-Wall -z muldefs -O0 -std=c++2a -Wno-deprecated-volatile -fdiagnostics-color=always -g -MMD -MP 
CXXFLAGS:=$(INCLUDES)

CFLAGS=
CFLAGS:=$(INCLUDES)

LIBS=-lm -lpthread -lGL -ldl -lglfw -lmpg123 -lao -lfreetype -lstdc++
LDFLAGS=
LDFLAGS:=$(LIBS)

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CXX=clang++
CC=clang

MAIN = game
OUT=$(MAIN).out

$(BUILD_DIR)/$(OUT): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p