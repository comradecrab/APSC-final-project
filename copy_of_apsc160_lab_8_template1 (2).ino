/* Lab 8 - L1G
 * Name: Victoria Farkas
 * Student ID: 22921597
 * Email: farkasv@student.ubc.ca
 * Date: December 7, 2022
 */


//define constants etc.

#define LED_LOSE 13
#define LEDR 12
#define LEDY 11
#define LEDB 10
#define LEDG 9
#define LED_WIN 8

#define pb_red 7
#define pb_yellow 6
#define pb_blue 5
#define pb_green 4

//set the maximum amount of numbers to be generated
#define MAX_RAND 6

//this variable holds the generated numbers
long randomnum;
int count;
int randomarr[5];
int increment;
int buttonarr[5];
int buttonstate = 0;
int buttonincr;

//define functions prototypes
void blink(int LED);
void youwon(void);
void youlost(void);
int buttonpress(void);

//initialization
void setup()
{
  //configure led outputs
  pinMode(LED_LOSE, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LED_WIN, OUTPUT);
  
  //configure pushbuttons as inputs
  pinMode(pb_red, INPUT);
  pinMode(pb_yellow, INPUT);
  pinMode(pb_blue, INPUT);
  pinMode(pb_green, INPUT);
  
  Serial.begin(9600);
  
  //initialize the seed with a floating pin
  randomSeed(analogRead(0));
  
 
}


//main program loop
void loop()
{
  //this for loop creates the initial array
  for(count = 0; count < MAX_RAND; count++) {
    
    //generate a random number between 0 and 3
    randomnum = random(9, 13);
    //assign the values to an array
    randomarr[count] = randomnum;
    
  }
  
  
  //this nested loop lights up the LEDs in an incremental pattern
  for(count = 0; count < MAX_RAND; count++) {
    
    for(increment = 0; increment < count; increment++) {
      
      //function for flashing LED
      blink(randomarr[increment]);
      
      
    }
    
    //check to see if a button is pressed
    buttonstate = buttonpress();
    
    //if a button is pressed, go through
    if(buttonstate == 1) {
      for(buttonincr = 0; buttonincr < count; buttonincr++){
        
      }
    
    }
    
    delay(1000);
    
    
  }
  
  youwon();
  delay(10000);

    
  
  
}

// FUNCTIONS



//Function: flashes the called upon LED
//Parameter: the LED number

void blink(int LED) {
  
  //light up the corresponding LED
      digitalWrite(LED, HIGH);
      //allow the light to stay on for a second
      delay(500);
      
      //turn off the light for a second
      digitalWrite(LED, LOW);
      delay(500);
}
  
//Function: plays the winning light sequence
void youwon(void) {
  int flashcount;
  
  for(flashcount = 3; flashcount > 0; flashcount--) {
    digitalWrite(LED_WIN, HIGH);
    delay(500);
    
    digitalWrite(LED_WIN, LOW);
    delay(500);
  }
  
}

//Function: plays the losing light sequence
void youlost(void) {
  int flashcount;
  
  for(flashcount = 3; flashcount > 0; flashcount--) {
    digitalWrite(LED_LOSE, HIGH);
    delay(500);
    
    digitalWrite(LED_LOSE, LOW);
    delay(500);  
  }
  
}

// check to see which button is pressed, return the corresponding pin number

int buttonpressed() {
  
  if(digitalRead(pb_red) == HIGH) {
    return 12;
  }
  
  else if(digitalRead(pb_yellow) == HIGH) {
    return 11;
  }
  
  else if(digitalRead(pb_green) == HIGH) {
    return 9;
  }
  
  else if(digitalRead(pb_blue) == HIGH) {
    return 10;
  }
  
}
  
    
  // check to see if the button is pressed, return a checker value
  
int buttonpress() {
   
  if(digitalRead(pb_red) == HIGH) {
    return 1;
  }
  
  else if(digitalRead(pb_yellow) == HIGH) {
    return 1;
  }
  
  else if(digitalRead(pb_blue) == HIGH) {
    return 1;
  }
  
  else if(digitalRead(pb_green) == HIGH) {
    return 1;
  }
  
  else {
    return 0;
  }
}


//sorry it's half done


    
  
  
