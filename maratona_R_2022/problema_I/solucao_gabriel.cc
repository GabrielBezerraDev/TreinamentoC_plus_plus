#include <bits/stdc++.h>

using namespace std;

//Resolvida

int main(){
    vector<int> bits(8);
    char result = 'S';
    for(int i = 0; i < bits.size(); i++){
        cin >> bits[i];
    }
    for(int i = 0; i < bits.size(); i++){
        if(bits[i] == 9){
            result = 'F';
        }
    }
    cout << result;
    return 0;
}