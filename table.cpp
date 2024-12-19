#include <iostream>
using namespace std;

int table(int num){
    for(int i = 0; i<11;i++){
        cout<< num << " x " << i << " = " << num*i <<endl;
    }
    return 0;
}


int main()
{
    cout<<"Enter The Number : " <<endl;
    int num;
    cin>>num;
    table(num);

    return 0;
}
