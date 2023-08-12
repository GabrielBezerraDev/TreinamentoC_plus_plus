#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int a[9], n = 0, test = 1;
    
    for (int i = 0; i < 8; i++){
        cin >> a[i];
    }
    
    for (int i = 0; i < 8; i++){
        int num = a[i];
        if(num != 1 && num != 0){
            test = 0;
            break;
        }
    }
    if(test == 0){
        cout << "F" << endl;
    }else{
        cout << "S" << endl;
    }
}