int sensorPin = A11; //sensor de humedad
int umbral_de_humedad = 900; //alertar si la lectura es mayor a este numero
int led = 7;
int First = 0;
int Hum = 0;
 
void setup() {
 
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW); //apagar el led para empezar
 
}
 
void loop() {
 
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
 
   if (First == 0){
     delay(10000);
     Hum = analogRead(sensorPin);
     First = 1;
     Serial.println("Listo!!!");
   }
   
   if (sensorValue <= (Hum - 10)){
     Serial.println("Alerta!");
     digitalWrite(led, HIGH);
     delay(1001);
     digitalWrite(led, LOW);
     delay(1001);
   } 

 
}
