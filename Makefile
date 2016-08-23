SOURCE_DIRECTORY=./src
TARGET_DIRECTORY=./build
OBJECT_DIRECTORY=$(TARGET_DIRECTORY)/obj
RESOURCE_DIRECTORY=./res

TARGET=$(TARGET_DIRECTORY)/warctic
SOURCE_FILES=$(wildcard $(SOURCE_DIRECTORY)/*.cpp) $(wildcard $(SOURCE_DIRECTORY)/**/*.cpp) $(wildcard $(SOURCE_DIRECTORY)/**/**/*.cpp)
TARGET_FILES=$(subst $(SOURCE_DIRECTORY), $(OBJECT_DIRECTORY), $(SOURCE_FILES))
OBJECT_FILES=$(TARGET_FILES:.cpp=.o)

COMPILER=g++
COMPILER_FLAGS=-c -g -std=c++11 -DLIN -DX64 -DDEBUG
COMPILER_INCLUDE=-I$(SOURCE_DIRECTORY)
LINKER=g++
LINKER_FLAGS=
LINKER_LIBRARY_DIRECTORIES=-L/usr/lib/x86_64-linux-gnu/
LINKER_LIBRARIES=-lstdc++ -lglfw -lGLEW -lGL -lopenal



.PHONY: all run clean cleanall src tar setup

all: setup game

setup:
	mkdir -p $(TARGET_DIRECTORY)

game: $(TARGET)

$(TARGET): $(OBJECT_FILES)
	$(LINKER) $(LINKER_FLAGS) $(LINKER_LIBRARY_DIRECTORIES) -o $@ $^ $(LINKER_LIBRARIES)

$(OBJECT_DIRECTORY)%.o: $(SOURCE_DIRECTORY)%.cpp
	mkdir -p $(dir $@)
	$(COMPILER) $(COMPILER_FLAGS) $(COMPILER_INCLUDE) -o $@ $<

run: all
	cd $(TARGET_DIRECTORY) && pwd && ./warctic

clean:
	rm -R $(OBJECT_DIRECTORY)

cleanall:
	rm -R $(TARGET_DIRECTORY)

src:
	echo $(SOURCE_DIRECTORY)
	echo $(SOURCE_FILES)

tar:
	echo $(OBJECT_DIRECTORY)
	echo $(OBJECT_FILES)
