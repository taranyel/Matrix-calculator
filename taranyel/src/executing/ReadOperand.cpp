#include "ReadOperand.h"

vector<vector<double>> ReadOperand::readMatrix(string buffer, int *zeroNumber, int *values) {

    vector<vector<double>> matrix;
    string strValue;
    bool finish;
    bool first = false;
    size_t i = 0;
    int rows = 0;

    while (i < buffer.size()) {

        if (!first && buffer[i] == '[' && i < buffer.size()) {
            first = true;
            i++;
        }

        if (!first && i < buffer.size()) {
            i++;
            continue;
        }

        while (buffer[i] == ' ' && i < buffer.size()) {
            i++;
        }

        finish = false;
        matrix.emplace_back();

        if (buffer[i] == '[' && i < buffer.size()) {

            i++;
            while (buffer[i] != ']' && i < buffer.size()) {

                bool digit = false;

                while (buffer[i] != ',' && buffer[i] != ']' && i < buffer.size()) {

                    if (digit && !isdigit(buffer[i]) && buffer[i] != '.'){
                        break;
                    }

                    if (isdigit(buffer[i])){
                        digit = true;
                    }

                    strValue += buffer[i];
                    i++;
                }

                double value;
                size_t end;

                try {
                    value = stod(strValue, &end);
                } catch (...) {
                    clearMatrix(matrix);
                    return {};
                }

                if (end != strValue.size()){
                    clearMatrix(matrix);
                    return{};
                }

                if (value == 0) {
                    (*zeroNumber)++;
                } else {
                    (*values)++;
                }

                strValue.clear();

                matrix[rows].push_back(value);

                if (buffer[i] == ' ') {
                    while (buffer[i] == ' ' && i < buffer.size()) {
                        i++;
                    }
                }
                
                if (buffer[i] == ',' && i < buffer.size()) {
                    i++;
                    if (buffer[i] == ' ') {
                        while (buffer[i] == ' ' && i < buffer.size()) {
                            i++;
                        }
                    }
                } else if (buffer[i] != ']'){
                    clearMatrix(matrix);
                    return {};
                }
            }

            if (i < buffer.size()){
                i++;
            }

            while (buffer[i] == ' ' && i < buffer.size()) {
                i++;
            }

            if (buffer[i] == ']') {
                finish = true;
            }

            if (rows > 0) {
                if (matrix[rows].size() != matrix[rows - 1].size()) {
                    clearMatrix(matrix);
                    return {};
                }
            }

            if (!finish && buffer[i] != ',') {
                clearMatrix(matrix);
                return {};

            } else if (!finish && i < buffer.size()) {
                i++;
                if (buffer[i] == ' ') {
                    while (buffer[i] == ' ' && i < buffer.size()) {
                        i++;
                    }
                }
            } else {
                i++;
                if (buffer.size() > i + 1) {
                    if (!isspace(buffer[i])) {
                        clearMatrix(matrix);
                        return {};
                    }
                }
            }
            rows++;

        } else {
            clearMatrix(matrix);
            return {};
        }

        if (finish) {
            return matrix;
        }
    }

    return {};
}

void ReadOperand::clearMatrix(vector<vector<double>> matrix) {
    for (auto &i: matrix) {
        i.clear();
    }
    matrix.clear();
}

bool ReadOperand::readNumber(const string &buffer, double *value) {
    double number;
    size_t end;

    try {
        number = stod(buffer, &end);
    } catch (...) {
        return false;
    }

    if (end != buffer.size()){
        return false;
    }

    (*value) = number;
    return true;
}

ReadOperand::ReadOperand() = default;
