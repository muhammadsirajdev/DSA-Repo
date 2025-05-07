// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
//     int x=10;
//     float y=8.7;
//     // cout << x;

//     // x is an integer type data,
//     // so we need a pointer of int type
//     // y is an float type data,
//     // so we need a pointer of int type

//     int*ptr =&x;
//     float*ptr1=&y;
//     cout<<ptr;
//     string car= "alto";
//     cout<<car;
//     cout<<ptr1;
//     return 0;
// }

#include <iostream>
#include <string>  // Include this for using std::string

using namespace std;

int main() {
     int x=10;
     float y=8.7;
     cout << x;

    // x is an integer type data,
    // so we need a pointer of int type
    // y is an float type data,
    // so we need a pointer of int type

    int*ptr =&x;
    float*ptr1=&y;
    cout<<"address stored in ptr is: " <<ptr<<"\n";
    cout << "initial values stores in ptrr is:" <<*ptr<<"\n";
      cout<<"address stored in ptr1 is: "<<ptr1<<"\n";
      cout<< "initial values stores in ptr1 is:" <<*ptr1<<"\n";
    //   cout<<*ptr;
      y=7.9;
      cout << "final values stores in ptr1 is:"  <<*ptr1;
    return 0;
}