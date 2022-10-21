//
// Created by 秦梓烈 on 14/10/2022.
//

#include "computer.h"
#include "router.h"
#include "iostream"

Computer::Computer(string ipAddress, Equipment* rootNode) {
    this->got_msg = false;
    this->animation = false;
    this->rootNode = rootNode;
    this-> IpAddress = ipAddress;
    std::cout << "Creating a new computer whose IpAddress is " + IpAddress << endl;
}

Computer::~Computer(){
    //std::cout << "Destroying a computer and its IpAddress is "  + this-> IpAddress << endl;
}
void Computer::processMessage(string message) {
    this->got_msg = true;

    if(this->animation){
        cout << string(40, '=')<< endl;
        cout << "Computer " << IpAddress << " got a message : " << message << endl;
        static_cast<Router *>(rootNode)->display();
        cout << string(40, '=')<< endl;
    } else {
        cout << "Computer " << IpAddress << " got a message : " << message << endl;
    }    
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

string Computer::showFigure(int deep) {
    return "Computer " + getIpAddress();
}

void Computer::display(Equipment *e, string r, string p){
    string msg = (this->got_msg) ? "*" : "";
    cout << r << "Computer" << msg << " " << this->IpAddress << endl;
}

std::ostream& operator<< (std::ostream& flot , const Computer& p){
    flot << "Computer :"<< p.IpAddress << std::endl;
    return flot ;
}