#include <stdio.h>
int main()
{
    int list[100] ={10,20,30,40,50};
    int i,size =5,pos =2,newvalue =35,n,found,key= 20;
    printf("1.deletion\n2.insertion\n3.updation\n4.transversal\n5.searching\n");
    printf("Enter the number:");
    scanf("%d",&n);
    switch (n)
    {
        case 1:
            for (i = pos;i<size;i++)
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
            break;
        case 2:
            for (i = size;i>pos;i--)
            {
                list[i] = list[i-1];
            }
            list[pos] = newvalue;
            size++;
            printf("list after insertion:\n");
            for (i = 0;i<size;i++)
            {
                printf("%d\n",list[i]);
                
            }
            break;
        case 3:
            list[pos] = newvalue;
            printf("list after updation: ");
            for(i = 0;i<size;i++)
            {
                printf("%d\n",list[i]);
            }
            break;
        case 4:
            printf("Elements are :\n");
            for(i = 0;i<size;i++)
            {
                printf("%d\n",list[i]);
            }
            break;
        case 5:
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
            break;


        default :
            printf("enter the corrrect number");
            

    }
    return 0;
}