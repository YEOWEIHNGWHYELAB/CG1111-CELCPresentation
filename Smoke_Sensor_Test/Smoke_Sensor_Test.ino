int buzzer = 8;
int led[3] = {2, 4, 7};
double threshold = 0.55;
double val;
int Ena = 3; 
int Mot1 = 5; 

void alarm() {
  for(int i = 0; i < 3; i += 1) {
    digitalWrite(led[i], HIGH);
    delay(1);
    for (long k = 0; k <= 3; k += 1) {
      for (long j = 0; j <= 8 ; j += 1 ) {
        digitalWrite(buzzer,HIGH);
        delay(k);
        digitalWrite(buzzer,LOW); 
        delay(k);
      }
    }
    digitalWrite(led[i], LOW);
  }
}

void motorrun() {
  digitalWrite(Mot1, HIGH);
}

void motorstop() {
  digitalWrite(Mot1, LOW);
}

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(Ena, OUTPUT); 
  pinMode(Mot1, OUTPUT); 
  digitalWrite(Ena, HIGH);
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}

void loop() {
  val = (5.0/1023) * analogRead(0);
  Serial.println(val);
  if (val > threshold) {
    motorrun();
    alarm();
  }
  else {
    motorstop();
  }
  delay(100);
}
