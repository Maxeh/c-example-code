/* widechar.c */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// swap the value of two variables 
void swapping(int *c, int *d) {
    int temp = *c;
    *c = *d;
    *d = temp;
}

void printHelloWorld() {
    char o[12] = "Hello world";
    char *o_ptr = &o[0];
    for (int i = 0; i < strlen(o); i++) {
        printf("%c \n", *(o_ptr + i)); 
    }
}

void pointerArithmetic() {
    char *(*p) = (char**) malloc(sizeof(*p) * 2); // pointer to a pointer to a char array
    *p = "Hey"; //equivalent to p[0], 
    *(p + 1) = "There";  //equivalent to p[1]
    printf("%s ", p[0]); // Hey
    printf("%s \n", p[1]); // There
    printf("%c", **p); // "H"
    printf("%c", *(*p+1)); // "e"
    printf("%c", *(*p+2)); // "y"
    printf("%c", **(p+1)); // "T"
    printf("\n");
    char *s = "Hi";
    printf("%p \n", s);
    printf("%p \n", *s);
    printf("%c", *(s+1)); // i
}

void pointerToPointer() {
    char **ptr = NULL; 
    char *p = NULL;
    char c = 'A';

    p = &c;
    ptr = &p;
    
    /* 
     * (|address of pointer| |value of pointer which is address it points to|) ---> (|address of variable||value of variable|)
     * dereferencing pointer provides value of variable (*pointer)
     */

    printf("\n [%c]\n",c); // value of c
    printf("\n [%d]\n",&c); // address of c - equals below
    printf("\n [%d]\n",p); // p points to address of c - equals above
    printf("\n [%c]\n",*p); // dereferenced p provides value of c
    printf("\n [%d]\n", &p); // p has also an adress
    printf("\n [%c]\n",**ptr); // two asterisk dereference of ptr provides value of c 
    printf("\n [%d]\n",*ptr); // one asterisk dereference of ptr provides value of p which is the address of c 
    printf("\n [%d]\n",ptr); // ptr points to adress of p 
    printf("\n [%d]\n",&ptr); // ptr has also an address 
        
    return 0;
}

void dynamicTwoDimArray() {
    int size = 3;
    char **c;
    if ((c = malloc(size*sizeof(*c))) == NULL) { // or sizeof(*char)
        return -1;
    }
    
    for (int i = 0; i < size; i++) {
        if ((c[i] = malloc(size+1)) == NULL) {
            return -1;
        }
        c[i][0] = 'a';
        c[i][1] = 'b';
        c[i][2] = 'c';
        c[i][3] = '\0';
        //c[i] = "abc";
        //strcpy(*(c+i), "abc");
    }
    
    for (int i = 0; i < size; i++) {
         //printf("%s \n", c[i]);
         for (int e = 0; e < size; e++) {
             printf("%c", c[i][e]);
         }
         printf("%s", "\n");
    } 
}

int dynamicTwoDimArray2(){
    int nrows = 5;
    int ncolumns = 5;
    int **array; // pointer to a pointer
    array = malloc(nrows * sizeof(int *)); // reserve nrows of int * (=int pointer) memory / or sizeof(*array)
    if(array == NULL) return -1;
    for(int i = 0; i < nrows; i++) {
        *(array+i) = malloc(ncolumns * sizeof(int)); // or array[i]
        if(array[i] == NULL) return -1;
        for (int e = 0; e < ncolumns; e++) {
          array[i][e] = 'A';
        }
    }
    
    for(int i = 0; i < nrows; i++) {
        for(int e = 0; e < ncolumns; e++) {
            printf("%c", array[i][e]);
        }
        printf("\n");
    }
    return 0;
}

void simpleMalloc() {
    char *s = "Max";
    char *s2;    
    printf("%d \n", strlen(s)); // 3
    s2 = malloc(strlen(s)+1); // assign new address from malloc to s3, +1 due to \0 byte
    strcpy(s2, s); // copy s2 into s3
    printf("%s \n", s2); // "Max"
    return 0;
}

void testSC() {
    int i = 5;
    char *buf;
    buf = malloc(i * sizeof(char));
    read(0, buf, i-1);
    *(buf+(i-1)) = '\0';
    printf("%s", buf);
}

int main(void) {
    //printHelloWorld();
    //pointerArithmetic();
    //pointerToPointer();
    //simpleMalloc();
   // dynamicTwoDimArray();
    //dynamicTwoDimArray2();
    
    char ch[] = "AZ";
    printf("%c", ('A'+1)); // prints B
    printf("%c", (ch[0]+1)); // prints B
    printf("%c", (*(ch+0)+1)); // prints B
    printf("%c", (*ch+1)); // prints B
    printf("%s", "\n");
    return 0;
}
