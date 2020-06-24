#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

typedef array<int, 3> triplet;

array<int, 2> compareTriplets(triplet a, triplet b) {
    array<int, 2> result = {0, 0};
    for (unsigned int i = 0; i < a.size(); i++) {
        int left = a[i], right = b[i];
        if (left > right) {
            result.at(0)++;
        } else if (right > left) {
            result.at(1)++;
        }
    }
    return result;
}

array<int, 3> parseInputLine() {
    string line;
    getline(cin, line);

    vector<string> items = split(rtrim(line));
    array<int, 3> scores;
    for (unsigned int i = 0; i < 3; i++) {
        scores[i] = stoi(items[i]);
    }
    return scores;
}

void writeResults(array<int, 2> result) {
    ofstream fout(getenv("OUTPUT_PATH"));
    for (unsigned int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";
    fout.close();
}

int main()
{

    array<int, 3> a = parseInputLine();
    array<int, 3> b = parseInputLine();

    array<int, 2> result = compareTriplets(a, b);

    writeResults(result);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

