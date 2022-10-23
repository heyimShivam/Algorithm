#include <iostream>
using namespace std;

bool find_array(int array[],int n,int key){
 for(int i=0; i<n; i++){
 if(array[i]==key){

  return 1;
 }
 }
 return 0;
}

int main(){
int key;
cin>>key;

int arry[5]={3,5,9,4,8};
bool suraj =find_array(arry,5,key);
if(suraj){
  cout<<"the number are present";
}else{
 cout<< "the number are not present";
}

}
