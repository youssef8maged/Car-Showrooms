#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Customer.h"
#include "Admin.h"
#include <fstream>
#include <ctime>
#include <ctime>

using namespace std;
bool logged;
bool ADMIN;
string NAME;
int ID;

void Register(string NA, string s);

void Login(string n, string s);

void dispalyshowroom(vector<Showroom> disrooms);

void displaycar(Showroom rm);

void displaygarage(vector<Garage> vg);

void displayservices(Garage garage);


class Process {
private:

    int ids;
    int customer_id;
    string type_process;
    string date;
    int money;
    Car car;
public:
    int getId() const {
        return ids;
    }

    void setId(int id) {
        Process::ids = id;
    }

    int getCustomer() const {
        return customer_id;
    }

    void setCustomer(int customer_id) {
        Process::customer_id = customer_id;
    }

    const string& getTypeProcess() const {
        return type_process;
    }

    void setTypeProcess(const string& typeProcess) {
        type_process = typeProcess;
    }

    const string& getDate() const {
        return date;
    }

    void setDate(const string& date) {
        Process::date = date;
    }

    const int& getMoney() const {
        return money;
    }

    void setMoney(const int& money) {
        Process::money = money;
    }

    const Car& getCar() const {
        return car;
    }

    void setCar(const Car& car) {
        Process::car = car;
    }

};

class serviceprocess {
private:
    int process_id;
    int customer_id;
    string date;
    string amount_of_money;
    service serv;
public:
    int getProcessId() const {
        return process_id;
    }

    void setProcessId(int processId) {
        process_id = processId;
    }

    int getCustomerId() const {
        return customer_id;
    }

    void setCustomerId(int customerId) {
        customer_id = customerId;
    }

    const string& getDate() const {
        return date;
    }

    void setDate(const string& date) {
        serviceprocess::date = date;
    }

    const string& getAmountOfMoney() const {
        return amount_of_money;
    }

    void setAmountOfMoney(const string& amountOfMoney) {
        amount_of_money = amountOfMoney;
    }

    const service& getServ() const {
        return serv;
    }

    void setServ(const service& serv) {
        serviceprocess::serv = serv;
    }

};

vector<serviceprocess> addserviceprocess(vector<serviceprocess>& adser, service servicee, string da);

vector<Process> retrieveprocessbr(vector<Process>& ps) {
    Process process;
    Car car;
    ////processinfo
    int id;
    int customer_id;
    string type_process;
    string date;
    int money;
    /////carinfo
    int id2;
    string make;
    string model;
    int year;
    int price;
    string installment;
    ////////////////////retrive
    string fn = NAME;
    fn += "processfile.txt";
    ifstream mypro(fn);
    while ((mypro >> id >> customer_id >> type_process >> date >> money >> id2 >> make >> model >> year >> price
        >> installment).good()) {
        car.setId(id2);
        car.setPrice(price);
        car.setInstallment(installment);
        car.setMake(make);
        car.setModel(model);
        car.setYear(year);
        process.setId(id);
        process.setCar(car);
        process.setCustomer(customer_id);
        process.setTypeProcess(type_process);
        process.setDate(date);
        process.setMoney(money);
        ps.push_back(process);
    }
    mypro.close();
    return ps;


};

vector<serviceprocess> retrieveprocessservice(vector<serviceprocess>& zeko) {
    //object
    serviceprocess servp;
    service sers;
    //processservice
    int proid;
    int cusid;
    string datee;
    string amount_of_money;
    //service
    int ide;
    string namee;
    string pricee;
    ////startfunction
    string namef = NAME;
    namef += "servicefile.txt";
    ifstream myfile(namef, ios::in);//oppen
    while ((myfile >> proid >> cusid >> datee >> amount_of_money >> ide >> namee).good()) {
        sers.setId(ide);
        sers.setName(namee);
        servp.setProcessId(proid);
        servp.setCustomerId(cusid);
        servp.setDate(datee);
        servp.setAmountOfMoney(amount_of_money);
        servp.setServ(sers);
        zeko.push_back(servp);
    }
    myfile.close();//clooseee
    return zeko;
};

vector<Process> addprocessbr(vector<Process>& ps, Car car, string type, string date);

void displayprocess(vector<Process> prs) {
    cout << "**********************your process************************************" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    for (int i = 0; i < prs.size(); i++) {
        cout << "process number: " << i + 1 << endl;
        cout << "Process Id :" << prs[i].getId() << endl;
        cout << " your ID :" << prs[i].getCustomer() << endl;
        cout << " Type Process :" << prs[i].getTypeProcess() << endl;
        cout << " Date :" << prs[i].getDate() << endl;
        cout << "money :" << prs[i].getMoney() << endl;
        cout << " CAR id:" << prs[i].getCar().getId() << endl;
        cout << "Car make :" << prs[i].getCar().getMake() << endl;
        cout << "car model :" << prs[i].getCar().getModel() << endl;
        cout << "year:" << prs[i].getCar().getYear() << endl;
        cout << "car installment :" << prs[i].getCar().getInstallment() << endl;
        cout << "*******-*-*--*--*--*************************-*-*-*--********************-*--*-";

    }


};

vector<serviceprocess> addserviceprocess(vector<serviceprocess>& adser, service servicee, string da) {
    serviceprocess serpv;
    string naf = NAME;
    naf += "servicefile.txt";
    ifstream check1(naf, ios::app);
    check1.seekg(0, ios::end); // put the "cursor" at the end of the file
    long long length = check1.tellg(); // find the position of the cursor
    check1.close();
    if (length == 0) {
        serpv.setProcessId(1);
        serpv.setCustomerId(ID);
        serpv.setDate(da);
        serpv.setAmountOfMoney(servicee.getPrice());
        serpv.setServ(servicee);
        adser.push_back(serpv);
        ofstream myfile(naf, ios::out);
        myfile << serpv.getProcessId() << endl << serpv.getCustomerId() << endl << serpv.getDate() << endl
            << serpv.getAmountOfMoney() << endl << serpv.getServ().getId() << endl << serpv.getServ().getName()
            << endl;
        myfile.close();
    }
    else {
        //object
        serviceprocess servp;
        //processservice
        int proid;
        int cusid;
        string datee;
        string amount_of_money;
        //service
        int ide;
        string namee;
        string pricee;
        list<serviceprocess> list;
        ifstream mylis(naf, ios::app);
        while (!mylis.eof()) {
            mylis >> proid >> cusid >> datee >> amount_of_money >> ide >> namee;
            servp.setProcessId(proid);
            list.push_back(servp);

        }
        mylis.close();
        servp.setProcessId(list.back().getProcessId() + 1);
        servp.setCustomerId(ID);
        servp.setDate(da);
        servp.setAmountOfMoney(servicee.getPrice());
        servp.setServ(servicee);
        adser.push_back(servp);
        ofstream mylie(naf, ios::app);
        mylie << servp.getProcessId() << endl << servp.getCustomerId() << endl << servp.getDate() << endl
            << servp.getAmountOfMoney() << endl << servp.getServ().getId() << endl << servp.getServ().getName()
            << endl;
        mylie.close();
    }
    return adser;

};

void displayserviceprocess(vector<serviceprocess> pse) {
    cout << "******************* myservices ***********************************" << endl;
    for (int i = 0; i < pse.size(); i++) {
        cout << " service_process number : " << i + 1 << endl;
        cout << "service_process ID :" << pse[i].getProcessId() << endl;
        cout << "customer ID :" << pse[i].getCustomerId() << endl;
        cout << " Date_service_process: " << pse[i].getDate() << endl;
        cout << " servicce_id :" << pse[i].getServ().getId() << endl;
        cout << "service_name : " << pse[i].getServ().getName() << endl;
        cout << "***************************************************************" << endl;


    }


};

int main() {

    string modelname;
    string nameshowroom;
    string namegarage;
    string nameservice;
    Admin admin;
    Showroom showroom;
    Car car;
    Garage garagE;
    service Service;

    vector<Showroom> vecrooms;
    vector<Garage> garages;
    vector<Process> process;
    vector<serviceprocess> servpro;
    if (vecrooms.empty() & garages.empty() & process.empty()) {
        showroom.retrivalshowroomwithcar(vecrooms);
        garagE.retrivalgarageswithservicfromfile(garages);
        retrieveprocessservice(servpro);
        retrieveprocessbr(process);
    }
    int option1;
    string name;
    string password;
mylabel:
    cout << "*********************** Hello in our program ****************** " << endl;
    cout << "******************************************************************" << endl;
    cout << " To Login for our program Press number:1" << endl;
    cout << " To Register for our program Press number:2" << endl;
    cin >> option1;
    switch (option1) {
    case 1:
        cout << "Enter your username :" << endl;
        cin >> name;
        cout << "Enter your Password :" << endl;
        cin >> password;
        Login(name, password);
        if (logged) {
            vector<service> services;
            vector<Car> cars;
            int genearlop;
            int option3;
            int option4;

            cout << "Enter number 1 to display Showrooms :" << endl;//hfghg
            cout << "Enter number 2 to display Garages :" << endl;
            cout << "Enter number 3 to display your picked car" << endl;
            cout << "Enter number 4 to display your historical service:" << endl;
            cout << "Enter number 5 to search showroom " << endl;
            cout << "Enter number 6 to search garage " << endl;
            cin >> genearlop;
            switch (genearlop) {
            case 1:
                if (ADMIN) {
                    dispalyshowroom(vecrooms);
                    int opadmin;
                    int opadmin2c;
                    cout << "Enter number 1 to display cars" << endl;
                    cout << "Enter number 2 to delete showroom" << endl;
                    cout << "Enter number 3 to update showroom" << endl;
                    cout << "Enter number 4 to Add showroom" << endl;
                    cin >> opadmin;
                    switch (opadmin) {
                    case 1:
                        cout << "Enter number ShowRoom to display Cars " << endl;
                        cin >> option3;
                        showroom.retrivalcarsfromfiles(vecrooms[option3 - 1], cars);
                        vecrooms[option3 - 1].setListOfCar(cars);
                        displaycar(vecrooms[option3 - 1]);
                        cout << "TO Add car enter number :1" << endl;
                        cout << "To delete car enter number :2" << endl;
                        cout << "TO update car enter number :3" << endl;
                        cout << "To search car enter number :4" << endl;
                        int opti;
                        cin >> opti;
                        switch (opti) {
                        case 1:
                            admin.addcar(cars, vecrooms[option3 - 1]);
                            break;
                        case 2:
                            admin.deletecar(cars, vecrooms[option3 - 1].getName());
                            break;
                        case 3:
                            admin.updatecar(cars, vecrooms[option3 - 1].getName());
                            break;
                        case 4:
                            cout << "Enter the car model :" << endl;
                            cin >> modelname;
                            showroom.searchcar(modelname, vecrooms);
                            break;
                        default:
                            goto mylabel;
                            break;

                        }

                        break;
                    case 2:
                        admin.deleteshowroom(vecrooms);
                        dispalyshowroom(vecrooms);
                        break;
                    case 3:
                        admin.updateshowroom(vecrooms);
                        dispalyshowroom(vecrooms);
                        break;
                    case 4:
                        admin.addshowroom(vecrooms);
                        dispalyshowroom(vecrooms);
                        break;
                    default:
                        cout << "invalid choice" << endl;
                        break;
                    }
                    break;

                }
                else {
                    dispalyshowroom(vecrooms);
                    int od;
                    cout << "Enter number 1 to go cars OR Enter nmber 2 to search" << endl;
                    cin >> od;

                    if (od == 1) {
                        int chosepick;
                        string type;
                        string date;
                        cout << "Enter number ShowRoom to display Cars ";
                        cin >> option3;
                        showroom.retrivalcarsfromfiles(vecrooms[option3 - 1], cars);
                        vecrooms[option3 - 1].setListOfCar(cars);
                        displaycar(vecrooms[option3 - 1]);
                        cout << "Enter number of cars to  pick it :" << endl;
                        cin >> chosepick;
                        cout << "Enter your Available dates EX.20/20/2022 :" << endl;
                        cin >> date;
                        cout << "Enter type of proccess EX. buy OR rent :" << endl;
                        cin >> type;
                        addprocessbr(process, cars[chosepick], type, date);
                        displayprocess(process);
                    }
                    else if (od == 2) {

                        cout << "Enter the car model :" << endl;
                        cin >> modelname;
                        showroom.searchcar(modelname, vecrooms);

                    }


                }
                break;

            case 2:
                if (ADMIN) {
                    displaygarage(garages);
                    int opadmin11;
                    int opadmin12;
                    cout << "Enter number 1 to display service" << endl;
                    cout << "Enter number 2 to delete garage  " << endl;
                    cout << "Enter number 3 to update garage  " << endl;
                    cout << "Enter number 4 to add garage  " << endl;
                    cin >> opadmin11;
                    switch (opadmin11) {
                    case 1:
                        cout << "Enter number of garage to display services " << endl;
                        cin >> option4;
                        garagE.retrivalservicefromfile(garages[option4 - 1], services);
                        garages[option4 - 1].setListOfServices(services);
                        displayservices(garages[option4 - 1]);
                        cout << "To add service Enter number 1" << endl;
                        cout << "To delete service Enter number 2" << endl;
                        cout << "To update service Enter number 3" << endl;
                        cout << "To Search service Enter number 4" << endl;
                        int hopti;
                        cin >> hopti;
                        switch (hopti) {
                        case 1:
                            admin.addservice(services, garages[option4 - 1]);
                            break;
                        case 2:
                            admin.deleteservice(services, garages[option4 - 1].getName());
                            break;
                        case 3:
                            admin.updateservice(services, garages[option4 - 1].getName());
                            break;
                        case 4:
                            cout << "Enter the service name :" << endl;
                            cin >> nameservice;
                            garagE.searchservice(nameservice, garages);
                        default:
                            cout << "invalid choice !!" << endl;
                            break;
                        }
                        break;
                    case 2:
                        admin.deletegarage(garages);
                        displaygarage(garages);
                        break;
                    case 3:
                        admin.updategarage(garages);
                        displaygarage(garages);
                        break;
                    case 4:
                        admin.addgarage(garages);
                        displaygarage(garages);
                        break;
                    default:
                        cout << "invalid choice" << endl;
                        break;
                    }


                }
                else {
                    int ind;
                    cout << "enter 1 to go to service OR number 2 to search about service" << endl;
                    cin >> ind;
                    if (ind == 1) {

                        int opi;
                        string dat;
                        displaygarage(garages);
                        int option7;
                        cout << "Enter number OF garage to dispaly service" << endl;
                        cin >> option7;
                        garagE.retrivalservicefromfile(garages[option7 - 1], services);
                        garages[option7 - 1].setListOfServices(services);
                        displayservices(garages[option7 - 1]);
                        cout << "Enter number of service to pick it" << endl;
                        cin >> opi;
                        cout << "Enter your available date :" << endl;
                        cin >> dat;
                        addserviceprocess(servpro, services[option7 - 1], dat);
                        displayserviceprocess(servpro);

                    }
                    else {
                        cout << "enter name service to search about it" << endl;
                        cin >> nameservice;
                        garagE.searchservice(nameservice, garages);


                    }


                }
                break;
            case 3:

                displayprocess(process);
                break;
            case 4:

                displayserviceprocess(servpro);
                break;
            case 5:
                cout << "Enter name of showroom" << endl;
                cin >> nameshowroom;
                showroom.searchshowroom(nameshowroom, vecrooms);
                break;
            case 6:
                cout << "Enter name of garage :" << endl;
                cin >> namegarage;
                garagE.searchgarage(namegarage, garages);
                break;
            default:
                cout << "invalid choice !" << endl;
                break;
            }


        }
        else {
            cout << "you should create new account" << endl;
            main();
        }
        break;
    case 2:
        cout << "Enter your username :" << endl;
        cin >> name;
        cout << "Enter your Password :" << endl;
        cin >> password;
        Register(name, password);
        main();
        break;
    default:
        cout << "Invalid choice! :" << endl;
        break;

    }

}

void Register(string NA, string s) {
    bool check;
    Customer customer;
    string name;
    string pass;
    int id;
    list<Customer> list_of_customers;
    list<Customer> Customers;
    ifstream check1("customers.txt", ios::app);
    check1.close();
    check1.open("customers.txt", ios::app); // open your file
    check1.seekg(0, ios::end); // put the "cursor" at the end of the file
    long long length = check1.tellg(); // find the position of the cursor
    check1.close(); // close your file
    if (length == 0) {
        check = true;
    }
    else {
        check = false;
    }

    if (check) {
        ofstream check2("customers.txt", ios::app);
        check2 << NA << endl;
        check2 << s << endl;
        check2 << 1 << endl;
        check2.close();
    }
    else {
        ifstream check3("customers.txt", ios::app);
        while (!check3.eof()) {
            check3 >> name >> pass >> id;
            customer.setId(id);
            customer.setUsername(name);
            customer.setPassword(pass);
            list_of_customers.push_back(customer);
        }
        check3.close();

        ofstream check4("customers.txt", ios::app);
        int val = list_of_customers.back().getId();
        check4 << NA << endl;
        check4 << s << endl;
        check4 << val + 1 << endl;
        check4.close();


    }
    string userpro = NA;
    userpro += "processfile.txt";
    string userservices = NA;
    userservices += "servicefile.txt";
    ofstream creatfile(userpro);
    creatfile.close();
    ofstream createfile1(userservices);
    createfile1.close();
};

void Login(string n, string s) {
    bool exist = false;

    if (n == "admin" && s == "admin") {
        ADMIN = true;
        logged = true;
        ID = 23577;
        NAME = "ADMIN";
        //call function dispaly with special function
    }
    else {
        ifstream output("customers.txt", ios::in);
        string username;
        string password;
        int id;
        Customer customer;
        vector<Customer> customers;
        while (!output.eof()) {
            output >> username >> password >> id;
            customer.setUsername(username);
            customer.setPassword(password);
            customer.setId(id);
            customers.push_back(customer);

        }
        output.close();
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i].getUsername() == n && customers[i].getPassword() == s) {
                NAME = customers[i].getUsername();
                ID = customers[i].getId();
                exist = true;
                if (exist == true) {
                    logged = true;
                    break;
                }
                else {
                    logged = false;
                    cout << "your account is not exist";

                }


            }

        }


    }


};

void dispalyshowroom(vector<Showroom> disrooms) {
    Showroom room;
    cout << "******************************************************************************************" << endl;
    cout << "                                 Available car showrooms                                 " << endl;
    cout << "*******************************************************************************************" << endl
        << endl << endl;
    for (int i = 0; i < disrooms.size(); i++) {
        cout << "number of show room" << i + 1 << endl;
        cout << "ID: " << disrooms[i].getId() << endl;
        cout << "Name: " << disrooms[i].getName() << endl;
        cout << "Location: " << disrooms[i].getLocation() << endl;
        cout << "Phone_Number: " << disrooms[i].getPhoneNumber() << endl;
        cout << "*************************************************************************************" << endl;

    }


};

void displaycar(Showroom rm) {
    string logo = rm.getName();
    logo += "'s cars";
    cout << "*************************************************************" << endl;
    cout << logo << endl;
    cout << "**************************************************************" << endl;
    for (int i = 0; i < rm.getListOfCar().size(); i++) {
        cout << "number of car:" << i + 1 << endl;
        cout << "ID : " << rm.getListOfCar()[i].getId() << endl;
        cout << "MAKE :" << rm.getListOfCar()[i].getMake() << endl;
        cout << "MODEL :" << rm.getListOfCar()[i].getModel() << endl;
        cout << "YEAR :" << rm.getListOfCar()[i].getYear() << endl;
        cout << "PRICE : " << rm.getListOfCar()[i].getPrice() << endl;
        cout << "installment :" << rm.getListOfCar()[i].getInstallment() << endl;
        cout << "------------------------------------------------------------------------------" << endl;

    }


};

void displaygarage(vector<Garage> vg) {
    Garage garage;
    cout << "*************************************************************" << endl;
    for (int i = 0; i < vg.size(); i++) {
        cout << "Garage number " << i + 1 << ":" << endl;
        cout << "ID :" << vg[i].getId() << endl;
        cout << "NAME :" << vg[i].getName() << endl;
        cout << "LOCATION :" << vg[i].getLocation() << endl;
        cout << "PHONE NUMBER :" << vg[i].getNumberphone() << endl;
        cout << "**********************************************************" << endl;
    }
};


vector<Process> addprocessbr(vector<Process>& ps, Car CAR, string type, string date) {
    Process process;
    string n = NAME;
    n += "processfile.txt";
    ifstream check1(n, ios::app);
    check1.seekg(0, ios::end); // put the "cursor" at the end of the file
    long long length = check1.tellg(); // find the position of the cursor
    check1.close(); // close your file
    if (length == 0) {
        ofstream myf(n, ios::out);
        process.setMoney(CAR.getPrice());
        process.setCustomer(ID);
        process.setCar(CAR);
        process.setDate(date);
        process.setTypeProcess(type);
        process.setId(1);
        ps.push_back(process);

        myf << 1 << endl << ID << endl << type << endl << date << endl << CAR.getPrice() << endl << CAR.getId() << endl
            << CAR.getMake() << endl << CAR.getModel() << endl << CAR.getYear() << endl << CAR.getInstallment() << endl;
        myf.close();
    }
    else {

        Car car;
        ////processinfo
        int id;
        int customer_id;
        string type_process;
        string date2;
        int money;
        /////carinfo
        int id2;
        string make;
        string model;
        int year;
        string installment;
        list<Process> prop;
        ifstream myfile(n, ios::in | ios::app);
        while (myfile.good()) {

            myfile >> id >> customer_id >> type_process >> date2 >> money >> id2 >> make >> model >> year
                >> installment;
            process.setId(id);
            prop.push_back(process);
        }
        myfile.close();

        Process pros;
        pros.setId(prop.back().getId() + 1);
        pros.setTypeProcess(type);
        pros.setCustomer(ID);
        pros.setCar(CAR);
        pros.setMoney(car.getPrice());
        pros.setDate(date);
        ps.push_back(pros);
        ofstream myf(n, ios::app | ios::out);
        myf << pros.getId() << endl << pros.getCustomer() << endl << pros.getTypeProcess() << endl
            << pros.getDate() << endl << pros.getMoney() << endl << pros.getCar().getId() << endl
            << pros.getCar().getMake() << endl << pros.getCar().getModel() << endl << pros.getCar().getYear()
            << endl << pros.getCar().getInstallment() << endl;
        myf.close();


    }
    return ps;

};


void displayservices(Garage garage) {
    cout << "*************************************************************" << endl;
    for (int i = 0; i < garage.getListOfServices().size(); i++) {
        cout << "service number " << i + 1 << ":" << endl;
        cout << "ID :" << garage.getListOfServices()[i].getId() << endl;
        cout << "NAME :" << garage.getListOfServices()[i].getName() << endl;
        cout << "PRICE :" << garage.getListOfServices()[i].getPrice() << endl;
        cout << "*************************************************************" << endl;
    }
};
