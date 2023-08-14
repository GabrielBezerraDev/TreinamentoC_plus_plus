#include <bits/stdc++.h>
using namespace std;

//Em processo

int main(){
    int amountWords;
    int wordsLength;
    cin >> amountWords >> wordsLength;
    vector<int> resultWords(amountWords);
    vector<vector<string>> compatibleWords(amountWords);
    vector<string> words(amountWords);
    for(int i = 0; i < words.size(); i++){
        cin >> words[i];
        if(words[i].length() != wordsLength) i--;
    }
    for(int i = 0; i < words.size(); i++){
        int compatible = 0;
        for(int j = 0; j < words.size(); j++){
            if(i != j){
                int checkingEquality = 0;
                for(int x = 0; x < wordsLength; x++){
                    if(words[i][x] == words[j][x] && words[i][x] != '*' && words[j][x] != '*'){
                        checkingEquality++;
                    }
                }
                if(checkingEquality == wordsLength-2){
                    // if(i == 0){
                    //     cout << endl << "Checando: "<< words[j] << endl;
                    // }
                    compatibleWords[i].push_back(words[j]);
                    compatible++;
                }
            }
        }
        resultWords[i] = compatible;
    }
    vector<vector<int>> finalResult = {{resultWords[0],0}};
    for(int i = 1; i < resultWords.size(); i++){
        if(finalResult[0][0] < resultWords[i]){
            finalResult[0][0] = resultWords[i];
            finalResult[0][1] = i;
        }
        else if(finalResult[0][0] == resultWords[i]){
            finalResult.push_back({resultWords[i],i});
        }
    }

    // for(int i = 0; i < finalResult.size(); i++){
    //     cout << endl << finalResult[i][0] << " " << finalResult[i][1] << endl;
    // }

    string priorityWord;
    int indice;
    for(int i = 0; i < finalResult.size(); i++){
        if(i < finalResult.size()-1){
            if(words[finalResult[i][1]] > words[finalResult[i+1][1]]){
                priorityWord = words[finalResult[i+1][1]];
                indice = finalResult[i+1][1];
            }
            else{
                priorityWord = words[finalResult[i][1]];
                indice = finalResult[i][1];
            }
        }
    }

    // for(int i = 0; i < compatibleWords[indice].size(); i++){
    //     cout << endl << "Palavra compatível: "<< compatibleWords[indice][i] << endl;
    // }

    // cout << endl << priorityWord << endl;

    char missingChar;
    int indiceChar;

    for(int i = 0; i < priorityWord.length(); i++){
        if(priorityWord[i] == '*'){
            indiceChar = i;
            break;
        }
    }
    for(int i = 0; i < compatibleWords[indice].size(); i++){
        if(compatibleWords[indice][i][indiceChar] != '*'){
            priorityWord[indiceChar] = compatibleWords[indice][i][indiceChar];
            break;
        }
    }
    // cout << endl << "Palavra completa: " << priorityWord << endl;
    // for(int i = 0; i < resultWords.size(); i++){
    //     cout << endl << words[i] << " " << resultWords[i] << endl;
    // }

     cout << priorityWord << " " << compatibleWords[indice].size();

    return 0;
}