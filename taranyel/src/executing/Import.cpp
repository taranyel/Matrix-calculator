#include "Import.h"

Import::Import(const string &fileName, const string &varName) : fileName(fileName), varName(varName) {}

map<string, Operand *> Import::import() {
    map<string, Operand *> imported;

    if (varName.empty()) {
        imported = importAll();
        if (imported.empty()){
            imported.clear();
            return {};
        }
    } else {
        Operand *result;
        result = importOne();
        if (result) {
            imported.insert({varName, result});
        } else {
            imported.clear();
            return {};
        }
    }

    return imported;
}

Operand *Import::importOne() {
    ifstream file(fileName, ios::in | ios::binary);
    string buffer;
    Operand *operand;

    if (file.is_open()) {

        while (!file.eof()) {
            if (file.good()) {

                string temp;
                getline(file, temp);

                istringstream iss(temp);

                while (iss) {
                    iss >> buffer;
                }
            } else {
                return nullptr;
            }
        }
    } else {
        return nullptr;
    }

    int zeroNumber = 0, values = 0;
    double value = 0;
    vector<vector<double>> result;

    result = ReadOperand::readMatrix(buffer, &zeroNumber, &values);

    if (result.empty()) {

        if (!ReadOperand::readNumber(buffer, &value)) {
            cout << "Invalid file context." << endl;
            return nullptr;
        }

        operand = new Number(value);

    } else {
        operand = createMatrix(zeroNumber, values, result);
    }

    return operand;
}

map<string, Operand *> Import::importAll() {
    ifstream file(fileName, ios::in | ios::binary);
    string buffer;
    Operand *operand;
    map<string, Operand *> result;
    Evaluate evaluate;

    if (file.is_open()) {

        while (!file.eof()) {
            if (file.good()) {

                string temp, name, eqSign;
                getline(file, temp);
                istringstream iss(temp);

                if (!(iss >> name)){
                    break;
                }

                iss >> eqSign;

                operand = evaluate.evaluate(result, evaluate.operators, iss);

                if (!operand){
                    for (auto i : result){
                        delete i.second;
                    }
                    
                    result.clear();
                    cout << "File contents invalid expression." << endl;
                    return {};
                }

                if (result.count(name)){
                    delete result.at(name);
                    result.erase(name);
                }

                result.insert({name, operand});

            } else {
                
                for (auto i : result){
                        delete i.second;
                }

                result.clear();
                return {};
            }
        }
    } else {
        result.clear();
        return {};
    }

    return result;
}

Matrix *Import::createMatrix(int zeroNumber, int values, vector<vector<double>> matrix) {
    Matrix *result;

    if (zeroNumber > values) {
        SparseMatrix *sparseMatrix = new SparseMatrix((int) matrix.size(), (int) matrix[0].size());
        sparseMatrix->createSparseMatrixCSR(matrix);
        result = sparseMatrix;
    } else {
        DenseMatrix *denseMatrix = new DenseMatrix((int) matrix.size(), (int) matrix[0].size(), matrix);
        result = denseMatrix;
    }

    return result;
}



