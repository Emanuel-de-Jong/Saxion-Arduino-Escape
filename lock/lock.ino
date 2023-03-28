#define PIN_BUZZER 8
#define POTMETER_PIN A0

class Stage {
  public:
    int rangeStart;
    int rangeEnd; 

    Stage(int _rangeStart, int _rangeEnd) {
      rangeStart = _rangeStart;
      rangeEnd = _rangeEnd;
    }

    bool isInRange(int value, int offset = 0) {
      if (value >= rangeStart - offset && value <= rangeEnd + offset) return true;
      return false;
    }
};

int currentStageIndex = 0;
Stage stages[] {
  Stage(250, 350),
  Stage(625, 675),
  Stage(325, 350),
};
int stageCount = sizeof(stages) / sizeof(Stage);

const int CHECK_RATE = 100;
const int COUNTDOWN_DURATION = 2 * 1000;

int countdown = COUNTDOWN_DURATION;

void setup() {
  Serial.begin(9600);
  pinMode(POTMETER_PIN, INPUT);
}

void loop() {
  if (currentStageIndex > stageCount - 1) {
    return;
  }
  
  Stage stage = stages[currentStageIndex];
  
  int potmeterValue = analogRead(POTMETER_PIN);
  if (stage.isInRange(potmeterValue)) {
    tone(PIN_BUZZER, 1047, CHECK_RATE + 10);

    countdown -= CHECK_RATE;
    if (countdown <= 0) {
      currentStageIndex++;
    }
   } else {
    if (stage.isInRange(potmeterValue, 50)) {
      tone(PIN_BUZZER, 262, CHECK_RATE + 10);
    } else if (stage.isInRange(potmeterValue, 100)) {
      tone(PIN_BUZZER, 65, CHECK_RATE + 10);
    } else {
      noTone(PIN_BUZZER);
    }
    
    countdown = COUNTDOWN_DURATION; 
  }

  delay(CHECK_RATE);
}
