const int soundpin = A0;
const int l1 = 8;
const int l2 = 9;
const int l3 = 10;
const int l4 = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(soundpin, INPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
}

void loop()
{
  int sound_1 = analogRead(soundpin);
  delay(70);
  int sound_2 = analogRead(soundpin);
  int finaldb = sound_2 - sound_1;
  Serial.println(sound_1);
  if (finaldb >= 1) {
    digitalWrite(l1, HIGH);
    if (finaldb >= 2) {
      digitalWrite(l2, HIGH);
      if (finaldb >= 3) {
        digitalWrite(l3, HIGH);
        if (finaldb >= 4) {
          digitalWrite(l4, HIGH);
        }
      }
    }
  }
  delay(100);
  stop();
}

void stop() {
  digitalWrite(l2, LOW);
  digitalWrite(l1, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l3, LOW);
}
