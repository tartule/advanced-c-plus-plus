//
// Created by 秦梓烈 on 14/10/2022.
//

#ifndef ADVANCED_C_PLUS_PLUS_ROUTER_H
#define ADVANCED_C_PLUS_PLUS_ROUTER_H
#include "equipment.h"
#include "list"

class Router : public Equipment{
private:
    string IpAddress;
    std::list<Equipment *> subEquipments;
public:
    Router(string ipAddress);
    ~Router();
    void processMessage(string message) ;
    void addSubEquipment(Equipment *equipment) ;
    void removeSubEquipment(Equipment *equipment) ;
    void showSubEquipment() ;
    bool isComposite();
    string getIpAddress();
};


#endif //ADVANCED_C_PLUS_PLUS_ROUTER_H
