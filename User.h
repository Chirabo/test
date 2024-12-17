#ifndef USERSTORY_USER_H
#define USERSTORY_USER_H
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

class User
{
protected:
    string first_name;
    string last_name;
    string id;
    string password;
    string email;
public:
    User();
    User(string first_name, string last_name, string id, string password, string email);
    string get_first_name() const {return first_name;}
    string get_last_name() const {return last_name;}
    string get_id() const {return id;}
    string get_password() {return password;}
    string get_email() const {return email;}
    virtual bool login (string id, const string password)=0;
   // virtual void register()=0;
    virtual void display_details() const;
    virtual ~User();
};


#endif //USERSTORY_USER_H
