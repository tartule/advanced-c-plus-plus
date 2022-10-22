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
    string equipementName=equipment->get_name();
    equipementName[0]=(char) std::toupper(equipementName[0]);//convert the first letter to upper case
    std::cout << "Adding a sub"<<equipementName<<" to router" + this -> IpAddress << endl;

}

void Router::removeSubEquipment(Equipment *equipment) {
    if (find(begin(subEquipments), end(subEquipments), equipment) == end(subEquipments)) {
        return;
    }
    this->subEquipments.remove(equipment);
    string equipementName=equipment->get_name();
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
        cout << e->get_name() << e -> getIpAddress() << endl;
    }
}

string Router::getIpAddress() {
    return this -> IpAddress;
}

string Router::showFigure(int deep) {
    string result;
    for (Equipment *e : subEquipments) {
        if (e == subEquipments.back()) {
            if (e->isComposite()) {
                result = result + " Router " + e->getIpAddress() + e->showFigure(deep+1);
            } else {
                result = result + e -> showFigure(deep+1);
            }
        } else {
            if (e->isComposite()) {
                result = result + "Router " + e->getIpAddress() + e->showFigure(deep+1) + " + ";
            } else {
                result = result + e -> showFigure(deep+1) + " + ";
            }
        }
    }

    string space(deep*2, ' ');

    return " -> Branch" + (string)"\n" + space  + (string)"(" +result + (string)")";
}
string Router::get_name(){
    return "router";
}

void Router::display(){
    display(this, "", "");
} 

void Router::display(Equipment *e, string r, string p) {
    string rs = "Router " + this->getIpAddress();
    cout << r << rs << endl;
    for (Equipment *e : subEquipments) {
        string rr = p + '|' + string(rs.length(), '-') + ' ';
        string pp = p + string(rs.length()+1, ' ');
        if(pp[0] != '|') pp = '|' + pp;
        e->display(e, rr, pp);
    }
}

ostream &operator<<(std::ostream& flot , const Router& p){
    flot << "Router :" << p.IpAddress << " ";
    return flot ;
}