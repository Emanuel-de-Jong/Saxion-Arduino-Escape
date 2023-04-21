// The parent class of the challenge classes

#ifndef CHALLENGE_H
#define CHALLENGE_H

class Challenge
{
private:
  int challengeId = -1; // Each challenge has a unique Id to distinguish them when they're for example all in a list

  bool isDone = false; // Once this is `true`, a challenge will stop executing logic in loop()

public:
  void setup();
  void loop();

  int getChallengeId();
  void setChallengeId(int val);
  bool getIsDone();
  void setIsDone(bool val);
};

#endif
