#include "IntList.h"
#include <iostream>

using namespace std;

int main() {
    cout<<boolalpha;

    IntList list0;
    cout<<"List0 inital test: "<<endl;
    cout<<"EMPTY: "<<list0.empty()<<endl;
    list0.push_front(0);
    cout<<"One Value: "<<list0<<endl;
    list0.push_front(1);
    list0.push_front(2);
    cout<<"EMPTY: "<<list0.empty()<<endl;
    cout<<"Three Values: "<<list0<<endl;

    list0.pop_front();
    cout<<"Two Values (pop): " << list0 << endl;
    list0.pop_front();
    list0.pop_front();
    cout<<"NO Values (popped): "<<list0<<endl;
    list0.pop_front();
    cout << "Poping empty list: "<<list0<<endl;
    
    list0.push_back(-1);
    cout<<"Push back in empty list: "<<list0<<endl;

    list0.push_back(-2);
    list0.push_back(-3);
    cout<<"Push back 3 values: "<<list0<<endl;

    cout<<"Print Reverse: "<<endl;
    list0.printReverse();
    cout<<endl;
    list0.pop_back();
    list0.printReverse();
    cout<<endl;
    list0.pop_back();
    list0.printReverse();
    cout<<endl;
    list0.pop_back();
    
    cout<<"Print Reverse of empty: ";
    list0.printReverse();

    
    return 0;
}