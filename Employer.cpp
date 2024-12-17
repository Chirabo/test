

//
// Created by Shira on 10/12/2024.
//
#include <iostream>
#include <vector>
using namespace std;
#include "Jobs.h"
#include "Employer.h"


Employer::Employer(string first_name, string last_name, string id,string password, string email): User(first_name,last_name,id,password,email)
{
}


bool Employer::login(string input_id, const string input_password)
{

    if (id == input_id && password == input_password) {
        cout << "Login successfully!" << endl;
        return true;
    } else {
        cout << "Invalid ID or password." << endl;
        return false;
    }
};
/*
void Employer::savetofile(const std::string &filename) {
    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()){
        cout << "Error: Could not open file " << filename << " for writing." << endl;
        return;
    }
    outfile << first_name << "," << last_name << "," << id << "," << password << "," << email << endl;
    outfile.close();
    cout << "Employer saved to file successfully." << endl;

}
 */

/*
vector<Employer> Employer::loadfromfile(const std::string &filename) {
    vector<Employer>employers;//create vector array of employers from employer type
    ifstream infile(filename);
    if (!infile.is_open()){
        cout << "Error: Could not open file " << filename << " for reading." << endl;
        return employers;
    }
    string line; // create temp line
    while (getline(infile,line)){
        stringstream x(line);//stringstream sort sentences by key like ,
        string first_name, last_name, id, password, email;
        getline(x, first_name, ',');
        getline(x, last_name, ',');
        getline(x, id, ',');
        getline(x, password, ',');
        getline(x, email, ',');
        employers.emplace_back(first_name,last_name,id,password,email);
    }
    infile.close();
    return employers;
}
 */
void Employer::employer_menu() {
    int choice;
    bool run = true;
    while (run) {
        cout << "\nEmployer Menu: \n";
        cout << "1) Post jobs " << endl;
        cout << "2) View Published jobs " << endl;
        cout << "3) Manage jobs " << endl;
        cout << "4) Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Jobs newJob = Jobs().create_job();
                jobs.push_back(newJob);
                cout << "Job posted successfully!";
                break;
            }
            case 2: {
                view_published_jobs();
                break;
            }
            case 3: {
                manage_jobs();
                break;
            }
            case 4: {
                run = false;
                cout << "Goodbye!" << endl;
                break;
            }
            default:
                cout << "Invalid choice. try again. \n";
        }
    }
}

void Employer::view_published_jobs() const {
    if (jobs.size() == 0) {
        cout << "You have not posted any jobs yet! " << endl;
        return;
    }

    cout << "\nJobs Posted by you:\n";
    for (int i = 0; i < jobs.size(); ++i) {
        jobs[i].display_jobs();
        cout << endl;
    }
}



void Employer::manage_jobs() {
    int choice = 0;
    bool run = true;
    while (run) {
        cout << "Choose an option( 1.Update job, 2.Delete job 3. exit ) " << endl;
        cin >> choice;

        switch (choice) {
            case 1 :
                int index;
                cout << "Choose the index of the job that you want to update:" << endl;
                cin >> index;

                if (index < 1 || index > jobs.size()) {
                    cout << "Invalid index " << endl;
                    break;
                }

                jobs[index - 1].update_job();
                break;

            case 2:
                int job_index;
                cout << "Choose the index ";
                cin >> job_index;
                if (job_index < 1 || job_index > jobs.size()) {
                    cout << "Invalid index " << endl;
                    break;
                }

                jobs.erase(jobs.begin() + job_index - 1);
                cout << "Job deleted successfully" << endl;
                employer_menu();
                break;

            case 3:
                run = false;
                break;

        }
    }
}


void Employer::view_applications()const {
    if ( applications.size() == 0) {
        cout << "There is no job applications! " << endl;
        return;
    }

    cout << "\n Jobs Applications: \n";
    for (int i = 0; i < applications.size(); ++i) {
        applications[i].display_application();
    }
}

