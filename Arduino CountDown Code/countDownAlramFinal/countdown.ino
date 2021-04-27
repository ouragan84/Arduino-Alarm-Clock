// arduino ports
#define latchPin 2
#define dataPin 3
#define clockPin 4
#define latchPin2 5
#define rotaryA 6
#define rotaryB 7
#define pauseButton 8
#define alarmPin 9

// time to wait in between led display refreshes
#define TIME_REFRESH .005

// time before we count down
#define INTERVAL 10

// tone and duration of beeps
#define TONE_FREQUENCY 880
#define TONE_LENGTH 500
#define TONE_GAP_LENGTH 500

#define BUTTON_PRESS_LEGNTH 1000

// Tracks the time since last count down
unsigned long previousMillis;

// nums[i] gives the number to send so that i is printed on the display
int nums[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

// quad[i] gives the number to send so that number is printed to the segment i - quad[0] is the number to send to refresh the display
int quad[] = {31, 28, 58, 22, 14};

// a = tens seconds, b = seconds, c = tenth seconds, 
int a, b, c, d;

// tells us we are counting down
bool isPlaying;
bool wasPlaying;

// for checking position of rotary encoder
int rotaryAState;
int rotaryLastAState;

// for button checks
int buttonState;
int buttonNormalState;
bool buttonIsPressed;
unsigned long timePressed;

// for alarm
bool isRinging;
bool isAlarmOn;
unsigned long lastTimeRing;


// set up the ports and variables
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin2, OUTPUT);
  
  pinMode(rotaryA, INPUT);
  pinMode(rotaryB, INPUT);
  pinMode(pauseButton, INPUT);

  pinMode(alarmPin, OUTPUT);

  a = 0; b = 0; c = 0; d = 0;
  isPlaying = false;
  wasPlaying = false;

  previousMillis = 0;

  rotaryLastAState = digitalRead(rotaryA);

  buttonNormalState = digitalRead(pauseButton);
  buttonIsPressed = false;
  isRinging = false;

  digitalWrite(alarmPin, 0);
}

void loop() {
 
  // print time
  printnumber(a, b, c, d);

  //check to add or sub seconds from timer
  rotaryAState = digitalRead(rotaryA);
  if(rotaryAState != rotaryLastAState){
    if(digitalRead(rotaryB) != rotaryAState){
      stopAlarm();
      addminute();
    }else{
      subminute();
    }
    rotaryLastAState = digitalRead(rotaryA);
  }

  buttonState = digitalRead(pauseButton);

  if(buttonState != buttonNormalState){
    //if button is being pressed
    
    if(!buttonIsPressed){
      //if button started to be pressed
      
      timePressed = millis();
      buttonIsPressed = true;
      wasPlaying = isPlaying;
      if(isPlaying) 
        isPlaying = false;
      
    }

    if(((unsigned long)timePressed + BUTTON_PRESS_LEGNTH) <= millis()){
      //if been pressed for 1.5 seconds
      a = 0;
      b = 0;
      c = 0;
      d = 0;
      isPlaying = false;
    }
    
  }else{
    // if not being pressed
    if(buttonIsPressed && !wasPlaying){
        isPlaying = true;
        stopAlarm();
    }
      
    buttonIsPressed = false;
  }

  if(isAlarmOn){
    if(isRinging){
      tone(alarmPin, TONE_FREQUENCY);
      if((unsigned long) (lastTimeRing + TONE_LENGTH) <= millis()){
        isRinging = false;
        lastTimeRing = millis();
      }
    }else{
      noTone(alarmPin);
      if((unsigned long) (lastTimeRing + TONE_GAP_LENGTH) <= millis()){
        isRinging = true;
        lastTimeRing = millis();
      }
    }
  }

  //if we are counting down
  if(isPlaying){

    // Wait until 10 millis have passed
    if((unsigned long)(millis() - previousMillis) >= INTERVAL){
      
      previousMillis = millis(); 
      
      // counting down and if time is 0, stop counting down
      if(countdown()){
        isRinging = true;
        isAlarmOn = true;
        lastTimeRing = previousMillis;
      }
    }
    
  }
  
}

void stopAlarm(){
  if((a == 0 && b == 0 && c == 0 && d == 0)){
    noTone(alarmPin);
    isAlarmOn = false;
    isPlaying = false;
  }
}

bool countdown(){
  
  d--;
  
  if(d < 0){
    d = 9;
    c --;
  }

  if(c < 0){
    c = 9;
    b --;
  }

  if(b < 0){
    b = 9;
    a --;
  }

  if(a < 0){
    isPlaying = false;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    return true;
  }

  return false;
}

void addminute(){
  
  b++;

  if(b > 9){
    b = 0;
    a ++;
  }

  if(a > 9){
    a = 9;
    b = 9;
    c = 9;
    d = 9;
  }

}

void subminute(){
  
  b--;

  if(b < 0){
    b = 9;
    a --;
  }

  if(a < 0){
    a = 0;
    b = 0;
    c = 0;
    d = 0;
  }

}

void printnumber(int num1, int num2, int num3, int num4){
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, nums[num1]);
  digitalWrite(latchPin, HIGH);
  
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[1]);
  digitalWrite(latchPin2, HIGH);
  
  delay(TIME_REFRESH);

  resetquads();


  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, nums[num2]);
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[2]);
  digitalWrite(latchPin2, HIGH);
  
  delay(TIME_REFRESH);

  resetquads();


  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, nums[num3]);
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[3]);
  digitalWrite(latchPin2, HIGH);
  
  delay(TIME_REFRESH);

  resetquads();


  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, nums[num4]);
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[4]);
  digitalWrite(latchPin2, HIGH);
  
  delay(TIME_REFRESH);

  resetquads();
  
}

void resetquads(){
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, quad[0]);
  digitalWrite(latchPin2, HIGH);

  delay(TIME_REFRESH);
}
