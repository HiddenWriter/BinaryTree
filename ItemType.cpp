#include "pch.h"
#include "ItemType.h"

ItemType::ItemType() {
    this->mName = "DEFAULT";
    this->mID = -1;
    return;
}

ItemType::~ItemType(){
    return;
}

void ItemType::SetID(int _id) {
    this->mID = _id;
    return;
}

void ItemType::SetName(std::string _name) {
    this->mName = _name;
    return;
}

void ItemType::SetIDFromUser() {
    std::cout << "\n\t ID : ";
    std::cin >> this->mID;
    return;
}

void ItemType::SetNameFromUser() {
    std::cout << "\n\t NAME : ";
    std::cin >> this->mName;
    return;
}

void ItemType::SetAllRecord(int _id, std::string _name) {
    SetID(_id);
    SetName(_name);
    return;
}

void ItemType::SetAllRecordFromUser() {
    SetIDFromUser();
    SetNameFromUser();
    return;
}

int ItemType::GetID() {
    return this->mID;
}

std::string ItemType::GetName() {
    return this->mName;
}