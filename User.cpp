//
// Created by Shira on 10/12/2024.
//

#include "User.h"

using namespace std;
#include <iostream>

User::User(){}

User::User(string first_name, string last_name, string id, string password, string email)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->id = id;
    this->password = password;
    this->email = email;
}

bool User :: login (string input_id , const string input_password) {
    if ( id == input_id && password == input_password) {
        cout << "Login successfully!" << endl;
        return true;
    }
    else {
        cout << "Invalid ID or password." << endl;
        return false;
    }
}

void User :: display_details() const {
    cout << "First name:" << first_name << endl;
    cout << "Last name:" << last_name << endl;
    cout << "ID number:" << id << endl;
    cout << "Password:" << password << endl;
    cout << "Email:" << email << endl;
}

User :: ~User(){}