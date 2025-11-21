// Given a class rectangle with attributes length and width, write methods to calc the area and perimeter of the rectangle.
// Also demonstrate the use of these methods in a sample program.
// In the above question, create a cuboid class which should be the derived class of rectangle class. The cuboid class should have only one member variable that is height.
// Also write a function that finds the volume of the cuboid. Note that because of the inheritance, the length and width variable is already avialable to the cuboid class.
// what are the changes need to be done in the rectangle class for this new task? --> Length and width should be declared as protected members so that they are accessible in the derived class.

#include <iostream>
using namespace std;

class Rectangle
{
protected:
    float length, width;

public:
    Rectangle()
    {
        length = 0;
        width = 0;
        cout << "Rectangle constructor called." << endl;
    }

    void setData(float l, float w)
    {
        length = l;
        width = w;
    }

    float area()
    {
        return length * width;
    }

    float perimeter()
    {
        return 2 * (length + width);
    }

    void printData(void)
    {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area of rectangle: " << area() << endl;
        cout << "Perimeter of rectangle: " << perimeter() << endl;
    }
};

class Cuboid : public Rectangle
{
protected:
    float height;

public:
    Cuboid()
    {
        height = 0;
        cout << "Cuboid constructor called." << endl;
    }

    void setHeight(float h)
    {
        height = h;
    }

    float volume()
    {
        return area() * height;
    }

    /* void printCuboidData(void)
     {
         cout << "Length: " << length << ", Width: " << width << ", Height: " << height << endl;
         cout << "Volume of cuboid: " << volume() << endl;
     }  */

    void printData(void)
    { // overriding the base class printData method
        cout << "Volume: " << volume() << endl;
    }
};

int main()
{
    Rectangle rect;
    rect.setData(5.0, 3.0);
    rect.printData();

    Cuboid cub;
    cub.setData(5.0, 3.0);
    cub.setHeight(4.0);
    // cub.printCuboidData();
    cub.printData();

    return 0;
}