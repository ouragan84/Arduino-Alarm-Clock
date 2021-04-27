void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(9));
  delay(10);
}
