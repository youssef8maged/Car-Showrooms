#include "Garage.h"

int Garage::getId() const {
    return id;
}

void Garage::setId(int id) {
    Garage::id = id;
}

const string& Garage::getName() const {
    return name;
}

void Garage::setName(const string& name) {
    Garage::name = name;
}

const string& Garage::getLocation() const {
    return location;
}

void Garage::setLocation(const string& location) {
    Garage::location = location;
}

const string& Garage::getNumberphone() const {
    return numberphone;
}

void Garage::setNumberphone(const string& numberphone) {
    Garage::numberphone = numberphone;
}

const vector<service>& Garage::getListOfServices() const {
    return list_of_services;
}

void Garage::setListOfServices(const vector<service>& listOfServices) {
    list_of_services = listOfServices;
}

vector<Garage> Garage::retrivalgargaesfromfile(vector<Garage>& vg) {
    Garage garage;
    int id;
    string name;
    string location;
    string phone_number;
    ifstream ret("garagesfile.txt");
    while ((ret >> id >> name >> location >> phone_number).good()) {
        garage.setId(id);
        garage.setName(name);
        garage.setLocation(location);
        garage.setNumberphone(phone_number);
        vg.push_back(garage);

    }
    ret.close();

    return vg;
}

vector<service> Garage::retrivalservicefromfile(Garage garage, vector<service>& vs) {
    service service;
    int id5;
    string name5;
    string price;
    string naf = garage.getName();
    naf += "services.txt";
    ifstream ret(naf);
    while ((ret >> id5 >> name5 >> price).good()) {
        service.setId(id5);
        service.setPrice(price);
        service.setName(name5);
        vs.push_back(service);
    }
    ret.close();
    return vs;
}

vector<Garage> Garage::retrivalgarageswithservicfromfile(vector<Garage>& vgs) {
    vector<service> ser;
    retrivalgargaesfromfile(vgs);
    for (int i = 0; i < vgs.size(); i++) {
        retrivalservicefromfile(vgs[i], ser);
        vgs[i].setListOfServices(ser);



    }
    return vgs;
}

void Garage::searchservice(string name, vector<Garage> garage) {
    for (int i = 0; i < garage.size(); i++) {
        for (int j = 0; j < garage[i].getListOfServices().size(); j++) {
            if (name == garage[i].getListOfServices()[j].getName()) {
                cout << "Is exist In : " << garage[i].getName() << endl;
                cout << "ID :" << garage[i].getListOfServices()[j].getId() << endl;
                cout << "Name :" << garage[i].getListOfServices()[j].getName() << endl;
                cout << "price :" << garage[i].getListOfServices()[j].getPrice() << endl;
                cout << "-*-*-**-*--**-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-**-*-*-*" << endl;

            }
            break;
        }

    }

}

void Garage::searchgarage(string name, vector<Garage> garage) {
    for (int i = 0; i < garage.size(); i++) {
        if (garage[i].getName() == name) {
            cout << "IS exist" << endl;
            cout << "Garage ID:" << garage[i].getId() << endl;
            cout << "Garage Name :" << garage[i].getName() << endl;
            cout << "Garage Phonenumber :" << garage[i].getNumberphone() << endl;
            cout << "Graga Location :" << garage[i].getLocation() << endl;
        }

        break;
    }

}


