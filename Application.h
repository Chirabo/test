//
// Created by Shira on 10/12/2024.
//

#include "Jobs.h"
#ifndef CANDIDATE_H
#define CANDIDATE_H
#include "Candidate.h"

class Candidate;
class Employer;

class Application {
private:
    string candidate_first_name;
    string candidate_last_name;
    string candidate_id;
    string candidate_email;
    string candidate_phone_number;
    string resume;
public:
    Application();
    Application(string candidate_first_name, string candidate_last_name, string candidate_id, string candidate_email,string candidate_phone_number,string resume);
    void set_application ( string candidate_first_name , string candidate_last_name , string candidate_id , string candidate_email , string candidate_phone_number , string resume);
    void display_application() const;


};


#endif //USERSTORY_APPLICATION_H
