#include <stdio.h>
int main(){
int list[100] = {10,20,30,40};
int size =4;
int i;
int pos = 2;
int item = 25;
for (i = size;i>pos;i--)
{
    list[i] = list[i-1];
}
list[pos] = item;
size++;
printf("list after insertion:\n");
for (i = 0;i<size;i++)
{
    printf("%d\n",list[i]);
    
}
return 0;
}