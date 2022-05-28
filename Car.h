#include<string>
#include<list>
#include <fstream>
#include <vector>
using namespace std;
class Car {
private:
    int id;
    string make;
    string model;
    int year;
    int price;
    string installment;
public:
    int getId() const;

    void setId(int id);

    const string& getMake() const;

    void setMake(const string& make);

    const string& getModel() const;

    void setModel(const string& model);

    int getYear() const;

    void setYear(int year);

    int getPrice() const;

    void setPrice(int price);

    const string& getInstallment() const;

    void setInstallment(const string& installment);


};
