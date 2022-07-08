//Erkin Aydın 22002956

#ifndef ASSIGNMENT_3_FLOWER_H
#define ASSIGNMENT_3_FLOWER_H

#include <string>

using namespace std;

class Flower{
public:
    Flower();
    Flower(string flowerName);
    Flower(const Flower& aFlower);
    ~Flower();
    bool isEmpty() const;
    int getLength() const ;
    bool add(string feature);
    bool remove(string feature);
    string printFlower() const;
    string getName() const;
    void setSize(int size);
    void setName(string name);
    void operator=(const Flower& aFlower);
    bool hasFeature(string feature) const;
//private:
    struct FeatureNode{
        string feature;
        FeatureNode* next;
    };
    int size;
    string flowerName;
    FeatureNode *head;
};

#endif //ASSIGNMENT_3_FLOWER_H
