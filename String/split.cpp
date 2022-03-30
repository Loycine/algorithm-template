#include <bits/stdc++.h>
using namespace std;

void split(const std::string& str, vector<string>& ret, char delim = ' ')
{
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        ret.push_back(token);
    }
}

vector<string> split(const std::string& str, char delim = ' ')
{
    vector<string> res;
    int current, previous = 0;
    current = str.find(delim);
    while (current != -1) {
        res.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    res.push_back(str.substr(previous, current - previous));
    return res;
}

int main(){ 
    string s = "[1,2,3,null,1,2,null,null,null,null,null,null,1,null,null]";

    vector<string> v;
    split(s.substr(1,s.size()-2), v ,',');
    for(auto x : v) {
        cout << x << "\n";
    }
}
