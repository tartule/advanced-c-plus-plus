#include <iostream>
#include "router.h"
#include "computer.h"
using namespace std;

int main() {
    cout << "=======================Start========================";
    Router routerRoot("192.168.1.1");
    Router router2("192.168.1.2");
    Router router3("192.168.1.3");
    Router router4("192.168.1.4");
    Router router5("192.168.1.5");
    Computer computer1("192.168.1.6");
    Computer computer2("192.168.1.7");
    Computer computer3("192.168.1.8");
    Computer computer4("192.168.1.9");
    Computer computer5("192.168.1.10");
    Computer computer6("192.168.1.11");
    routerRoot.addSubEquipment(router2);
    routerRoot.addSubEquipment(router3);
    routerRoot.addSubEquipment(computer1);
    router2.addSubEquipment(computer2);
    router2.addSubEquipment(router4);
    router3.addSubEquipment(computer3);
    router3.addSubEquipment(computer4);
    router4.addSubEquipment(computer5);
    router4.addSubEquipment(router5);
    router5.addSubEquipment(computer6);


}