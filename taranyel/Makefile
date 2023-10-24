CXX=g++
LD=g++
CXXFLAGS=-Wall -pedantic -std=c++14

OBJECTS=build/main.o build/Input.o build/CheckConfiguration.o build/Execute.o build/Commands.o  build/Error.o build/Import.o \
	  build/Export.o build/Evaluate.o build/ReadOperand.o build/Operators.o build/Rank.o build/Trimming.o build/Transposition.o \
	  build/GaussMethod.o build/Inversion.o build/Determinant.o build/Merging.o build/Multiplying.o build/Minus.o build/Plus.o \
	  build/Operator.o build/SparseMatrix.o build/DenseMatrix.o build/Number.o build/Matrix.o build/Operand.o
	
MAINSOURCES=src/main.cpp src/input/*.h src/configuration/*.h src/executing/*.h src/operators/*.h src/operands/*.h 
INPUTSOURCES=src/input/*.h src/configuration/*.h src/executing/*.h src/operators/*.h src/operands/*.h 
EXECSOURSES=src/executing/*.h src/operators/*.h src/operands/*.h
OPERATORSSRC=src/operators/*.h src/operands/*.h
HEADERS = $(wildcard src/*/*.h)
TESTS = $(wildcard examples/*.test.cpp)


all: taranyel

taranyel: $(OBJECTS)
	mkdir -p build
	$(LD) $(OBJECTS) -o taranyel

doc: Doxyfile $(HEADERS)
	doxygen Doxyfile

compile: taranyel

run: taranyel
	./taranyel

clean:
	rm taranyel
	rm -r build/ doc/
	
clean_doc:
	rm -r doc/

clean_test:
	rm -r debug/

.PHONY: clean

debug/%.test: examples/%.test.cpp $(filter-out build/main.o,$(OBJECTS))
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $< $(filter-out build/main.o,$(OBJECTS)) -I examples/ -o $@

test: $(TESTS:examples/%.test.cpp=debug/%.test)
	./debug/*.test
	
# Requirements / Dependencies
build/main.o: $(MAINSOURCES) 
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/main.cpp -o $@

build/Input.o: src/input/Input.cpp $(INPUTSOURCES) 
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/input/Input.cpp -o $@

build/CheckConfiguration.o: src/configuration/CheckConfiguration.cpp src/configuration/CheckConfiguration.h src/configuration/Commands.h
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/configuration/CheckConfiguration.cpp -o $@

build/Commands.o: src/configuration/Commands.cpp src/configuration/Commands.h
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/configuration/Commands.cpp -o $@

build/Execute.o: src/executing/Execute.cpp $(EXECSOURSES)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/executing/Execute.cpp -o $@

build/Error.o: src/error/Error.cpp src/error/Error.h
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/error/Error.cpp -o $@

build/Import.o: src/executing/Import.cpp $(EXECSOURSES)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/executing/Import.cpp -o $@

build/Export.o: src/executing/Export.cpp $(EXECSOURSES)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/executing/Export.cpp -o $@

build/Evaluate.o: src/executing/Evaluate.cpp $(EXECSOURSES)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/executing/Evaluate.cpp -o $@

build/ReadOperand.o: src/executing/ReadOperand.cpp src/executing/ReadOperand.h
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/executing/ReadOperand.cpp -o $@

build/Operators.o: src/executing/Operators.cpp src/executing/Operators.h $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/executing/Operators.cpp -o $@

build/Rank.o: src/operators/Rank.cpp $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/Rank.cpp -o $@

build/Trimming.o: src/operators/Trimming.cpp $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/Trimming.cpp -o $@

build/Transposition.o: src/operators/Transposition.cpp $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/Transposition.cpp -o $@

build/GaussMethod.o: src/operators/GaussMethod.cpp $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/GaussMethod.cpp -o $@

build/Inversion.o: src/operators/Inversion.cpp $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/Inversion.cpp -o $@

build/Determinant.o: src/operators/Determinant.cpp $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/Determinant.cpp -o $@

build/Merging.o: src/operators/Merging.cpp $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/Merging.cpp -o $@

build/Multiplying.o: src/operators/Multiplying.cpp $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/Multiplying.cpp -o $@

build/Minus.o: src/operators/Minus.cpp $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/Minus.cpp -o $@

build/Plus.o: src/operators/Plus.cpp $(OPERATORSSRC)
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/Plus.cpp -o $@

build/Operator.o: src/operators/Operator.cpp src/operators/Operator.h src/operands/*.h
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operators/Operator.cpp -o $@

build/SparseMatrix.o: src/operands/SparseMatrix.cpp src/operands/*.h
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operands/SparseMatrix.cpp -o $@

build/DenseMatrix.o: src/operands/DenseMatrix.cpp src/operands/*.h
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operands/DenseMatrix.cpp -o $@

build/Number.o: src/operands/Number.cpp src/operands/*.h
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operands/Number.cpp -o $@

build/Matrix.o: src/operands/Matrix.cpp src/operands/*.h
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operands/Matrix.cpp -o $@

build/Operand.o: src/operands/Operand.cpp src/operands/Operand.h
	mkdir -p build
	$(CXX) -g $(CXXFLAGS) -c src/operands/Operand.cpp -o $@
