//
// Created by Shira on 10/12/2024.
//

#ifndef USERSTORY_EMPLOYER_H
#define USERSTORY_EMPLOYER_H
#include "User.h"
#include "Jobs.h"
#include "Application.h"
#include <string>
#include <vector>
#define MAX_APPLICATIONS 5

class Employer : public User {
private:
    vector<Jobs> jobs;
    vector<Application> applications;

public:
    Employer(string first_name, string last_name, string id,string password, string email);
    bool login (string input_id ,  string input_password) ;
    //void savetofile (const string &filename);
    //static vector<Employer> loadfromfile(const string &filename);
    void employer_menu();
    void post_jobs();
    void view_published_jobs() const;
    void manage_jobs();
    void view_applications()const;
    ~Employer(){};


};

#endif //USERSTORY_EMPLOYER_H
