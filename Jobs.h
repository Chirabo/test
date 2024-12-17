//
// Created by Shira on 10/12/2024.
//

#ifndef USERSTORY_JOBS_H
#define USERSTORY_JOBS_H
#include <string>
#include <iostream>
#include <vector>
#include "Employer.h"
#include "Application.h"
using namespace std;



class Jobs
{
protected:
    string location;
    string profession;
    string job_type;
    string experience;
    string jobUID;
    vector <Application> list_of_applications;

public:
    Jobs();
    Jobs(string location, string profession, string job_type, string jobUID, string experience);
   // void savetofile (const string &filename);
    //static vector<Jobs> loadfromfile(const string &filename);
    void set_job(string location , string profession , string job_type, string jobUID, string experience);
    string get_location(){return location;}
    string get_profession() {return profession;}
    string get_job_type(){return job_type;}
    string get_jobUID()const {return jobUID;}
    string get_experience(){return experience;}
    void display_jobs()const;
    void update_job();
    void set_application (const Application& app);
    //vector<Application> get_list_of_applications() {return list_of_applications;};
    vector <Jobs> search_jobs();
    Jobs create_job();
   // void view_all_jobs();
    //void delete_job ( Jobs *job , int &current_size , int index);
    //void add_application();
    friend ostream &operator << (ostream &os , const Jobs &j){
        os << "Location:" << j.location << ", Profession: " << j.profession << ", Job Type : " << j.job_type;
        return os;}


};

extern std:: vector <Jobs> all_jobs;


#endif //USERSTORY_JOBS_H



