EXEC = BancoSimples
SRC = main.cpp Cliente.cpp ContaBancaria.cpp
OBJ = $(SRC:.cpp=.o)

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
DEPS = $(OBJ:.o=.d)

.PHONY: all clean test

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

tests/test_conta: tests/test_conta.cpp Cliente.cpp ContaBancaria.cpp Cliente.h ContaBancaria.h
	$(CXX) $(CXXFLAGS) -I. tests/test_conta.cpp Cliente.cpp ContaBancaria.cpp -o $@

test: tests/test_conta
	./tests/test_conta

clean:
	rm -f *.o *.d $(EXEC) tests/test_conta
