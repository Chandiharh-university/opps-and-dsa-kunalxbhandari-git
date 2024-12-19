#include <iostream> // including input/output stream
using namespace std; //we don't have to write std again and again.

void passbyvalue(int num){ // function --> passbyvalue 
    cout<<"Value : " << num << endl;  // printing the value
    num+=10; // incremented the value by 10.
    cout<<"Value after increment : " << num << endl; // printing incremental value.
}

void passbyrefrence(int &num){ // function --> passbyreference
    cout<< " Value : " << num << endl; // printing the value
    num+=10; // incremented the value by 10.
    cout<<"Value after increment : " << num << endl; // printing incremental value.

}

void staticvariable(){  // function --> static variable
    static int count = 0; // set count to 0.
    count++; // increment count by 1.
    cout<<"Count after increment : " << count << endl; //print
}

float add(float num1,float num2){ // function --> add
    float sum = num1+num2;
    cout<<" Sum of two numbers num1 and num2 = " << sum << endl; // add
    return sum;
}

int main() { // main function
    float num1,num2;
    cout<<"Enter the first number you want to add : "<<endl; 
    cin>>num1;
    cout<<"Enter the second number you want to add : "<<endl;
    cin>>num2;
    add(num1,num2);
    
    cout<<"Enter Number For value and reference : " << endl;
    int num;
    cin >> num;
    passbyvalue(num);
    cout<< " FOR REFRENCE : "<< endl;;
    passbyrefrence(num);
    staticvariable();
    staticvariable();
    
    return 0;
}















