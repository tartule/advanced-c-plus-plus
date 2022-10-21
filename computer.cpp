//
// Created by 秦梓烈 on 14/10/2022.
//

#include "computer.h"
#include "iostream"

Computer::Computer(string ipAddress) {
    this-> IpAddress = ipAddress;
    std::cout << "Creating a new computer whose IpAddress is " + IpAddress << endl;
}

Computer::~Computer(){
    std::cout << "Destroying a computer whose IpAddress is "  + this-> IpAddress << endl;
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

string Computer::showFigure() {
    return "Computer " +getIpAddress();
}