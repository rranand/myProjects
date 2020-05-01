#define soundread A0
#define pwm A1
#define rled 10
#define wled 12
#define m1 8
#define m2 9
#define buzz 6
#define start 3

const int lockpattern[5] = {3, 3, 3, 0, 3};
const int unlockpattern[5] = {3, 3, 0, 3, 3};

void setup() {
  Serial.begin(9600);
  pinMode(soundread, INPUT);
  pinMode(rled, OUTPUT);
  pinMode(wled, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(start, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(pwm, INPUT);
  digitalWrite(13, LOW);
  digitalWrite(rled, LOW);
  digitalWrite(wled, LOW);
  digitalWrite(buzz, LOW);
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  analogWrite(pwm, 200);
}

void loop() {
  digitalWrite(start,HIGH);
  int read1 = analogRead(soundread);
  delay(500);
  int read2 = analogRead(soundread);
  if (abs(read2 - read1) > 5) {
    for (int i=0;i<2;i++) {
      digitalWrite(start,LOW);
      delay(500);
      digitalWrite(start,HIGH);
    }
    Serial.println("Start locking");
    if (checklockpattern() == true) {
      digitalWrite(rled, HIGH);
      digitalWrite(buzz, HIGH);
      forward();
    } else {
      digitalWrite(wled, HIGH);
    }

  } else if (abs(read2 - read1) > 1 && abs(read2 - read1) < 5) {
    Serial.println("Start Unlocking");
    if (checkunlockpattern() == true) {
      digitalWrite(rled, HIGH);
      digitalWrite(buzz, HIGH);
      backward();
    } else {
      digitalWrite(wled, HIGH);
    }
  }
  Serial.println("END");
  delay(2000);
  reset();
}

bool checklockpattern() {
  int flag = 1;
  int read1, read2, match[5];
  delay(800);
  Serial.println("Start Clapping");
  delay(1000);
  for (int i = 0; i < 5; i++) {
    read1 = analogRead(soundread);
    delay(500);
    read2 = analogRead(soundread);
    match[i] = abs(read2 - read1);
    Serial.print("Storing analog Values for lock:");
    Serial.println(match[i]);
    delay(800);
  }
  for (int i = 0; i < 5; i++) {
    if (match[i] > lockpattern[i]) { //Need to be checked
      flag = 0;
    }
  }
  if (flag == 1) {
    return true;
  }
  return false;
}

bool checkunlockpattern() {
  int flag = 1;
  int read1, read2, match[5];
  delay(800);
  Serial.println("Start Clapping");
  delay(1000);
  for (int i = 0; i < 5; i++) {
    read1 = analogRead(soundread);
    delay(500);
    read2 = analogRead(soundread);
    match[i] = abs(read2 - read1);
    Serial.print("Storing analog Values for unlock:");
    Serial.println(match[i]);
    delay(800);
  }
  for (int i = 0; i < 5; i++) {
    if (match[i] > unlockpattern[i]) { //Need to be checked
      flag = 0;
    }
  }
  if (flag == 1) {
    return true;
  }
  return false;
}

void reset() {
  digitalWrite(13, LOW);
  digitalWrite(rled, LOW);
  digitalWrite(wled, LOW);
  digitalWrite(buzz, LOW);
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(start,LOW);
}

void forward() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
}

void backward() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
}
