#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> transpose_matrix(vector<vector<int>> arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr[i].size();j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    return arr;
}

vector<vector<int>> reverse_matrix(vector<vector<int>> arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size()/2;j++){
            swap(arr[i][j],arr[i][arr.size()-1-j]);
        }
    }
    return arr;
}

int main(){
    int n,a;
    cout<<"Enter no.of rows: ";
    cin>>n;
    cout<<"Enter elements of matrix: ";
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Transposed matrix is: "<<endl;
    vector<vector<int>> transarr(n,vector<int>(n));
    transarr=transpose_matrix(arr);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<transarr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Reversed matrix is: "<<endl;
    vector<vector<int>> reversearr(n,vector<int>(n));

    reversearr=reverse_matrix(transarr);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<reversearr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
