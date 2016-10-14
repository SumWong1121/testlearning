#include <iostream>
#inlcude <string>

using namespace std;

class Inventory{
private:
int itemNumber,quantity;
double cost,totalCost;
public:
  Inventory{itemNumber = 0; quantity = 0;cost = 0; totalcost = 0;};
void Constructor(int iNum, double cost, int quantity);
int setitemNumber();
int setQuantity();
double setCost();
void setTotalCost();
int getItemNumber();
int getQuantity();
double getCost();
double getTotalcost();
}

Inventory::Constructor(int iNum, double cos, int quan)
{
  itemNumber = iNum;
  quantity = quan;
  cost = cos;
  setTotalCost();
}

Inventory::setitemNumber()
{
  int iNum = -1;
  while(iNum < 0)
  {
    cout << "What is the item number:";
    if(!cin >> iNum)
    {cout << "Please put number only!\n";cin.clear();cin.ignore(10000,'\n');}
    else if(iNum < 0)
      cout << "Number cannot be negative!\n";
  }
  return iNum;
}
Inventory::setQuantity()
{
  int quan = -1;
  while(quan < 0)
  {
    cout << "What is the Quantity:";
    if(!cin >> quan)
    {cout << "Please put number only!\n";cin.clear();cin.ignore(10000,'\n');}
    else if(quan < 0)
      cout << "Number cannot be negative!\n";
  }
  return quan;
}
Inventory::setCost()
{
  double cos = -1;
  while(cos < 0)
  {
    cout << "What is the Cost:";
    if(!cin >> cos)
    {cout << "Please put number only!\n";cin.clear();cin.ignore(10000,'\n');}
    else if(cos < 0)
      cout << "Number cannot be negative!\n";
  }
  return cos;
}
Inventory::setTotalCost(){totalCost = quantity * cost;}
Inventory::getItemNumber(){return itemNumber;}
Inventory::getQuantity(){return quantity;}
Inventory::getCost(){return cost;}
Inventory::getTotalcost(){return totalCost;}

int main()
{
    Inventory newItem;
    int newiNum,newquan;
    double newcos;
    newiNum = newItem.setitemNumber();
    newquan = newItem.setQuantity();
    newcos = newItem.setCost();
    newItem.Constructor(newItem.iNum, newItem.cos, newItem.quan);
    cout << "ItemNo.  :" << newItem.getItemNumber() << endl;
    cout << "Quantity :" << newItem.getQuantity() << endl;
    cout << "Cost     :" << newItem.getCost() << endl;
    cout << "Totalcost:" << newItem.getTotalcost() << endl;
    return 0;
}
