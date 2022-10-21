//
// Created by 秦梓烈 on 14/10/2022.
//

#include "computer.h"
#include "iostream"

Computer::Computer(string ipAddress) {
    this-> IpAddress = ipAddress;
    std::cout << "Creating a new computer and its IpAddress is " + ipAddress << endl;
}

Computer::~Computer(){
    std::cout << "Destroying a computer and its IpAddress is"  + this-> IpAddress << endl;
}
void Computer::processMessage(string message) {
    if (message == this->IpAddress) {
        std::cout << "I am " + message << endl;
    } else {
        std::cout << "I am not" + message << endl;
    }
}

bool Computer::isComposite(){
    return false;
}

string Computer::getIpAddress() {
    return this -> IpAddress;
}