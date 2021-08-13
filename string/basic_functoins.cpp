#include<bits/stdc++.h>
using namespace std;

int input(){
    string name;
    getline(cin,name);
    cout << name;
    cin >> name;
    cout << '\n' <<name;
}

int concatinate(){
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

int crud(){
    string a = "nicompoop";
    int index = 0;
    int num_of_char = 5; 

    a.erase(0,5);
    cout << a <<"\n";

    cout << a.find("o"); //return 1st index where it is found

    a.insert(index,"nicom");
    cout <<"\n" << a;

    for(int i=0;i<a.size();i++){
        cout << endl << a[i] ;
    }

    string sunString = a.substr(index,num_of_char);

}

int conversion(){
    string a = "123";
    int x = stoi(a);
    cout << endl<< x++;
    cout << endl << x++;
    int p = 123;
    a = to_string(p) + '2';
    cout << endl << a;
}

int sort(){
    string a = "bla bla";
    sort(a.begin(),a.end()); //.begin and .end are pointer
}

int transforming_to_upper_or_lower(){
    string a = "qertyQWERTY";
    cout <<endl << a << endl;
    transform(a.begin(), a.end(),a.begin(), ::toupper);
    cout << a << endl;
    transform(a.begin(), a.end(),a.begin(), ::tolower);
    cout << a << endl;


}

int solve(){
    input();
    concatinate();
    compare();
    crud();
    conversion();
    sort();
    transforming_to_upper_or_lower();
}

int main(){
    solve();
}