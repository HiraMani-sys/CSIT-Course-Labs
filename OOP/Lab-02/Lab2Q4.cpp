#include<iostream>
using namespace std;
class Time{
	int t[2];
	int h;
	int m;
	int s;
	public:
void getTime(){
	cout << "Enter first time in HH:MM:SS";
	cin >> t[1].h >> t[1].m >> t[1].s;
		cout << "Enter second time in HH:MM:SS";
	cin >> t[2].h >> t[2].m >> t[2].s;

}
void calculate(){
t[0].h=t[1].h+t[2].h;
t[0].m=t[1].m+t[2].m;
t[0].s=t[1].s+t[2].s;
while (t[0].s>=60){
	t[0].m++;
	t[0].s-60;
}
while (t[0].m>=60){
	t[0].h++;
	t[0].m-60;
}
}
void display(){
	cout << "HH:MM:SS" << t[0].h << ":" << t[0].m << ":" << t[0].s << ":" << endl;
}
};
while
int main(){
	Time obj1;
	obj1.getTime();
	obj1.calculate();
	obj1.display();
	return 0;
}
