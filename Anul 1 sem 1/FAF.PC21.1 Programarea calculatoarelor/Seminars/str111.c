// Scrieti un program care determina numarul de cuvinte dintr-o propozitie introdusa 
// de la tastatura si afiseaza aceste cuvinte pe ecran

#include<stdio.h>
#include<cstring>
#include<string>
#include<stdlib.h>

int nrCuv(char*);
char** cuvinte(char*, int);
void sortCuv(char**,int);
int main ( ) 
{ 
char str[100], **cuv;         
int k, i;
char *t;

puts("Dati propozitie: ");
fflush(stdin);
gets(str);                    
t=(char*)malloc((strlen(str)+1)*sizeof(char)); 
if (t==NULL) { puts("eroare 1 !"); return 1;}      
strcpy(t,str); 
k=nrCuv(t);
puts("Rezultate:");
printf("numarul de cuvinte:  %d\n", k);
strcpy(t,str); 
cuv=cuvinte(t,k);
if (cuv==NULL) { puts("eroare 2 !"); return 2;} 
puts("cuvintele nesortate: ");
i=0;                           					 
while (cuv[i] != NULL)                
{ puts (cuv[i]); 
i++;                    
}
 sortCuv(cuv, k);
puts("cuvintele sortate lexografic: ");
i=0;                           					 
while (cuv[i] != NULL)                
{ puts (cuv[i]); 
i++;                    
} 
free(t);
free(cuv);
return 0;                       
}

int nrCuv(char *t)
{

char const *sep = "!.,;:\t \n";   	
int k; char*p ;

p = strtok (t,sep);        
k=0;                          					 
while (p != NULL)                
{
k++;                 
p = strtok(NULL,sep);     
} 
return k;
}

char** cuvinte(char *t, int k)
{

char** cuv; 
char const *sep = "!.,;\t\n ";  
int i;                      
cuv=(char**)malloc((k+1)*sizeof(char*));
if (cuv==NULL) { return NULL;}
cuv[0] = strtok (t, sep);         
i=0;                          					 
while (cuv[i] !=NULL)                
{ 
i++;                  
cuv[i] = strtok(0,sep);
}    
return cuv;
}
void sortCuv(char** cuv, int k)
{ int i, j, f;
char * p;
for (i=0; i<k-1; i++)
{
	f=0;
	for(j=0; j<k-1-i; j++)
	{
	if(strcmp(cuv[j],cuv[j+1])>0) // if(strlen(cuv[j])>strlen( cuv[j+1]))
		{
		p = cuv[j];
		cuv[j] = cuv[j+1];
		cuv[j+1] = p;
		f = 1;
		}
	}
	if(f==0) break;
}
return;
}
