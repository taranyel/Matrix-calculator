#include "../src/executing/Import.h"
#include <cassert>
#include <map>

    void fillOperands(map <string, Operand*> &operands){
        SparseMatrix *m1 = new SparseMatrix(3, 3);
        SparseMatrix *m2 = new SparseMatrix(2, 3);
        SparseMatrix *m3 = new SparseMatrix(1, 1);
        SparseMatrix *m4 = new SparseMatrix(2, 2);
        SparseMatrix *m5 = new SparseMatrix(2, 1);

        m1->createSparseMatrixCSR({{0, 0, 1}, {1, 0, 0}, {3, 0, 0}});
        m2->createSparseMatrixCSR({{0, 0, 1}, {3, 0, 0}});
        m3->createSparseMatrixCSR({{0}});
        m4->createSparseMatrixCSR({{0, 2}, {0, 9}});
        m5->createSparseMatrixCSR({{0}, {0}});

        operands.insert({"a", m1});
        operands.insert({"b", m2});
        operands.insert({"c", m3});
        operands.insert({"d", m4});
        operands.insert({"e", m5});
        operands.insert({"f", new DenseMatrix(3, 3, {{14, 5, 6}, {0, 2, 3}, {6, 7, 0}})});
        operands.insert({"g", new DenseMatrix(2, 2, {{3, 4}, {0, -9}})});
        operands.insert({"h", new DenseMatrix(2, 3, {{9, 23, -6}, {2, 3, 4}})});
        operands.insert({"i", new DenseMatrix(5, 7, {{2, 3, 4, 6, 8, 9, 0}, {0, 9, -6, -34, -1, 3, 0}, 
        {-9, -5, -2, 45, 7.65, 9.2, 0}, {9.7, 0.3, 3, 1, 9.34, 0.2, 2}, {4, 6.78, -23.4, -67, 3, 9, 0}})});
        operands.insert({"j", new Number(4)});
        operands.insert({"k", new Number(-23)});
        operands.insert({"l", new Number(0.345)});
        operands.insert({"m", new Number(-1)});
        operands.insert({"n", new Number(4.7)});
    }

    void clearTest(vector<vector<double>> &test){
        for (auto i : test){
            i.clear();
        }
        test.clear();
    }

    void clearMap(map<string, Operand*> &operands){
        for (const auto &i: operands) {
            i.second->clear();
            delete i.second;
        }
        operands.clear();
    }
   
    int main(){

        Evaluate evaluate;
        map <string, Operand*> operands;
        string expression;
        Operand *result;

        fillOperands(operands);

        expression = "a f 2 MUL + DET [[2, 3, 0], [0, 9, 7]] MUL";
        istringstream stream (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream);

        vector<vector<double>> test = {{-4100, -6150, 0 }, {0, -18450, -14350}};

        assert(result->getValue().second == test);
        delete result;
        clearTest(test);



        expression = "a f +";
        istringstream stream1 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream1);
        test = {{14, 5, 7}, {1, 2, 3}, {9, 7, 0}};

        assert(result->getValue().second == test);
        delete result;
        clearTest(test);
    


        expression = "d h MUL b -";
        istringstream stream2 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream2);
        test = {{4, 6, 7}, {15, 27, 36}};

        assert(result->getValue().second == test);
        delete result;
        clearTest(test);


        expression = "g j MUL d + [[3, 4], [9, 0]] -";
        istringstream stream3 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream3);
        test = {{9, 14}, {-9, -27}};

        assert(result->getValue().second == test);
        delete result;
        clearTest(test);



        expression = "e TRANS [[3, 4]] ADD e MUL RANK";
        istringstream stream4 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream4);

        assert(result->getValue().first == 0);
        delete result;



        expression = "m n + [[5]] MUL c - [[2], [6], [0]] ADD";
        istringstream stream5 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream5);
        test = {{18.5}, {2}, {6}, {0}};

        assert(result->getValue().second == test);
        delete result;
        clearTest(test);



        expression = "i RANK";
        istringstream stream6 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream6);

        assert(result->getValue().first == 5);
        delete result;



        expression = "a d MUL c ADD TRANS";
        istringstream stream7 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream7);

        assert(!result);



        expression = "i m + [[1, 2, 5]] -";
        istringstream stream8 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream8);

        assert(!result);



        expression = "i 2 MUL f TRIM";
        istringstream stream9 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream9);
        test = {{4, 6, 8}, {0, 18, -12}, {-18, -10, -4}};

        assert(result->getValue().second == test);
        delete result;
        clearTest(test);



        expression = "b f MUL [[3, 4, 5], [-8, 6.45, -0.1]] - DET";
        istringstream stream10 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream10);

        (!result);



        expression = "f GAUSS a MUL [[3, -9, 5], [1, 2, -6], [45, -8.7, -1.2]] ADD g TRIM";
        istringstream stream11 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream11);
        test = {{23, 0}, {11, 0}};

        assert(result->getValue().second == test);
        delete result;
        clearTest(test);



        expression = "2 3 1 MUL + 9 -";
        istringstream stream12 (expression);

        result = evaluate.evaluate(operands, evaluate.operators, stream12);

        assert(result->getValue().first == -4);    



        clearMap(operands);
        clearTest(test);
        operands.clear();
        delete result;

        return 0;
   }