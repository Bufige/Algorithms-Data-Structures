# compiler used.
COMPILER = g++

# path of the files 
INCLUDE_PATH = include
SRC_PATH = src
BIN_PATH = bin
DOC_PATH = doc

# executable name 
EXE_NAME = main

# accepted extension 
SRC_EXT = cpp


# command to make the terminal clear.
.SILENT: clean doxy

# compiler flags 
COMPILER_FLAGS = -std=c++11 -Wall

# for later testings
# OS flag \
OS := $(shell uname) \
windows flag \
ifeq ($(OS),Windows_NT) \
else \
	ifeq ($(OS),Linux) \
	endif \
endif

# command  to compile the code 
all:
	$(COMPILER) $(COMPILER_FLAGS) $(SRC_PATH)/*.$(SRC_EXT) -o $(BIN_PATH)/$(EXE_NAME) -I $(INCLUDE_PATH)

#command to create working directories 
dir:
	@echo "creating directories"
	@mkdir $(INCLUDE_PATH)
	@mkdir $(SRC_PATH)
	@mkdir $(BIN_PATH)
	@mkdir $(DOC_PATH)

doxy:
	rmdir /s /q $(DOC_PATH)
	@mkdir $(DOC_PATH)
	doxygen Doxyfile

# command to clean the binaries 
clean:
# windows clean
	rmdir /s /q $(BIN_PATH)
	rmdir /s /q $(DOC_PATH)
	@mkdir $(BIN_PATH)
	@mkdir $(DOC_PATH)
# linux clean
# rm -rf $(BIN_PATH)/*
# rm -rf $(DOC_PATH)/*