#include <string>

using namespace std;

class LoginClass {
private:
    string username;
    string password;

public:
    bool user_login(string username, string password) {
        // cout << username << password;
        if (username == "admin" && password == "admin") {
            return true;
        } else {
            return false;
        }
    }
};
