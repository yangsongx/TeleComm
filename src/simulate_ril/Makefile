# Makefile
CC = gcc
CXX = g++

INCLUDE = -Iinc/

CFLAGS =  $(INCLUDE) -W -Wall
CXXFLAGS =  $(INCLUDE) -Immril/ -W -Wall

RILD_SRC = ril_main.c
MMRIL_SRC = mmril/rilmm_main.cpp

RILD_OBJ = $(RILD_SRC:.c=.o)
MMRIL_OBJ = $(MMRIL_SRC:.cpp=.o)

all:rild mmril

rild:$(RILD_OBJ)
	$(CC) -o rild $(RILD_OBJ)
mmril:$(MMRIL_OBJ)
	$(CXX) $(CXXFLAGS) -shared -fPIC -o mmril.so $(MMRIL_OBJ)

.PHONY: clean
clean:
	rm *.o rild mmril.so
	find . -name '*.o' -exec rm -rf {} ";"
