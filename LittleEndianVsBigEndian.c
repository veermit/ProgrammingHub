int main()
{
    unsigned int uiVar =  1;
    char *cVar = (char *)&uiVar;
    if(*cVar)
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }

    return 0;
}
