#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<iomanip.h>
#include<process.h>
#include<fstream.h>
class student
{
int age;
char name[20];
public:
void search()
{
int a,count=0;
cout<<"enter age:";
cin>>a;
ifstream fin;
fin.open("myrecord.txt",ios::in);
fin.read((char*)this,sizeof(*this));
while(!fin.eof())
{
if(this->age==a)
{
count++;
cout<<"\nage is:"<<age;
cout<<"\nname is:"<<name;
}
fin.read((char*)this,sizeof(*this));
}
fin.close();
if(count!=0)
{
cout<<"\n"<<count<<"record founded";
}
else
{
cout<<"\n"<<count<<"record founded";
}
}
void insert()
{
cout<<"Enter age:";
cin>>age;
cout<<"Enter name:";
gets(name);
ofstream fout;
fout.open("myrecord.txt",ios::app);
fout.write((char*)this,sizeof(*this));
cout<<"record inserted";
fout.close();
}
void deletere()
{
int a;
int count=0;
ifstream fin;
fin.open("myrecord.txt",ios::in);
ofstream fout;
fout.open("temp.txt",ios::out);
fin.read((char*)this,sizeof(*this));
cout<<"enter the age u want to delete:";
cin>>a;
while(!fin.eof())
{
if(a==this->age)
{
count++;
}
else
{
fout.write((char*)this,sizeof(*this));
}
fin.read((char*)this,sizeof(*this));
}
fin.close();
fout.close();
remove("myrecord.txt");
rename("temp.txt","myrecord.txt");
if(count==0)
{
cout<<count<<"record found";
}
else
{
cout<<count<<"record deleted";
}
}
void update()
{
int a;
int count=0;
fstream f;
f.open("myrecord.txt",ios::in|ios::out);
f.read((char*)this,sizeof(*this));
cout<<"enter the age u want to update:";
cin>>a;
while(!f.eof())
{
if(a==this->age)
{
count++;
cout<<"\n Enter new details:";
cout<<"\nenter age:";
cin>>age;
cout<<"\nenter name:";
gets(name);
f.seekp(f.tellp()-sizeof(*this));
f.write((char*)this,sizeof(*this));
}
f.read((char*)this,sizeof(*this));
}
if(count==0)
{
cout<<count<<"record updates";
}
else
{
cout<<count<<"record updated";
}
}

void show()
{
ifstream fin;
fin.open("myrecord.txt",ios::in);
fin.read((char*)this,sizeof(*this));
while(!fin.eof())
{
cout<<"\n"<<setw(20)<<age<<setw(22)<<name<<"\n";
fin.read((char*)this,sizeof(*this));
}
}
void showheader()
{
cout<<"\n"<<setw(20)<<"AGE"<<setw(20)<<"NAME";
cout<<"\n"<<setw(20)<<"---"<<setw(20)<<"----";
}
};
void main()
{
clrscr();
int b;
student s1;
//s1.showheader();
//s1.show();
clrscr();
while(b!=6)
{
cout<<"\nenter 1 to insert the record\nenter 2 to search the record\nenter 3 to update the record\nenter 4 to delete the record\nenter 5 to display the record\nenter 6 to exit";
cout<<"\nEnter your choice:-";
cin>>b;
if(b==1)
{
clrscr();
s1.insert();
}
else if(b==2)
{
clrscr();
s1.search();
}
else if(b==3)
{
clrscr();
s1.update();
}
else if(b==4)
{
clrscr();
s1.deletere();
}
else if(b==5)
{
clrscr();
s1.showheader();
s1.show();
}
else if(b==6)
{
exit(0);
}
else
{
clrscr();
cout<<"entered invalid choice";
}
}
getch();
}