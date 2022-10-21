//
// Created by 秦梓烈 on 14/10/2022.
//
#ifndef ADVANCED_C_PLUS_PLUS_EQUIPMENT_H
#define ADVANCED_C_PLUS_PLUS_EQUIPMENT_H
#include <string>
#include <list>

using namespace std;

class Equipment {
public:
    virtual ~Equipment(){};
    
    virtual string getIpAddress() = 0;
    //virtual list<Equipment *> getChildren(){};

    virtual bool isComposite() = 0;

    virtual void processMessage(string message) = 0;
    virtual void addSubEquipment(Equipment *equipment){} ;
    virtual void removeSubEquipment(Equipment *equipment){} ;
    virtual void showSubEquipment(){} ;
    virtual bool existInTree(Equipment *equipment)= 0;
    virtual string showFigure(int deep) = 0;

    virtual void display(Equipment *e, string r, string p) = 0;
};


#endif //ADVANCED_C_PLUS_PLUS_EQUIPMENT_H
