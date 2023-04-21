#ifndef CHALLENGE_H
#define CHALLENGE_H

class Challenge
{
private:
  int challengeId = -1;

  bool isDone = false;

public:
  void setup();
  void loop();

  int getChallengeId();
  void setChallengeId(int val);
  bool getIsDone();
  void setIsDone(bool val);
};

#endif
