#include <iostream>

using namespace std;

class Inventory{
private:
	int m_itemNumber;
	int m_quantity;
	double m_cost;
	double m_totalCost;

public:
	Inventory();
	Inventory(int itemNum, int quantity, double cost);

	void setItemNumber(int itemNum);
	void setQuantity(int quantity);
	void setCost(double cost);
	void setTotalCost();

	int getItemNumber();
	int getQuantity();
	double getCost();
	double getTotalCost();

};

Inventory::Inventory(){

	m_itemNumber = 0;
	m_quantity = 0;
	m_cost = 0;
	m_totalCost = 0;
}

Inventory::Inventory(int itemNum, int quantity, double cost){
	if (itemNum < 0){
		cout << "Input cannot be less than 0. Value unchanged." << endl;
	}
	else {
		m_itemNumber = itemNum;
	}
	if (quantity < 0){
		cout << "Input cannot be less than 0. Value unchanged." << endl;
	}
	else {
		m_quantity = quantity;
	}
	if (cost < 0){
		cout << "Input cannot be less than 0. Value unchanged." << endl;
	}
	else {
		m_cost = cost;
	}
	setTotalCost();
}

void Inventory::setItemNumber(int itemNum){
	if (itemNum < 0){
		cout << "Input cannot be less than 0. Value unchanged." << endl;
	}
	else {
		m_itemNumber = itemNum;
	}
}

void Inventory::setQuantity(int quantity){
	if (quantity < 0){
		cout << "Input cannot be less than 0. Value unchanged." << endl;
	}
	else {
		m_quantity = quantity;
	}
}

void Inventory::setCost(double cost){
	if (cost < 0){
		cout << "Input cannot be less than 0. Value unchanged." << endl;
	}
	else {
		m_cost = cost;
	}
}

void Inventory::setTotalCost(){
	m_totalCost = m_quantity * m_cost;
}

int Inventory::getItemNumber(){
	return m_itemNumber;
}

int Inventory::getQuantity(){
	return m_quantity;
}

double Inventory::getCost(){
	return m_cost;
}

double Inventory::getTotalCost(){
	return m_totalCost;
}

/******************
Driver Program
*******************/

int main(){

	Inventory myItem;

	cout << myItem.getItemNumber() << endl;
	cout << myItem.getQuantity() << endl;
	cout << myItem.getCost() << endl;
	cout << myItem.getTotalCost() << endl;
	myItem.setItemNumber(-5);
	myItem.setQuantity(-32);
	myItem.setCost(-4.99);
	cout << myItem.getItemNumber() << endl;
	cout << myItem.getQuantity() << endl;
	cout << myItem.getCost() << endl;
	cout << myItem.getTotalCost() << endl;
	myItem.setItemNumber(5);
	myItem.setQuantity(32);
	myItem.setCost(4.99);
	myItem.setTotalCost();
	cout << myItem.getItemNumber() << endl;
	cout << myItem.getQuantity() << endl;
	cout << myItem.getCost() << endl;
	cout << myItem.getTotalCost() << endl;

	Inventory otherItem(1, 12, 4.99);
	cout << otherItem.getItemNumber() << endl;
	cout << otherItem.getQuantity() << endl;
	cout << otherItem.getCost() << endl;
	cout << otherItem.getTotalCost() << endl;

	return 0;
}
