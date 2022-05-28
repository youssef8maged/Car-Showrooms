#include<iostream>
#include<fstream>
#include<vector>
#include<list>
using namespace std;
class service {
private:
    int id;
    string name;
    string price;
public:
    int getId() const;

    void setId(int id);

    const string& getName() const;

    void setName(const string& name);

    const string& getPrice() const;

    void setPrice(const string& price);
};
