#define MOT_POS   9
#define MOT_NEG   10

#define DUTY_1    60
#define DUTY_2    100

void setup() 
{
  //set pins to act as outputs
  pinMode(MOT_POS, OUTPUT);
  pinMode(MOT_NEG, OUTPUT);

  //we will use the builtin LED as a status LED
  pinMode(LED_BUILTIN, OUTPUT);  
}

void loop() 
{
  int value;

  //go forward at DUTY_1
  value = map(DUTY_1, 0, 100, 0, 255);  //map duty cycle (0-100) to PWM range (0-255)
  analogWrite(MOT_POS, value);  
  analogWrite(MOT_NEG, 0);      
  delay(2000);                  //wait for 2 seconds

  //stop the motor
  analogWrite(MOT_POS, 0);  
  analogWrite(MOT_NEG, 0);
  delay(500);
  
  //go forward at DUTY_2
  value = map(DUTY_2, 0, 100, 0, 255);  //map duty cycle (0-100) to PWM range (0-255)
  analogWrite(MOT_POS, value);  
  analogWrite(MOT_NEG, 0);
  delay(2000);                  //wait for 2 seconds

  //stop the motor
  analogWrite(MOT_POS, 0);  
  analogWrite(MOT_NEG, 0);
  delay(500);
  
  //go reverse at DUTY_1
  value = map(DUTY_1, 0, 100, 0, 255);  //map duty cycle (0-100) to PWM range (0-255)
  analogWrite(MOT_POS, 0);        
  analogWrite(MOT_NEG, value);
  delay(2000);                  //wait for 2 seconds

  //stop the motor
  analogWrite(MOT_POS, 0);  
  analogWrite(MOT_NEG, 0);
  delay(500);
  
  //go reverse at DUTY_2
  value = map(DUTY_2, 0, 100, 0, 255);  //map duty cycle (0-100) to PWM range (0-255)  
  analogWrite(MOT_POS, 0);
  analogWrite(MOT_NEG, value);
  delay(2000);                  //wait for 2 seconds

  //stop the motor
  analogWrite(MOT_POS, 0);  
  analogWrite(MOT_NEG, 0);
  delay(500);
  
  //toggle the built-in LED to act as a status LED
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
