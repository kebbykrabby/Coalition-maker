#include "JoinPolicy.h"

Coalition LastOfferJoinPolicy:: join(vector<Coalition> offersC)
{

    return offersC.back();

}

char LastOfferJoinPolicy::getType()
{
    return 'L';
}
