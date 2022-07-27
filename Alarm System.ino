int pirState = LOW;   //This is used to describe the initial state of the PIR sensor. When the program starts, we want the sensor to assume no motion is detected.               
int on_off = 0;      //This is the variable used to read the status of the PIR sensor, detecitng if it is on or off. (Explained later).              
int speakerPin = 12;           
int led_1 = 2;     
int led_2 = 10;  
int led_3 = 13;             
int pirPin = 4;               
//This section of the code is simply setting the pin number variables used for our modules, in order to be applied to the rest of the code. 
//The variables are named according to what module they are. For exampe, first LED is labelled "led_1"
//If this was not done, you would always have to tell the program which module belongs to which pin, making the code much more efficient. 

void setup() {
  // put your setup code here, to run once:    
  pinMode(pirPin, INPUT);     
  pinMode(speakerPin, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);  
  Serial.begin(9600);  //This sends the code to the arduino so the task can be performed. Hence "begin".
  //In this function, we are seting up the program. This is achieved by identifying to the program which modules need data to output or input data.
}

void loop(){
  // put your main code here, to run repeatedly:
  on_off = digitalRead(pirPin);    //Here, the on_off variable is called, it is set to read the activity of the PIR sensore.
  if (on_off == HIGH) {            //This if statement is for if motion is detected 
    digitalWrite(led_1, HIGH);     //If the if statement is activated, LED will turn on.               
    digitalWrite(led_2, HIGH);                      
    digitalWrite(led_3, HIGH);    
    delay(200);                  //There will be a 200 millisecond delay between this and the next task.
    digitalWrite(led_1, LOW);    //LED will turn off.                 
    digitalWrite(led_2, LOW);                     
    digitalWrite(led_3, LOW);         
    buzzer(300, 160);          //Play the buzzer sound using the playTone function below
    delay(150);                  //Since this function is a loop that runs repeatedly, another delay has been added (150 millisecond) to give some space. 

    
  } else {                           //If the if statement is not activated, the following code will occur:
      digitalWrite(led_1, LOW);      //LED's remain off.                
      digitalWrite(led_2, LOW);                     
      digitalWrite(led_3, LOW);
      buzzer(0, 0);                //No sound is played.
      delay(300);                    //There is a delay since it is a loop function. 
      //Keep in mind: Due to the lack of sensetivity in the PIR sensor, it takes a while to react and shut off when motion is detected. 
      //Having said this, the if statement still works. If it doesn't detect motion, all sound and LED's turn off. 
  }

  Serial.println(on_off); //This will read the value of the on_off variable and display in the serial monitor if the PIR sensor detects or doesn't detect motion. 
}

void buzzer(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(speakerPin,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(speakerPin, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }
}
