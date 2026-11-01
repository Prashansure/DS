#include <stdio.h>
int main(){
int list[ ] = {10,20,30,40,50};
int size =5;
int i;
int found = 0;
int key = 40;
for(i = 0;i<size;i++)
{
    if (list[i]== key)
    {
        found = 1;
        printf("element found at index %d",i);
        break;
    }
}
    if (found == 0)
    {
        printf("element not in list");
    }

return 0;
}