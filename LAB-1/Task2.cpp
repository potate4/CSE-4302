#include <iostream>
using namespace std;
class Medicine
{
private:
    string name;
    string genericName;
    double discount_percent = 5;
    double unitPrice = 0;
public:
 void assignName(string NAME, string GENERICNAME)
 {
    name = NAME;
    genericName = GENERICNAME;
 }
 void assignPrice(double price = 0)
 {
    unitPrice = price;
 }
 void setDiscountPercent(double percent = 5)
 {
    if(percent >= 0 && percent <= 45)
        discount_percent = percent;
 }
 double getSellingPrice()
 {
     return (unitPrice - ((discount_percent/100) * unitPrice));
 }
 void display()
 {
    cout << name << " (" << genericName <<") has a unit price of " << unitPrice << ". Current discount " << discount_percent << "%." <<endl;
 }
};
int main()
{

    Medicine med;
    string name, genName;
    cin >> name >> genName;
    med.assignName(name, genName);  
    double price;
    cin >> price;
    med.assignPrice(price);
    double dis;
    cin >> dis;
    med.setDiscountPercent(dis);
    med.display();
    return 0;
}