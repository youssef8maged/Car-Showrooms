#include "Showroom.h"

int Showroom::getId() const {
    return id;
}

void Showroom::setId(int id) {
    Showroom::id = id;
}

const string& Showroom::getName() const {
    return Name;
}

void Showroom::setName(const string& name) {
    Name = name;
}

const string& Showroom::getLocation() const {
    return location;
}

void Showroom::setLocation(const string& location) {
    Showroom::location = location;
}

const string& Showroom::getPhoneNumber() const {
    return phone_number;
}

void Showroom::setPhoneNumber(const string& phoneNumber) {
    phone_number = phoneNumber;
}

const vector<Car>& Showroom::getListOfCar() const {
    return list_of_car;
}

void Showroom::setListOfCar(const vector<Car>& listOfCar) {
    list_of_car = listOfCar;
}


vector<Showroom> Showroom::retrivalshowroomfromfile(vector<Showroom>& v) {
    int id1;
    string name;
    string location2;
    string phone;
    Showroom room;
    ifstream myfile("showroomsfile.txt", ios::in);
    while ((myfile >> id1 >> name >> location2 >> phone).good()) {
        room.setId(id1);
        room.setLocation(location2);
        room.setName(name);
        room.setPhoneNumber(phone);
        v.push_back(room);

    }
    myfile.close();
    return v;

}

vector<Car> Showroom::retrivalcarsfromfiles(Showroom ra, vector<Car>& vc) {
    int id;
    string make;
    string model;
    int year;
    int price;
    string installment;
    Car car;
    string nameroom = ra.getName();
    nameroom += "cars.txt";
    ifstream ret(nameroom);
    while ((ret >> id >> make >> model >> year >> price >> installment).good()) {

        car.setId(id);
        car.setMake(make);
        car.setModel(model);
        car.setYear(year);
        car.setPrice(price);
        car.setInstallment(installment);
        vc.push_back(car);
        //   if(ret.eof())
        //  break;
    }
    ret.close();
    return vc;
}

vector<Showroom> Showroom::retrivalshowroomwithcar(vector<Showroom>& sc) {
    vector<Car> cars;
    retrivalshowroomfromfile(sc);
    for (int i = 0; i < sc.size(); i++) {
        retrivalcarsfromfiles(sc[i], cars);
        sc[i].setListOfCar(cars);

    }


    return sc;
}

void Showroom::searchshowroom(string n, vector<Showroom> room) {

    for (int i = 0; i < room.size(); i++) {
        if (n == room[i].getName()) {
            cout << "-*-*-*-*-*-**-*-*-**-*-*-*-*-*-*-*-**-*-**-*-*-*-*-*-*-*-*-**-*-*-*" << endl;
            cout << "IS Exist" << endl;
            cout << "ID : " << room[i].getId() << endl;
            cout << "NAME : " << room[i].getName() << endl;
            cout << " LOCATION :" << room[i].getLocation() << endl;
            cout << "PHONE_NUMBER :" << room[i].getPhoneNumber() << endl;
            cout << "-*-*-**-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-**-*-*-*-*-*-" << endl;


        }
        break;
    }

}

void Showroom::searchcar(string model, vector<Showroom> roomsc) {
    for (int i = 0; i < roomsc.size(); i++) {
        for (int k = 0; k < roomsc[i].getListOfCar().size(); k++) {
            if (model == roomsc[i].getListOfCar()[k].getModel()) {
                cout << "Is exist IN :" << roomsc[i].getName() << endl;
                cout << "ID :" << roomsc[i].getListOfCar()[k].getId() << endl;
                cout << "MODEL : " << roomsc[i].getListOfCar()[k].getModel() << endl;
                cout << "MAKE : " << roomsc[i].getListOfCar()[k].getMake() << endl;
                cout << "PRICE :" << roomsc[i].getListOfCar()[k].getPrice() << endl;
                cout << " installment :" << roomsc[i].getListOfCar()[k].getInstallment() << endl;
                cout
                    << "-*-*-*-*-**-*-*--**-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-**-*-*-*-**-*-*-*-*-*-*-*-*-*-"
                    << endl;

            }
            break;
        }


    }

}
