//a
// Created by Shira on 10/12/2024.
//
#include "Candidate.h"
#include "Jobs.h"
#include "Application.h"
#include <cstring>

using namespace std;


Candidate::Candidate() : User() {
    this->resume = nullptr;
    this->job_type = nullptr;
    this->phone_number = nullptr;
}

Candidate::Candidate(string first_name, string last_name, string id, string password, string email, string resume,
                     string phone_number, string job_type) : User(first_name, last_name, id, password, email) {
    this->resume = resume;
    this->phone_number = phone_number;
    this->job_type = job_type;
}

void Candidate::candidate_menu() {
    int choice;
    bool run = true;
    while (run) {
        cout << "\nCandidate Menu: \n";
        cout << "1) Search jobs."
             << endl;   // from this option we call the functions( add to favourite, add application)
        cout << "2) Edit profile." << endl;
        cout << "3) View favorites." << endl;
        cout << "4) View application." << endl;
        cout << "5) View profile." << endl;
        cout << "6) Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Jobs job_manager;
                vector<Jobs> found_result = job_manager.search_jobs();
                if (found_result.empty())
                    cout << "No jobs match the given criteria." << endl;
                else {
                    cout << "Matching jobs:" << endl;
                    for (int i = 0; i < found_result.size(); ++i) {
                        found_result[i].display_jobs();
                        cout << "----------------------" << endl;
                    }
                }
                int apply_choice;
                string UID;
                cout << "Do you want to apply for the job ?\n1.yes\n2.no" << endl;
                cin >> apply_choice;
                if (apply_choice == 1) {
                    cout << "Enter the UID of the job you want to apply for:";
                    cin >> UID;
                    bool job_found = false;
                    for (int i = 0; i < found_result.size(); ++i) {
                        if (found_result[i].get_jobUID() == UID) {
                            job_found = true;
                            Application app(get_first_name(), get_last_name(), get_id(), get_email(),
                                            get_phone_number(), get_resume());
                            found_result[i].set_application(app);
                            cout << "Application added successfully for the job with UID" << UID << "!" << endl;
                            break;
                        }
                    }
                    if (!job_found) {
                        cout << "Invalid job UID. No job matching." << endl;
                    }
                }
                break;
            }
            case 2: {
                edit_profile(*this);
                break;
            }
            case 3: {
                view_favorites();
                break;
            }
            case 4: {
                view_application_history();
                break;
            }
            case 5:
                display_details();
                break;
            case 6:
                run = false;
                break;

            default:
                cout << "Invalid choice. try again. \n";
        }
    }
}


bool Candidate::login(string input_id, string input_password) {
    if (id == input_id && password == input_password) {
        cout << "Login successfully!" << endl;
        return true;
    } else {
        cout << "Invalid ID or password." << endl;
        return false;
    }
}

/*void Candidate::savetofile(const string &filename) {
    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cout << "Error: Could not open file " << filename << " for writing." << endl;
        return;
    }
    outfile << first_name << "," << last_name << "," << id << "," << password << "," << email << ","
            << phone_number << "," << job_type << "," << resume << endl;
    outfile.close();
    cout << "Candidate saved to file successfully." << endl;
}

vector<Candidate> Candidate::loadfromfile(const std::string &filename) {
    vector<Candidate> candidates;
//create vector array of employers from employer type
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Error: Could not open file " << filename << " for reading." << endl;
        return candidates;
    }
    string line; // create temp line
    while (getline(infile, line)) {
        stringstream x(line);//stringstream sort sentences by key like ,
        string first_name, last_name, id, password, email, phone_number, job_type, resume;
        getline(x, first_name, ',');
        getline(x, last_name, ',');
        getline(x, id, ',');
        getline(x, password, ',');
        getline(x, email, ',');
        getline(x, phone_number, ',');
        getline(x, job_type, ',');
        getline(x, resume, ',');
        candidates.emplace_back(first_name, last_name, id, password, email, phone_number, job_type, resume);
    }
    infile.close();
    return candidates;
}
*/
void Candidate::view_favorites() const {
    if (favorites.empty()) {
        cout << "No favorite jobs yet." << endl;
        return;
    }
    cout << "Favorites jobs:" << endl;
    for (int i = 0; i < favorites.size(); ++i) {
        cout << i + 1 << ")";
        favorites[i].display_jobs();
        cout << endl;

    }
}

<<<<<<< Updated upstream
void Candidate::view_application_history() {
    if (app_history.empty()) {
=======
void Candidate ::add_application(const Jobs &job) {
    Application application = (job, *this, )
    app_history.push_back(job);
    cout << "Favorites Jobs: " << endl;
    for (int i = 0; i < favorites.size(); ++i) {
        cout << i + 1 << ") ";
        favorites[i].display_jobs();
        cout << endl;
    }
}
/*
void Candidate ::view_application_history() {
    if ( app_history.empty()){
>>>>>>> Stashed changes
        cout << "No application history yet." << endl;
        return;
    } else {
        cout << "Application history:" << endl;
        for (int i = 0; i < app_history.size(); ++i) {
            cout << i + 1 << ") ";
            app_history[i].display_application();
            cout << endl;
        }
    }
}

/*void Candidate::upload_resume(const string &file_resume) {
    resume = file_resume;
    cout << "Resume uploaded successfully." << endl;
}

*/
void Candidate::edit_profile(Candidate &candidate) {
    int choice;
    bool run = true;
    while (run) {
        cout << "Manage profile menu:" << endl;
        cout << "1. Change my first name:" << endl;
        cout << "2. Change my last name:" << endl;
        cout << "3. Change my email address:" << endl;
        cout << "4. Change my phone number:" << endl;
        cout << "5. Display my profile's details:" << endl;
        cout << "6.Exit." << endl;
        cout << "Please choose an option:" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter the new first name :";
                string new_first_name;
                cin >> new_first_name;
                candidate.set_first_name(new_first_name);
                cout << "First name updated successfully!";
                break;
            }
            case 2: {
                cout << "Enter the new last name : ";
                string new_last_name;
                cin >> new_last_name;
                candidate.set_last_name(new_last_name);
                cout << "Last name updated successfully!";
                break;
            }
            case 3: {
                cout << "Enter the new email:";
                string new_email;
                cin >> new_email;
                candidate.set_email(new_email);
                cout << "Email updated successfully!";
                break;
            }
            case 4: {
                cout << "Enter the new phone number:";
                string new_phone_number;
                cin >> new_phone_number;
                candidate.set_phone_number(new_phone_number);
                cout << "Phone number updated successfully!";
                break;
            }
            case 5: {
                candidate.display_details();
                break;
            }
            case 6:
                cout << "Goodbye!" << endl;
                run = false;
                break;
            default:
                cout << "invalid option , please try again.";
        }
    }
}

void Candidate::display_details() const {
    cout << "===================================" << endl;
    cout << "Candidate details: " << endl;
    User::display_details();
    cout << "Resume:" << (resume.empty() ? "Not uploaded" : resume) << endl;
    cout << "Phone Number:" << phone_number << endl;
    cout << "Preferred Job Type:" << job_type << endl;
    cout << "===================================" << endl;
}

void Candidate::set_first_name(const string &new_first_name) {
    first_name = new_first_name;
}

void Candidate::set_last_name(const string &new_last_name) {
    last_name = new_last_name;
}


void Candidate::set_email(const string &new_email) {
    email = new_email;
}

void Candidate::set_phone_number(const string &new_phone_number) {
    phone_number = new_phone_number;
}

/*void Candidate::add_favorite_job(Jobs &job) {
    for (const auto &fav: favorites) {
        if (fav.get_jobUID() == job.get_jobUID()) {
            cout << "This job is already in your favorites." << endl;
            return;
        }
    }
    favorites.push_back(job);
    cout << "Job added to favorites successfully!" << endl;
}
*/

