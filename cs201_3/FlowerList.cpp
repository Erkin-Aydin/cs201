// Erkin Aydın 22002956

#include "FlowerList.h"
#include <iostream>

FlowerList::FlowerList() {
    size = 0;
    head = NULL;
}

FlowerList::FlowerList(const FlowerList &aList) {
    size = aList.getLength();
    if(aList.head == NULL) {
        head == NULL;
    }
    else {
        head = new FlowerNode;
        head->f = aList.head->f;
        FlowerNode* newPtr = head;
        for(FlowerNode* cur = aList.head->next; cur != NULL; cur = cur->next) {
            newPtr->next = new FlowerNode;
            newPtr = newPtr->next;
            newPtr->f = cur->f;
        }
        newPtr->next = NULL;
    }
}

FlowerList::~FlowerList() {
    if(head != NULL) {
        while(head != NULL) {
            FlowerNode* toBeRemovedNext = head->next;
            delete head;
            head = toBeRemovedNext;
        }
    }
}

bool FlowerList::isEmpty() const {
    return size == 0;
}

int FlowerList::getLength() const {
    return size;
}

bool FlowerList::retrieve(string flowerName, Flower &flower) const {
    for(FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        if(cur->f.getName() == flowerName) {
            flower = cur->f;
            return true;
        }
    }
    return false;
}

bool FlowerList::add(string flowerName) {
    FlowerNode* prev = NULL;
    FlowerNode* cur = NULL;
    string newFlowerName = "";
    for(int i = 0; i < flowerName.length(); i++) {
        newFlowerName += tolower(flowerName[i]);
    }
    for(prev = NULL, cur = head; (cur != NULL)&&(newFlowerName >= cur->f.getName()); prev = cur, cur = cur->next) {
        if( newFlowerName == cur->f.getName()) {
            return false;
        }
    }
    FlowerNode* newFlower = new FlowerNode;
    newFlower->f = Flower(newFlowerName); // MemoryLeak?????????????
    if( prev == NULL) {
        newFlower->next = cur;
        head = newFlower;
    }
    else if(cur != NULL) {
        newFlower->next = cur;
        prev->next = newFlower;
    }
    else if(cur == NULL) {
        newFlower->next = NULL;
        prev->next = newFlower;
    }
    return true;
}

bool FlowerList::remove(string flowerName) {
    FlowerNode* prev;
    FlowerNode* cur;
    for(prev = NULL, cur = head; cur != NULL; prev = cur, cur = cur->next) {
        if(flowerName == cur->f.getName()) {
            if(prev == NULL) {
                head = head->next;
            }
            else {
                prev->next = cur->next;
            }
            delete cur;
            return true;
        }
    }
    return false;
}

bool FlowerList::toGetFlower(string flowerName, Flower *&flowerPtr) const{
    for(FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        if(cur->f.getName() == flowerName) {
            flowerPtr = &(cur->f);
            return true;
        }
    }
    return false;
}

string FlowerList::flowersWithFeature(string feature) const{
    string names = "";
    for(FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        if(cur->f.hasFeature(feature)) names += cur->f.getName() + ", ";
    }
    if(names == "") names += "there is no such flower";
    return names;
}

void FlowerList::listOfFlowers() const{
    for(FlowerNode* cur = head; cur != NULL; cur = cur->next) {
        cout << cur->f.printFlower() << endl;
    }
}