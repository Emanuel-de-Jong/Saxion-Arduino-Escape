#include "CSafeStage.h"

CSafeStage::CSafeStage(int rangeStart, int rangeEnd)
: rangeStart(rangeStart), rangeEnd(rangeEnd) {
}

bool CSafeStage::isInRange(int value, int offset) {
  if (value >= rangeStart - offset && value <= rangeEnd + offset) return true;
  return false;
}
