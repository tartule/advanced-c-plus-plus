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
    std::list<Equipment *> subEquipments
public:
    Router(string ipAddress);
    ~Router();
    string processMessage(string message) override final;
    void addSubEquipment(Equipment *equipment) override final;
    void removeSubEquipment(Equipment *equipment) override final;
    void showSubEquipment() override final;
};


#endif //ADVANCED_C_PLUS_PLUS_ROUTER_H
