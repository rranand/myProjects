const int t2=13,t1=11,t0=9;
const int e2=12,e1=10,e0=8;
const int h1=7,h0=6;
const int l5=5,l4=4,l3=3,l2=2;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
long d[2],tm[2];
pinMode(l2,OUTPUT);
pinMode(l3,OUTPUT);
pinMode(l4,OUTPUT);
pinMode(l5,OUTPUT);
pinMode(t0,OUTPUT);
pinMode(t1,OUTPUT);
pinMode(t2,OUTPUT);
pinMode(h0,OUTPUT);
pinMode(h1,OUTPUT);
//US0
digitalWrite(t0, LOW);
delayMicroseconds(2);
digitalWrite(t0, HIGH);
delayMicroseconds(10);
digitalWrite(t0, LOW);
pinMode(e0, INPUT);
tm[0] = pulseIn(e0, HIGH);
d[0]=cal(tm[0]);
Serial.print(d[0]);
Serial.print("cm");
Serial.println();
//US1
digitalWrite(t1, LOW);
delayMicroseconds(2);
digitalWrite(t1, HIGH);
delayMicroseconds(10);
digitalWrite(t1, LOW);
pinMode(e1, INPUT);
tm[1] = pulseIn(e1, HIGH);
d[1]=cal(tm[1]);
Serial.print(d[1]);
Serial.print("cm");
Serial.println();
//US2
digitalWrite(t2, LOW);
delayMicroseconds(2);
digitalWrite(t2, HIGH);
delayMicroseconds(10);
digitalWrite(t2, LOW);
pinMode(e2, INPUT);
tm[2] = pulseIn(e2, HIGH);
d[2]=cal(tm[2]);
Serial.print(d[2]);
Serial.print("cm");
Serial.println();
delay(2000);
//logic
if (d[1]>=10)
{
digitalWrite(l2,HIGH);
digitalWrite(l3,LOW);
}
else
{
digitalWrite(l2,LOW);
digitalWrite(l3,HIGH);
}
if (d[2]>=10)
{
digitalWrite(l4,HIGH);
digitalWrite(l5,LOW);
}
else
{
digitalWrite(l4,LOW);
digitalWrite(l5,HIGH);
}
if (d[0]<=10)
{
if (d[1]>=10 && d[2]<=10)
{
firstfloor();
}
else if (d[1]<=10 && d[2]>=10)
{
secondfloor();
}
else if (d[1]>=10 && d[2]>=10)
{
third();
}
else
{}
}
else
{}
}

//function
long cal(long time)
{
return time / 29 / 2;
}

void firstfloor()
{
digitalWrite(l2,HIGH);
digitalWrite(l3,LOW);
digitalWrite(l4,LOW);
digitalWrite(l5,HIGH);
digitalWrite(h0,HIGH);
digitalWrite(h1,LOW);
delay(2000);
digitalWrite(l2,LOW);
digitalWrite(l3,HIGH);
digitalWrite(h0,LOW);
digitalWrite(h1,HIGH);
delay(2000);  
stop();
}

void secondfloor()
{
digitalWrite(l2,LOW);
digitalWrite(l3,HIGH);
digitalWrite(l4,HIGH);
digitalWrite(l5,LOW);
digitalWrite(h0,HIGH);
digitalWrite(h1,LOW);
delay(5000);
digitalWrite(l4,LOW);
digitalWrite(l5,HIGH);
digitalWrite(h0,LOW);
digitalWrite(h1,HIGH);
delay(5000);
stop();  
}

void third()
{
digitalWrite(l2,HIGH);
digitalWrite(l3,LOW);
digitalWrite(l4,HIGH);
digitalWrite(l5,LOW);
digitalWrite(h0,HIGH);
digitalWrite(h1,LOW);
delay(2000);
digitalWrite(l2,LOW);
digitalWrite(l3,HIGH);
digitalWrite(h0,LOW);
digitalWrite(h1,HIGH);
delay(2000);  
stop();	
}

void stop()
{
digitalWrite(h0,LOW);
digitalWrite(h1,LOW);
}
