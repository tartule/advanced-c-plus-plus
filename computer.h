//
// Created by 秦梓烈 on 14/10/2022.
//

#ifndef ADVANCED_C_PLUS_PLUS_COMPUTER_H
#define ADVANCED_C_PLUS_PLUS_COMPUTER_H
#include "equipment.h"

class Computer : public Equipment{
private:
    string IpAddress;
    Equipment* rootNode;
public:
    Computer(string ipAddress, Equipment* rootNode);
    ~Computer();
    void processMessage(string message) ;
    bool isComposite();
    string getIpAddress();
    virtual bool existInTree(Equipment* new_equipment);
    string showFigure();
};


#endif //ADVANCED_C_PLUS_PLUS_COMPUTER_H
