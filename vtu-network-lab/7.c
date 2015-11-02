#include<stdio.h>
#include<string.h>
#define N strlen(g)

char t[128], cs[128], g[]="10001000000100001";
int a, e, c;

void xor() {
    for (c = 1; c < N; c++) 
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
}

void crc() {
    for (e = 0; e < N; e++) 
        cs[e] = t[e];
    do {
        if (cs[0] == '1') 
            xor();
        for (c = 0; c < N - 1; c++) 
            cs[c] = cs[c + 1];
        cs[c] = t[e++];
    } while (e <= a + N - 1);
}

int main() {
   
    printf("\nEnter poly : "); 
    scanf("%s",t);
    
    printf("\nGenerating Polynomial is : %s",g);
    a=strlen(t);

    for (e = a; e < a + N - 1; e++) 
        t[e] = '0';

    printf("\nModified t[u] is :  %s",t);

    crc();
  
    printf("\nChecksum is : %s",cs);
    for (e = a; e < a + N - 1; e++) t[e] = cs[e - a];

    printf("\nFinal Codeword is : %s", t);
    printf("\nTest Error detection 0(yes) 1(no) ? : ");

    scanf("%d", &e);
    
    if (e == 0) {
        printf("Enter position where error is to inserted : ");
        scanf("%d",&e);
        t[e] = (t[e] == '0') ? '1' : '0';
        printf("Errorneous data   : %s\n", t);
    }
    crc();
    for (e = 0; (e < N - 1) && (cs[e] != '1') ; e++);
  
    if (e < N - 1) 
        printf("Error detected.\n");
    else 
        printf("No Error Detected.\n");

    return 0;
}

