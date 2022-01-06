# files to compile
# '*' indicates compile every file
OBJS =  *.cpp

# compiler we are using
CC = g++

# compiler flags
# -Wall turns lots of compiler warnings
COMPILER_FLAGS = -w -g -Wall

# libraries we are linking
LINKER_FLAGS = -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf 

# final executable
OBJ_NAME = a.out

# target
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

# delete the executable
clean:
	rm $(OBJ_NAME)