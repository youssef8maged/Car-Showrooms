#include <string>
#include "Car.h"
#include<iostream>

using namespace std;

class Showroom {
private:
    int id;
    string Name;
    string location;
    string phone_number;
    vector<Car> list_of_car;
public:


    const vector<Car>& getListOfCar() const;

    void setListOfCar(const vector<Car>& listOfCar);

public:
    int getId() const;

    void setId(int id);

    const string& getName() const;

    void setName(const string& name);

    const string& getLocation() const;

    void setLocation(const string& location);

    const string& getPhoneNumber() const;

    void setPhoneNumber(const string& phoneNumber);


    vector<Showroom> retrivalshowroomfromfile(vector<Showroom>& v);

    vector<Car> retrivalcarsfromfiles(Showroom room, vector<Car>& vc);

    vector<Showroom> retrivalshowroomwithcar(vector<Showroom>& sc);

    void searchshowroom(string n, vector<Showroom> room);

    void searchcar(string model, vector<Showroom> roomsc);
};

