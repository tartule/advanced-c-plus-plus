#include <iostream>
#include "router.h"
#include "computer.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << "=======================Start========================\n";
    
    Router routerRoot("192.168.1.1", &routerRoot);
    
    Router router2("192.168.1.2", &routerRoot);
    Router router3("192.168.1.3", &routerRoot);
    Computer computer1("192.168.1.6", &routerRoot);
    
    routerRoot.addSubEquipment(&router2);
    routerRoot.addSubEquipment(&router3);
    routerRoot.addSubEquipment(&computer1);

    Router router4("192.168.1.4", &routerRoot);
    Computer computer2("192.168.1.7", &routerRoot);

    router2.addSubEquipment(&computer2);
    router2.addSubEquipment(&router4);

    Computer computer3("192.168.1.8", &routerRoot);
    Computer computer4("192.168.1.9", &routerRoot);

    router3.addSubEquipment(&computer3);
    router3.addSubEquipment(&computer4);
    
    Router router5("192.168.1.5", &routerRoot);
    Computer computer5("192.168.1.10", &routerRoot);
    Computer computer6("192.168.1.11", &routerRoot);   

    router4.addSubEquipment(&computer5);
    router4.addSubEquipment(&router5);
    router5.addSubEquipment(&computer6);

    string broadcast_message = "hello world";
    routerRoot.processMessage(broadcast_message);

    // get children
    routerRoot.showSubEquipment();
    router2.showSubEquipment();
    router3.showSubEquipment();
    router4.showSubEquipment();
    router5.showSubEquipment();
    cout << endl;

    cout << "==============================================================Figure========================================================" << endl;
    cout << "Router " + routerRoot.getIpAddress();
    cout << routerRoot.showFigure() << endl;
    cout << "==============================================================Figure========================================================" << endl;

}