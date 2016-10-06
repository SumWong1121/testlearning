#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//#include <cstdlib> for linux

using namespace std;

public int choice,temp;

struct INVdata{
	string description;
	int quantity;
	double WScost, Rcost;
	string Data;
};

bool validation(string prompt, string input);
void Display_menu();
void display(INVdata Invdata);
void editing(INVdata &Invdata, fstream &file);
void writingdata(INVdata Invdata, fstream &file);
INVdata getdata(fstream &file);

int main()
{
	vector<INVdata> Invsdata;
	fstream file;
	do
	{
		file.open("inventorydata.txt",ios::in | ios::out |ios::binary);
		if(!file.open)
		{
			cout << "Fail to open the file!\n";
			exit(EXIT_FAILURE);
		}
		
		while(!file.eof()))
		{
			Invsdata.pushback(getdata(file));
		}
		Displaymenu();
		switch(choice)
		{
			case 1:editing(Invsdata,file);break;
			case 2:display(Invsdata);break;
			case 3:editing(Invsdata,file);break;
			case 4:editing(Invsdata,file);break;
			case 5:break;
		}
		Invsdata.clear();
		file.close();
	}
	while(choice != 5);
}

bool validation(string prompt, string input)
{
	bool TF = true;
	if(prompt == "Which record you want to edit?")
	{
		if(!isdigit(temp))
			{
				cout << "Invalid input!Please put number only!\n";
				cin.clear(temp, 10000);
				TF= false;
			}
		else if(temp < 1 || temp > Invdata.size())
				{
					cout << "No record found!Please choose again!\n";
					TF= false;
				}
	}
	else if(prompt == "Please put the number here:")
	{
		if(!isdigit(choice))
			{
				cout << "Invalid input!Please put number only!\n";
				cin.clear(choice, 10000);
				TF = false;
			}
		else if(choice > 5 || choice < 1)
			{
				cout << "Invalid input!Please put 1-5 only!";
				TF = false;
			}
	}
	
}

void Display_menu()
{
	cout << "-------Menu-------\n";
	cout << "1. Add New Record\n";
	cout << "2. Display Records\n";
	cout << "3. Change Record\n";
	cout << "4. Delete Record\n";
	cout << "5. exit\n\n";
	do{
	cout << "Please put the number here:";
	cin >> choice;
	}while(!validation("Please put the number here:",NULL));
}

void display(INVdata Invdata)
{
	switch(choice)
	{
	case 2:for(unsigned int index;index < Invdata.size(); index++)
	{
		cout << (index+1) << ".        " <<	Invdata[index].description << endl;
		cout << "Quantity: " << Invdata[index].quantity;
		cout << "WholeSale:" << Invdata[index].WScost;
		cout << "Retail:   " << Invdata[index].Rcost;
		cout << "Date:     " << Invdata[index].Date;
	}break;
	case 3: for(unsigned int index;index < Invdata.size(); index++)
		{
		cout << (index+1) << ".        " <<	description << endl;
		}
		break;
	case 4: for(unsigned int index;index < Invdata.size(); index++)
		{
		cout << (index+1) << ".        " <<	description << endl;
		}
		break;
	}
}

void editing(INVdata &Invdata, fstream &file)
{
	file.clear();
	switch(choice)
	{
		case 1: Invdata.pushback(getdata(file));break;
		case 3:display(INVdata);
			   do
			   {
			   cout << "Which record you want to edit?\n";
			   do{
			   cout << "ANS:";
			   cin >> temp;
				}while(!validation("Which record you want to edit?",NULL));
	}
	writingdata(Invdata,file);
}

void writingdata(INVdata Invdata, fstream &file)
{
	switch(choice)
	{
	case 3:for(unsigned int index;index < Invdata.size(); index++)
			{
				file << Invdata[index].description << ":" << Invdata[index].quantity << ":" 
					 << Invdata[index].WScost << ":" << Invdata[index].Rcost << ":" 
					 << Invdata[index].Date << endl;
			}
			break;
	case 4:for(unsigned int index;index < (Invdata.size()-1); index++)
			{
				file << Invdata[index].description << ":" << Invdata[index].quantity << ":" 
					 << Invdata[index].WScost << ":" << Invdata[index].Rcost << ":" 
					 << Invdata[index].Date << endl;
			}
			break;
	}
}

INVdata getdata(fstream &file)
{
	INVdata record
}
