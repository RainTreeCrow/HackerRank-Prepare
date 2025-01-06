#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hour = s.substr(0, 2);
    string minute = s.substr(3, 2);
    string second = s.substr(6, 2);
    string period = s.substr(8, 2);

    int hh = stoi(hour);

    if (period == "AM") {
        if (hh == 12) {
            hh = 0;
        }
    } else {
        if (hh != 12) {
            hh += 12;
        }
    }

    stringstream result;
    result << setfill('0') << setw(2) << hh << ":"
           << minute << ":"
           << second;

    return result.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
