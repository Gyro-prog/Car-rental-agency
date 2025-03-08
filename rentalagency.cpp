
#include <iostream>
using namespace std;

// Qa) BASE CLASS.

class vehicle
{
protected:
    string make, model;
    int year;

    // constructor.
public:
    vehicle(string mke, string mdl, int yr) : make(mke), model(mdl), year(yr) {}

    // virtual function to get cost of renting
    virtual double calculaterentalcost(int days) = 0;

    // details function
    virtual void details()
    {
        cout << "Make: " << make << ", Model: " << model << ", Year: " <<year << endl;
    }

    // destructor.
    virtual ~vehicle() {}
};

// Qb.) DERIVED CLASSES WITH PRIVATE ATTRIBUTES

// 1. class car

class car : public vehicle
{
private:
    int numdoors;
    // constructor.
public:
    car(string mke, string mdl, int yr, int doors) : vehicle(mke, mdl, yr), numdoors(doors)
    {
    }

    // calculate rental cost

    double calculaterentalcost(int days) override
    {
        double totalcost = days * (1000+ numdoors * 500);
        return totalcost;
    }
    void details() override
    { 
        vehicle::details();
        cout << " Number of Doors: "<< numdoors << endl;
    }
    //destructor
    virtual ~car() {}
};

//class suv
class suv: public vehicle{

    private: 
    int passengercapacity;

    public:
    suv(string mke, string mdl, int yr, int capacity):vehicle(mke,mdl,yr), passengercapacity(capacity){}
    double calculaterentalcost(int days) override
    {
        double totalcost = days * (1500 + passengercapacity * 500);
        return totalcost;
    }
    void details() override{
        vehicle:: details();
        cout << "Passenger Capacity: " << passengercapacity << endl;

    }
    virtual ~suv() {}
};

//3.Truck

class truck:public vehicle{
    private:
    int loadcapacity;

public:

truck(string mke, string mdl, int yr, int tones):vehicle(mke,mdl,yr), loadcapacity(tones){}
double calculaterentalcost(int days) override{
    double totalcost = days * (4000 + loadcapacity * 500);
    return totalcost;
}
void details()override{
    vehicle::details();
    cout << "Load Capacity: " << loadcapacity << " Tones" << endl;
}
virtual ~truck() {}

};


int main()

{
    cout << "Enter the number of days you want to rent the car for: ";
    int days;
    cin >> days;    

    //car objects
    car car1("Toyota", "Markx", 2013,4);
    car1.details();
    cout << "Cost of renting for " << days<< " days is: " << car1.calculaterentalcost(days) <<"Ksh"<< endl;

    //suv

    suv suv1("Mazda" , "CX-5", 2015, 5);
    suv1.details();
    cout << "Cost of renting for " << days << " days is: " << suv1.calculaterentalcost(days)<< "Ksh" << endl;

    //truck
    truck truck1("Mitstubishi", "Canter", 2013, 8);
    truck1.details();
    cout << "Cost of renting for " << days << " days is: " << truck1.calculaterentalcost(days) << "Ksh" << endl;

    return 0;
}
