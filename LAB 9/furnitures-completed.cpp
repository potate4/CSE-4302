#include <iostream>
#include <string>
#include<cmath>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    int discPerc;
    string prodName;
public:
    Furniture(){}
    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood),discPerc(0)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    Furniture(string na, double p,double d,Material m):price(0),discount(0),madeof(Material::Wood),discPerc(0)
    {   
        setProdName(na);
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setProdName(string na){
        prodName = na;
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    double getDiscountedPrice(){
        return price - discount;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    void setDiscountPercentage(int x){
        discPerc = x;
        discount = ceil(price - price*(static_cast<double>(discPerc)/100));
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else if(madeof == Material::foam)
            return string("Foam");
        else 
            return string("");
    }
    virtual void productDetails()
    {
        cout << "Product Name: " << prodName << endl;
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << ceil(price - discount) << endl;
        cout << "Material: " << getMadeof() << endl;
    }
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
    protected:
        BedSize size;
    public:
        Bed(double p,double d,Material m, BedSize b)
        {
            price = p;
            discount = d;
            setMadeof(m);
            setBedSize(b);

        }
        void productDetails() override
        {
            Furniture::productDetails();
            cout << "BedSize: " << getBedSize() << endl;
        }
        void setBedSize(BedSize s){
            size = s;
        }
        string getBedSize()
    {
        if(size==BedSize::Single)
            return string("Single");
        else if(size==BedSize::SemiDouble)
            return string("SemiDouble");
        else if(size==BedSize::Double)
            return string("Double");
        else
            return string("");
    }
};

enum class SeatNumber{One, Two, Three, Four, Five};
class Sofa:public Furniture
{
    protected:
        SeatNumber size;
    public:
        Sofa(double p,double d,Material m, SeatNumber b)
        {
            price = p;
            discount = d;
            setMadeof(m);
            setSeatNumber(b);

        }

        void setSeatNumber(SeatNumber m){
            size = m;
        }

        string getSeatNumber()
    {
        if (size == SeatNumber::One)
            return string("One");
        else if (size == SeatNumber::Two)
            return string("Two");
        else if (size == SeatNumber::Three)
            return string("Three");
        else if (size == SeatNumber::Four)
            return string("Four");
        else if (size == SeatNumber::Five)
            return string("Five");
        else
            return string("");
    }
    void productDetails()
        {
            
            cout << "Seat Number: " << getSeatNumber() << endl;
        }


    /*
    Furniture *f;
    void a()
    {
        f = new Bed();
    }
    
    ~Sofa
    {
        delete f;
    }
    */
};

enum class ChairCount {Two, Four, Six};

class DiningTable : public Furniture
{
private:
    ChairCount dsize;
public:
    DiningTable(double p, double d, Material m, ChairCount ds):Furniture(p,d,m),dsize(ds){}
    string getChairCount()
    {
        if (dsize == ChairCount::Two)
            return string("Two");
        else if (dsize == ChairCount::Four)
            return string("Four");
        else if (dsize == ChairCount::Six)
            return string("Six");
        else
            return string("");
    }
    void productDetails()
    {
        Furniture::productDetails();
        cout << "Dining Table Size: " << getChairCount() <<endl;
    }
};

void swap(Furniture* xp, Furniture* yp)
{
    Furniture temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort for Furniture class
void sort_furniture_discount(Furniture* arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j]->getDiscountedPrice() < arr[j + 1]->getDiscountedPrice()) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}


/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/
//void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures);


int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SeatNumber::Five);
    f_list[2] = new DiningTable(13000,345,Material::Wood,ChairCount::Four);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    f_list[2]->setDiscountPercentage(30);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
        cout << endl;
    }

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4
    So that following lines can be executed without error
    */
   cout << endl;
   cout << endl;
   cout << endl;

    sort_furniture_discount(f_list,4);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
        cout << endl;
    }
    /**task 4 ends here*/

}
