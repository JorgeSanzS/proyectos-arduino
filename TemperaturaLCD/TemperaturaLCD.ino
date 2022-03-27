/**
  Termometro usando un sensor LM35 que muestra por un LCD de 16x2 la temperatura
**/

#include <LiquidCrystal.h>

//Declarar LCD y pines

LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  //Definir las dimensiones del LCD (16x2) y los caracteres que deben salir en las lineas
  lcd.begin(16,2);
  lcd.print("Temperatura");
  lcd.setCursor(0,1);
  lcd.print("C=");
}

void loop() {
  float centigrados = leerGradosC();
  //Sacamos por pantalla los grados
  lcd.setCursor(2,1);
  lcd.print(centigrados);
  //Lo realizamos cada segundo
  delay(1000);
}

float leerGradosC() {
  int dato;
  float c;
  //Leemos los datos analogicos del sensor de temperatura
  dato = analogRead(A0);
  //Convertimos el dato de entrada en grados C segun la formula
  c = (500.0 * dato / 1024);
  return c;  
}
