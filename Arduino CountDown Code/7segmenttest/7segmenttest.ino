int latchPin = 2; //pin 12 on the 595
int dataPin = 3; //pin 14 on the 595
int clockPin = 4; //pin 11 on the 595
int latchPin2 = 5;

int nums[] = {63, 6, 91, 79, 102, 107, 123, 7, 127, 111};
int quad[] = {31, 28, 26, 22, 14};

int t = 2;
int mynum[] = {2, 0, 2, 1};

//D1 = 1792, D2 = 256, D3 = 512, D4 = 1024
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {

  
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, nums[mynum[0]]);
  digitalWrite(latchPin, HIGH);
  
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[1]);
  digitalWrite(latchPin2, HIGH);
  
  delay(t);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[0]);
  digitalWrite(latchPin2, HIGH);

  delay(t);


  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, nums[mynum[1]]);
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[2]);
  digitalWrite(latchPin2, HIGH);
  
  delay(t);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[0]);
  digitalWrite(latchPin2, HIGH);

  delay(t);


  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, nums[mynum[2]]);
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[3]);
  digitalWrite(latchPin2, HIGH);
  
  delay(t);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[0]);
  digitalWrite(latchPin2, HIGH);

  delay(t);


  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, nums[mynum[3]]);
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[4]);
  digitalWrite(latchPin2, HIGH);
  
  delay(t);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[0]);
  digitalWrite(latchPin2, HIGH);

  delay(t);

}
