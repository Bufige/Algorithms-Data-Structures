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
.SILENT: clean doxy dir

# compiler flags 
COMPILER_FLAGS = -std=c++11 -Wall

# for later testings
# OS flag \
OS := $(shell uname)
ifeq ($(OS),Windows_NT)
	# temporary... windows #@!#$%%#%$%¨%$#$#@$%¨&%%#
	RM = rm -rf
else
	ifeq ($(OS),Linux)
		RM = rm -rf
	endif
endif

# command  to compile the code 
all:
	$(COMPILER) $(COMPILER_FLAGS) $(SRC_PATH)/*.$(SRC_EXT) -o $(BIN_PATH)/$(EXE_NAME) -I $(INCLUDE_PATH)

#command to create working directories 
dir:
	@echo "Creating directories..."
	if [ ! -d "./$(INCLUDE_PATH)" ];then  \
		mkdir $(INCLUDE_PATH); \
	fi	
	if [ ! -d "./$(SRC_PATH)" ];then  \
		mkdir $(SRC_PATH); \
	fi	
	if [ ! -d "./$(BIN_PATH)" ];then  \
		mkdir $(BIN_PATH); \
	fi	
	if [ ! -d "./$(DOC_PATH)" ];then  \
		mkdir $(DOC_PATH); \
	fi		

doxy:
	@echo "Making documentation..."
	if [ -d "./$(DOC_PATH)" ];then  \
		$(RM) -rf $(DOC_PATH); \
	fi
	if [ ! -d "./$(DOC_PATH)" ];then  \
		mkdir $(DOC_PATH); \
	fi
	doxygen Doxyfile

# command to clean the binaries 
clean:
	@echo "Deleting directories."
	if [ -d "./$(BIN_PATH)" ];then  \
		$(RM) $(BIN_PATH); \
	fi
	if [ -d "./$(DOC_PATH)" ];then  \
		$(RM) $(DOC_PATH); \
	fi

# linux clean
# rm -rf $(BIN_PATH)/*
# rm -rf $(DOC_PATH)/*