#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.14
class Shape
{

};
class TwoDimensionalShape : public Shape
{
protected:
    float area;
    float perimeter;
public:
    TwoDimensionalShape():area(0), perimeter(0) {}
    TwoDimensionalShape(float a, float b): area(a), perimeter(b)
    {}
    void printArea()
    {
        cout << "Area: " << area << endl;
    }
    void printPerimeter()
    {
        cout << "Perimeter: " << perimeter << endl;
    }
    virtual float getArea()
    {
        return area;
    }
    virtual void print()
    {
        cout << "BASE CLASS\n";
        printArea();
        printPerimeter();
    }
};

class Square : public TwoDimensionalShape
{
private:
    float side;
public:
    Square(): TwoDimensionalShape(), side(0){}
    Square(float r):side(r)
    {
        area = pi * r * r;
        perimeter = 2 * pi * r;
    }
    Square(float a, float p, float r): TwoDimensionalShape(a, p), side(r){}
    float getArea()
    {
        return area;
    }
    void print()
    {
        cout << "Square" << endl;
        TwoDimensionalShape::printArea();
       // TwoDimensionalShape::printPerimeter();
    }
    
};
class Triangle : public TwoDimensionalShape
{
private:
    float a;
    float b;
    float c;
public:
    Triangle() : TwoDimensionalShape(), a(0), b(0), c(0){}
    Triangle(float s1, float s2, float s3) : a(s1), b(s2), c(s3)
    {
        float x = a + b + c;
        area = sqrt (x * (x - a) * (x - b) * (x - c));
        perimeter = a + b + c;
    }
    Triangle(float ar, float p, float s1, float s2, float s3) : TwoDimensionalShape(ar, p), a(s1), b(s2), c(s3){}
    float getArea()
    {
        return area;
    }
    void print()
    {
        cout << "Triangle" << endl;
        TwoDimensionalShape::printArea();
       // TwoDimensionalShape::printPerimeter();
    }
};

class Rectangle : public TwoDimensionalShape
{
private:
    float len;
    float width;
public:
    Rectangle() : TwoDimensionalShape(), len(0), width(0){}
    Rectangle(float l, float w): len(l), width(w)
    {
        area  = len * width;
        perimeter = len * 2 + width * 2;
    } 
    Rectangle(float a, float p, float l, float w) : TwoDimensionalShape(a, p), len(l), width(w) {}
    float getArea()
    {
        return area;
    }
    void print()
    {
        cout << "Rectangle" << endl;
        TwoDimensionalShape::printArea();
       // TwoDimensionalShape::printPerimeter();
    }
};
class Hexagon : public TwoDimensionalShape
{
private:
    float side;
public:
    Hexagon() : TwoDimensionalShape(), side(0){}
    Hexagon(float l): side(l)
    {
        area  = ((3/2) * sqrt(3)) * side * side;
        perimeter = side * 6;
    } 
    Hexagon(float a, float p, float l) : TwoDimensionalShape(a, p), side(l) {}
    float getArea()
    {
        return area;
    }
    void print()
    {
        cout << "Hexagon" << endl;
        TwoDimensionalShape::printArea();
       // TwoDimensionalShape::printPerimeter();
    }
};

void Swap(TwoDimensionalShape ** p1, TwoDimensionalShape ** p2)
{
    TwoDimensionalShape ** temp;
    temp = p1;
    p1 = p2;
    p2 = temp;
}
int main()
{
    // Triangle t1(3, 4, 5), t2(6,7,10);
    // Rectangle r1(5, 5), r2(5, 10);
    // Square s1(5), s2(10);
    // Hexagon h1(5), h2(10);

    // TwoDimensionalShape List[8];
    // List[0] = t1;
    // List[1] = t2;
    // List[2] = r1;
    // List[3] = r2;
    // List[4] = s1;
    // List[5] = s2;
    // List[6] = h1;
    // List[7] = h2;

    // for(int i = 0; i < 8; i++)
    // {
    //     List[i].print();
    // }

    TwoDimensionalShape * List[8];
    List[0] = new Triangle(3,4,5);
    List[1] = new Triangle(6,7,10);
    List[2] = new Rectangle(5, 5);
    List[3] = new Rectangle(5, 10);
    List[4] = new Square(5);
    List[5] = new Square(10);
    List[6] = new Hexagon(5);
    List[7] = new Hexagon(10);

    for(int i = 0; i < 8; i++)
    {
        for(int k = i + 1; k < 8; k++)
        {
            if(List[i]->getArea() < List[k]->getArea())
            {
                swap(List[i], List[k]);
            }
        }
    }

    for(int i = 0; i < 8; i++)
    {
        List[i]->print();
    }

    return 0;
}