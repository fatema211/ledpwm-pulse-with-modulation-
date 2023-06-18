void setup(){
  
  const byte ocr2b = 63;  // duty cycle 

  asm volatile(
    "ldi r16, 0x23\n\t"  // non inverting fast pwm 
    "ldi r27, 0x00\n\t"   
    "ldi r26, 0xB0\n\t"  //L/S address of TCCR2A(0xB0) with content 0x23
    "st X, r16\n\t"    //content 0x23 is stored in address 0xB0
    "ldi r16, 0x04\n\t" 
    "ldi r26, 0xB1\n\t"
    "st x, r16\n\t"    // prescaler 64
    
    //"st X, r16\n\t"     // TCCR2B= 0x04 (prescaler 64) for period 1024µs
    "ldi r26, 0xB4\n\t"   // X= OCR2B
    "st X,%0\n\t"      // REGI OCR2B=variable oc2b
    "ldi r16, 0x08\n\t" // DDRB output configuration in PD3= 00001000
    "out 0x0A, r16"::"r"(ocr2b) );    // input variable ocr2b , no return value // load content of r16 in address 0x0A=DDRD
    
   
  
  
  }
  void loop(){   }
