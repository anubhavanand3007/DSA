#include<bits/stdc++.h>
using namespace std;

int input(){
    string name;
    getline(cin,name);
    cout << name;
    cin >> name;
    cout << '\n' <<name;
}

int concatimate(){
    string s1 ="fam";
    string s2 = "ily";

    s1.append(s2);
    cout << "\n" << s1;
    string a =s1+s2;
    cout << a;

    a.clear();
}

int compare(){
    string a = "Anubhav";
    string b = "Anubhav";
    string c = "Anand";

    cout << a.compare(b) << "\n";
    cout << a.compare(c) << "\n";
    cout << c.compare(a) << "\n";

    a.clear();

    cout << a.empty() << "\n";
}

int solve(){
    input();
    concatimate();
    compare();
}

int main(){
    solve();
}