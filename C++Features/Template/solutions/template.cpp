template<typename T>
T add (T x,T y)
{
    return x+y;
}

template<typename T>
T ArraySum(const T *pArr, size_t arrSize)
{
    T sum=0;
    for(size_t i =0; i < arrSize; i++)
    {
        sum+=pArr[i];
    }
    return sum;
}

template<typename T>
T Max(const T *pArr, size_t arrSize)
{
    T maxi=0;
    for(size_t i =0; i < arrSize; i++)
    {
        maxi=max(maxi,pArr[i]);
    }
    return maxi;
}

template<typename T>
std::pair<T,T> MinMax(const T *pArr, size_t arrSize)
{
    std::pair<T,T> ans = {T(),T()};
    if(!arrSize)
        return ans;
    T maxi=pArr[0];
    T mini=pArr[0];
    for(size_t i =1; i < arrSize; i++)
    {
        maxi=std::max(maxi,pArr[i]);
        mini=std::min(mini,pArr[i]);
    }
    ans={mini,maxi};
    return ans;
}