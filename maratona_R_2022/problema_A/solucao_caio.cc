#include <bits/stdc++.h>
 
using namespace std;
 
int count_a_in_maximal_monotone_chunks(int N, string sequence) {
    int count = 0;
    char current_chunk = '\0';
    int current_count = 0;
 
    for (int i = 0; i < N; ++i) {
        char ch = sequence[i];
        if (current_chunk == '\0' || ch == current_chunk) {
            current_chunk = ch;
            current_count++;
        } else {
            if (current_count >= 2 && current_chunk == 'a') {
                count += current_count;
            }
            current_chunk = ch;
            current_count = 1;
        }
    }
 
    if (current_count >= 2 && current_chunk == 'a') {
        count += current_count;
    }
    return count;
}
 
int main() {
    int N;
    string sequence;
 
    cin >> N;
    cin >> sequence;
 
    int result = count_a_in_maximal_monotone_chunks(N, sequence);
    cout << result << endl;
 
    return 0;
}