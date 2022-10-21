//
// Created by 秦梓烈 on 14/10/2022.
//
#include <iostream>
#include "router.h"
using namespace std;

Router::Router(string ipAddress) {
    this -> IpAddress = ipAddress;
    std::cout << "Creating a new router which IpAddress is " << ipAddress << std::endl;
}
Router::~Router() {
    /*for (auto equipment : subEquipments) {
        delete equipment;
    }*/
    std::cout << "Destroying a router which IpAddress is "  + this-> IpAddress << std::endl;
}

void Router::addSubEquipment(Equipment *equipment) {
    if (find(begin(subEquipments), end(subEquipments), equipment) != end(subEquipments)) {
        return;
    }
    this -> subEquipments.push_back(equipment);
    if (equipment->isComposite()) {
        std::cout << "Adding a subRouter to router " + this -> IpAddress << std::endl;
    } else {
        std::cout << "Adding a subComputer to router " + this -> IpAddress << std::endl;
    }
}
void Router::removeSubEquipment(Equipment *equipment) {
    if (find(begin(subEquipments), end(subEquipments), equipment) == end(subEquipments)) {
        return;
    }
    this->subEquipments.remove(equipment);
    
    if (equipment->isComposite()) {
        std::cout << "Removing a subRouter from router" + this -> IpAddress;
    } else {
        std::cout << "Removing a subComputer from" + this -> IpAddress;
    }
    //delete equipment;
}

bool Router::isComposite() {
    return true;
}

void Router::processMessage(string message) {
    for (Equipment *e: subEquipments) {
        e->processMessage(message);
    }
}

void Router::showSubEquipment() {
    cout << "My subEquipments are" << endl;
    for (Equipment *e: subEquipments) {
        cout << e -> getIpAddress() + " ";
    }
}
string Router::getIpAddress() {
    return this -> IpAddress;
}