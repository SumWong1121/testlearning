#include <iostream>
#inlcude <string>

using namespace std;

class Inventory{
private:
int itemNumber,quantity;
double cost,totalCost;
public:
  Inventory{itemNumber = 0; quantity = 0;cost = 0; totalcost = 0;}
void Constructor(int iNum, double cost, int quantity);
int setitemNumber();
int setQuantity();
double setCost();
double setTotalCost(double cost, int quantity);
void getItemNumber();
void getQuantity();
void getCost();
void getTotalcost();
}

Inventory::Constructor(int iNum, double cos, int quan)
{
  itemNumber = iNum;
  quantity = quan;
  cost = cos;
  totalcost = setTotalCost(cost,quantity);
}

Inventory::setitemNumber{return iNum;}
