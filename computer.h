//
// Created by 秦梓烈 on 14/10/2022.
//

#ifndef ADVANCED_C_PLUS_PLUS_COMPUTER_H
#define ADVANCED_C_PLUS_PLUS_COMPUTER_H
#include "equipment.h"

class Computer : public Equipment{
private:
    string IpAddress;
public:
    Computer(string ipAddress);
    ~Computer();
    void processMessage(string message) override final;
    bool isComposite() override final;
};


#endif //ADVANCED_C_PLUS_PLUS_COMPUTER_H
