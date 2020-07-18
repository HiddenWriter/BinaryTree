#pragma once
class ItemType{
public:

    ItemType();
    ~ItemType();
        
    void SetID(int _id);
    void SetName(std::string _name);
    void SetIDFromUser();
    void SetNameFromUser();
    void SetAllRecord(int _id, std::string _name);
    void SetAllRecordFromUser();
    int GetID();
    std::string GetName();

    // operator overloading
    bool operator==(ItemType _item) {
        if(this->GetID() == _item.GetID()) {
            return true;
        }
        else {
            return false;
        }
    }
    void operator=(ItemType _item) {
        this->SetID(_item.GetID());
        this->SetName(_item.GetName());
        return;
    }
    bool operator<(ItemType _item) {
        if(this->GetID() < _item.GetID()) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator>(ItemType _item) {
        if(this->GetID() > _item.GetID()) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator<=(ItemType _item) {
        if(this->GetID() <= _item.GetID()) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator>=(ItemType _item) {
        if(this->GetID() >= _item.GetID()) {
            return true;
        }
        else {
            return false;
        }
    }
    friend std::ostream& operator<<(std::ostream& _os, ItemType _item) {
        std::cout << "\n\t";
        std::cout << "ID   : " << _item.GetID() << "\n\t";
        std::cout << "Name : " << _item.GetName() << '\n';
        return _os;
    }
private:
    std::string mName;
    int mID;
};
