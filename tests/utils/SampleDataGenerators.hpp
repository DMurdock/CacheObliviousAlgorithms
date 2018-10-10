static int* createAscendingIntArray(unsigned int length)
{
    int* ret = new int[length];
    for(unsigned int i = 0; i < length; i++)
    {
        ret[i] = i;
    }
    return ret;
}

static void createDescendingIntArray(std::vector<int>& vec)
{//std::cout << "START" << std::endl;
    for(unsigned int i = 0; i < vec.size(); i++)
    {//std::cout << i << std::endl;
        vec[i] = vec.size() - i;
    }
}

