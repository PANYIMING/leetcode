#include <iostream>
#include <assert.h>
using namespace std;

void Assert(bool con, string a){
    assert(con);
    cout<<a<<endl;
}
