#include"service.h"


class Garage {
private:
    int id;
    string name;
    string location;
    string numberphone;
    vector <service> list_of_services;
public:
    int getId() const;

    void setId(int id);

    const string& getName() const;

    void setName(const string& name);

    const string& getLocation() const;

    void setLocation(const string& location);

    const string& getNumberphone() const;

    void setNumberphone(const string& numberphone);

    const vector<service>& getListOfServices() const;

    void setListOfServices(const vector<service>& listOfServices);

    vector<Garage> retrivalgargaesfromfile(vector<Garage>& vg);

    vector<service> retrivalservicefromfile(Garage garage, vector<service>& vs);

    vector<Garage>retrivalgarageswithservicfromfile(vector<Garage>& vgs);

    void searchservice(string name, vector<Garage> garage);


    void searchgarage(string name, vector<Garage>garage);



};
