// Erkin Aydın 22002956

#include <iostream>
#include "Flower.h"
using namespace std;

Flower::Flower() {
    size = 0;
    head = NULL;
}

Flower::Flower(string flowerName) {
    size = 0;
    this->flowerName = flowerName;
    head = NULL;
}


// This code has parts from slides.
Flower::Flower(const Flower &aFlower) {
    //This part is from slides
    size = aFlower.size;
    flowerName = aFlower.flowerName;
    if(aFlower.head == NULL) {
        head = NULL;
    }
    else {
        head = new FeatureNode;
        head->feature = aFlower.head->feature;
        FeatureNode* newPtr = head;
        for(FeatureNode* cur = aFlower.head->next; cur != NULL; cur = cur->next) {
            newPtr->next = cur;
            newPtr = newPtr->next;
            newPtr->feature = cur->feature;
        }
        newPtr->next = NULL;
    }
    // The part form slides ended
}


//It deallocates everything on the feature linked list
Flower::~Flower() {
    while(head != NULL) {
        FeatureNode* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }
}

//Returns 1 if the total number of features is 0, if not, returns 1.
bool Flower::isEmpty() const {
    return getLength() == 0;// return size == 0; ???
}

//Returns the number of features.
int Flower::getLength() const {
    return size;//?
}

// Adds a feature to the feature linked list in lexicographic order.
bool Flower::add(string feature) {
    FeatureNode* prev;
    FeatureNode* cur;
    for(prev = NULL, cur = head; (cur != NULL)&&(feature >= cur->feature); prev = cur, cur = cur->next){ //PROBLEM
        if(feature == cur->feature) {
            return false; // if feature == cur->feature, then the feature already exists in the linked list
        }
    }//23. slide
    FeatureNode* newPtr = new FeatureNode;
    newPtr->feature = feature;
    if(prev == NULL) { // Placing at the beginning of the linked list
        newPtr->next = head;
        head = newPtr;
    }
    /*To this part, writing else if(cur == NULL) is better, as it is an else if statement and prev == NULL is eliminated
     * in the previous part
    */
    else if(prev != NULL && cur == NULL) { // Placing at the end of the linked list
        newPtr->next = NULL;
        prev->next = newPtr;
    }
    /*To this part, writing else if(cur != NULL) is better, as it is an else if statement and prev == NULL is eliminated
    * in the previous part
    */
    else if(prev != NULL && cur != NULL){ // Placing at the middle of the linked list
        newPtr->next = cur;
        prev->next = newPtr;
    }
    else {
        cout << "puppe" << endl;
    }
    return true;
}

//Removes a particular feature from the linked list
bool Flower::remove(string feature) {
    FeatureNode* prev;
    FeatureNode* cur;
    for(prev = NULL, cur = head; (cur != NULL); prev = cur, cur = cur->next){
        if(cur->feature == feature) {
            if(prev == NULL) {
                head = cur->next;
            }
            else {
                prev->next = cur->next;
            }
            delete cur;
            return true;
        }
    }//23. slide
    return false;
}

//Print features of the flower
string Flower::printFlower() const {
    string output = flowerName;
    output += ": ";
    if(head == NULL) {
        output += "No feature";
    }
    else {
        for (FeatureNode* ptr = head; ptr != NULL; ptr = ptr->next) {// Order is problematic
            output += ptr->feature;
            if (ptr->next != NULL) {
                output += ", ";
            }
        }
    }
    return output;
}

string Flower::getName() const {
    return flowerName;
}

void Flower::setSize(int size) {
    this->size = size;
}

void Flower::setName(string name) {
    flowerName = name;
}

void Flower::operator=(const Flower &aFlower) {
    this->size = aFlower.size;
    this->flowerName = aFlower.flowerName;
    this->head = aFlower.head;
}

bool Flower::hasFeature(string feature) const {
    if(head == NULL) return false;
    for(FeatureNode* cur = head; cur != NULL; cur = cur->next) {
        if(cur->feature == feature) return true;
    }
    return false;
}