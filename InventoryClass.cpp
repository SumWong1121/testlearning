#include <iostream>
#include <string>

using namespace std;

class Inventory{
private:
int itemNumber,quantity;
double cost,totalCost;
public:
  Inventory(){itemNumber = 0; quantity = 0;cost = 0; totalCost = 0;};
void Constructor(int iNum, double cos, int quan)
{
  itemNumber = iNum;
  quantity = quan;
  cost = cos;
  setTotalCost();
}
int setitemNumber()
{
  int iNum = -1;
  do
  {
    cout << "What is the item number:";
    if(!(cin >> iNum))
    {cout << "Please put number only!\n";cin.clear();cin.ignore(10000,'\n');}
    else if(iNum < 0)
      cout << "Number cannot be negative!\n";
  }
  while(iNum < 0);
  return iNum;
}
int setQuantity()
{
  int quan = -1;
  do
  {
    cout << "What is the Quantity:";
    if(!(cin >> quan))
    {cout << "Please put number only!\n";cin.clear();cin.ignore(10000,'\n');}
    else if(quan < 0)
      cout << "Number cannot be negative!\n";
  }
  while(quan < 0);
  return quan;
}

double setCost()
{
  double cos = -1;
  do
  {
    cout << "What is the Cost:";
    cin >> cos;
    if(cos < 0)
      cout << "Number cannot be negative!\n";
  }
  while(cos < 0);
  return cos;
}
void setTotalCost(){totalCost = quantity * cost;}
int getItemNumber(){return itemNumber;}
int getQuantity(){return quantity;}
double getCost(){return cost;}
double getTotalcost(){return totalCost;}
};

int main()
{
    Inventory newItem;
    int newiNum,newquan;
    double newcos;
    newiNum = newItem.setitemNumber();
    newquan = newItem.setQuantity();
    newcos = newItem.setCost();
    newItem.Constructor(newiNum, newcos, newquan);
    cout << "ItemNo.  :" << newItem.getItemNumber() << endl;
    cout << "Quantity :" << newItem.getQuantity() << endl;
    cout << "Cost     :" << newItem.getCost() << endl;
    cout << "Totalcost:" << newItem.getTotalcost() << endl;
    return 0;
}
