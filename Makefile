#
# Macros
#

PROJECT_NAME=KNN

C_SOURCE=$(wildcard ./src/*.cpp)
H_SOURCE=$(wildcard ./src/*.h)
OBJ=$(subst .cpp,.o,$(subst src,obj,$(C_SOURCE)))

CPPC=g++
CPPC_FLAGS=-c \
           -w \
           -Wall
RM = rm -rf

#
# Compilation and linking
#

all: objFolder binFolder $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJ)
	@ date && echo '[INFO] Building target using G++ compiler: $<'
	@ $(CPPC) $< -o ./bin/$@
	@ echo ' '

./obj/main.o: ./src/main.cpp $(H_SOURCE)
	@ date && echo '[INFO] Building target using G++ compiler: $<'
	@ $(CPPC) $< $(CPPC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ date && echo '[INFO] Creating objects folder'
	@ mkdir -p obj
	@ echo ' '

binFolder:
	@ date && echo '[INFO] Creating binaries folder'
	@ mkdir -p bin
	@ echo ' '

clean:
	@ date && echo '[INFO] Cleaning binary and object files...'
	@ $(RM) ./obj/*.o ./bin/$(PROJECT_NAME)
	@ rmdir obj
	@ rmdir bin
	@ echo ' '

run:
	@ date && echo '[INFO] Running program: $(PROJECT_NAME)'
	@ echo ' '
	@ cat ./static/dataset.txt | ./bin/$(PROJECT_NAME)