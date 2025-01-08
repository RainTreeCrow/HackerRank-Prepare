#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

void splitCamelCase(string input, char type) {
    if (type == 'M') {
        input = input.substr(0, input.length() - 2);  // Remove "()"
    }
    if (type == 'C') {
        cout << (char)tolower(input[0]);
    } else {
        cout << (char)input[0];
    }

    for (size_t i = 1; i < input.length(); i++) {
        if (isupper(input[i])) {
            cout << " " << (char)tolower(input[i]);
        } else {
            cout << (char)input[i];
        }
    }
    cout << endl;
}

void combineCamelCase(string input, char type) {
    if (type == 'C') {
        cout << (char)toupper(input[0]);
    } else {
        cout << (char)input[0];
    }
    bool flag = false;
    
    for (int i = 1; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            flag = true;
        } else {
            if (flag == 1) {
                cout << (char)toupper(input[i]);
                flag = false;
            }
            else {
                cout << (char)input[i];
            }
        }
    }
    if (type == 'M') cout << "()";
    cout << endl;
}

int main() {
    string line;
    while (getline(cin, line)) {
        line.erase(line.find_last_not_of("\r\n") + 1);

        char operation = line[0];
        char type = line[2];
        string input = line.substr(4);

        if (operation == 'S') {
            splitCamelCase(input, type);
        } else if (operation == 'C') {
            combineCamelCase(input, type);
        }
    }
    return 0;
}
