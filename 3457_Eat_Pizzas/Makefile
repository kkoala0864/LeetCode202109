CXX=clang++

SRC=$(filter-out main.cpp,$(wildcard *.cpp))
STATIC_OBJ=$(SRC:%.cpp=%.o)
HEADER=$(wildcard *.h)
CFLAGS+=-O3
CXXFLAGS+=-O3 -std=c++17 -Weffc++
INC_PATH=.
DATA_TYPE_INCLUDE_PATH=../data_type
deps := $(SRC:%.cpp=.%.o.d)

.PHONY:
all: exe

exe : main.cpp $(STATIC_OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) -o exe $< $(STATIC_OBJ) -I$(INC_PATH) -I$(DATA_TYPE_INCLUDE_PATH)

%.o : %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -o $@ -c $< -I$(INC_PATH) -I$(DATA_TYPE_INCLUDE_PATH) -MMD -MF .$@.d

clean :
	rm $(STATIC_OBJ) exe $(deps) &> /dev/null || true
ifeq ($(shell uname -s),Darwin)
	rm -rf exe.dSYM
endif

-include $(deps)
