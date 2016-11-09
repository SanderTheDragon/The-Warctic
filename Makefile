# Set source directory
SOURCE_DIRECTORY=./src

# Set target directory
TARGET_DIRECTORY=./build

# Set object directory, all compiled files will go here
OBJECT_DIRECTORY=$(TARGET_DIRECTORY)/obj

# Set additional include and library directories
INCLUDE_DIRECTORY=./include
LIBRARY_DIRECTORY=./lib

# Set executable name
TARGET=warctic

# Best to leave unchanged
SOURCE_FILES=$(wildcard $(SOURCE_DIRECTORY)/*.cpp) $(wildcard $(SOURCE_DIRECTORY)/**/*.cpp) $(wildcard $(SOURCE_DIRECTORY)/**/**/*.cpp)
TARGET_FILES=$(subst $(SOURCE_DIRECTORY), $(OBJECT_DIRECTORY), $(SOURCE_FILES))
OBJECT_FILES=$(TARGET_FILES:.cpp=.o)

# This is all configured to my system, change to your own if you want to compile
COMPILER=g++
COMPILER_FLAGS=-c -g -std=c++11 -DLIN -DX64 -DUNSTABLE
COMPILER_INCLUDE=-I$(SOURCE_DIRECTORY) -I$(INCLUDE_DIRECTORY)
LINKER=g++
LINKER_FLAGS=
LINKER_LIBRARY_DIRECTORIES=-L/usr/lib/x86_64-linux-gnu/ -L$(LIBRARY_DIRECTORY)
LINKER_LIBRARIES=-lstdc++ -lSDL2 -lSDL2_mixer -lGL



.PHONY: all run clean cleanall src tar setup

all: setup game

# You could change this, but that will require changing generate-resources.py and src/Config.hpp
setup:
	mkdir -p $(TARGET_DIRECTORY)
	mkdir -p $(TARGET_DIRECTORY)/resources
	python ./generate-resources.py
	mv ./resources/*.zip $(TARGET_DIRECTORY)/resources

game: $(TARGET_DIRECTORY)/$(TARGET)

$(TARGET_DIRECTORY)/$(TARGET): $(OBJECT_FILES)
	$(LINKER) $(LINKER_FLAGS) $(LINKER_LIBRARY_DIRECTORIES) -o $@ $^ $(LINKER_LIBRARIES)

$(OBJECT_DIRECTORY)%.o: $(SOURCE_DIRECTORY)%.cpp
	mkdir -p $(dir $@)
	$(COMPILER) $(COMPILER_FLAGS) $(COMPILER_INCLUDE) -o $@ $<

run: all
	cd $(TARGET_DIRECTORY) && pwd && ./$(TARGET) --debug

run_ndbg: all
	cd $(TARGET_DIRECTORY) && pwd && ./$(TARGET)

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
