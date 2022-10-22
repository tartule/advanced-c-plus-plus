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
    
    for (Equipment* e : this->subEquipments){
        if (e->existInTree(new_equipment)){
            return true;
        }
    }

    return false;
}

void Router::addSubEquipment(Equipment *equipment) {
    bool existAlready = rootNode->existInTree(equipment);
    if (existAlready) {
        cout << "exist already" << endl;
        return;
    }
    this -> subEquipments.push_back(equipment);
    string equipementName=equipment->getName();
    equipementName[0]=(char) std::toupper(equipementName[0]);//convert the first letter to upper case
    std::cout << "Adding a sub"<<equipementName<<" to router" + this -> IpAddress << endl;

}

void Router::removeSubEquipment(Equipment *equipment) {
    if (find(begin(subEquipments), end(subEquipments), equipment) == end(subEquipments)) {
        return;
    }
    this->subEquipments.remove(equipment);
    string equipementName=equipment->getName();
    equipementName[0]=(char) std::toupper(equipementName[0]);//convert the first letter to upper case
    std::cout << "Removing a sub"<<equipementName<<" from router" + this -> IpAddress << endl;

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
        cout << e->getName() << e -> getIpAddress() << endl;
    }
}

string Router::getIpAddress() {
    return this -> IpAddress;
}

string Router::getNetworkSummary(int deep) {
    string result;
    for (Equipment *e : subEquipments) {
        if (e == subEquipments.back()) {
            if (e->isComposite()) {
                result = result + " Router " + e->getIpAddress() + e->getNetworkSummary(deep+1);
            } else {
                result = result + e -> getNetworkSummary(deep+1);
            }
        } else {
            if (e->isComposite()) {
                result = result + "Router " + e->getIpAddress() + e->getNetworkSummary(deep+1) + " + ";
            } else {
                result = result + e -> getNetworkSummary(deep+1) + " + ";
            }
        }
    }

    string space(deep*2, ' ');

    return " -> Branch" + (string)"\n" + space  + (string)"(" +result + (string)")";
}
string Router::getName(){
    return "router";
}

void Router::display(){
    display(this, "", "");
} 

void Router::display(Equipment *e, string prefix_son, string prefix_descendant) {
    string rs = "Router " + this->getIpAddress();
    cout << prefix_son << rs << endl;//is a direct son of parent
    for (Equipment *e : subEquipments) {
        string new_prefix_son = prefix_descendant + '|' + string(rs.length(), '-') + ' ';
        string new_prefix_descendant = prefix_descendant + string(rs.length()+1, ' ');
        
        //make sure that the first line always is | (only works for first iteration)
        if(new_prefix_descendant[0] != '|') new_prefix_descendant = '|' + new_prefix_descendant;
        e->display(e, new_prefix_son, new_prefix_descendant);
    }
}

ostream &operator<<(std::ostream& flot , const Router& p){
    flot << "Router :" << p.IpAddress << " ";
    return flot ;
}