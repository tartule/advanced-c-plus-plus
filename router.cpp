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
    /*for (auto equipment : subEquipments) {
        delete equipment;
    }*/
    //std::cout << "Destroying a router whose IP address is "  + this-> IpAddress << std::endl;
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

//bool Router::existInTree(Equipment* root, Equipment* equipment) {
    // if (!root->isComposite()) {
    //     if (root->getIpAddress() == equipment->getIpAddress()) {
    //         return true;
    //     } else {
    //         return false;
    //     }
    // } else if (root->getIpAddress() == equipment->getIpAddress()) {
    //     return true;
    // }
    // bool exist;
    // exist = existInTree(root->equipment); // subEquipments
 
    // return exist;

    // for (Equipment* e : subEquipments){
    //     if(e->existInTree(equipment)){
    //         return true;
    //     }
    // }
//}

// root->existInTree(root, );
/*bool Router::existInTree1(Equipment* new_equipment) {
    if (this->getIpAddress() == new_equipment->getIpAddress()) {
        return true;
    } 
    for (Equipment* e : this->subEquipments){    
        if(e->existInTree1(new_equipment))
            return true;
    }
    return false;
}*/


void Router::addSubEquipment(Equipment *equipment) {
    /*if (find(begin(subEquipments), end(subEquipments), equipment) != end(subEquipments)) {
        return;
    }*/

    // bool existAlready = root->existInTree();

    //bool existAlready = existInTree(rootNode, equipment);
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

void Router::showTree() {
    // show root
    //cout << endl;
    /*if (this->isComposite()) {
        cout << "router : " << IpAddress << endl;
    } else {
        cout << "computer : " << IpAddress << endl;
        return;
    }
    
    for (auto child : subEquipments) {
        if (child->isComposite()) {
            //cout << "router : " << child->getIpAddress() << endl; 
            child->showTree();
        } else {
            cout << "computer : " << child->getIpAddress() << endl;
        }
    }*/

}