#include <stdio.h>
int main(){
int list[100] = {10,20,30,40,50};
int size =5;
int i;
int pos = 2;
for (i = pos;i<size;i++)
{
    list[i] = list[i+1];
}
size--;
printf("list after deletion:\n");
for(i =0;i <size;i++)
{
    printf("%d\n",list[i]);
}
return 0;
}