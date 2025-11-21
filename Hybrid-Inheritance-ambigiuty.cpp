#include <iostream>
using namespace std;

class Car
{
public:
    string fueltype;

    void start()
    {
        cout << "Car started.." << endl;
    }
    void stop()
    {
        cout << "Car stopped.." << endl;
    }
};

class familyCar : public Car
{
};

class sportsCar : public Car
{
};

class Suv : public familyCar, public sportsCar
{
};

int main()
{
    Suv s1;
    // s1.start(); // Error: Ambiguity because start() is inherited from both familyCar and sportsCar
    // s1.stop(); // Error: Ambiguity because stop() is inherited from both familyCar and sportsCar
    
    // s1.fueltype(); // Error: Ambiguity because fueltype() is inherited from both familyCar and sportsCar
    s1.familyCar::fueltype = "Petrol";
    cout << "Fuel type of SUV: " << s1.familyCar::fueltype << endl;

    // we can also use virtual inheritance to solve this ambiguity problem.

    return 0;
}
