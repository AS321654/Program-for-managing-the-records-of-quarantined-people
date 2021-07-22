#include<iostream>
#include<string>
#define trooms 5
using namespace std;
int vrooms=5;
int orooms=0;

struct Records
{
    int RoomNo;
    string name;
	string address;
	int age;
	string ArrivalDate;
	string Cfrom;
	string Goingto;
	string DisDate;
	
};
class queue{
	Records que[500];
	int front,rear;
	public:
		queue(){
			front=-1;
			rear=-1;
		}
	 void enqueue();
	 void dequeue();
	 void display();
	 void SearchRecord();
     void VacantRooms();
	 void OccRooms();
	 void SortNames();
	

		
};
void queue::enqueue()
{   
	if((front==0&&rear==trooms-1)||(front==rear+1))
	{
		cout<<"\n....No more vacant rooms....\n";
	}
	else
	{
		if(rear==-1)
		{
			front=rear=0;
		}
		else
		{
			if(rear==trooms-1)
			 rear=0;
			else
			 rear++;
		}
		
	}
	
	que[rear].RoomNo=rear+89;
	cout<<"\nRoom No.: ";
	cout<<que[rear].RoomNo;
	cin.ignore();
	cout<<"\nEnter the following the details\n";
	cout<<"\nName: ";
    getline(cin,que[rear].name);
    cout<<"\nAddress: ";
	getline(cin,que[rear].address);
	cout<<"\nAge: ";
	cin>>que[rear].age;
	cin.ignore();
	cout<<"\nArrival Date: ";
	getline(cin,que[rear].ArrivalDate);
	cout<<"\nComing From: ";
	getline(cin,que[rear].Cfrom);
	cout<<"\nGoing to: ";
	getline(cin,que[rear].Goingto);
	cout<<"\nDischarged Date: ";
	getline(cin,que[rear].DisDate);
	
	
	vrooms--;
	orooms++;
	
}
void queue::dequeue() 
{       if(front==-1)
       {
	     cout<<"\n...No More Records to delete...";
       }
       else{cout<<"\nThe deleted record details are\n";
		cout<<"\nRoom No: ";
		cout<<que[front].RoomNo;
		cout<<"\nName: ";
		cout<<que[front].name;
		cout<<"\nAddress: ";
		cout<<que[front].address;
		cout<<"\nAge: ";
		cout<<que[front].age;
		cout<<"\nArrival Date: ";
		cout<<que[front].ArrivalDate;
		cout<<"\nComing From: ";
		cout<<que[front].Cfrom;
		cout<<"\nGoing to: ";
		cout<<que[front].Goingto;
		cout<<"\nDischarged Date: ";
		cout<<que[front].DisDate;
	   }

		
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else 
		{if(front==trooms-1)
		  front=0;
		 else
		  front++;
		}
		vrooms++;
		orooms--;
		
		
	
}
void queue::display()
{
	int i=0;
	cout<<"\n                                    ***********Records***********\n";
	if(front==-1)
	{
		cout<<"\n                                          ***************Records are empty*****************\n";
	}
	else 
	{if(rear>=front)
	{   cout<<"\nRoom No....Name.....Address.....Age....Arrival Date....Coming from......Going to.......Discharged Date\n";
		
		
		for(i=front;i<=rear;i++)
		{
			cout<<que[i].RoomNo;
	 	    cout<<"        ";
		    cout<<que[i].name;
		    cout<<"       ";
		    cout<<que[i].address;
		    cout<<"      ";
		    cout<<que[i].age;
		    cout<<"      ";
		    cout<<que[i].ArrivalDate;
		    cout<<"       ";
		    cout<<que[i].Cfrom;
		    cout<<"      ";
		    cout<<que[i].Goingto;
		    cout<<"      ";
		    cout<<que[i].DisDate;
		    cout<<endl<<endl;
		    
		}
   }
	else
	{
			for(i=0;i<=rear;i++)
			{cout<<que[i].RoomNo;
	 	    cout<<"     ";
		    cout<<que[i].name;
		    cout<<"   ";
		    cout<<que[i].address;
		    cout<<"   ";
		    cout<<que[i].age;
		    cout<<"   ";
		    cout<<que[i].ArrivalDate;
		    cout<<"   ";
		    cout<<que[i].Cfrom;
		    cout<<"   ";
		    cout<<que[i].Goingto;
		    cout<<"   ";
		    cout<<que[i].DisDate;
		    cout<<endl<<endl;
			}
			
			for(i=front;i<trooms;i++)
		   { cout<<que[i].RoomNo;
	 	    cout<<"     ";
		    cout<<que[i].name;
		    cout<<"   ";
		    cout<<que[i].address;
		    cout<<"   ";
		    cout<<que[i].age;
		    cout<<"   ";
		    cout<<que[i].ArrivalDate;
		    cout<<"   ";
		    cout<<que[i].Cfrom;
		    cout<<"   ";
		    cout<<que[i].Goingto;
		    cout<<"   ";
		    cout<<que[i].DisDate;
		    cout<<endl<<endl;
		   }
			
	
	}
	}
	
}
void queue::VacantRooms()
{
	 cout<<"\n*****Total Number of vacant rooms******\n";
	 cout<<vrooms<<endl;
	 if(vrooms==0)
	 {
	 	cout<<"\nAll rooms are occupied\n";
	 }
	 else
	{
	  cout<<"\nList of Vacant Rooms\n";
	  if(rear>=front)
	  { 
	     for(int i=0;i<front;i++)
		 {
		  cout<<i+89<<endl;
	     }
	     if(rear!=trooms-1)
	     {for(int i=rear+1;i<trooms;i++)
	      {
	     	cout<<i+89<<endl;
		  }
		 }
	 	
	  }
	  else
      {
     	for(int i=rear+1;i<front;i++)
     	{
     		cout<<i+89<<endl;
		}
	  }
    }
	    
	 
	 
	 
}
void queue::OccRooms()
{   
    cout<<"\nNumber of Occupied Rooms\n";
    cout<<orooms;
     int i;
    if(front==-1)
	{
		cout<<"\n                                          ***************All Rooms are vacant*****************\n";
	}
	else 
	{if(rear>=front)
	 {   cout<<"\nRoom No\n";
		
		for(i=front;i<=rear;i++)
		{
			cout<<que[i].RoomNo<<endl;
		    
		}
     }
	 else
	 {      cout<<"\nRoom No\n";
			for(i=0;i<=rear;i++)
			{cout<<que[i].RoomNo;
		    cout<<endl;
			}
			
			for(i=front;i<trooms;i++)
		   { cout<<que[i].RoomNo;
	 	     cout<<endl;
		   }
			
	
	 }
	}
	
	
}

int main()
{
	queue Rec;
    int num;
	cout<<"                                             *****************Quarentine People's Record*****************\n";
	while(1)
	{
		cout<<"\nMenu: \n 1)New Record \n 2)Delete Record \n 3)Display \n 4)Search Record \n 5)No. of Vacant Rooms \n 6)No. of Occupied Rooms \n 7) Sort Names\n 8)Exit\n\n";
		cout<<"Enter Your Choice:\n";
		cin>>num;
		switch(num)
		{
			case 1 :Rec.enqueue();
				     break;
			case 2 :Rec.dequeue();
			        break;
			case 3 :Rec.display();
			        break;
			case 4 :Rec.SearchRecord();
			        break;
			case 5 :Rec.VacantRooms();
			        cout<<endl;
			        break;
			case 6 :Rec.OccRooms();
			        cout<<endl;
			        break;
			case 7 :Rec.SortNames();
			        break;
			case 8 :exit(0);
			default: cout<<"Wrong choice entered" ;
			
		}
	}
	return 0;
}
