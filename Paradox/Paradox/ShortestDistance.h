#pragma once

namespace Paradox {
class ShortestDistance {
public:
  ShortestDistance();
  ~ShortestDistance();

  int FindPath(const int nStartX, const int nStartY, const int nTargetX,
               const int nTargetY, const unsigned char *pMap,
               const int nMapWidth, const int nMapHeight, int *pOutBuffer,
               const int nOutBufferSize);
};
} // namespace Paradox
