#include <iostream>
#include <map>
#include "login.h"
#include "journal.h"
using namespace std;

int main() {
    int LoginOptions=0;
    LoginClass studentA;
    JournalDetails studentJournal;
    string loginUsername;
    string loginPassword;
    bool checklogin;
    while (LoginOptions != 4) {
        cout << "Login CI:\n"
                "1. Login\n"
                "2. Print\n"
                "3. Add new journal\n"
                "4. Sign Out\n";
            cout << "Please enter your options: ";
            cin >> LoginOptions;
            if (LoginOptions == 1) {
                cout << "Please Enter your username: ";
                cin >> loginUsername;
                cout << "Please Enter your password: ";
                cin >> loginPassword;
                checklogin = studentA.userLogin(loginUsername,loginPassword);
                if (checklogin) {
                    cout << "Login Successful\n";
                } else {
                    cout << "Login Failed!\nYou will be force to logout now";
                    break;
                }
            }
            else if (LoginOptions == 2) {
                for (auto &data: studentJournal.journal) {
                    cout << data.first << " "
                         << data.second << "\n";
                    }
            } else if (LoginOptions == 3) {
                cin.ignore();
                cout << "Create new Journal\n Please enter Journal ID: ";
                cin >> studentJournal.journalID;
                cout << "Please enter what you want to write today:";
                cin.ignore();
                getline(cin, studentJournal.journalData);
                studentJournal.createNewJournal(studentJournal.journalID, studentJournal.journalData);
            }
    }
}
