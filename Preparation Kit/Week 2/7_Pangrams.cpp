#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    bool letters[26] = {false};
    int count = 0;

    for (char c : s) {
        if (isalpha(c)) {
            int index = tolower(c) - 'a';
            if (!letters[index]) {
                letters[index] = true;
                count++;
                if (count == 26) {
                    return "pangram";
                }
            }
        }
    }
    return "not pangram";
}

// string pangrams(string s) {
//     unordered_set<char> letters;

//     for (char c : s) {
//         if (isalpha(c)) {
//             letters.insert(tolower(c));
//         }
//     }
//     if (letters.size() == 26) {
//         return "pangram";
//     } else {
//         return "not pangram";
//     }
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
