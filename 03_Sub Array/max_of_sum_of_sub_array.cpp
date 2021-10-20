#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

int brute_force_approach(int a[], int n){
    int max_sum=0;
    int sum=0;
    f(i,n){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                sum+=a[k];
            }
            if(max_sum<sum)max_sum=sum;
            sum=0;
        }
    }
    cout << max_sum; 
}

int cummulative_sum_approach(int a[], int n){
    int cumm_sum=0;
    int max_sum=0;
    
    f(i,n){
        for(int j=i;j<n;j++){
            cumm_sum += a[j];
            if(cumm_sum>max_sum)max_sum=cumm_sum;
        }
        cumm_sum=0;
    }
    cout << max_sum;
}

int kadanes_algo(int a[], int n){
    //when curr sum<0 make curr sum=0
    //keep recording max sum;
    int curr_sum=0;
    int max_sum=INT_MIN;
    f(i,n){
        curr_sum += a[i];
        if(curr_sum<0)curr_sum=0;
        if(max_sum<curr_sum)max_sum=curr_sum;
    }
    cout << max_sum;
    return max_sum;
}


int max_sum_subarray_for_circular_array(int a[], int n){
    //check wether the contributing elements are wrapping of not
    //for wrapping only kadane, and
    //for un wrapping eliminate sum of non-contributing element from sum of array
    //find non contributing by negetivating value and applying kadane
    
    
    int array_sum=0, max_sum_of_non_contr, max_sum_of_wrap, max_sum_of_non_wrap, max_sum_of_subarray;

    //let max will be found without wrapping
    max_sum_of_non_wrap = kadanes_algo(a,n);
    
    //let max will be found without wrapping
    f(i,n){
        array_sum += a[i];
        a[i] = -a[i];
    }
    max_sum_of_non_contr = kadanes_algo(a,n);
    max_sum_of_wrap =  array_sum + max_sum_of_non_contr;

    if(max_sum_of_non_wrap>max_sum_of_wrap)max_sum_of_subarray=max_sum_of_non_wrap;
    else max_sum_of_subarray=max_sum_of_wrap;

    cout << max_sum_of_subarray;
    return max_sum_of_subarray;
}

int solve(){
    ;
}

int main(){
int n;
cin >> n;
int a[n];
for(int i=0;i<n;i++)cin >> a[i];
brute_force_approach(a,n);
cummulative_sum_approach(a,n);
kadanes_algo(a,n);
max_sum_subarray_for_circular_array(a,n);

}