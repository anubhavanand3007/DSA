#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

int matrix_transpose(){
    int n, m;
    cin >> n >> m;
    int a[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0 ; i<n ;i++){
        for(int j=0; j<=i ;j++){
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    cout << "\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }


}

int matrix_multiplication(){
    int n1 , n2 , n3;
    cin >> n1 >> n2 >> n3;
    int a[n1][n2], b[n2][n3];

    for(int i=0; i<n1; i++)for(int j=0;j<n2;j++)cin >> a[i][j];
    for(int i=0;i<n2;i++)for(int j=0;j<n3;j++)cin>>b[i][j];

    int sum=0, ans[n1][n3] = {0};

    //acessing every row of first matrix
    for(int i=0;i<n1;i++){
        //acessing every column for the secind matrix
        for(int j=0;j<n3;j++){

            //calculating each element
            sum = 0;
            for(int k=0;k<n2;k++){
                sum += a[i][k]*b[k][j];
            }
            ans[i][j] = sum;
        }
    }

    cout << "\n";

    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int search(){
    //input matrix
    int r,c, key;
    cin >> r>> c >> key;
    int a[r][c];
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>a[i][j];

    //  [ a , b, c]
    //  [ c , d, e]
    bool found = false;
    int row = 0,col = c;
    while(row<r && col>=0){
        if(a[row][col]==key){
            found = true;
            break;
        }
        else if (a[row][col]>key)col--;
        else row++;
    }
    if(found)cout << "element found";
    else cout << "element does not exist";
}

int main(){
    int t;
    cin >> t;

    for(int test = 1; test<=t ; test++){

        cout << "Case #" << test << ": " ;// test case numbering
        //matrix_transpose();
        //matrix_multiplication();
        search();
        cout << "\n"; //endline
    }
}