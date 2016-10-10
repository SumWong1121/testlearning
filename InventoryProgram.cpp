#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//#include <cstdlib> for linux

using namespace std;

struct INVdata{
	string description;
	int quantity;
	double WScost, Rcost;
	string Date;
};

 vector<INVdata> Invdata;

string ValidStrInput(string prompt);
double ValidNumInput(string prompt);
void Display_menu(int &choice);
void display(int choice);
void editing(fstream &file, int choice);
void writingdata(fstream &file);
INVdata getdata(fstream &file, int choice);
string formmatingDate(string input);

int main()
{
    int choice;
	fstream file;
	do
	{
        choice = 0;
		file.open("inventorydata.txt",ios::in | ios::out |ios::binary);
		if(!file)
		{
			cout << "Fail to open the file!\n";
			exit(EXIT_FAILURE);
		}
		
		while(!(file.eof()))
		{
			Invdata.push_back(getdata(file,choice));
		}
		Display_menu(choice);
		switch(choice)
		{
			case 1:editing(file,choice);break;
			case 2:display(choice);break;
			case 3:editing(file,choice);break;
			case 4:editing(file,choice);break;
			case 5:break;
		}
		Invdata.clear();
		file.close();
	}
	while(choice != 5);
}

void Display_menu(int &choice)
{
	cout << "-------Menu-------\n";
	cout << "1. Add New Record\n";
	cout << "2. Display Records\n";
	cout << "3. Change Record\n";
	cout << "4. Delete Record\n";
	cout << "5. exit\n\n";
	while (choice < 1 || choice > 5){
	cout << "Please put the number here:";
    if(!(cin >> choice))
    {
        cout << "Invalid Input!Number only!\n";
        cin.clear();cin.ignore(10000,'\n');
    }
    if(choice <1 || choice > 5)
        cout << "Invalid input!\n";
    }
}

void display(int choice)
{
	switch(choice)
	{
	case 2:for(unsigned int index = 0;index < Invdata.size(); index++)
	{
		cout << (index+1) << ". " <<	Invdata[index].description << endl;
		cout << "Quantity: " << Invdata[index].quantity << endl;
		cout << "WholeSale:" << Invdata[index].WScost << endl;
		cout << "Retail:   " << Invdata[index].Rcost << endl;
		cout << "Date:    " << Invdata[index].Date << endl << endl;
	}
    if(Invdata.size() == 0)
        cout << "No data found!\n";
        break;
	case 3: for(unsigned int index = 0;index < Invdata.size(); index++)
		{
		cout << (index+1) << "." <<	Invdata[index].description << endl;
		}
		break;
	case 4: for(unsigned int index = 0;index < Invdata.size(); index++)
		{
		cout << (index+1) << "." <<	Invdata[index].description << endl;
		}
		break;
	}
}

void editing(fstream &file,int choice)
{
   unsigned int temp = -1;
	file.close();
	switch(choice)
	{
		case 1: Invdata.push_back(getdata(file,choice));break;
		case 3:display(choice);
			   cout << "Which record you want to edit?\n";
			   while((temp-1) < 0 || (temp-1) > Invdata.size()){
			   cout << "ANS:";
               if (!(cin >> temp))
                   {cout << "Invalid input!Please put number only!\n";cin.clear();cin.ignore(10000,'\n');}
               if((temp-1) < 0 || (temp-1) > Invdata.size())
					cout << "No record found!Please choose again!\n";
   			    }
                Invdata[temp-1] = getdata(file,choice);
                break;
        case 4:display(choice);
			   cout << "Which record you want to delete?\n";
			   while((temp-1) < 0 || (temp-1) > Invdata.size()){
			   cout << "ANS:";
               if (!(cin >> temp))
                   {cout << "Invalid input!Please put number only!\n";cin.clear();cin.ignore(10000,'\n');}
               if((temp-1) < 0 || (temp-1) > Invdata.size())
					cout << "No record found!Please choose again!\n";
   			    }
                Invdata.erase(Invdata.begin()+(temp-1));
                break;
	}
    file.open("inventorydata.txt",ios::in | ios::out |ios::binary|ios::trunc);
    for(unsigned int index = 0;index < Invdata.size();index++)
    {
    Invdata[index].Date = formmatingDate(Invdata[index].Date);
    }
	writingdata(file);
}

void writingdata(fstream &file)
{
    for(unsigned int index = 0;index < Invdata.size(); index++)
			{
                if(index != (Invdata.size()-1))
				file << Invdata[index].description << ':' << Invdata[index].quantity <<' '
					 << Invdata[index].WScost <<' ' << Invdata[index].Rcost << ' '
					 << Invdata[index].Date << ';';
                else
                file << Invdata[index].description << ':' << Invdata[index].quantity <<' '
					 << Invdata[index].WScost <<' ' << Invdata[index].Rcost << ' '
					 << Invdata[index].Date;
			}
}

INVdata getdata(fstream &file, int choice)
{
	INVdata record;
    switch(choice)
    {
        case 1:record.description = ValidStrInput("What is the name of the item:");
               record.quantity = static_cast <int> (ValidNumInput("What is the item's quantity:"));
               record.WScost = ValidNumInput("What is the item's wholesale cost:");
               record.Rcost = ValidNumInput("What is the item's retail cost:");
               record.Date = ValidStrInput("What is the date:");break;
        case 3:record.description = ValidStrInput("What is the name of the item:");
               record.quantity = static_cast <int> (ValidNumInput("What is the item's quantity:"));
               record.WScost = ValidNumInput("What is the item's wholesale cost:");
               record.Rcost = ValidNumInput("What is the item's retail cost:");
               record.Date= ValidStrInput("What is the date:");break;
        default: getline(file,record.description,':');
                 file >> record.quantity >> record.WScost >> record.Rcost;
                 getline(file,record.Date,';');break;
    }
    return record;
}

string ValidStrInput(string prompt)
{
    string input= "",temp1;
    int month=0,day=0,year=0;

    if(prompt == "What is the name of the item:")
    {
        while(input.length() < 1)
        {
        cout << prompt;
        cin.clear();
        cin.ignore(10000,'\n');
        getline(cin,input);
        if(input.length() < 1)
            cout << "Invalid Input!Name cannot be empty!\n";
        }
    }
    else
    {
        while(input.length() != 11 || year > 2016 || month > 12 || month < 1 || day > 31 || day <1)
        {
            cout << prompt;
            cin >> input;

         for(unsigned int index = 0; index < input.length(); index++){
            while(isdigit(input[index]))
            {
            temp1 += input[index];
            index++;
            }
            if (month == 0)
                month = atoi(temp1.c_str());
            else if (day == 0)
                day = atoi(temp1.c_str());
            else year = atoi(temp1.c_str());
            if(index == input.length())
                break;
            else if(input[index] != '/'){
                cout << "Invalid Input!Date must be MM/DD/YYYY!(must with the / !)\n";
                break;
            }
            temp1 ="";
        }
        if(year > 2016)
            cout << "Invalid Input! Year must before 2016\n";
        else if(month> 12 || month < 1)
            cout << "Invalid Input!Month must within 1-12!\n";
        else if(day > 31||day < 1)
            cout << "Invalid Input!Day must between  1 - 31!\n";

        if(year == 0 || month == 0 || day == 0)
            input ="";

        if(input == "")
            cout << "Invalid Input!Please try again!\n";

        input ="";
        if(month < 10 && day < 10)
            input = " 0" + to_string(month) + "/0" + to_string(day) + "/" + to_string(year);
        else if(month < 10)
            input = " 0" + to_string(month) + "/" + to_string(day) + "/" + to_string(year);
        else if(day < 10)
            input = " " + to_string(month) + "/0" + to_string(day) + "/" + to_string(year);
        else input = " " + to_string(month) + "/" + to_string(day) + "/" + to_string(year);
        }
    }

    return input;
}

double ValidNumInput(string prompt)
{
    double input = -1;
    int input1 = -1;

    if(prompt =="What is the item's quantity:")
    {
        while(input1 < 0)
        {
            cout << prompt;
            if(!(cin >> input1))
            {
                cout << "Invalid Input!It must be a number!\n";
                cin.clear();cin.ignore(10000,'\n');
                input1 = -1;
            }
            if(input1 < 0)
            {
                cout << "Invalid Input!It cannot be negative!\n";
            }
        }
        return (static_cast<double> (input1));
    }
    else
    {
        while(input < 0)
        {
            cout << prompt;
            if(!(cin >> input))
            {
                cout << "Invalid Input!It must be a number!\n";
                cin.clear();cin.ignore(10000,'\n');
                input = -1;
            }
            if(input < 0)
            {
                cout << "Invalid Input!It cannot be negative!\n";
            }
        }
        return input;
    }
}

string formmatingDate(string input)
{
    string temp1;
    int month=0,day=0,year=0;
         for(unsigned int index = 1; index < (input.length()+1); index++){
            while(isdigit(input[index]))
            {
            temp1 += input[index];
            index++;
            }
            if (month == 0)
                month = atoi(temp1.c_str());
            else if (day == 0)
                day = atoi(temp1.c_str());
            else year = atoi(temp1.c_str());
            if(index == input.length())
                break;
            else if(input[index] != '/')
                break;
            temp1 ="";
         }
        input = "";
        if(month < 10 && day < 10)
            input = "0" + to_string(month) + "/0" + to_string(day) + "/" + to_string(year);
        else if(month < 10)
            input = "0" + to_string(month) + "/" + to_string(day) + "/" + to_string(year);
        else if(day < 10)
            input = to_string(month) + "/0" + to_string(day) + "/" + to_string(year);
        else input = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    
    return input;
}