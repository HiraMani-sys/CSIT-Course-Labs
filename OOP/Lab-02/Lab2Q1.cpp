#include<iostream>
using namespace std;
class Largest{
              int x;
              int y;
      public:
             l
             Largest(){
                         cout << "enter any two numbers";
                         cin >> x >> y;
                  }
             void Lnum(){
                  if (x>y){
                           cout << endl << x << "is the largest";
                           }
                  else{
                       cout << endl << y << "is the largest";
                       }
                  }
      };
      int main(){
          Largest obj1;
          obj1.Lnum();
          return 0;
          }
