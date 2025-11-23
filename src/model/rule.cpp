#include "model/rule.hpp"

void Rule::addNoun(TextNoun noun) {
    nouns.push_back(noun);
}

void Rule::addOperator(TextOperator op) {
    operators.push_back(op);
}

void Rule::addProperty(TextProperty prop) {
    properties.push_back(prop);
}

vector<TextNoun> Rule::getNouns() const {
    return nouns;
}

vector<TextOperator> Rule::getOperators() const {
    return operators;
}

vector<TextProperty> Rule::getProperties() const {
    return properties;
}

void Rule::clear() {
    nouns.clear();
    operators.clear();
    properties.clear();
}

void Rule::printRule() {
    cout << "Rule: " << endl;
    cout << "Nouns: ";
    for (TextNoun noun : nouns) {
        cout << noun.getId() << " ";
    }
    cout << endl;
    cout << "Operateurs: ";
    for (TextOperator op : operators) {
        cout << op.getId() << " ";
    }
    cout << endl;
    cout << "Properties: ";
    for (TextProperty prop : properties) {
        cout << prop.getId() << " ";
    }
    cout << endl;
}