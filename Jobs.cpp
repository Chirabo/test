//
// Created by Shira on 10/12/2024.
//
#include "Jobs.h"
#include <vector>

Jobs::Jobs() {
    this->location = nullptr;
    this->profession = nullptr;
    this->job_type = nullptr;
    this->jobUID = nullptr;
    this->experience = nullptr;
    this->list_of_applications.clear();
}


Jobs::Jobs(string location, string profession, string job_type, string jobUID, string experience) {
    this->location = location;
    this->profession = profession;
    this->job_type = job_type;
    this->jobUID = jobUID;
    this->experience = experience;
    Jobs temp;
    temp.set_job(location, profession, job_type, jobUID, experience);
    all_jobs.push_back(temp);
}

/*
void Jobs::savetofile(const string &filename) {
    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        cout << "Error: Could not open file " << filename << " for writing." << endl;
        return;
    }
    outfile << location << "," << profession << "," << job_type << endl;
    outfile.close();
    cout << "Job saved to file successfully." << endl;
}
*/
/*
vector<Jobs> Jobs::loadfromfile(const std::string &filename) {
    vector<Jobs> jobs;
//create vector array of employers from employer type
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Error: Could not open file " << filename << " for reading." << endl;
        return jobs;
    }
    string line; // create temp line
    while (getline(infile, line)) {
        stringstream x(line);//stringstream sort sentences by key like ,
        string location, profession, job_type, jobUID, experience;
        getline(x, location, ',');
        getline(x, profession, ',');
        getline(x, job_type, ',');
        getline(x, jobUID, ',');
        getline(x, experience, ',');
        jobs.emplace_back(location, profession, job_type, jobUID, experience);
    }
    infile.close();
    return jobs;
}
*/

void Jobs ::set_application(const Application& app){
    list_of_applications.push_back(app);
}


void Jobs::set_job(string location, string profession, string job_type, string jobUID, string experience) {
    this->location = location;
    this->profession = profession;
    this->job_type = job_type;
    this->jobUID = jobUID;
    this->experience = experience;
    //max_applications = max;
}

void Jobs::update_job() {
    int choice = 0;
    bool run = true;
    while (run) {
        cout << "What do tou want to update?:" << endl;
        cout << "1. Job location :" << endl;
        cout << "2. Job profession (job title):" << endl;
        cout << "3. Job type ( full time / part time):" << endl;
        cout << "4. Required experience:" << endl;
        cout << "5.Exit." << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                string new_location;
                cout << "Enter the new location:" << endl;
                cin >> new_location;
                location = new_location;
                break;
            }
            case 2: {
                string new_profession;
                cout << "Enter the new profession:" << endl;
                cin >> new_profession;
                profession = new_profession;
                break;
            }
            case 3: {
                string new_job_type;
                cout << "Enter the new job-type :" << endl;
                cin >> new_job_type;
                job_type = new_job_type;
                break;
            }
            case 4: {
                string new_experience;
                cout << "Enter the new required experience:" << endl;
                cin >> new_experience;
                experience = new_experience;
                break;
            }
            case 5 : {
                run = false;
                cout << "Updated successfully completed!" << endl;
                break;
            }
            default:
                cout << "Invalid choice." << endl;

        }
    }
}

Jobs Jobs::create_job() {
    string profession, location, job_type, jobUID, experience;
    cout << "Enter the location:" << endl;
    cin >> location;
    cout << "Enter the profession:" << endl;
    cin >> profession;
    cout << "Enter the job type:" << endl;
    cin >> job_type;
    cout << " Enter jobUID: " << endl;
    cin >> jobUID;
    cout << " Enter required experience: " << endl;
    cin >> experience;
    return Jobs(profession, location, job_type, jobUID, experience);
}


vector<Jobs> Jobs::search_jobs() {
    string filter_location, filter_job_type, filter_experience, filter_profession;
    bool use_location = false, use_job_type = false, use_experience = false, use_profession = false;
    cout << "By which criteria do you want to search a job?" << endl;
    int choice;
    bool run = true;
    while (run) {
        cout << "Choose an option:" << endl;
        cout << "1. By location." << endl;
        cout << " 2. By job type ( full-time/part-time)" << endl;
        cout << "3. Required experience ." << endl;
        cout << "4.Profession." << endl;
        cout << "5. Display filters result." << endl;
        cout << "Exit." << endl;
        cin >> choice;
        switch (choice) {
            case 1 : {
                cout << "Enter a location:" << endl;
                cin >> filter_location;
                use_location = true;
                break;
            }
            case 2: {
                cout << "Enter the job-type:" << endl;
                cin >> filter_job_type;
                use_job_type = true;
                break;
            }
            case 3: {
                cout << "Enter your experience:" << endl;
                cin >> filter_experience;
                use_experience = true;
                break;
            }
            case 4: {
                cout << "Enter your profession:" << endl;
                cin >> filter_profession;
                use_profession = true;
                break;
            }
            case 5: {
                vector<Jobs> results;
                for (int i = 0; i < all_jobs.size(); ++i) {
                    Jobs job = all_jobs[i];
                    bool match = true;
                    if (use_location && job.get_location() != filter_location)
                        match = false;
                    if (use_job_type && job.get_job_type() != filter_job_type)
                        match = false;
                    if (use_experience && job.get_experience() != filter_experience)
                        match = false;
                    if (use_profession && job.get_profession() != filter_profession)
                        match = false;
                    if (match)
                        results.push_back(job);
                }
<<<<<<< Updated upstream
                return results;
=======
                if (results.empty()) {
                    cout << "No jobs match the given criteria." << endl;
                } else {
                    cout << "Matching jobs:" << endl;
                    for (int i = 0; i < results.size(); ++i) {
                        results[i].display_jobs();
                        cout << "----------------------" << endl;

                    }
                    cout << "Do you want ";
>>>>>>> Stashed changes
                }
            case 6 : {
                cout << "Goodbye!" << endl;
                run = false;
                break;
            }
            default:
                cout << "Invalid choice.Try again !" << endl;
        }
    }
}

/*
void Jobs::delete_job(Jobs *job, int &current_size, int index) {
    if (index < 0 || index >= current_size) {
        cout << "Invalid index . You can't delete the job." << endl;
        return;
    }
    for (int i = 0; i < current_size; ++i) {
        job[i] = job[i + 1];
        current_size--;
        cout << "The job was successfully deleted!" << endl;
        all_jobs.erase(all_jobs.begin() + index);
    }
}
*/
void Jobs::display_jobs() const {
    cout << "Job details: " << endl;
    cout << "Location: " << location << endl;
    cout << "Profession: " << profession << endl;
    cout << "Job type: " << job_type << endl;
    cout << "required experience: " << experience << endl;
    cout << "Job UID: " << jobUID << endl;
}




