#include<bits/stdc++.h>
using namespace std;

int isPowerof2(int n){
    int ReverseBitTill1 = n-1;
    int answer = (n & ReverseBitTill1);
    if(n==0)return false;
    else{
        if(answer == 0)return true;
        else return false;
    } 
}

int totalBit(int n){
    int count =0;
    while(n>0){
        n = n & (n-1); //by this operation only the right most 1 get affected
        count++;
    }
    return count;
}

int PrintAllSubSet(){
   int a[9] = {1,2};
    
    for(int subset = 0; subset < pow(2,2)-1; subset++){
        cout << '{';
        for(int pos = 0; pos<9; pos++){
            if(subset & (1<<pos))cout << a[pos]<< ", ";
        }
        cout << "}" << "\n";
    }
    
} 

int rare_number(){
    int a[] = {1,2,3,4,5,6,5,4,3,2,1};
    int xorsum = 0;
    for(int i=0;i<11;i++){
        xorsum = xorsum^a[i];
    }

}

int solve(){
    int n = 10;  
    cout << isPowerof2(n) << endl;
    cout << totalBit(n) << endl;
    cout << PrintAllSubSet()<< endl;
    cout << rare_number();
}

int main(){
    solve();
}