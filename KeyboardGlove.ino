int thumbButton = 2;
int indexButton = 3;
int middleButton = 4;
int ringButton = 5;
int pinkyButton = 6;
int lastState = 0;

void setup() {  
  Serial.begin(9600);
  pinMode(thumbButton, INPUT);
  pinMode(indexButton, INPUT);
  pinMode(middleButton, INPUT);
  pinMode(ringButton, INPUT);
  pinMode(pinkyButton, INPUT);
}

void loop() {
  int thumbState = digitalRead(thumbButton) << 4;
  int indexState = digitalRead(indexButton) << 3;
  int middleState = digitalRead(middleButton) << 2;
  int ringState = digitalRead(ringButton) << 1;
  int pinkyState = digitalRead(pinkyButton);

  int state = thumbState | indexState | middleState | ringState | pinkyState;
  if(state > 0 && lastState == state) {
    Serial.println(state);
    delay(100);
  } else {
    lastState = state;
    delay(50);
  }
}
