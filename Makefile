ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
DEP = dependencies/
INCL = /include
OUT = out/

## Includes
GLAD			= $(DEP)glad$(INCL)
GLM 			= $(DEP)glm$(INCL)
GLWF 			= $(DEP)glfw$(INCL)
IMGUI	 		= $(DEP)imgui$(INCL)
#VULKAN 			= $(DEP)vulkan$(INCL)

## LIBS
GLFW_L 			= $(DEP)glfw/lib
GLFW_L_FILE 	= glfw3dll
VULKAN_L		= $(DEP)vulkan/lib


## Attaching the Flags
CFLAGS = -std=c++17 -I. -Isrc\
		-I$(GLAD) \
		-I$(GLM) \
		-I$(GLWF) \
		-I$(IMGUI) \
		# -I$(VULKAN)

LDFLAGS = -L$(GLFW_L) -l$(GLFW_L_FILE)\
		-L$(VULKAN_L)

INTERNALS = src/*
EXTERNALS = dependencies/*/ext/* #All external source files have to be inside dependencies/<name/ext folder

a.exe: *.cpp *.hpp
	g++ $(CFLAGS) $(INTERNALS) $(EXTERNALS) -o $(OUT)a.exe *.cpp $(LDFLAGS) 

.PHONY: test clean

test: a.exe
	./a.exe

clean:
	rm -f a.exe