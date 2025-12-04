#include<iostream>
using namespace std;
#define MAX 10

	
	int main()
	{
		int a[MAX], count=-1, choice=0, temp=0, pos, i=0, element=0;
		bool found=false;
		cout <<"press the number for the following operation:" << endl;
		cout << "press 1 for insert"<< endl;
		cout << "press 2 for display" << endl;
		cout << "press 3 for delete" << endl;
		cout << "press 4 for update" << endl;
		cout << "press 5 for searching" << endl;
		cout << "press 6 for find max" << endl;
		cout << "press 7 for find min" << endl;
		
		cout << "enter your choice:" ;
		cin >> choice;
		switch(choice)
		{
			case 1:
				if (count == MAX-1){
					cout << "Array is full " << endl;
				}
				else{
					count=count;
					cout << "enter the data of array " << (count+2) << ":";
					cin >> a[count];
					}
			break;
			
			case 2:
				if (count < 0){
				cout << "Array is empty" << endl;
				}	
				else {
					for (i=0;i<count;i++){
						cout << "the value of array " << (i+1) << " :" << a[i];
					}
			}
			break;
			
			case 3:
				cout << "enter the position of an array to delete:" ;
				cin >> pos;
				temp = a[pos];
				for (i=pos; i<MAX-1; i++)
				{
					a[i]=a[i+1];
				}
				cout << "the deleted data and its position is " << a[pos] << "and " << pos;
			break;
				
			case 4:
				cout << "Enter the position of array to update:" ;
				cin >> pos;
					if(pos<0||pos>=count)
					{
						cout << "Invalid Position." << endl;
					}
					else
					{
						cout << "enter new data: ";
						cin >> temp;
						a[pos]=temp;		
					}	
			break;
			
			case 5:
				cout << "enter the element to search:";
				cin >> element;
				for (i=0 ; i<count; i++)
				{
					if (a[i]==element)
					{
						cout << "found in position " << i << "." << endl;
					found=true;
					}
				}
				if(found!=true)
				{
					cout << "element not found." << endl;
				}
			break;
			
			case 6:
				if (count<0)
				{
					cout << "Array is empty." << endl;
	
				}
				else {
					int minVal=a[0];
						for(i=0;i<count;i++){
							if(a[i]<minVal)
							{
								minVal=a[i];
							}
						}
					cout << "the minimum value in an array is " << minVal << "." << endl;
				}
			break;		
			
			case 7:
				if (count<0)
				{
					cout << "Array is empty." << endl;
	
				}
				else {
					int maxVal=a[0];
					for(i=0;i<count;i++){
						if(a[i]<maxVal)
						{
							maxVal=a[i];
						}
					}
					cout << "the maximum value in an array is " << maxVal << "." << endl;
				}
				
			default:
				cout << "Invalid choice. Try again" << endl;
				
		return 0;	
 	}
 }
