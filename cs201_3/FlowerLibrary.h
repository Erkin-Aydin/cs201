//Erkin Aydın 22002956

#ifndef ASSIGNMENT_3_FLOWERLIBRARY_H
#define ASSIGNMENT_3_FLOWERLIBRARY_H

#include "FlowerList.h"
class FlowerLibrary{
public:
    FlowerLibrary();
    ~FlowerLibrary();
    void addFlower(string name);
    void removeFlower(string name);
    void listFlowers() const;
    void listFeatures(string name) const;
    void addFeature(string name,string feature);
    void removeFeature(string name, string feature);
    void findFlowers(string feature) const;
    string toLower(string word) const;
private:
    FlowerList flowers;
    int flowerNum;
};

#endif //ASSIGNMENT_3_FLOWERLIBRARY_H
