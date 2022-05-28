#include<string>
using namespace std;
class Customer {
private:

    string username;
    string password;
    int id;
public:
    const string& getUsername() const;

    void setUsername(const string& username);

    const string& getPassword() const;

    void setPassword(const string& password);

    int getId() const;

    void setId(int id);
};