//
// Created by 秦梓烈 on 14/10/2022.
//

#ifndef ADVANCED_C_PLUS_PLUS_ROUTER_H
#define ADVANCED_C_PLUS_PLUS_ROUTER_H
#include "equipment.h"
#include <list>

class Router : public Equipment{
private:
    string IpAddress;
    std::list<Equipment *> subEquipments;
    Router* rootNode;
public:
    Router(string ipAddress, Router* rootNode);
    ~Router();
    void processMessage(string message) ;
    void addSubEquipment(Equipment *equipment) ;
    void removeSubEquipment(Equipment *equipment) ;
    void showSubEquipment() ;
    bool isComposite();
    string getIpAddress();
    bool existInTree(Equipment*);
    string getNetworkSummary(int deep);
    
    void display();
    string getName();

    friend std::ostream& operator<< (std::ostream& flot , const Router& p);

private:
    void display(Equipment *e, string for_son, string p);
};


#endif //ADVANCED_C_PLUS_PLUS_ROUTER_H
