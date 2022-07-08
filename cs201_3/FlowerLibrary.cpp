// Erkin Aydın 22002956

#include <iostream>
#include "FlowerLibrary.h"
using namespace std;

FlowerLibrary::FlowerLibrary(){
    flowerNum = 0;
}

FlowerLibrary::~FlowerLibrary(){}

void FlowerLibrary::addFeature(string name, string feature) {
    Flower* luckyFlower;
    string newFlowerName = toLower(name);
    string newFeature = toLower(feature);
    if(!flowers.toGetFlower(newFlowerName, luckyFlower)) {
        cout << newFlowerName << " isn't found in library" << endl;
    }
    else{
        if(!(*luckyFlower).add(newFeature)) {
            cout << newFeature << " already exists in " << newFlowerName << endl;
        }
        else {
            cout << newFeature << " is added into " << newFlowerName << endl;
        }
    }
}

void FlowerLibrary::addFlower(string name) {
    Flower* luckyFlower;
    string newFlowerName = toLower(name);
    if(flowers.toGetFlower(newFlowerName, luckyFlower)) {
        cout << newFlowerName << " cannot be added into the library because it already exists" << endl;
    }
    else{
        flowers.add(newFlowerName); // Problem
        flowerNum++;
        cout << newFlowerName << " has been added into the library." << endl;
    }
}
// Problem
void FlowerLibrary::findFlowers(string feature) const {

    string newFeature = toLower(feature);
    cout << newFeature << " flowers: " << flowers.flowersWithFeature(newFeature) << endl;
}

void FlowerLibrary::listFeatures(string name) const {
    Flower* luckyFlower;
    string newFlowerName = toLower(name);
    if(!flowers.toGetFlower(newFlowerName, luckyFlower)){
        cout << newFlowerName << " isn't found in library" << endl;
    }
    else {
        cout << (*luckyFlower).printFlower() << endl;
    }
}

//Problem
void FlowerLibrary::listFlowers() const {
    flowers.listOfFlowers();
}

void FlowerLibrary::removeFlower(string name) {
    Flower* unluckyFlower;
    string newFlowerName = toLower(name);
    if(!flowers.toGetFlower(newFlowerName, unluckyFlower)) {
        cout << newFlowerName << " cannot be removed because it's not in the library." << endl;
    }
    else {
        flowers.remove(newFlowerName);
        flowerNum--;
        cout << newFlowerName << " has been removed from the library" << endl;
    }
}

void FlowerLibrary::removeFeature(string name, string feature) {
    Flower* unluckyFlower;
    string newFlowerName = toLower(name);
    string newFeature = toLower(feature);
    if(!flowers.toGetFlower(newFlowerName, unluckyFlower)) {
        cout << newFlowerName << " does not exist in the library" << endl;
    }
    else {
        if(!(*unluckyFlower).remove(newFeature)) {
            cout << feature << " doesn't exist in " << name << endl;
        }
        else {
            cout << feature << " is removed from " << name << endl;
        }
    }
}

string FlowerLibrary::toLower(string word) const {
    string newWord = "";
    for(int i = 0; i < word.length(); i++) {
        newWord += tolower(word[i]);
    }
    return newWord;
}