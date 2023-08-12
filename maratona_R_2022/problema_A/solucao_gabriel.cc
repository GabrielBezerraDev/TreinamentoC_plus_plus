#include <iostream> 
#include <string>

using namespace std;

//Resolvida

//Autor solução Gabriel
int main(){
    int valueToSum = 2;
    int count = 0;
    string word;
    cin >> word;
    for(int i = 0; i < word.size(); i++){
        if(word[i] == 'a' && i < word.size()-1){
            if(word[i] == word[i+1]){
               count += valueToSum;
               valueToSum = 1; 
            }
            else{
                valueToSum = 2;
            }
        }
    }
    cout << "Valor total de a: " << count << endl;
    return 0;
}
