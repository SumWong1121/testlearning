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
void display(INVdata Invdata);
void editing(INVdata &Invdata);
INVdata getdata(fstream &file);

int main()
{
	vector<INVdata> Invsdata;
	
	do
	{
		fstream file("inventorydata.txt",ios::in | ios::out |ios::binary);
		while(!file.eof()))
		{
			Invsdata.pushback(getdata(file));
		}
		Displaymenu();
		switch(choice)
		{
			case 1:editing(Invsdata);break;
			case 2:display(Invsdata);break;
			case 3:editing(Invsdata);break;
			case 4:editing(Invsdata);break;
			case 5:break;
		}
		file.close();
	}
	while(choice == 5);
}

void Display_menu()
{
	cout << "-----menu-----\n";
	cout << "1. Add New Record\n";
	cout << "2. Display Records\n";
	cout << "3. Change Record\n";
	cout << "4. Delete Record\n";
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
