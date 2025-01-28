#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
 int n = s.length();
    
    // If the string length is odd, it's not possible to split into two equal parts
    if (n % 2 != 0) {
        return -1;
    }

    // Split the string into two halves
    string first_half = s.substr(0, n / 2);
    string second_half = s.substr(n / 2, n / 2);

    // Count frequency of characters in the first and second halves
    vector<int> freq1(26, 0), freq2(26, 0);
    
    for (char c : first_half) {
        freq1[c - 'a']++;
    }

    for (char c : second_half) {
        freq2[c - 'a']++;
    }

    // Calculate the minimum number of changes
    int changes = 0;
    for (int i = 0; i < 26; i++) {
        // The difference in frequency of characters between the two halves
        changes += abs(freq1[i] - freq2[i]);
    }

    // Return half the changes (since we are counting for one half only)
    return changes / 2;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}