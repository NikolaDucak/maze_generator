#Variable declaration
PROGRAM_NAME = maze-generator
COMPILER = g++
FLAGS = -I.

#directories
OBJECT_DIRECTORY = ./obj
INCLUDE_DIRECTORY = ./inc
SOURCE_DIRECTORY = ./src
BUILD_DIRECTORY = ./build

#files
SOURCE_FILES = $(wildcard $(SOURCE_DIRECTORY)/*.cpp)
OBJECT_FILES = $(subst $(SOURCE_DIRECTORY), $(OBJECT_DIRECTORY), $(SOURCE_FILES:.cpp=.o))

#rule macro for object file
$(OBJECT_DIRECTORY)/%.o : $(SOURCE_DIRECTORY)/%.cpp 
	$(COMPILER) -c -o $@ $^
	
all: $(OBJECT_FILES) 
	$(COMPILER) $(OBJECT_FILES) -o $(BUILD_DIRECTORY)/$(PROGRAM_NAME) 

clean:
	-rm $(OBJECT_DIRECTORY)/*.o
