static int* createAscendingIntArray(unsigned int length)
{
    int* ret = new int[length];
    for(int i = 0; i < length; i++)
    {
        ret[i] = i;
    }
    return ret;
}

static int* createDescendingIntArray(unsigned int length)
{
    int* ret = new int[length];
    for(int i = length - 1; i >= 0; i--)
    {
        ret[i] = i;
    }
    return ret;
}

