#include "ShortestDistance.h"

namespace Paradox {
    ShortestDistance::ShortestDistance()
    {}

    ShortestDistance::~ShortestDistance()
    {}



    /* 
    
    ___________________________________
    | |1|0| | | | | | | | | | | | | | |
    ___________________________________
    | | |0|1|1|1|0|0|0|0|1|1|1|0|1|1|0|
    ___________________________________
    | | | | | | | | | | | | | | | | |0|
    ___________________________________
    | | | | | | | | | | | | | | | | | |
    -----------------------------------
    
    
    
    
    */
    int ShortestDistance::FindPath(const int nStartX, const int nStartY, const int nTargetX,
        const int nTargetY, const unsigned char* pMap,
        const int nMapWidth, const int nMapHeight, int* pOutBuffer,
        const int nOutBufferSize)
    {
        //Solution:  Calculate the displacement and create a triangle. Since, diagonals are not allowed, will take right angle sides of triangle to be the shortest possible path
        // Once, we have coordinates of the right angle sides of the triangle, will start creating path from source to right angle first.
        // Then from right angle to target
        
        // Case to consider:
        // 1. Same source and destination: return 0
        // 2. Diagonally adjacent points: will follow generic path
        // 3. seamless wall: nothing can be done. Return -1
        // 4. Right angle sides coordinate itself is blocked: In that case, we need to find nearest allowed point
        //Steps: 1 to N
    }
};