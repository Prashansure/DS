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
