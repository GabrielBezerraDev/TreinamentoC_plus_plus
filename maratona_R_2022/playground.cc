#include<iostream>
#include<list>

using namespace std;

int main(){
    list<int> nums = {1,5,4,8,2};
    auto it = nums.end();
    cout << *it << endl;
    return 0;

}