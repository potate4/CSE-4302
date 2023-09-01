#include <iostream>
using namespace std;

class Product
{
    private:
    string name;
    int id;
    double price = 1;
    double quantity = 1;
    bool availability = 1; 
    int maxQuantity = 20;

    public:
    static double allProducts;
    Product()
    {
        allProducts += (quantity * price);
    }
    Product(string NAME, int ID, double PRICE, double QUANTITY)
    {
        name = NAME;
        id = ID;
        price = PRICE;
        quantity = QUANTITY;
        allProducts += (quantity * price);
    }
    // setters
    void setName(string s)
    {
        name = s;
    }
    void setId(int i)
    {
        id = i;
    }
    void setPrice(double p)
    {
        allProducts -= (quantity * price);
        price  = p;
        allProducts += (quantity * price);
        
    }
    void setQuantity(double q)
    {
        allProducts -= (quantity * price);
        quantity = q;
        allProducts += (quantity * price);
    }
    void setStatus(bool f)
    {
        availability = f;
    }
    // getters

    string getName()
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    double getPrice()
    {
        return price;
    }
    double getQuantity()
    {
        return quantity;
    }
    bool getStatus()
    {
        return availability;
    }
    // other functions
    void setMaxQuantity(int qty)
    {
        maxQuantity = qty;
    }
    void addToInventory(int added_quantity)
    {
        if(quantity + added_quantity <= maxQuantity)
            quantity += added_quantity;
    }
    bool isAvailable()
    {
        if(quantity > 0) availability = 1;
        else availability = 0;

        return availability;
    }
    void purchase(int q)
    {
        if(isAvailable())
        {
            quantity -= q;
        }
    }
    int updatePrice(int percent)
    {
        price += (double)(price * ((double) percent/(double)100.0));
    }
    void displayInventoryValue()
    {
        double total = quantity * price;
        cout << total << endl;
       
    }
    void displayDetails()
    {
        cout << "ID : " << id << endl;
        cout << "price : " << price << endl;
        cout << "quantity : " << quantity << endl;
        cout << "Availability : " << availability << endl;
    }
    static double displayTotalInventoryValue()
    {
       return allProducts;   
    }
};
double Product::allProducts = 0.0;
int main()
{    
    Product p1("A", 1, 2, 1), p2("B", 2, 3, 4), p3("C", 3, 4, 5);

    p1.displayInventoryValue();
    p2.displayInventoryValue();
    p3.displayInventoryValue();

   

    cout << "total : " << Product::displayTotalInventoryValue() << endl;
    
    p1.setPrice(10);

    p1.displayInventoryValue();
    p2.displayInventoryValue();
    p3.displayInventoryValue();

    cout << "total : " << Product::displayTotalInventoryValue() << endl;

    return 0;
}
