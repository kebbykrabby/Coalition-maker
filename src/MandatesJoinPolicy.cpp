#include "JoinPolicy.h"

Coalition MandatesJoinPolicy:: join(vector<Coalition> offersC){
    Coalition max  = offersC.at(0);
    int maxM = max.getMandates();
    for(unsigned int i = 1; i< offersC.size();i++)
    {
            Coalition temp = offersC.at(i);
            int mandatesTemp = temp.getMandates();
            if(mandatesTemp >= maxM)
            {
                maxM = mandatesTemp;
                max = temp;
            }
    }
    return max;

}
char MandatesJoinPolicy::getType()
{
    return 'M';
}
