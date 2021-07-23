#include<iostream>
#include<string>
#include<sstream>
#define trooms 5
using namespace std;
int vrooms=5;
int orooms=0;

struct Records
{
    int RoomNo;
    string name;
	string address;
	string age;
	string ArrivalDate;
	string Cfrom;
	string Goingto;
	string DisDate;
	
};
class queue{
	Records que[500];
	int front,rear;
	void SortNames(Records temp[],int l,int r);
	void merge(Records temp[],int l,int m,int r);
	void transfer(Records temp[]);
	public:
		queue(){
			front=-1;
			rear=-1;
		}
	 void enqueue();
	 void dequeue();
	 void display();
     void VacantRooms();
	 void OccRooms();
	 void sort();
	 void search();
	
};
void queue::enqueue()
{   
	if((front==0&&rear==trooms-1)||(front==rear+1))
	{
		cout<<"\n....No more vacant rooms....\n";
		return;
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
	cout<<"\nEnter the following the details\n";
	cout<<"\nName: ";
    getline(cin,que[rear].name);
    cout<<"\nAddress: ";
	getline(cin,que[rear].address);
	age:cout<<"\nAge: ";
	getline(cin,que[rear].age);
	for(int i=0;i<que[rear].age.length();i++)
	{
		if(isdigit(que[rear].age[i])==false)
		 {
		  cout<<"\nEnter a valid Whole Number in age\n";
		  goto age;
	     }
		else
		 break;
		
	}
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
	     cout<<"\n                        ...No Records yet...";
	     return;
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
		cout<<endl<<endl;
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
		cout<<"\n                                          ***************No Records yet*****************\n";
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
	 {      cout<<"\nRoom No....Name.....Address.....Age....Arrival Date....Coming from......Going to.......Discharged Date\n";
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
void queue::transfer(Records temp[])
{
	int count=0;
	if(rear>=front)
	{
		for(int i=front,j=0;i<=rear;i++,j++)
		{
			temp[j]=que[i];
			
		}
	}
	else
	{
		for(int i=front,j=0;i<trooms;i++,j++)
		{
			temp[j]=que[i];
			count++;
		
		}
		for(int i=0,j=count;i<=rear;i++,j++)
		{
			temp[j]=que[i];
			
		}
	}
}
void queue::search()
{   if(front==-1&&rear==-1)
    {
    	cout<<"\n                 **************No Records yet*************\n";
    	return;
	}
	
	 int N;
	 Roomno: cout<<"\nEnter a valid Room Number to find out the details(89-411)\n";
	         cin>>N;
	         cin.ignore();
	 if(N<89||N>411)
	 {
	 	cout<<"\n***Not a Valid Room Number***\n";
	 	goto Roomno;
	 	
	 }
	 
	 Records temp[orooms];
	 int first=0;
	 int last=orooms-1;
	 int mid=(first+last)/2;
	 transfer(temp);
	 SortNames(temp, 0, orooms-1);
	 while(first<=last)
	 {
		if(temp[mid].RoomNo<N)
		 {
		 	first=mid+1;
		 }
	    
	    else if(temp[mid].RoomNo==N)
	    {   cout<<"\nRoom No....Name.....Address.....Age....Arrival Date....Coming from......Going to.......Discharged Date\n";
		    cout<<temp[mid].RoomNo;
	 	    cout<<"        ";
		    cout<<temp[mid].name;
		    cout<<"       ";
		    cout<<temp[mid].address;
		    cout<<"      ";
		    cout<<temp[mid].age;
		    cout<<"      ";
		    cout<<temp[mid].ArrivalDate;
		    cout<<"       ";
		    cout<<temp[mid].Cfrom;
		    cout<<"      ";
		    cout<<temp[mid].Goingto;
		    cout<<"      ";
		    cout<<temp[mid].DisDate;
		    cout<<endl<<endl;
		    break;
	    }
	    else{
	    	last=mid-1;
		}
		mid=(first+last)/2;
     } 
    
     if(first>last)
      cout<<"\nThis Room Number is Vacant\n";
    

}
void queue::merge(Records temp[],int low,int high,int mid)
{
	int i, j, k;
	Records  a[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	
	while (i <= mid && j <= high)
	{
		if (temp[i].RoomNo< temp[j].RoomNo)
		{
			a[k] = temp[i];
			k++;
			i++;
		}
		else
		{
			a[k] = temp[j];
			k++;
			j++;
		}
	}
 
	
	while (i <= mid)
	{
		a[k] = temp[i];
		k++;
		i++;
	}
 
	
	while (j <= high)
	{
		a[k] = temp[j];
		k++;
		j++;
	}
 
 
	
	for (i = low; i <= high; i++)
	{
		temp[i] = a[i-low];
	}
	
}
void queue::SortNames(Records temp[],int low,int high)
{   int mid;
	if(low<high)
	{ mid=(low+high)/2;
	 SortNames(temp,low,mid);
	 SortNames(temp,mid+1,high);
	 merge(temp,low,high,mid);
	}
	
}
void queue::sort()
{   if(front==-1&&rear==-1)
    {
    	cout<<"\n               ***********No Records yet*************\n";
	}
	else
	{Records temp[orooms];
     transfer(temp);
	 SortNames(temp, 0, orooms-1);
	 cout<<"\nSorting of Names as per their Room No\n ";
	 cout<<"Room No.   Name";
	 for(int i=0;i<orooms;i++)
	 {   cout<<endl;
		cout<<" "<<temp[i].RoomNo;
		cout<<"         ";
		cout<<temp[i].name;
		cout<<endl;
	 } 
	 cout<<endl;
		
	}
    
}

int main()
{
	queue Rec;
    
    int k=0;
	cout<<"                                             *****************Quarentine People's Record*****************\n";
	while(1)
	{   
	    string num;
		cout<<"\nMenu: \n 1)New Record \n 2)Delete Record \n 3)Display \n 4)Search Record \n 5)Vacant Rooms \n 6)Occupied Rooms \n 7)Sort Names\n 8)Exit\n\n";
		choice: cout<<"Enter Your Choice:\n";
		        getline(cin,num);
	    for(int i=0;i<num.length();i++)
	   {
		if(isdigit(num[i])==false)
		 {
		  cout<<"\nEnter a valid Whole Number in choice\n";
		  goto choice;
	     }
		else
		 {
		   
		   stringstream choice(num);
		   choice>>k;
		   break;
	     }
		
	   }
		
		switch(k)
		{
			case 1 :Rec.enqueue();
				      break;
			case 2 :Rec.dequeue();
			          break;
			case 3 :Rec.display();
			          break;
			case 4 :Rec.search();
			        break;
			case 5 :Rec.VacantRooms();
			        cout<<endl;
			        break;
			case 6 :Rec.OccRooms();
			        cout<<endl;
			        break;
			case 7 :Rec.sort();
			        break;
			case 8 :exit(0);
			default: cout<<"Wrong choice entered" ;
			
		}
	}
	return 0;
}
