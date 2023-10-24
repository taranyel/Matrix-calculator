#include "Operators.h"

void Operators::fillOperators() {
    operators.insert({"+", new Plus});
    operators.insert({"-", new Minus});
    operators.insert({"ADD", new Merging});
    operators.insert({"MUL", new Multiplying});
    operators.insert({"GAUSS", new GaussMethod});
    operators.insert({"INV", new Inversion});
    operators.insert({"TRANS", new Transposition});
    operators.insert({"TRIM", new Trimming});
    operators.insert({"RANK", new Rank});
    operators.insert({"DET", new Determinant});
}

Operators::~Operators() {
    for (const auto& i : operators){
        delete i.second;
    }

    operators.clear();
}
