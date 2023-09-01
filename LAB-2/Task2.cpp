#include <iostream>
using namespace std;
class Medicine
{
    private:
    string name;
    string genericName;
    double discountPercent = 5;
    double unitPrice = 0;

    public:
    static double total;
    Medicine()
    {

    }
    Medicine(string Name, string Gname, double up)
    {
        name = Name;
        genericName = Gname;
        unitPrice = up;
        total += up;
    }

    //setters
    void setName(string s)
    {
        name = s;
    }
    void setGenericName(string s)
    {
        genericName = s;
    }
    void setDiscountPercent(double d)
    {
        discountPercent = d;
    }
    void setUnitPrice(double up)
    {
        unitPrice = up;
    }
    // getters
    string getName()
    {
        return name;
    }
    string getGenericName()
    {
        return genericName;
    }
    double getDiscountPercent()
    {
        return discountPercent;
    }
    double getUnitPrice()
    {
        return unitPrice;
    }


    //others
    double getSellingPrice()
    {
        return (unitPrice - unitPrice*(discountPercent/100.0));
    }
    bool isAffordable(double budget)
    {
        if(getSellingPrice() <= budget)
            return true;
        return false;
    }
    void resetPrice()
    {
        unitPrice = 0;
        cout << unitPrice << endl;
    }
    void display()
    {
        cout << "NAME: " << name << endl;
        cout << "GENERICNAME: " << genericName << endl;
        cout << "PRICE: " << unitPrice << endl;
        cout << "DISCOUNT " << discountPercent << endl;
    }
    ~Medicine()
    {

    }
};
double Medicine::total = 0.0;
int main() 
{
    Medicine m1("Napa", "Paracetamol", 50), m2("A", "AA", 10), m3("B", "BB", 10);
    cout << m1.getSellingPrice() << endl;
    cout << m1.isAffordable(10) << endl;
    m1.display();

    cout << m2.getSellingPrice() << endl;
    cout << m2.isAffordable(10) << endl;
    m2.display();

    cout << m3.getSellingPrice() << endl;
    cout << m3.isAffordable(10) << endl;
    m3.display();

    cout << Medicine::total << endl;
    return 0;
}