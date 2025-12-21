#include<iostream>
using namespace std;
class Temperature{
      double f_scale;
      double c_scale;
      public:
             void getdata(){
                  cout << "enter the temerature in f scale:";
                  cin >> f_scale;
                  }
             void display(){
                  c_scale = (f_scale-32)/1.8;
                  cout <<endl << f_scale << "F in celsius scale is " << c_scale << "C";
                  }
      };
      int main(){
          Temperature obj1;
          obj1.getdata();
          obj1.display();
          return 0;
          }
