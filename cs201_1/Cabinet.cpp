//Erkin Aydın 22002956
#include <iostream>
using namespace std;
#include "Cabinet.h"

Cabinet::Cabinet() {
    id = -1;
    rowDimension = -1;
    columnDimension = -1;
    emptyPlaces = -1;
    chems = NULL;//PORBLEM
}

Cabinet::Cabinet( int idInput, int rowDimensionInput, int columnDimensionInput) {
    id = idInput;
    rowDimension = rowDimensionInput;
    columnDimension = columnDimensionInput;
    emptyPlaces = columnDimension * rowDimension;
    chems = new Chemical**[rowDimension];
    for(int i = 0; i < rowDimension; i++) {
        chems[i] = new Chemical*[columnDimension];
        for(int j = 0; j < columnDimension; j++) {
            chems[i][j] = new Chemical( -1, "+");
        }
    }
}

Cabinet::~Cabinet() {
    for(int i = 0; i < rowDimension; i++) {
        for (int j = 0; j < rowDimension; j++)
            delete[] chems[i][j];//Segmentation Fault
        delete[] chems[i];
    }
    delete[] chems;
}

bool Cabinet::isPlaceCombustive( int rowIndex, int columnIndex) {
    return chems[rowIndex][columnIndex]->isPlaceCombustive();
}

string Cabinet::getChemType(int rowIndex, int columnIndex) {
    return chems[rowIndex][columnIndex]->getType();
}

int Cabinet::getId() {
    return id;
}

int Cabinet::getChemId( int rowIndex, int columnIndex) {
    return chems[rowIndex][columnIndex]->getId();
}

void Cabinet::displayDimensions() {
    cout << rowDimension << "x" << columnDimension;
}

void Cabinet::operator=(Cabinet c) {
    id = c.getId();
    rowDimension = c.numOfRows();
    columnDimension = c.numOfColumns();
    emptyPlaces = c.numOfEmptySlots();
    for(int i = 0; i < rowDimension; i++)
        for(int j = 0; j < columnDimension; j++)
            chems[i][j] = c.chems[i][j]; //InvalidRead
}

int Cabinet::numOfEmptySlots() {
    return emptyPlaces;
}

int Cabinet::numOfRows() {
    return rowDimension;
}

int Cabinet::numOfColumns() {
    return columnDimension;
}

void Cabinet::placeChemical( int rowIndex, int columnIndex, int id, string type) {
    chems[rowIndex][columnIndex]->setType(type);
    chems[rowIndex][columnIndex]->setId(id);
    if(chems[rowIndex][columnIndex]->getType() == "c") {
        for(int i = 0; i < numOfRows(); i++)
            for(int j = 0; j < numOfColumns(); j++) {
                int rowChecker = rowIndex - i;
                int columnChecker = columnIndex - j;
                if(rowChecker < 0)
                    rowChecker = -rowChecker;
                if(columnChecker < 0)
                    columnChecker = -columnChecker;
                if (rowChecker<=1 && columnChecker<=1)
                    chems[i][j]->increaseDegree();
            }
    }
    emptyPlaces--;
}

void Cabinet::removeChemical(int rowIndex, int columnIndex) {
    if(chems[rowIndex][columnIndex]->getType() == "c") {
        for (int i = 0; i < numOfRows(); i++)
            for (int j = 0; j < numOfColumns(); j++) {
                int rowChecker = rowIndex - i;
                int columnChecker = columnIndex - j;
                if(rowChecker < 0)
                    rowChecker = -rowChecker;
                if(columnChecker < 0)
                    columnChecker = -columnChecker;
                if (rowChecker<=1 && columnChecker<=1)
                    chems[i][j]->decreaseDegree();
            }
    }
    chems[rowIndex][columnIndex]->setType("+");
    chems[rowIndex][columnIndex]->setId(-1);
    emptyPlaces++;
}