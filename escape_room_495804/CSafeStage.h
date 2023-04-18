#ifndef CSAFESTAGE_H
#define CSAFESTAGE_H

class CSafeStage {
private:
  int rangeStart;
  int rangeEnd; 
public:
  CSafeStage(int rangeStart, int rangeEnd);
  bool isInRange(int value, int offset);
};

#endif
