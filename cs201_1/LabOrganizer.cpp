//Erkin Aydın 22002956
#include <iostream>
using namespace std;
#include "LabOrganizer.h"
#include "Cabinet.h"

LabOrganizer::LabOrganizer() {
    numOfCabinets = 0;
    rowArray = new char[9];
    for(int i = 0; i < 9; i++) {
        switch (i) {
            case 0:rowArray[i] = 'A';break;
            case 1:rowArray[i] = 'B';break;
            case 2:rowArray[i] = 'C';break;
            case 3:rowArray[i] = 'D';break;
            case 4:rowArray[i] = 'E';break;
            case 5:rowArray[i] = 'F';break;
            case 6:rowArray[i] = 'G';break;
            case 7:rowArray[i] = 'H';break;
            case 8:rowArray[i] = 'I';break;
            default: break;
        }
    }
    cabinets = NULL;
}

LabOrganizer::~LabOrganizer() {
    for(int i = 0; i < numOfCabinets; i++)
        delete[] cabinets[i];
    delete[] cabinets;
    delete[] rowArray;
}

void LabOrganizer::addCabinet(int id, int rows, int columns) {

    if (rows > 9 || rows <= 0 || columns > 9 || columns <= 0) {
        cout << "Cannot add the cabinet: dimensions are out of bounds" << endl;
        return;
    }
    if(numOfCabinets > 0) {
        for (int i = 0; i < numOfCabinets; i++){
            if (cabinets[i]->getId() == id) {
                cout << "Cannot add the cabinet: ID " << id << " is already at the system" << endl;
                return;
            }
        }
        Cabinet** newCabinets = new Cabinet*[numOfCabinets + 1];
        Cabinet* newCabinet =  new Cabinet( id, rows, columns);
        for(int i = 0; i < numOfCabinets; i++) {
            newCabinets[i] = cabinets[i];
        }
        newCabinets[numOfCabinets] = newCabinet;
        delete[] cabinets;
        cabinets = newCabinets;
        numOfCabinets++;
        cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << endl;
    }
    else {
        cabinets = new Cabinet*[1];
        cabinets[0] = new Cabinet( id, rows, columns);
        numOfCabinets++;
        cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << endl;
    }
}

void LabOrganizer::removeCabinet(int id) {
    if(numOfCabinets == 0) {
        cout << "There is no cabinet to remove" << endl;
        return;
    }
    for(int i = 0; i < numOfCabinets; i++) {
        if(cabinets[i]->getId() == id) {
            for(int j = 0; j < cabinets[i]->numOfRows(); j++) {
                for(int k = 0; k < cabinets[i]->numOfColumns(); k++){
                    if(cabinets[i]->getChemType(j,k) != "+")
                        cout << "Chemical " << cabinets[i]->getChemId(j,k) << " has been removed from the system" << endl;
                    cabinets[i]->removeChemical( j, k);
                }
            }
            Cabinet** newCabinets = new Cabinet*[numOfCabinets - 1];
            for(int j = 0; j < i; j++) {
                newCabinets[j] = cabinets[j];
            }
            for(int k = i + 1; k < numOfCabinets; k++) {
                newCabinets[k - 1] = cabinets[k];
            }
            delete[] cabinets;
            cabinets = newCabinets;
            numOfCabinets--;
            cout << "Cabinet " << id << " has been removed" << endl;
            return;
        }
    }
    cout << "Cabinet " << id << " is not in the system" << endl;
}

void LabOrganizer::listCabinets() {
    for(int i = 0; i < numOfCabinets; i++) {
        cout << "ID: " << cabinets[i]->getId() << ", Dim: ";
        cabinets[i]->displayDimensions();
        cout << ", Number of empty slots: " << cabinets[i]->numOfEmptySlots() << endl;
    }
}

void LabOrganizer::cabinetContents(int id) {
    for(int i = 0; i < numOfCabinets; i++) {
        if( id == cabinets[i]->getId()) {
            cout << "ID: " << cabinets[i]->getId() << ", Dim: ";
            cabinets[i]->displayDimensions();
            cout << ", Number of empty slots: " << cabinets[i]->numOfEmptySlots() << endl;
            cout << " ";
            for(int j = 1; j <= cabinets[i]->numOfColumns(); j++)
                cout << " " << j;
            cout << endl;
            for (int k = 0; k < cabinets[i]->numOfRows(); k++) {
                cout << rowArray[k];
                for(int l = 0; l < cabinets[i]->numOfColumns(); l++) {
                    cout << " " << cabinets[i]->getChemType( k, l);
                }
                cout << endl;
            }
            return;
        }
    }
    cout << "A cabinet with id " << id << " does not exist in the system" << endl;
}

void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID) {
    bool isChemUnique = true;
    bool isLocationEmpty = true;
    bool doesCabinetExist = false;
    bool canCombustivePlaced = true;
    for(int i = 0; i < numOfCabinets; i++) {
        if (cabinets[i]->getId() == cabinetId)
            doesCabinetExist = true;
        for(int j = 0; j < cabinets[i]->numOfRows(); j++)
            for(int k = 0; k < cabinets[i]->numOfColumns(); k++)
                if(cabinets[i]->getChemId(j,k) == chemID)
                    isChemUnique = false;

    }
    if(!doesCabinetExist) {
        cout << "No such cabinet exists in the system";
        return;
    }
    else if(!isChemUnique) {
        cout << "Chemical with ID " << chemID << " already exists in the system" << endl;
        return;
    }
    int row = 0;
    int column = 0;
    for(int i = 0; i < numOfCabinets; i++) {
        if (cabinets[i]->getId() == cabinetId) {
            for (int t = 0; t < 9; t++) {
                if (location[0] == rowArray[t]) {
                    row = t;
                    break;
                }
            }
            if(location[1] == 1){

            }
            switch (location[1]) {
                case '1':column = 0;break;
                case '2':column = 1;break;
                case '3':column = 2;break;
                case '4':column = 3;break;
                case '5':column = 4;break;
                case '6':column = 5;break;
                case '7':column = 6;break;
                case '8':column = 7;break;
                case '9':column = 8;break;
            }
            if(cabinets[i]->getChemType(row,column) != "+")
                isLocationEmpty = false;
            if((cabinets[i]->isPlaceCombustive(row,column))||cabinets[i]->getChemType(row,column) == "c")
                canCombustivePlaced = false;
        }
    }
    if(!isLocationEmpty) {
        cout << "Location " << location << " in cabinet " << cabinetId << " is already occupied. Nearest possible locations are: ";
        if(chemType == "combustive") {
            for(int i = 0; i < numOfCabinets; i++)
                if(cabinets[i]->getId()==cabinetId)
                    for(int j = 0; j < cabinets[i]->numOfRows(); j++)
                        for(int k = 0; k < cabinets[i]->numOfColumns(); k++) {
                            int rowChecker = row - j;
                            int columnChecker = column - k;
                            if(rowChecker<0)
                                rowChecker = -rowChecker;
                            if(columnChecker<0)
                                columnChecker = -columnChecker;
                            if (rowChecker<=1&&columnChecker<=1&&!(row == j && column == k)&&!cabinets[i]->isPlaceCombustive(j, k)
                                && cabinets[i]->getChemType(j, k) == "+" &&
                                cabinets[i]->getId() == cabinetId)
                                cout << " " << rowArray[j] << (k + 1);
                        }
            cout << endl;
            return;
        }
        else {
            for(int i = 0; i < numOfCabinets; i++)
                if(cabinets[i]->getId()==cabinetId)
                    for(int j = 0; j < cabinets[i]->numOfRows(); j++)
                        for(int k = 0; k < cabinets[i]->numOfColumns(); k++) {
                            int rowChecker = row - j;
                            int columnChecker = column - k;
                            if(rowChecker<0)
                                rowChecker = -rowChecker;
                            if(columnChecker<0)
                                columnChecker = -columnChecker;
                            if (rowChecker<=1&&columnChecker<=1&&!(row == j && column == k)&&cabinets[i]->getChemType(j, k) == "+"
                                && cabinets[i]->getId() == cabinetId)
                                cout << " " << rowArray[j] << (k + 1);
                        }
            cout << endl;
            return;
        }
    }
    else if(chemType == "combustive" && !canCombustivePlaced) {
        cout << "Location " << location << " in cabinet " << cabinetId << " is not suitable for a combustive chemical: Nearest possible locations are: ";
        for(int i = 0; i < numOfCabinets; i++)
            if(cabinets[i]->getId()==cabinetId)
                for(int j = 0; j < cabinets[i]->numOfRows(); j++)
                    for(int k = 0; k < cabinets[i]->numOfColumns(); k++) {
                        int rowChecker = row - j;
                        int columnChecker = column - k;
                        if(rowChecker<0)
                            rowChecker = -rowChecker;
                        if(columnChecker<0)
                            columnChecker = -columnChecker;
                        if (rowChecker<=1&&columnChecker<=1&&!(row == j && column == k)&&!cabinets[i]->isPlaceCombustive(j, k)
                            && cabinets[i]->getChemType(j, k) == "+" && cabinets[i]->getId() == cabinetId)
                            cout << " " << rowArray[j] << (k + 1);
                    }
        cout << endl;
        return;
    }
    else {
        for(int i = 0; i < numOfCabinets; i++) {
            if(cabinets[i]->getId() == cabinetId) {
                cabinets[i]->placeChemical(row, column, chemID, chemType);
                cout << chemType << " chemical with ID " << chemID << " has been placed at location ";
                cout << rowArray[row] << (column+1) << " at cabinet " << cabinetId << endl;
            }
        }
    }
}

void LabOrganizer::findChemical(int id) {
    for(int i = 0; i < numOfCabinets; i++) {
        for(int j  = 0; j < cabinets[i]->numOfRows(); j++) {
            for(int k = 0; k < cabinets[i]->numOfColumns(); k++) {
                if(cabinets[i]->getChemId( j, k) == id) {
                    cout << "Chemical " << id << " is at location " << rowArray[j] << (k+1) << " in cabinet " << cabinets[i]->getId() << endl;
                    return;
                }
            }
        }
    }
    cout << "Chemical " << id << " is not at the system" << endl;
}

void LabOrganizer::removeChemical(int id) {
    for(int i = 0; i < numOfCabinets; i++)
        for(int j = 0; j < cabinets[i]->numOfRows(); j++)
            for(int k = 0; k < cabinets[i]->numOfColumns(); k++)
                if(cabinets[i]->getChemId( j, k) == id) {
                    cabinets[i]->removeChemical( j, k);
                    cout << "Chemical " << id << " has been removed from the system" << endl;
                    return;
                }
    cout << "Chemical " << id << " is not in the system" << endl;
}