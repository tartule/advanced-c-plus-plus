//
// Created by 秦梓烈 on 14/10/2022.
//
#ifndef ADVANCED_C_PLUS_PLUS_EQUIPMENT_H
#define ADVANCED_C_PLUS_PLUS_EQUIPMENT_H
#include <string>

using namespace std;

class Equipment {
public:
    virtual void processMessage(string message) = 0;
    virtual void addSubEquipment(Equipment *equipment){} ;
    virtual void removeSubEquipment(Equipment *equipment){} ;
    virtual void showSubEquipment(){} ;
    virtual bool isComposite() = 0;
    virtual string getIpAddress() = 0;
    virtual ~Equipment(){};
    virtual string showFigure() = 0;
};


#endif //ADVANCED_C_PLUS_PLUS_EQUIPMENT_H
