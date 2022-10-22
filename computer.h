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

    bool animation;
    bool got_msg;
public:
    Computer(string ipAddress, Equipment* rootNode);
    ~Computer();
    void processMessage(string message) ;
    bool isComposite();
    string getIpAddress();
    string getName();
    string getNetworkSummary(int deep);
    bool existInTree(Equipment* new_equipment);
    void display(Equipment *e, string prefix_son, string prefix_descendant);
    
    friend std::ostream& operator<< (std::ostream& flot , const Computer& p);
};


#endif //ADVANCED_C_PLUS_PLUS_COMPUTER_H
