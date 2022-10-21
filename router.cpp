//
// Created by 秦梓烈 on 14/10/2022.
//
#include <iostream>
#include <algorithm>
#include "router.h"
#include <queue>
#include <unordered_set>
using namespace std;


Router::Router(string ipAddress, Router* rootNode):rootNode(rootNode) {
    this->IpAddress = ipAddress;
    std::cout << "Creating a new router whose IP address is " << ipAddress << std::endl;
}
Router::~Router() {

}

// root->existInTree();

bool Router::existInTree(Equipment* new_equipment) {
    
    if (this->getIpAddress() == new_equipment->getIpAddress()) {
        return true;
    } 
    bool exist;
    for (Equipment* e : this->subEquipments){
        exist = e->existInTree(new_equipment);
    }

    return exist;
}

void Router::addSubEquipment(Equipment *equipment) {
    bool existAlready = rootNode->existInTree(equipment);
    if (existAlready) {
        cout << "exist already" << endl;
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
        std::cout << "Removing a subRouter from router" + this -> IpAddress << endl;
    } else {
        std::cout << "Removing a subComputer from" + this -> IpAddress << endl;
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
    cout << IpAddress << ": My subequipments are" << endl;
    for (Equipment *e: subEquipments) {
        if (e->isComposite()) {
            cout << "router : " << e->getIpAddress() << endl;
        } else {
            cout << "computer : " << e -> getIpAddress() << endl;
        }
        
    }
    //cout << endl;
}
string Router::getIpAddress() {
    return this -> IpAddress;
}

string Router::showFigure() {
    string result;
    for (Equipment *e : subEquipments) {
        if (e == subEquipments.back()) {
            if (e->isComposite()) {
                result = result + " Router " + e->getIpAddress() + e->showFigure();
            } else {
                result = result + e -> showFigure();
            }
        } else {
            if (e->isComposite()) {
                result = result + "Router " + e->getIpAddress() + e->showFigure() + " + ";
            } else {
                result = result + e -> showFigure() + " + ";
            }
        }
    }

    return " -> Branch" + (string)"\n" + (string)"(" +result + (string)")";
}