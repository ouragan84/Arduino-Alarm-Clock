int latchPin = 2; //pin 12 on the 595
int dataPin = 3; //pin 14 on the 595
int clockPin = 4; //pin 11 on the 595
int latchPin2 = 5;
int nums[] = {63, 6, 93, 79, 102, 107, 123, 7, 127, 111};
int t = 100;

//D1 = 1792, D2 = 256, D3 = 512, D4 = 1024
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  
  /*
  for(int i = 0; i < 10; i++){
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, 256 + 64 >> 8);
      shiftOut(dataPin, clockPin, MSBFIRST, nums[i]);
      digitalWrite(latchPin, HIGH);
      delay(1000);
  }*/

  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 1);
  digitalWrite(latchPin, HIGH);
  delay(t);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 2);
  digitalWrite(latchPin, HIGH);
  delay(t);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 4);
  digitalWrite(latchPin, HIGH);
  delay(t);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 8);
  digitalWrite(latchPin, HIGH);
  delay(t);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 16);
  digitalWrite(latchPin, HIGH);
  delay(t);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 32);
  digitalWrite(latchPin, HIGH);
  delay(t);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 64);
  digitalWrite(latchPin, HIGH);
  delay(t);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);
  
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 2);
  digitalWrite(latchPin2, HIGH);
  delay(t);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 4);
  digitalWrite(latchPin2, HIGH);
  delay(t);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 8);
  digitalWrite(latchPin2, HIGH);
  delay(t);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 16);
  digitalWrite(latchPin2, HIGH);
  delay(t); 

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin2, HIGH);

  /*
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 1373);
  digitalWrite(latchPin, HIGH);
  delay(1000);*/
/*
  for(int i = 0; i < 2048; i++){
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, i*2);
      digitalWrite(latchPin, HIGH);
      delay(1000);
  }

  digitalWrite(5, HIGH);
  delay(5000);
  digitalWrite(5, LOW);
  delay(1000);*/
}
