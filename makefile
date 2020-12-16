CFLAGS= -Wall -z muldefs -O0 -std=c++2a -Wno-deprecated-volatile -fdiagnostics-color=always
LINK= -lpthread -lGL -ldl -lglfw -lmpg123 -lao -I/usr/include/freetype2 -lfreetype -Iinclude/
OBJS=$(shell ls src/*.c*) $(shell ls src/*/*.c*)
CXX=clang++
OUT=main.out
all:
	$(CXX) $(CFLAGS) $(LINK) $(OBJS) -o $(OUT)

start:
	./$(OUT)
