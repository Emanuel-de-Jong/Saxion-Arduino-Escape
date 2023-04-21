// A instance of a stage in the Safe challenge

#ifndef CSAFESTAGE_H
#define CSAFESTAGE_H

class CSafeStage
{
private:
  // The potmeter must have a value between rangeStart and rangeEnd
  int rangeStart;
  int rangeEnd;

public:
  CSafeStage(int rangeStart, int rangeEnd);

  // Checks if the potmeter value is in range
  // The range can be loosened with an offset
  bool isInRange(int value, int offset = 0);
};

#endif
