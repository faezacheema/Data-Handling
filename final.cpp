#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 struct student{
 int rollno;
 string name;
 };
 void createRecord(){
 	ofstream file("data.txt",ios::app);
	 student std;
	 cout<<"Enter your ID: ";
	 cin>>std.rollno;
	 cout<<"Enter your name: ";
	 cin>>std.name; 
	 file<<std.rollno<<" "<<std.name<<endl;
	 file.close();
	  }
  void readRecord(){
  	ifstream file("data.txt");
  	student std;
  	cout<<"Current Records"<<endl;
  	while(file>>std.rollno>>std.name){
  		cout<<std.rollno<<" "<<std.name<<endl;
	  }
  	file.close();
  	
 	
 }
  void updateRecord(){
  	ifstream file("data.txt");
  	ofstream temp("temp.txt");
  	int rollNo;
  	string newName;
  	student std;
  	cout<<"Enter the roll no. to be updated: ";
  	cin>>rollNo;
  	while(file>>std.rollno>>std.name){
  		if(std.rollno==rollNo){
  			cout<<"Enter the new name: ";
  			cin>>newName;
  			temp<<std.rollno<<" "<<newName<<endl;
		  }
		else{
			temp<<std.rollno<<" "<<std.name<<endl;
		}
	  }
	  file.close();
	  temp.close();
	  remove("data.txt");
	  rename("temp.txt","data.txt");
	  cout<<"Record has been updated!";
  	
  	
 	
 }
  void deleteRecord(){
  	ifstream file("data.txt");
  	ofstream temp("temp.txt");
  	int rollNo;
  	
  	student std;
  	cout<<"Enter the roll no. to be deleted: ";
  	cin>>rollNo;
  	while(file>>std.rollno>>std.name){
  		if(std.rollno!=rollNo){
  			
  			temp<<std.rollno<<" "<<std.name<<endl;
		  }
		
	  }
	  file.close();
	  temp.close();
	  remove("data.txt");
	  rename("temp.txt","data.txt");
	  cout<<"Record has been deleted!";
  	
  	
 	
 	
 }
 int main(){
 	int option;
 	cout<<"---Options---"<<endl;
 	cout<<"1.Create Record"<<endl;
 	cout<<"2.Read Record"<<endl;
 	cout<<"3.Update Record"<<endl;
 	cout<<"4.Delete Record"<<endl;
 	cout<<"5.Exit"<<endl;
 	
 	cout<<"\n\n\n Enter an option: ";
 	cin>>option;
 	
 	switch(option){
 		case 1: createRecord(); break;
 		case 2: readRecord(); break;
 		case 3: updateRecord(); break;
 		case 4: deleteRecord(); break;
 		case 5: cout<<"Exiting the program."; break;
 		default:
 			cout<<"Invalid options";
	 }
 	
 	
 	return 0;
 	
 }
