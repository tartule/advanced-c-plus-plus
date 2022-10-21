//
// Created by 秦梓烈 on 14/10/2022.
//

#include "computer.h"
#include "iostream"

Computer::Computer(string ipAddress) {
    this-> IpAddress = ipAddress;
    std::cout << "Creating a new computer and its IpAddress is " + IpAddress << endl;
}

Computer::~Computer(){
    std::cout << "Destroying a computer and its IpAddress is"  + this-> IpAddress << endl;
}
void Computer::processMessage(string message) {
    cout << IpAddress << "got a message" << message << endl;
}

bool Computer::isComposite(){
    return false;
}

string Computer::getIpAddress() {
    return this -> IpAddress;
}