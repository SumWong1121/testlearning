#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

public int choice;

struct INVdata{
	string description;
	int quantity;
	double WScost, Rcost;
	string Data;
};

bool validation(string prompt, string input);
void Display_menu();
void display(fstream &file);
void editing(fstream &file);
INVdata getdata(fstream &file);

int main()
{
	vector<INVdata> Invsdata;
	fstream file("inventorydata.txt",ios::in | ios::out |ios::binary);
	
	do
	{
		while(!file.eof()))
		{
			Invsdata.pushback(getdata(file));
		}
		Displaymenu();
		switch(choice)
		{
			case 1:
		}
	}
	while(choice == 5);
}

void Display_menu()
{
	cout << "-----menu-----\n";
	cout << "1. Add New Record\n";
	cout << "2. Display Records\n";
	cout << "3. Change record\n";
	cout << "4.  new record\n";
	cout << "5. exit\n\n";
	do{
	cout << "Please put the number here:";
	cin >> choice;
	if(!isdigit(choice))
	{
		cout << "Invalid input!Please put number only!\n";
		cin.clear(choice, 10000);
	}
	else if(choice > 5 || choice < 1)
	{
		cout << "Invalid input!Please put 1-5 only!";
	}
	}while(!isdigit(choice)&& choice > 5 && choice < 1);
}
//Anthony
