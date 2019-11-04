const int soundpin = A0;
const int l1 = 6;
const int l2 = 5;
const int l3 = 7;
const int l4 = 4;
const int l5 = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(soundpin, INPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);
}

void loop()
{
  int sound_1 = analogRead(soundpin);
  delay(50);
  int sound_2 = analogRead(soundpin);
  int finaldb = sound_2 - sound_1;
  Serial.println(sound_1);
  if (finaldb > 1) {
    digitalWrite(l1, HIGH);
    if (finaldb >= 2) {
      digitalWrite(l2, HIGH);
      if (finaldb >= 3) {
        digitalWrite(l3, HIGH);
        if (finaldb >= 4) {
          digitalWrite(l4, HIGH);
          if (finaldb >= 5) {
            digitalWrite(l5, HIGH);
          }
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
  digitalWrite(l5, LOW);
}
