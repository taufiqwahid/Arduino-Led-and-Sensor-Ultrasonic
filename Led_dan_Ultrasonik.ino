#define ledMerah 15
#define echoPin 18
#define trigPin 19

float duration, distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledMerah,OUTPUT);
  
  Serial.begin(215200);
  pinMode(trigPin,OUTPUT); // MENGELUARKAN FREKUENSI
  pinMode(echoPin,INPUT); //MENERIMA FREKUENSI
}

void loop() {
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);

  if(distance>=0 && distance<=10){
      digitalWrite(ledMerah,HIGH);
      Serial.print(distance);
      Serial.println(" Jarak terlalu dekat");  
  }else{
  digitalWrite(ledMerah,LOW);
  }
}
