//
// Created by Shira on 11/12/2024.
//

#include "Application.h"
#include "Jobs.h"
using namespace std;



Application::Application(string candidate_first_name, string candidate_last_name, string candidate_id, string candidate_email,string candidate_phone_number,string resume)
{
    this->candidate_first_name = candidate_first_name;
    this->candidate_last_name = candidate_last_name;
    this->candidate_id = candidate_id;
    this->candidate_email = candidate_email;
    this->candidate_phone_number = candidate_phone_number;
    this->resume = resume;
}
void Application ::display_application() const {
    cout << "Name: " << candidate_first_name << " " << candidate_last_name << endl;
    cout << "Job UID: " << candidate_id << endl << "Resume:" << resume << endl << "Phone number:" << candidate_phone_number << endl << "Email:" << candidate_email;
}

