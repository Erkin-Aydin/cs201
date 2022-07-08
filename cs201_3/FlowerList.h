//Erkin Aydın 22002956

#ifndef ASSIGNMENT_3_FLOWERLIST_H
#define ASSIGNMENT_3_FLOWERLIST_H

#include "Flower.h"
class FlowerList{
public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower& flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    bool toGetFlower(string flowerName, Flower*& flowerPtr) const;
    string flowersWithFeature(string feature) const;
    void listOfFlowers() const;
private:
    struct FlowerNode{
        Flower f;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head;
};

#endif //ASSIGNMENT_3_FLOWERLIST_H
