//
// Created by Triet Nguyen on 3/20/23.
//

#ifndef JOURNALPROJECT_JOURNAL_H
#define JOURNALPROJECT_JOURNAL_H

#endif //JOURNALPROJECT_JOURNAL_H
#include <ctime>
#include <iostream>
#include <map>
#include <string>
using namespace std;
class JournalDetails{
public:
    int journalID;
    string journalData;
    map<string, pair<int,string>> journal;
    void JournalEntry(){
        cin.ignore();
        cout << "Create new Journal\n Please enter Journal ID: ";
        cin >> journalID;
        cout << "Please enter what you want to write today:";
        cin.ignore();
        getline (cin, journalData);
    }
    void createNewJournal(string username, int journalID, string journalData)
    {
        journal.insert({username, pair(journalID,journalData)});
    }
};
