
int motorAizq = 11; //avanza para delante
int motorAder = 10;//avanza para atras
int motorBizq = 8; //avanza para delante
int motorBder = 9; //avanza para Atras
int Trig = A0;
int Echo = A1;
int vel = 150; //velocidad entre 0 y 255

void setup() {
  pinMode(motorAizq, OUTPUT);
  pinMode(motorAder, OUTPUT);

  pinMode(motorBizq, OUTPUT);
  pinMode(motorBder, OUTPUT);

  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  Serial.begin (9600);
}

void loop() {
  analogWrite(motorAizq, HIGH);//avanza 
  analogWrite(motorAder, LOW);

  analogWrite(motorBizq, HIGH);//avanza 
  analogWrite(motorBder, LOW);
  
  delay(2000);

  long duracion;
  long distancia;
  
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  
  duracion = pulseIn(Echo,HIGH);
  distancia = (duracion/2)/29;

  Serial.println(distancia);

  delay(100);

  if (distancia< 30) {
    
    
     analogWrite(motorAizq, 0);//detiene 
     analogWrite(motorAder, 0);

     analogWrite(motorBizq, 0);//detiene
     analogWrite(motorBder, 0);
     delay(1000);
     
     analogWrite(motorAizq, 0);// 
     analogWrite(motorAder, vel);//retrocede

     analogWrite(motorBizq, 0);
     analogWrite(motorBder, vel);//retrocede
     delay(2000);

     analogWrite(motorAizq, 0);// 
     analogWrite(motorAder, 0);//detiene para girar

     analogWrite(motorBizq, vel);//gira a la derecha
     analogWrite(motorBder, 0);
     delay(2000);}
  else {
      analogWrite(motorAizq, vel);//avanza
      analogWrite(motorAder, 0);

      analogWrite(motorBizq, vel);//avanza
      analogWrite(motorBder, 0);
      delay(2000);}

}
