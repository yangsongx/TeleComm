# Makefile
#
CC = gcc
CXX = g++

INCLUDE = -Iinc/

CFLAGS =  $(INCLUDE) -W -Wall -Wno-unused-parameter
CXXFLAGS =  $(INCLUDE) -Immril/ -Icdmaril/ -W -Wall -Wno-unused-parameter

RILD_SRC = ril_main.c
MMRIL_SRC = mmril/rilmm_main.cpp mmril/rilmm_util_log.cpp mmril/rilmm_psd.cpp \
            mmril/rilmm_bip.cpp
LTERIL_SRC = lteril/lteril_main.cpp
CDMARIL_SRC = cdmaril/cdmaril_main.cpp
QMIRIL_SRC = cdmaril/qmi/MotQmiConnection.cpp

RILD_OBJ = $(RILD_SRC:.c=.o)
MMRIL_OBJ = $(MMRIL_SRC:.cpp=.o)
LTERIL_OBJ = $(LTERIL_SRC:.cpp=.o)
CDMARIL_OBJ = $(CDMARIL_SRC:.cpp=.o)
QMIRIL_OBJ = $(QMIRIL_SRC:.cpp=.o)

#in future, need change ifneq to ifeq
#to make default mode as release.
ifneq ($(DEBUG),false)
	CFLAGS += -DDEBUG -g -O0
	CXXFLAGS += -DDEBUG -g -O0
else
	CFLAGS += -O2
	CXXFLAGS += -O2
endif

all:rild mmril lteril cdmaril qmiril

rild:$(RILD_OBJ)
	$(CC) -ldl -o rild $(RILD_OBJ)

mmril:$(MMRIL_OBJ)
	$(CXX) -shared -fPIC -o mmril.so $(MMRIL_OBJ)

lteril:$(LTERIL_OBJ)
	$(CXX) -shared -fPIC -o lteril.so $(LTERIL_OBJ)

cdmaril:$(CDMARIL_OBJ)
	$(CXX) -shared -fPIC -o cdmaril.so $(CDMARIL_OBJ)

qmiril:$(QMIRIL_OBJ)
	$(CXX) -shared -fPIC -o qmiril.so $(QMIRIL_OBJ)

.PHONY: clean
clean:
	rm *.o rild mmril.so cdmaril.so lteril.so qmiril.so
	find . -name '*.o' -exec rm -rf {} ";"
