**Sorting challenge: Sort as fast as you can _  
_**

Task: Implement a competitive sorting algorithm. The *.cpp/*.c file should be
uploaded here.

The program should respect below conditions.

1\. Windows exe file - compiled program  
2\. NAME_SURNAME_GR.exe (compile with: gcc/g++ yourProgram.c/cpp -o
NAME_SURNAME_GR.exe)  
3\. program takes 1 string as argument - name of input file  
4\. Struct of input file:  
**n** _(ex: 3) - nr of elements_  
**n elements** _(ex: 8 34 2) - elements_

5\. your program should out in the console the sorted array

Ex of your program: (Written in C language)

**_#include <stdio.h>_**

**_#include <stdlib.h>_**

**_//sort function_**

**_void sortt(int *a, int size)_**

**_{_**

**_/// do your sort here_**

**_}_**

**_int main(int ac, char **ag)_**

**_{_**

**_FILE *f;_**

**_f = fopen(ag[1], "r+"); // ag[0] is the name of the executable,_**

**_// ag[1] is the argument given to the executable_**

**_int n;_**

**_fscanf(f, "%d", &n);_**

**_int *a;_**

**_a = (int *)malloc(sizeof(int) * n);_**

**_for (int i = 0; i < n; i++)_**

**_{_**

**_fscanf(f, "%d", &a[i]);_**

**_}_**

**_// use sort_**

**_sortt(a, n);_**

**_//out the sorted array in the console (required)_**

**_for (int i = 0; i < n; i++)_**

**_printf("%d ", a[i]);_**

**_fclose(f);_**

**_return (0);_**

**_}_**
