#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
#include <string>
#include<cstring>

typedef struct Student
{
	char *name; // char name[40];
	char surname [40];
	// string email;
	int year;
	float average;
} Student;

void setInitStudent(Student* ps)
{
ps->name=(char*)malloc((strlen("NoName")+1)*sizeof(char));
if(!ps->name) { exit(1);}
strcpy(ps->name,"NoName");
strcpy(ps->surname,"NoSurname");
// ps->email= email;
ps->year=0;
ps->average=0;
}

void setStudent(Student* ps,const char* name,const char* surname,int year, float average)
{
if(ps->name) free(ps->name);
ps->name=(char*)malloc((strlen(name)+1)*sizeof(char));
if(!ps->name) { exit(1);}
strcpy(ps->name,name);
strcpy(ps->surname,surname);
// ps->email= email;
ps->year=year;
ps->average=average;
}
 void freeNameStudent(Student* ps)
 {
 	if(ps->name) free(ps->name);
 	ps->name=nullptr;
  } 
int getYear(Student* ps) 
{
	return ps->year;
}

void showStudent(Student* ps)
{
	cout<<"Name: " <<ps->name<<" Surname: "<<ps->surname<<" Year: "<<ps->year<<" Average: "<<ps->average<<endl;
}

void readStudent(Student* ps)
{
char name[40];
fflush(stdin);
cout<<"Name: "; cin>>name; 	
if(ps->name) free(ps->name);
ps->name=(char*)malloc((strlen(name)+1)*sizeof(char));
if(!ps->name) { exit(1);}
strcpy(ps->name,name);
cout<<"Surname: "; cin>>ps->surname;
cout<<"Year: "; cin>>ps->year;
cout<<"Average: ";cin>>ps->average;
}

void readArrayOfStudents(Student* arr, int n)
{int i;
cout<<"Enter info about students:"<<endl;
for(i=0;i<n;i++)
{
	cout<<"Student "<<i+1<<endl;
	readStudent(&arr[i]);
}
}

void showArrayOfStudents(Student* arr, int n)
{int i;
cout<<"Info about students:"<<endl;
for(i=0;i<n;i++)
{
	cout<<"Student "<<i+1<<endl;
	showStudent(&arr[i]);
}
}

void freeArray(Student* s, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		freeNameStudent(&s[i]);
	}
}

int saveArray(Student* s, int n, char* filename)
{
 int i;
 FILE* fp;
 fp=fopen(filename,"w");
 if(!fp) return 0;
 for(i=0;i<n;i++)
 {
 	fprintf(fp,"%s %s %d %.2f\n", s[i].name,s[i].surname,s[i].year,s[i].average );
	 }
	fclose(fp);
	return 1; 	
}

int loadArray(Student* s, int n, char* filename)
{
 int i;
 FILE* fp;
 fp=fopen(filename,"r");
 if(!fp) return 0;
 for(i=0;i<n;i++)
 {
 	char name[40];
	 fscanf(fp,"%s%s%d%f", name, s[i].surname, &s[i].year, &s[i].average );
	 s[i].name=(char*)calloc(strlen(name)+1,sizeof(char));
	 strcpy(s[i].name,name);
	 }
	fclose(fp);
	return 1; 	
}


int main()
{
Student a, *s;
int n,d;
char fileName[40];
FILE *fp;
setInitStudent(&a);
showStudent(&a);
setStudent(&a,"Nicolae","Nicolescu", 2, 9.5);
// printf("Year: %d \n", getYear(&a));
showStudent(&a);
readStudent(&a);
showStudent(&a);
s=(Student*)malloc(sizeof(Student));
setInitStudent(s);
showStudent(s);
free(s);
cout<<"Enter n: "; cin>>n;
s=(Student*)calloc(n,sizeof(*s));
readArrayOfStudents(s,n);
showArrayOfStudents(s,n);
cout<<"Enter file name: "; cin>> fileName;
d=saveArray(s,n,fileName);
if(d)
{
	cout<<"Array was writeen in the file"<<endl;
}
else exit(1);	
freeArray(s,n);// freeing names 
free(s); // freeng array;
s=nullptr;
s=(Student*)calloc(n,sizeof(*s));
cout<<"Memory was alocated"<<endl;
d=loadArray(s,n,fileName);
if(d)
{
	cout<<"Array was read from the file"<<endl;
}
else {
	cout<<"File was not opened"<<endl;
exit(1);
}
showArrayOfStudents(s,n);
freeArray(s,n);// freeing names 
free(s); // freeng array;
return 0;	
}