#pragma once
#include <string>
#include <fstream>
#include <list>
#include"Showroom.h"
#include<iostream>
#include "Garage.h"

using namespace std;

class Admin {
private:
    int id;
    string username;
    string password;
public:
    int getId() const;

    void setId(int id);

    const string& getUsername() const;

    void setUsername(const string& username);

    const string& getPassword() const;

    void setPassword(const string& password);

    vector<Showroom> addshowroom(vector<Showroom>& Rooms);

    vector<Car> addcar(vector<Car>& Cars, Showroom room);

    vector<Garage> addgarage(vector<Garage>& Garages);

    vector<service> addservice(vector<service>& services, Garage garage);

    void updateshowroom(vector<Showroom>& v);

    void updatecar(vector<Car>& c, string ShNa);

    void updategarage(vector<Garage>& g);

    void updateservice(vector<service>& s, string GaNa);

    void deleteshowroom(vector<Showroom>& s);

    void deletegarage(vector<Garage>& g);

    void deletecar(vector<Car>& c, string ShNa);

    void deleteservice(vector<service>& se, string GaNa);

};


