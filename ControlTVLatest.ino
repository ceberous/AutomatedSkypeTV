int IRledPin =  13;
int ButtonPin = 12;

int buttonState = 0;

int tvON = 0;
int recievedData = 0;

void setup() {

  Serial.begin(9600);   
  
  pinMode( IRledPin , OUTPUT );

  // pinMode(buttonPin, INPUT);
  // digitalWrite(buttonPin, HIGH);
  pinMode( ButtonPin , INPUT_PULLUP );
  
}

void loop() {

  if ( tvON == 0 ) {

    buttonState = digitalRead(ButtonPin);

    // check if the pushbutton is pressed.
    if ( buttonState == LOW ) {         
      // Serial.println("button pushed");
      // Serial.print("tvON = "); Serial.print(tvON); Serial.print("\n");
      toggleTVPOWER();
      // Serial.println("TV POWER TOGGLED");
      delay(500);
      // tvON = 1;
      // Serial.print("tvON = "); Serial.print(tvON); Serial.print("\n");
      Serial.println("collin.cerbus");
      // delay(2000);

    }

  }
  

    if ( Serial.available() ) {

      // recievedData = ( Serial.read() - 'O' );
      recievedData = Serial.parseInt();
      Serial.println(recievedData);
      if ( recievedData == 1 ) {
        delay(2000);
        Serial.println("recieved signal to end call");
        toggleTVPOWER();
        delay(500);
        tvON = 0;
      }


    }

  
  

}


void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}

void toggleTVPOWER() {

  delayMicroseconds(62244); pulseIR(8780);
  delayMicroseconds(4340); pulseIR(580);
  delayMicroseconds(500); pulseIR(580);
  delayMicroseconds(520); pulseIR(580);
  delayMicroseconds(500); pulseIR(580);
  delayMicroseconds(520); pulseIR(560);
  delayMicroseconds(520); pulseIR(580);
  delayMicroseconds(520); pulseIR(560);
  delayMicroseconds(520); pulseIR(580);
  delayMicroseconds(520); pulseIR(560);
  delayMicroseconds(1620); pulseIR(560);
  delayMicroseconds(1620); pulseIR(580);
  delayMicroseconds(1600); pulseIR(580);
  delayMicroseconds(1600); pulseIR(580);
  delayMicroseconds(1600); pulseIR(580);
  delayMicroseconds(1600); pulseIR(580);
  delayMicroseconds(1600); pulseIR(580);
  delayMicroseconds(1620); pulseIR(560);
  delayMicroseconds(520); pulseIR(580);
  delayMicroseconds(500); pulseIR(580);
  delayMicroseconds(1620); pulseIR(560);
  delayMicroseconds(1620); pulseIR(560);
  delayMicroseconds(1620); pulseIR(560);
  delayMicroseconds(520); pulseIR(580);
  delayMicroseconds(520); pulseIR(580);
  delayMicroseconds(500); pulseIR(580);
  delayMicroseconds(1600); pulseIR(580);
  delayMicroseconds(1600); pulseIR(580);
  delayMicroseconds(520); pulseIR(580);
  delayMicroseconds(500); pulseIR(580);
  delayMicroseconds(520); pulseIR(560);
  delayMicroseconds(1620); pulseIR(580);
  delayMicroseconds(1600); pulseIR(560);
  delayMicroseconds(1620); pulseIR(580);
  delayMicroseconds(38780); pulseIR(8780);
  delayMicroseconds(2160); pulseIR(580);
  
}






































