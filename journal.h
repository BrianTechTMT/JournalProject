//
// Created by Triet Nguyen on 3/20/23.
//

#ifndef JOURNALPROJECT_JOURNAL_H
#define JOURNALPROJECT_JOURNAL_H

#endif //JOURNALPROJECT_JOURNAL_H
#include <ctime>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <utility>
#include <string>
#include <nlohmann/json.hpp>
#include <jsoncpp-master/include/json/json.h>

using namespace std;
using json =  nlohmann::json;
class JournalDetails{
public:
    int journalID;
    string journalData;
    vector<pair<string,pair<int,string>>> journal;
    json journalJSONData;
    void JournalEntry(){
        cout << "Please enter what you want to write today: ";
        cin.ignore();
        getline (cin, journalData);
    }
    void createNewJournal(string username, string journalData)
    {
        json data;
        cout << journalID;
        if(journal.size() != 0)
            journalID = journal[0].second.first + 1;
        else
            journalID = 1;
        cout << journalID;
        journal.insert(journal.begin(),make_pair(username, make_pair(journalID,journalData)));
    }

    void printJournal()
    {
        cin.ignore();
        for (auto &data: journal) {
            cout << "Username: "<< data.first << " | "<<
            "Entry ID: " << data.second.first << " | " <<
            "Entry: " << data.second.second << "\n";

        }
    }

    void saveAsJson(vector<pair<string, pair<int,string>>> savingJournal){
        for (const auto& element : savingJournal) {
            journalJSONData.push_back({
                {"username", element.first},
                {"journal",
                    {
                        {"ID", element.second.first},
                        {"Entry", element.second.second}
                    }
                }
            });
        }
        string jsonfileName = savingJournal[0].first + ".json";
        ifstream file(jsonfileName);
        if(file.is_open()){
            try{
                file.close();
                filesystem::remove(jsonfileName);
                cout << "Overwritten" << endl;
            }
            catch(const std::filesystem::filesystem_error& err) {
                std::cout << "filesystem error: " << err.what() << '\n';
            }

        }
        ofstream jsonFile(jsonfileName,std::ios::app);
        jsonFile << setw(4) << journalJSONData << endl;
    }

    void loadJSONEntries(string username)
    {
        string jsonFileName = username+".json";
        if(filesystem::exists(jsonFileName)){
            ifstream ifs(jsonFileName);
            json j;
            ifs >> j;
            string loadedUsername = j[0]["username"];
            if(username == loadedUsername){
                cout << "loading previous entries" <<  endl;
                vector<pair<string, pair<int, string>>> loadingJournal;
                for (const auto& element : j) {
                    string loaded_username = element["username"];
                    int loaded_ID = element["journal"]["ID"];
                    string loaded_entry = element["journal"]["Entry"];
                    journal.emplace_back(loaded_username, make_pair(loaded_ID,loaded_entry));
                    // cout << "loading entry" << " " << loaded_ID<< endl; Debug line
                }
                cout << "... Completed" << endl;
            }
        }
    }
};
