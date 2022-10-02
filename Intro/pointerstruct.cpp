#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main(){
    Rectangle *P ;
    

    P = new Rectangle;
    
    cout<<P->length<<endl;
    cout<<P->breadth<<endl;
    
}