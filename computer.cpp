//
// Created by 秦梓烈 on 14/10/2022.
//

#include "computer.h"
#include "iostream"

Computer::Computer(string ipAddress, Equipment* rootNode) {
    this->rootNode = rootNode;
    this-> IpAddress = ipAddress;
    std::cout << "Creating a new computer whose IpAddress is " + IpAddress << endl;
}

Computer::~Computer(){
    //std::cout << "Destroying a computer and its IpAddress is "  + this-> IpAddress << endl;
}
void Computer::processMessage(string message) {
    cout << "Computer " << IpAddress << " got a message : " << message << endl;
}

bool Computer::isComposite(){
    return false;
}

string Computer::getIpAddress() {
    return this -> IpAddress;
}

// // root->existInTree(root, );
bool Computer::existInTree(Equipment* new_equipment) {
    if (this->getIpAddress() == new_equipment->getIpAddress()) {
        return true;
    } 
    return false;
}

string Computer::showFigure() {
    return "Computer " +getIpAddress();
}