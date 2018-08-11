.DEFAULT_GOAL := all

# compiler used.
COMPILER = g++

# path of the files 
INCLUDE_PATH = include
SRC_PATH = src
BIN_PATH = bin
DOC_PATH = doc

#doxygen filename
DOXYGEN_FILE = Doxyfile

# executable name 
EXE_NAME = main

#template for fast coding.
MAIN_TEXT = "\#include <iostream>\n\n\n\nint main()\n{\n	\n	return 0;\n}"

# accepted extension 
SRC_EXT = cpp




# command to make the terminal clear.
.SILENT: clean doxy dir

# compiler flags 
COMPILER_FLAGS = -std=c++11 -Wall

# for later testings
# OS flag
OS := $(shell uname)
ifeq ($(OS),Windows_NT)
	# temporary... windows #@!#$%%#%$%¨%$#$#@$%¨&%%#
	RM = rm
else
	ifeq ($(OS),Linux)
		RM = rm
	endif
endif

# command to compile the code, if no folder is created it will try to create them and make a simple starting setup.
all: dir 
	$(COMPILER) $(COMPILER_FLAGS) $(SRC_PATH)/*.$(SRC_EXT) -o $(BIN_PATH)/$(EXE_NAME) -I $(INCLUDE_PATH)

#command to create working directories 
dir :
	if [ ! -d "./$(INCLUDE_PATH)" ];then  \
		echo "Creating $(INCLUDE_PATH)...";\
		mkdir $(INCLUDE_PATH); \
	fi	
	if [ ! -d "./$(SRC_PATH)" ];then  \
		echo "Creating $(SRC_PATH)...";\
		mkdir $(SRC_PATH); \
		echo "Creating $(EXE_NAME).cpp...";\
		echo -e $(MAIN_TEXT) > ./$(SRC_PATH)/$(EXE_NAME).cpp; \
	fi	
	if [ ! -d "./$(BIN_PATH)" ];then  \
		echo "Creating $(BIN_PATH)...";\
		mkdir $(BIN_PATH); \
	fi	
	if [ ! -d "./$(DOC_PATH)" ];then  \
		echo "Creating $(DOC_PATH)...";\
		mkdir $(DOC_PATH); \
	fi		

# command to generate the documentation
doxy:
	@echo "Making documentation..."
	if [ -d "./$(DOC_PATH)" ];then  \
		$(RM) -rf $(DOC_PATH); \
	fi
	if [ ! -d "./$(DOC_PATH)" ];then  \
		mkdir $(DOC_PATH); \
	fi
	if [ -d "./$(DOC_PATH)" ];then  \
		$(RM) -rf $(DOC_PATH); \
	fi
	if [ -a "./$(DOXYGEN_FILE)" ];then  \
		doxygen $(DOXYGEN_FILE); \
	else \
		echo "couldn't find the doxygen file";  \
	fi	

# command to clean everything. 
clean:
	@echo "Deleting directories."
	if [ -d "./$(BIN_PATH)" ];then  \
		$(RM) -rf $(BIN_PATH); \
	fi
	if [ -d "./$(DOC_PATH)" ];then  \
		$(RM) -rf $(DOC_PATH); \
	fi

# snippet command to a fresh instalation.
fresh: clean dir