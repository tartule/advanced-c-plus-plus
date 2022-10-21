//
// Created by 秦梓烈 on 14/10/2022.
//

#ifndef ADVANCED_C_PLUS_PLUS_EQUIPMENT_H
#define ADVANCED_C_PLUS_PLUS_EQUIPMENT_H


class Equipment {
    virtual string processMessage(string message) = 0;
    virtual void addSubEquipment(Equipment *equipment) = 0;
    virtual void removeSubEquipment(Equipment *equipment) = 0;
    virtual void showSubEquipment() = 0;
    virtual bool isComposite() = 0;
};


#endif //ADVANCED_C_PLUS_PLUS_EQUIPMENT_H
