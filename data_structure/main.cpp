#include "ArrayList.hpp"
#include <iostream>
using namespace std;

int main(){
    AList <int> a(10);
    a.insert(10);
    cout<<a.currPos()<<endl;
    cout<<a.getValue()<<endl;
return 0;
}
