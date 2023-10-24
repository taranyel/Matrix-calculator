#include "Number.h"

Number::Number(double value) : value(value) {}

Number::Number() = default;

Number::~Number() = default;

void Number::print(ostream &stream) {
    stream << value << endl;
}

void Number::clear() {}

int Number::getType() {
    return NUMBER;
}

pair<double, vector<vector<double>>> Number::getValue() {
    pair<double, vector<vector<double>>> number (value, {});
    return number;
}
