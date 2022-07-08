//Erkin Aydın 22002956
#include <string>
#include <iostream>
using namespace std;
#include "Chemical.h"

Chemical::Chemical() {}

Chemical::Chemical( int idNum, string type) {
    this->id = idNum;
    setType(type);
    this->combustiveDegree = 0;
}

int Chemical::getId() {
    return this->id;
}

void Chemical::setId( int newId) {
    this->id = newId;
}

void Chemical::setType( string s) {
    if(s == "combustive")
        this->type = "c";
    else if(s == "retardant")
        this->type = "r";
    else if(s == "+")
        this->type = "+";
}

string Chemical::getType() {
    return this->type;
}

int Chemical::getCombustiveDegree() {
    return this->combustiveDegree;
}

void Chemical::increaseDegree() {
    this->combustiveDegree++;
}

void Chemical::decreaseDegree() {
    this->combustiveDegree--;
}

bool Chemical::isChemCombustive() {
    return getType() == "c";
}

bool Chemical::isPlaceCombustive() {
    return this->combustiveDegree > 0;
}