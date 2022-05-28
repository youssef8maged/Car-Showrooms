#include "Admin.h"
#include<fstream>
using namespace std;

int Admin::getId() const {
    return id;
}

void Admin::setId(int id) {
    Admin::id = id;
}

const string& Admin::getUsername() const {
    return username;
}

void Admin::setUsername(const string& username) {
    Admin::username = username;
}

const string& Admin::getPassword() const {
    return password;
}

void Admin::setPassword(const string& password) {
    Admin::password = password;
}

vector<Showroom> Admin::addshowroom(vector<Showroom>& Rooms) {
    string name;
    string location;
    string phone;
    cout << "Enter the name :" << endl;
    cin >> name;
    cout << "Enter the location :" << endl;
    cin >> location;
    cout << "Enter the phone number :" << endl;
    cin >> phone;
    ifstream myfile("showroomsfile.txt", ios::app);//oppeeeen
    myfile.seekg(0, ios::end);
    long long length = myfile.tellg();
    myfile.close(); //clooose
    if (length == 0) {
        ofstream input("showroomsfile.txt", ios::app);//oopeeenn
        input << 1 << endl;
        input << name << endl;
        input << location << endl;
        input << phone << endl;
        input.close();//clooseeee
        string name2 = name;
        name2 += "cars.txt";
        ofstream create(name2);//opennn
        create.close();//closseeee
        Showroom nroom;
        nroom.setId(1);
        nroom.setName(name);
        nroom.setLocation(location);
        nroom.setPhoneNumber(phone);
        Rooms.push_back(nroom);

    }
    else {
        int ID;
        string NAME;
        string LOCATION;
        string PHONE;
        Showroom room;
        list<Showroom> rooms;
        ifstream output("showroomsfile.txt");//oppennn
        while (!output.eof()) {
            output >> ID >> NAME >> LOCATION >> PHONE;
            room.setId(ID);
            room.setName(NAME);
            room.setPhoneNumber(PHONE);
            room.setLocation(LOCATION);
            rooms.push_back(room);
        }
        output.close();//clooseeee
        ofstream input("showroomsfile.txt", ios::app);//OPPEENN
        int c = rooms.back().getId();
        c += 1;
        input << c << endl;
        input << name << endl;
        input << location << endl;
        input << phone << endl;
        input.close();
        string a = name;
        a += "cars.txt";
        ofstream NEW(a);
        NEW.close();
        Showroom nroom;
        nroom.setId(c);
        nroom.setName(name);
        nroom.setLocation(location);
        nroom.setPhoneNumber(phone);
        Rooms.push_back(nroom);

    }
    return Rooms;

}

vector<Car> Admin::addcar(vector<Car>& Cars, Showroom room) {
    Car car;
    string make;
    string model;
    int year;
    int price;
    string installment;
    cout << "Enter car make :" << endl;
    cin >> make;
    cout << "Enter the car model : " << endl;
    cin >> model;
    cout << "Enter the car year :" << endl;
    cin >> year;
    cout << "Enter the car price :" << endl;
    cin >> price;
    cout << "Enter the car installment :" << endl;
    cin >> installment;
    string MAKE;
    string MODEL;
    int ID;
    int YEAR;
    int PRICE;
    string INSTALLMENT;
    string nameroom = room.getName();
    nameroom += "cars.txt";
    ifstream myfile(nameroom, ios::app);//oppeeeen
    myfile.seekg(0, ios::end);
    long long length = myfile.tellg();
    myfile.close(); //clooose
    if (length == 0) {
        ofstream store(nameroom, ios::app);//opennnnn
        store << 1 << endl;
        store << make << endl;
        store << model << endl;
        store << year << endl;
        store << price << endl;
        store << installment << endl;
        store.close();//closeeeeee
        Car ncar;
        ncar.setId(1);
        ncar.setMake(make);
        ncar.setModel(model);
        ncar.setYear(year);
        ncar.setPrice(price);
        ncar.setInstallment(installment);
        Cars.push_back(ncar);
    }
    else {
        list<Car> cars;
        ifstream retrive(nameroom, ios::app);
        while (!retrive.eof()) {
            retrive >> ID >> MAKE >> MODEL >> YEAR >> PRICE >> INSTALLMENT;
            car.setId(ID);
            car.setMake(MAKE);
            car.setModel(MODEL);
            car.setYear(YEAR);
            car.setPrice(PRICE);
            car.setInstallment(INSTALLMENT);
            cars.push_back(car);
            retrive.close();
        }

        ofstream record(nameroom, ios::app);//opeeeeen
        record << cars.back().getId() + 1 << endl;
        record << make << endl;
        record << model << endl;
        record << year << endl;
        record << price << endl;
        record << installment << endl;
        record.close();//closseeeee
        Car ncar;
        ncar.setId(cars.back().getId() + 1);
        ncar.setMake(make);
        ncar.setModel(model);
        ncar.setYear(year);
        ncar.setPrice(price);
        ncar.setInstallment(installment);
        Cars.push_back(ncar);


    }
    return Cars;

}


vector<Garage> Admin::addgarage(vector<Garage>& Garages) {
    string name;
    string location;
    string phone_number;
    cout << "Enter the garage name :" << endl;
    cin >> name;
    cout << "Enter the garage location :" << endl;
    cin >> location;
    cout << "Enter the garage phone number :" << endl;
    cin >> phone_number;
    int id;
    string na;
    string loca;
    string pho;
    list<Garage> gs;
    Garage garage;
    ifstream myfile("garagesfile.txt", ios::app);//oppeeeen
    myfile.seekg(0, ios::end);
    long long length = myfile.tellg();
    myfile.close(); //clooose
    if (length == 0) {
        ofstream record("garagesfile.txt");
        record << 1 << endl;
        record << name << endl;
        record << location << endl;
        record << phone_number << endl;
        string nm = name;
        nm += "services.txt";
        ofstream file(nm);
        file.close();
        Garage ngarage;
        ngarage.setId(1);
        ngarage.setName(name);
        ngarage.setLocation(location);
        ngarage.setNumberphone(phone_number);
        Garages.push_back(ngarage);

    }
    else {
        ifstream out("garagesfile.txt");
        while (!out.eof()) {
            out >> id >> na >> loca >> pho;
            garage.setId(id);
            garage.setName(name);
            garage.setLocation(location);
            garage.setNumberphone(pho);
            gs.push_back(garage);
        }
        int i;
        i = gs.back().getId() + 1;
        garage.setId(i);
        garage.setName(name);
        garage.setNumberphone(phone_number);
        garage.setLocation(location);
        gs.push_back(garage);
        ofstream rec("garagesfile.txt", ios::app);
        rec << gs.back().getId() << endl;
        rec << gs.back().getName() << endl;
        rec << gs.back().getLocation() << endl;
        rec << gs.back().getNumberphone() << endl;
        rec.close();
        string nm = name;
        nm += "services.txt";
        ofstream file(nm);
        file.close();
        Garage ngarage;
        ngarage.setId(i);
        ngarage.setName(name);
        ngarage.setLocation(location);
        ngarage.setNumberphone(phone_number);
        Garages.push_back(ngarage);

    }

    return Garages;
}

vector<service> Admin::addservice(vector<service>& services, Garage garage) {
    int ch;
    string na;
    string price;
    cout << "Enter the service Name :" << endl;
    cin >> na;
    cout << "Enter the service price :" << endl;
    cin >> price;
    string n = garage.getName();
    list<service> sv;
    service s;
    n += "services.txt";
    ifstream my(n, ios::app);//oppeeeen
    my.seekg(0, ios::end);
    long long length1 = my.tellg();
    /*cout<<length1;*/
    my.close(); //clooose
    if (length1 == 0) {
        s.setId(1);
        s.setName(na);
        s.setPrice(price);
        ofstream rec(n);
        rec << s.getId() << endl;
        rec << s.getName() << endl;
        rec << s.getPrice() << endl;
        rec.close();
        service nser;
        nser.setId(1);
        nser.setName(na);
        nser.setPrice(price);
        services.push_back(nser);
    }
    else {
        ifstream res(n, ios::app);////OPEEENNN
        while (!res.eof()) {
            int ID;
            string name;
            string price;
            res >> ID >> name >> price;
            s.setId(ID);
            s.setName(name);
            s.setPrice(price);
            sv.push_back(s);


        }
        res.close();////closseeeeeee
        int x = sv.back().getId();
        s.setId(x + 1);
        s.setName(na);
        s.setPrice(price);
        ofstream red(n, ios::app);
        red << s.getId() << endl;
        red << s.getName() << endl;
        red << s.getPrice() << endl;
        red.close();
        service nser;
        nser.setId(x);
        nser.setName(na);
        nser.setPrice(price);
        services.push_back(nser);

    }
    return services;
}

void Admin::updateshowroom(vector<Showroom>& v) {
    int ShNum;
    cout << "Enter the number of showroom :" << endl;
    cin >> ShNum;
    int choice;
    string NewName;
    string NewLoc;
    string NewPhon;
    cout << "For updating location press 1 !" << endl;
    cout << "For updating phone Number press 2 !" << endl;
    cin >> choice;
    switch (choice)
    {

    case 1:
        cout << "Enter the new location :" << endl;
        cin >> NewLoc;
        v[ShNum - 1].setLocation(NewLoc);
        break;
    case 2:
        cout << "Enter the new Phone Number :" << endl;
        cin >> NewPhon;
        v[ShNum - 1].setPhoneNumber(NewPhon);
        break;
    default:
        cout << "Invalid choice !!" << endl;
        break;
    }
    ofstream show("showroomsfile.txt");//OPPEENN
    show.clear();
    for (int i = 0; i < v.size(); i++) {
        show << v[i].getId() << endl;
        show << v[i].getName() << endl;
        show << v[i].getLocation() << endl;
        show << v[i].getPhoneNumber() << endl;

    }show.close();//closeeee



}

void Admin::updatecar(vector<Car>& c, string ShNa) {
    int op;
    cout << "enter number of car" << endl;
    cin >> op;
    int choice;
    string NewModel;
    string NewMake;
    int Newyear;
    int Newprice;
    string Newinstallment;
    cout << "For updating Make press 1: " << endl;
    cout << "For updating Model press 2: " << endl;
    cout << "For updating The Year press 3: " << endl;
    cout << "For updating The price press 4: " << endl;
    cout << "For updating The installment press 5: " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Enter the new Make :" << endl;
        cin >> NewMake;
        c[op - 1].setMake(NewMake);
        break;
    case 2:
        cout << "Enter the new Model :" << endl;
        cin >> NewModel;
        c[op - 1].setModel(NewModel);
        break;
    case 3:
        cout << "Enter the new Year :" << endl;
        cin >> Newyear;
        c[op - 1].setYear(Newyear);
        break;
    case 4:
        cout << "Enter the new price :" << endl;
        cin >> Newprice;
        c[op - 1].setPrice(Newprice);
        break;
    case 5:
        cout << "Enter the new Installment :" << endl;
        cin >> Newinstallment;
        c[op - 1].setInstallment(Newinstallment);
        break;
    default:cout << "Invalid Choice !! " << endl;
        break;
    }
    string filename;
    filename = ShNa + "cars.txt";
    ofstream cfile(filename);//OPPEENN
    cfile.clear();
    for (int i = 0; i < c.size(); i++) {
        cfile << c[i].getId() << endl;
        cfile << c[i].getMake() << endl;
        cfile << c[i].getModel() << endl;
        cfile << c[i].getYear() << endl;
        cfile << c[i].getPrice() << endl;
        cfile << c[i].getInstallment() << endl;

    }cfile.close();//closeeee



}

void Admin::updategarage(vector<Garage>& g) {
    int option;
    cout << "please Enter number of garage to update " << endl;
    cin >> option;
    string Nlocat;
    string Nphone;
    int choice;
    cout << "For updating the location press 1 : " << endl;
    cout << "For updating the phone_number press 2 : " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Enter the new location : " << endl;
        cin >> Nlocat;
        g[option - 1].setLocation(Nlocat);
        break;
    case 2:
        cout << "Enter the new phone number :" << endl;
        cin >> Nphone;
        g[option - 1].setNumberphone(Nphone);
        break;
    default:cout << "Invalid choice !!" << endl;
        break;
    }
    ofstream gfile("garagesfile.txt");//OPPEENN
    gfile.clear();
    for (int i = 0; i < g.size(); i++) {
        gfile << g[i].getId() << endl;
        gfile << g[i].getName() << endl;
        gfile << g[i].getLocation() << endl;
        gfile << g[i].getNumberphone() << endl;

    }gfile.close();//closeeee

}

void Admin::updateservice(vector<service>& s, string GaNa) {
    int op;
    cout << "Please enter the number of service to update :" << endl;
    cin >> op;
    string Nname;
    string Nprice;
    int choice;
    cout << "For updating the name press 1" << endl;
    cout << "For updating the price press 2" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Enter the new name :" << endl;
        cin >> Nname;
        s[op - 1].setName(Nname);
        break;
    case 2:
        cout << "Enter the new price :" << endl;
        cin >> Nprice;
        s[op - 1].setPrice(Nprice);
        break;
    default: cout << "Invalid Choice !!" << endl;
        break;

    }
    string filename;
    filename = GaNa + "services.txt";
    ofstream sfile(filename);//OPPEENN
    sfile.clear();
    for (int i = 0; i < s.size(); i++) {
        sfile << s[i].getId() << endl;
        sfile << s[i].getName() << endl;
        sfile << s[i].getPrice() << endl;


    }sfile.close();//closeeee

}

void Admin::deleteshowroom(vector<Showroom>& s) {

    int op;
    cout << "Enter the number of showroom : " << endl;
    cin >> op;
    s.erase(s.begin() + (op - 1));
    ofstream show("showroomsfile.txt");//OPPEENN
    show.clear();
    for (int i = 0; i < s.size(); i++) {
        show << s[i].getId() << endl;
        show << s[i].getName() << endl;
        show << s[i].getLocation() << endl;
        show << s[i].getPhoneNumber() << endl; 

    }show.close();//closeeee
}

void Admin::deletegarage(vector<Garage>& g) {
    int op;
    cout << "Enter the number of Garage :" << endl;
    cin >> op;
    g.erase(g.begin() + (op - 1));
    ofstream gfile("garagesfile.txt");//OPPEENN
    gfile.clear();
    for (int i = 0; i < g.size(); i++) {
        gfile << g[i].getId() << endl;
        gfile << g[i].getName() << endl;
        gfile << g[i].getLocation() << endl;
        gfile << g[i].getNumberphone() << endl;

    }gfile.close();//closeeee

}

void Admin::deletecar(vector<Car>& c, string ShNa) {
    int op;
    cout << "Enter the number of car :" << endl;
    cin >> op;
    c.erase(c.begin() + (op - 1));
    string filename;
    filename = ShNa;
    filename += "cars.txt";
    ofstream cfile(filename);//OPPEENN
    cfile.clear();
    for (int i = 0; i < c.size(); i++) {
        cfile << c[i].getId() << endl;
        cfile << c[i].getMake() << endl;
        cfile << c[i].getModel() << endl;
        cfile << c[i].getYear() << endl;
        cfile << c[i].getPrice() << endl;
        cfile << c[i].getInstallment() << endl;

    }cfile.close();//closeeee
}

void Admin::deleteservice(vector<service>& se, string GaNa) {
    int op;
    cout << "Enter the number of the service :" << endl;
    cin >> op;
    se.erase(se.begin() + (op - 1));
    string filename;
    filename = GaNa + "services.txt";
    ofstream sfile(filename);//OPPEENN
    sfile.clear();
    for (int i = 0; i < se.size(); i++) {
        sfile << se[i].getId() << endl;
        sfile << se[i].getName() << endl;
        sfile << se[i].getPrice() << endl;


    }sfile.close();//closeeee
}
