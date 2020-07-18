#include "pch.h"
#include "Application.h"

Application::Application() {
    this->command = -1;
    return;
}

Application::~Application(){ return; }

int Application::Run() {
	bool isTerminated = false;
	while (!isTerminated) {
		switch (GetCommand()) {
		case 1:
			Add();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Search();
			break;
		case 4:
			Modify();
			break;
		case 5:
			Display();
			break;
		case 6:
			Clear();
			break;
		case 0:
			isTerminated = true;
			break;
		default:
			break;
		}

	}
	return 1;
}

int Application::GetCommand() {
    std::cout << "\t * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    std::cout << "\t * Simple Sorted List Programme.                   *\n";
    std::cout << "\t * 1 : Add data.                                   *\n";
    std::cout << "\t * 2 : Delete data.                                *\n";
    std::cout << "\t * 3 : Search data.                                *\n";
    std::cout << "\t * 4 : Modify Data.                                *\n";
	std::cout << "\t * 5 : Display all data.                           *\n";
	std::cout << "\t * 6 : Clear Tree.                                *\n";
    std::cout << "\t * 0 : Exit.                                       *\n";
	std::cout << "\t * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	std::cout << "\t: ";

    std::cin >> this->command;
    switch (this->command)
    {
    case 1:
        this->command = 1;
        break;
    case 2:
        this->command = 2;
        break;
    case 3:
        this->command = 3;
        break;
    case 4:
        this->command = 4;
        break;
	case 5:
		this->command = 5;
		break;
	case 6:
		this->command = 6;
		break;
	case 7:
		this->command = 7;
		break;
    case 0:
        this->command = 0;
        break;
    default:
        break;
    }
    return this->command;
}

int Application::Add() {
    ItemType temp;
	temp.SetAllRecordFromUser();
	if(ItemList.Add(temp)) { 
		std::cout << "\n\t Successfully Added. \n";
		std::cout << "\n\t Added Item Information : " << temp;
		return 1;
	}
	else {
		std::cout << "\n\t Error. Failed to add the item : " << temp;
		return 0;
	}
}

int Application::Delete() {
    ItemType temp;
	temp.SetIDFromUser();
	if(ItemList.Delete(temp)) {
		std::cout << "\n\t Successfully Deleted. \n";
		std::cout << "\n\t Deleted Item Information : " << temp;
		return 1;
	}
	else {
		std::cout << "\n\t Error. Failed to Delete the item : " << temp;
		return 0;
	}
}

int Application::Search() {
    ItemType temp;
	temp.SetIDFromUser();
	if(ItemList.Search(temp)) {
		return 1;
	}
	else {
		std::cout << "\n\t Error. Failed to search the item : " << temp;
		return 0;
	}
}

int Application::Display() {
    if(ItemList.Display()) { return 1; }
	else { 
		std::cout << "\n\t Nothing to display. \n";
		return 0;
	}
}

int Application::Modify() {
	ItemType temp, old;
	std::cout << "\n\t Enter the ID you want to modify. \n";
	old.SetIDFromUser();
	if(!ItemList.Get(old)) {
		std::cout << "\n\t Error. Couldn't find such item. \n";
		return 0;
	}
	else {
		std::cout << "\n\t Enter the Name. \n";
		temp.SetNameFromUser();
		temp.SetID(old.GetID());
		if (ItemList.Modify(temp)) {
			std::cout << "\n\t Successfully Modified. \n";
			std::cout << "\n\t Before Modified Item : " << old;
			std::cout << "\n\t After Modified Item  : " << temp;
			return 1;
		}
		else {
			std::cout << "\n\t Error. Failed to modify the item : " << old;
			return 0;
		}
	}
}

int Application::Clear() {
	std::cout << "\n\t Done. \n";
	return ItemList.Clear();
}