//Erkin Aydın 22002956
#ifndef UNTITLED_CABINET_H
#define UNTITLED_CABINET_H

#include <string>
#include "Chemical.h"

using namespace std;

class Cabinet {
public:
    Cabinet();
    Cabinet( int id, int rows, int columns);
    ~Cabinet();

    bool isPlaceCombustive( int rowIndex, int columnIndex);
    string getChemType( int rowIndex, int columnIndex);
    int getId();
    int getChemId( int rowIndex, int columnIndex);
    void displayDimensions();
    void operator=(Cabinet);
    int numOfEmptySlots();
    int numOfRows();
    int numOfColumns();
    void placeChemical( int rowIndex, int columnIndex, int id, string);
    void removeChemical( int rowIndex, int columnIndex);
private:
    int id;
    int rowDimension;
    int columnDimension;
    int emptyPlaces;
    static const int maxDimensions = 9;
    Chemical*** chems;
};
#endif