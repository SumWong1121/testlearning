#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Item{
	string description;
	int    quantity;
	double wholeCost,
	       retailCost;
	string dateAdded;
};

void populateVector(vector<Item> &stock);
void executeChoice(int menuChoice, vector<Item> &stock);
int displayMenu();
Item collectItemInfo();
void addNewItem(vector<Item> &stock, Item item);
void displayInventory(vector<Item> &stock);
void editInventory(vector<Item> &stock);
void editItem(Item &itemEdit);
void writeInvFile(vector<Item> stock);
void deleteInvItem(vector<Item> &stock);
string isValidDate(string date);

int main(){
	vector<Item> stock;
	populateVector(stock);
	while (1){
		executeChoice(displayMenu(), stock);
	}
	return 0;
}

void populateVector(vector<Item> &stock){
	stock.clear();
	ifstream inventory;
	const int SIZE = 81;
	char fileContents[SIZE] = "";
	Item item;
	inventory.open("\\SpuriousInventory.txt", ios::in);
	if (inventory.fail()){
		cout << "Inventory is currently empty." << endl;
	}
	while (inventory.good()){
		bool isBadItem = false;
		inventory.getline(fileContents, SIZE, '\n');
		item.description = fileContents;
		inventory.getline(fileContents, SIZE, '\n');
		if (atoi(fileContents) < 0){
			cout << "Quantity in file is less than 0. Cannot add item: " << item.description << endl;
			isBadItem = true;
		}
		else {
			item.quantity = atoi(fileContents);
		}
		inventory.getline(fileContents, SIZE, '\n');
		if (atof(fileContents) < 0){
			cout << "Wholesale cost in file is less than 0. Cannot add item: " << item.description << endl;
			isBadItem = true;
		}
		else {
			item.wholeCost = atof(fileContents);
		}
		inventory.getline(fileContents, SIZE, '\n');
		if (atof(fileContents) < 0){
			cout << "Retail cost in file is less than 0. Cannot add item: " << item.description << endl;
			isBadItem = true;
		}
		else {
			item.retailCost = atof(fileContents);
		}
		inventory.getline(fileContents, SIZE, '\n');
		item.dateAdded = fileContents;
		if (!inventory.eof() && !isBadItem){
			stock.push_back(item);
		}
	}
}

void executeChoice(int menuChoice, vector<Item> &stock){
	if (stock.size() == 0 && menuChoice != 1) {
		cout << "Inventory currently empty." << endl;
	}
	switch (menuChoice){
	case 1: addNewItem(stock, collectItemInfo()); break;
	case 2: displayInventory(stock); break;
	case 3: editInventory(stock); break;
	case 4: deleteInvItem(stock); break;
	case 99: exit(0);
	default: cout << "Hmmm. That doesn't seem to be a choice..." << endl;
	}
}

int displayMenu(){
	string menuChoice = "";
	cout << "1. Add Item" << endl;
	cout << "2. Display Items" << endl;
	cout << "3. Edit Item" << endl;
	cout << "4. Delete Item" << endl;
	cout << "99. End Program" << endl;
	cout << endl << "Menu Choice >";
	getline(cin, menuChoice);
	return atoi(menuChoice.c_str());
}

Item collectItemInfo(){
	Item newItem;
	string input;
	cout << "Enter description:";
	getline(cin, input);
	newItem.description = input;
	cout << "Enter quantity:";
	getline(cin, input);
	while (atoi(input.c_str()) < 0){
		cout << "Quantity must be 0 or greater." << endl;
		getline(cin, input);
	}
	newItem.quantity = atoi(input.c_str());
	cout << "Enter wholesale cost:";
	getline(cin, input);
	while (atoi(input.c_str()) < 0){
		cout << "Wholesale cost must be 0 or greater." << endl;
		getline(cin, input);
	}
	newItem.wholeCost = atof(input.c_str());
	cout << "Enter retail cost:";
	getline(cin, input);
	while (atoi(input.c_str()) < 0){
		cout << "Retail cost must be 0 or greater." << endl;
		getline(cin, input);
	}
	newItem.retailCost = atof(input.c_str());
	cout << "Date item was added: ";
	getline(cin, input);
	while (isValidDate(input) == ""){
		cout << "Invalid Date. Date must be between 01/01/1971 and 01/01/2100 and must be in the format XX/XX/XXXX" << endl;
		getline(cin, input);
	}
	newItem.dateAdded = input;
	return newItem;
}

void addNewItem(vector<Item> &stock, Item item){
	stock.push_back(item);
	writeInvFile(stock);
}

void displayInventory(vector<Item> &stock){
	populateVector(stock);
	for (unsigned int index = 0; index < stock.size(); index++){
		cout << stock[index].description << endl;
		cout << stock[index].quantity << endl;
		cout << stock[index].wholeCost << endl;
		cout << stock[index].retailCost << endl;
		cout << stock[index].dateAdded << endl;
	}
}

void editInventory(vector<Item> &stock){
	if (stock.size() != 0){
		unsigned int editIndex = 0;
		string input = "";
		cout << "Which item would you like to edit?" << endl;
		for (unsigned int index = 0; index < stock.size(); index++){
			cout << index + 1 << ". " << stock[index].description << endl;
		}
		getline(cin, input);
		editIndex = atoi(input.c_str());
		while (editIndex <= 0 || editIndex > stock.size()){
			cout << "Invalid item number!" << endl;
			cout << "Which item would you like to edit?" << endl;
			getline(cin, input);
			editIndex = atoi(input.c_str());
		}
		editItem(stock[editIndex - 1]);
		writeInvFile(stock);
	}
}

void editItem(Item &itemEdit){
	cout << itemEdit.description << " was selected." << endl;
	cout << "Please enter in the new information: " << endl;
	itemEdit = collectItemInfo();
}

void writeInvFile(vector<Item> stock){
	ofstream inventory;
	inventory.open("\\SpuriousInventory.txt", ios::out);
	for (unsigned int index = 0; index < stock.size(); index++){
		inventory << stock[index].description << "\n";
		inventory << stock[index].quantity << "\n";
		inventory << stock[index].wholeCost << "\n";
		inventory << stock[index].retailCost << "\n";
		inventory << stock[index].dateAdded << "\n";
	}
	inventory.close();
}

void deleteInvItem(vector<Item> &stock){
	if (stock.size() != 0){
		unsigned int deleteIndex = 0;
		string input = "";
		cout << "Which item would you like to delete?" << endl;
		for (unsigned int index = 0; index < stock.size(); index++){
			cout << index + 1 << ". " << stock[index].description << endl;
		}
		getline(cin, input);
		deleteIndex = atoi(input.c_str());
		while (deleteIndex <= 0 || deleteIndex > stock.size()){
			cout << "Invalid item number!" << endl;
			cout << "Which item would you like to delete?" << endl;
			getline(cin, input);
			deleteIndex = atoi(input.c_str());
		}
		cout << "Are you sure you want to delete " << stock[deleteIndex - 1].description << "?" << endl;
		cout << "This will permanantly remove the item from your database." << endl;
		cout << "Type YES(ALL CAPS) to PERMANANTLY remove item from the database." << endl;
		getline(cin, input);
		if (input == "YES"){
			stock.erase(stock.begin() + (deleteIndex - 1));
			writeInvFile(stock);
			cout << "Item deleted!" << endl;
		}
	}
}

string isValidDate(string date){
	bool isDate = true;
	string check = "";
	string retDate = "";
	int slashCounter = 0;
	for (unsigned int index = 0; index < date.length(); index++){
		if (date[index] != '/'){
			check += date[index];
		}
		else if (date[index] == '/'){
			slashCounter++;
			switch (slashCounter){
			case 1: 
				if (atoi(check.c_str()) < 1 || atoi(check.c_str()) > 12){
					isDate = false;
				}
				else {
					retDate += (check + '/');
					check = "";
				}
				break;
			case 2:
				if (atoi(check.c_str()) < 1 || atoi(check.c_str()) > 31){
					isDate = false;
				}
				else {
					retDate += (check + '/');
					check = "";
				}
				break;
			default:
				isDate = false;
			}
		}
	}
	if (atoi(check.c_str()) < 1970 || atoi(check.c_str()) > 2100){
		isDate = false;
	}
	else {
		retDate += check;
	}
	if (isDate == true){
		return retDate;
	}
	else {
		return "";
	}
}
