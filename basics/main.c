#include <stdio.h>
#include <math.h>

void stringTest() {
    char str1[] = "Hello";
    char *str2 = "Goodbye";
    int i[] = {2,3,4};
    
    printf("%x %x %s\n", &str1, str1, str1);
    
    // %s needs an address to print the string
    printf("%x %x %s\n", &str2, str2, str2);
    
    // if you dereference the address you get the first element (char) of the array
    printf("%x %x %c\n", &str1, str1, *str1);
    printf("%x %x %c\n", &str2, str2, *str2);
    printf("%x %x %c\n", &str2, str2+1, *(str2+1));
    printf("%x %x %d\n", &i, i, *i);
    
    // => The value of an array name is the address of the start of that array
    
    // illegal operation: str1 = "TEST"
    // this works:
    str2 = "Test";
    printf("%x %x %s\n", &str2, str2, str2);
}

void dynamicTwoDimArray3() {
    int x[10][10]; 
    
    /* dynamic version:
     *                         _ _ _ _ _ _ _ _ _ _
     * pp -------> p1 ------> |_|_|_|_|_|_|_|_|_|_| (10 int fields in memory) 
     *             p2 ------> .....
     *             p3 ------> .....
     *             ................ 
     *
     int **x = malloc(10*sizeof(int*));
     for (int i = 0; i < 10; i++) {
        *(x+i) = malloc(10*sizeof(int));
     }
    */
    
    for (int i = 0; i < 10; i++) {
        for (int e = 0; e < 10; e++) {
            x[i][e] = e;
            // same with pointer arithmetic on address: *(*(x+i)+e) = e;
        }
    }
    
    for (int i = 0; i < 10; i++) {
        for (int e = 0; e < 10; e++) {
            printf("%d", x[i][e]);
        }
        printf("%s", "\n");
    }
}

void main(int argc, char **argv) {
    stringTest();
}
