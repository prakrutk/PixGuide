	
#include <SPI.h>
#include <MaxMatrix.h>

int DIN = 4;   // DIN pin of MAX7219 module
int CS = 5;   // CLK pin of MAX7219 module
int CLK = 6;    // CS pin of MAX7219 module
int maxInUse = 1,i;
int ar[50];
int pin = 7;
unsigned long duration;
int freq;
MaxMatrix m(DIN, CS, CLK, maxInUse);


byte Right[] = {8, 8, B10000001,B01000010,B00100100,B00011000,B00000000,B00000000,B00000000,B00000000}; 
*/**
   **
    **
   **
  ** */ 
byte slightright1[] ={8, 8, B00110000,B00110000,B11110000,B11110000,B00000000,B00000000,B00000000,B00000000};
*/*****
  *****
     **
     **
     ** */	
byte slightright2[] = {8, 8, B00001100,B00001100,B00001100,B00001100,B11111100,B11111100,B00000000,B00000000};
byte slightright3[] =  {8, 8, B00000011,B00000011,B00000011,B00000011,B00000011,B00000011,B11111111,B11111111};
byte sharpright[] =  {8, 8, B10000001,B01000010,B10100101,B01011010,B10100101,B01011010,B00100100,B00011000};
*/* * *
   * * *
    * * *
   * * *
  * * * */
byte Left[]= {8, 8, B00000000,B00000000,B00000000,B00000000,B00011000,B00100100,B01000010,B10000001};
*/  **
   **
  **
   **
    ** */
byte sharpleft[] = {8, 8, B00011000,B00100100,B01011010,B10100101,B01011010,B10100101,B01000010,B10000001};
*/  * * *
   * * *
  * * *
   * * *
    * * *  */

byte circle[] = {8, 8, B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};
*/    *
     * *
    *   *
     * *
      *    */
byte slightleft1[] =  {8, 8, B00000000,B00000000,B00000000,B00000000,B11110000,B11110000,B00110000,B00110000};
*/*****
  *****
  **
  **
  **  */
byte slightleft2[] ={8, 8, B00000000,B00000000,B11111100,B11111100,B00001100,B00001100,B00001100,B00001100};
byte slightleft3[] = {8, 8, B11111111,B11111111,B00000011,B00000011,B00000011,B00000011,B00000011,B00000011};
byte ramp[] =  {8, 8, B00000000,B00000000,B11111111,B11111111,B11111111,B11111111,B00000000,B00000000};
*/ ***
   ***
   *** */
byte phone[] = {8, 8, B00000000,B00000000,B11111111,B10100001,B10100001,B11111111,B00000000,B00000000};
*/ ****
   *  *
   *  *
   **** */
byte uturn[] ={8, 8, B00000000,B11111100,B00000010,B00000001,B00000001,B00100010,B01111100,B00100000};
*/****
  *  *
  *  * */
byte continuestraight[] ={8, 8, B00001000,B00001100,B11111110,B11111111,B11111111,B11111110,B00001100,B00001000};
*/  *
   ***
    *
    *   */
byte datalost[] ={8, 8, B00111100,B01000010,B10010101,B10100001,B10100001,B10010101,B01000010,B00111100};
*/  *****
   * * * *
   *  *  *
   * * * *
    *****     */
byte hundred[] = {8, 8, B00000000,B01111100,B00000000,B01111100,B01111100,B00000000,B01111100,B01111100};
*/* ** **
  * ** **
  * ** ** */
byte twohundred[] = {8, 8, B01110100,B01011100,B00000000,B01111100,B01111100,B00000000,B01111100,B01111100};
*/*** ** **
   ** ** **
  **  ** **
  *** ** ** */
byte hundredfifty[] =  {8, 8, B01111100,B00000000,B01011100,B01010100,B01110100,B00000000,B01111100,B01111100};
*/* **** **
  * **   **
  *  *** **
  *   ** **
  * **** ** */
byte fifty[] ={8, 8, B00000000,B01001110,B01001010,B01111010,B00000000,B01111110,B01000010,B01111110};
*/**** **
  **   **
   *** **
    ** **
  **** ** */ 
byte happy[] = {8, 8, B00111100,B01000010,B10010101,B10100001,B10100001,B10010101,B01000010,B00111100};
*/   *****
    * * * *
    * * * *
    *  *  *
     *****  */
byte then[] = {8, 8, B10000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
*/ *
void function ()
{
          int t=500;
         for(i=0;i<4;i++)
         {
           m.shiftRight(false);
           delay(t);
         
         }
}
void function1()
{
  int t=500;
  for(i=0;i<4;i++)
   {
           m.shiftLeft(false);
           delay(t);
   }
}      




void setup() {
 
	//Start Serial monitor in 9600
  	//ESP_BT.begin("ESP32_LED_Control"); //Name of your Bluetooth Signal
  	//Serial.println("Bluetooth Device is Ready to Pair");
  	m.init(); // MAX7219 initialization
  	m.setIntensity(8); // initial led matrix intensity, 0-15
  	Serial.begin(9600);
  	pinMode(7, INPUT);
}
void loop() {

	duration = pulseIn(7, HIGH);
	freq=(500000/duration);
	Serial.println("freq is");
	Serial.println(freq);
	switch(freq>=250)
	{
		case 1 : switch(freq >= 370)
			 {
				case 1 : switch(freq >= 430)
			  	 	 {
						case 1: switch(freq >=450)
							{
								case 1 : switch(freq >= 470)
									 {
									 	case 1 :switch(freq <490)
											{
												case 1 : m.writeSprite(0,0,happy);   //470-490 Hz 
											 		 delay(500);
													 for(i=0;i<5;i++)
													 {	 m.shiftLeft(false);
														 delay(500);
													 }
													 m.writeSprite(0,0,Left);
													 for(i=0;i<5;i++)
													 {	 m.shiftLeft(false);
														 delay(500);
													 }
													 break;
												case 0 : break; //>490 Hz
											}
											break;
										case 0 : m.writeSprite(0,0,happy); //450-470 Hz
											 delay(500);
											 for(i=0;i<5;i++)
											 {
											 	m.shiftRight(false);
												delay(500);
											 }
											 m.writeSprite(0,0,Right);
											 for(i=0;i<5;i++)
											 {
												m.shiftRight(false);
												delay(500);
											 }
											 break;
							 		 }
							 		 break;
								case 0 : m.writeSprite(0,0,twohundred); //430-450 Hz
									 delay(1000);
									 break;
							}
							break;

						case 0 : switch(freq >= 390)
							 {
							 	case 1 : switch(freq >= 410)
									 {
									 	case 1 : m.writeSprite(0,0,hundredfifty); //410-430 Hz
											 function();
											 break;  
 										case 0 : m.writeSprite(0,0,hundred); //390-410 Hz
											 delay(1000);
											 break;
									 }
									 break; 
								case 0 : m.writeSprite(0,0,fifty); //370-390 Hz
									 delay(1000);
									 break;
							 }
							 break;
					}
					break;
				case 0 :switch(freq >= 310)
					{
						case 1 :switch(freq >= 330)
							{
								case 1 :switch(freq >= 350)
								       {
										case 1 :m.writeSprite(0,0,continuestraight); //350-370 Hz
											delay(1000);
											break;
										case 0 :m.writeSprite(0,0,datalost); //330-359 Hz
											delay(1000);
											break;
									}
									break;
								case 0 :m.writeSprite(0,0,uturn); //310-330 Hz
								        delay(1000);
									break;
							}
							break;
						case 0 :switch(freq >= 270)
							{
								case 1 :switch(freq >=290) 
									{
										case 1 :m.writeSprite(0,0,slightright1); //290-310 Hz
											delay(1000);
											m.writeSprite(0,0,slightright2);
											delay(1000);
											m.writeSprite(0,0,slightright3);
											delay(1000);
											break;
										case 0 :m.writeSprite(0,0,ramp); //270-290 Hz
											delay(1000);
											break;
									}
									break;
								case 0 :m.writeSprite(0,0,slightleft1); //250-270 Hz
									delay(1000);
									m.writeSprite(0,0,slightleft2);
									delay(1000);
									m.writeSprite(0,0,slightleft3);
									delay(1000);
									break;
							 }
							 break;
					}
					break;
			}
			break;
		case 0 :switch(freq >= 170)
			{
				case 1 :switch(freq >= 210)
					{
						case 1 :switch(freq >= 230)
							{
								case 1 :m.writeSprite(0,0,circle); //230-250 Hz
									for(i=0;i<3;i++)
									{
										m.shiftLeft(false);
										delay(1000);
									}
									m.writeSprite(0,0,continuestraight);
									break;
								case 0 :m.writeSprite(0,0,phone); //210-230 Hz
									delay(1000);
									break;
							}
							break;
						case 0 :switch(freq >= 190) 
							{
								case 1 :m.writeSprite(0,0,then); //190-210 Hz
									function();
									break;
								case 0 :m.writeSprite(0,0,Left); //170-190 Hz
									delay(500);
									function1();	
									break;
							}
							break;
					}
					break;
				case 0 :switch(freq >=130)
					{
						case 1 :switch(freq >= 150)
							{
								case 1 :m.writeSprite(0,0,sharpleft); //150-170 Hz
									delay(1000);
									break;

								case 0 :m.writeSprite(0, 0,Right); //130-150 Hz
									function();
									break;
							}
							break;
						case 0 :switch(freq >= 110)
							{
								case 1 :m.writeSprite(0,0,sharpright); //110-130 Hz
									delay(7000);
									break;
								case 0 :switch(freq > 90)
									{
										case 1 :m.writeSprite(0,0,happy); //90-110 Hz
											delay(7000);
											break;
										case 0 :break; //<90 Hz
									}
									break;
							}
							break;
					}
					break;
			}
			break;
	}
  								

	 	   
	/*if(freq>=90&&freq<110)
	{	m.writeSprite(0,0,happy);
		delay(7000);
	}
	else if(freq>=110&&freq<130)
	{	m.writeSprite(0,0,sharpright);
		delay(7000);
	}

	else if(freq>=130&&freq<150)
	{
		m.writeSprite(0, 0,Right);
		function();  
	}
	else if(freq>=150&&freq<170)
	{	m.writeSprite(0,0,sharpleft);
		delay(1000);
	}
	else if(freq>=170&&freq<190)
	{
		m.writeSprite(0,0,Left);
		delay(500);
		function1();
	}
	else if(freq>=190&&freq<210)
	{	m.writeSprite(0,0,then);
		function();
	}
	else if(freq>=210&&freq<230)
	{	m.writeSprite(0,0,phone);
		delay(1000);
	}

	else if(freq>=230&&freq<250)
	{	m.writeSprite(0,0,circle);
		for(i=0;i<3;i++)
		{
			m.shiftLeft(false);
			delay(1000);
		}
		m.writeSprite(0,0,continuestraight);
	}
	else if(freq>=250&&freq<270)
	{	m.writeSprite(0,0,slightleft1);
		delay(1000);
		m.writeSprite(0,0,slightleft2);
		delay(1000);
		m.writeSprite(0,0,slightleft3);
		delay(1000);
	}
	else if(freq>=270&&freq<290)
	{	m.writeSprite(0,0,ramp);
		delay(1000);
	}
	else if(freq>=290&&freq<310)
	{
		m.writeSprite(0,0,slightright1);
		delay(1000);
		m.writeSprite(0,0,slightright2);
		delay(1000);
		m.writeSprite(0,0,slightright3);
		delay(1000);

	}

	else if(freq>=310&&freq<330)
	{	m.writeSprite(0,0,uturn);
		delay(1000);
	}

	else if(freq>=330&&freq<350)
	{	m.writeSprite(0,0,datalost);
		delay(1000);
	}
	else if(freq>=350&&freq<370)
	{	m.writeSprite(0,0,continuestraight);
		delay(1000);
	}
	else if(freq>=370&&freq<390)
	{	m.writeSprite(0,0,fifty);
		delay(1000);
	}
	else if(freq>=390&&freq<410)
	{	m.writeSprite(0,0,hundred);
		delay(1000);
	}
	else if(freq>=410&&freq<430)
	{	m.writeSprite(0,0,hundredfifty);
		function();
	}
	else if(freq>=430&&freq<450)
	{	m.writeSprite(0,0,twohundred);
		delay(1000);
	}
	else if(freq>=450&&freq<470)
	{	m.writeSprite(0,0,happy);
		delay(500);
		for(i=0;i<5;i++)
		{\*
			m.shiftRight(false);
			delay(500);
		}
		m.writeSprite(0,0,Right);
		for(i=0;i<5;i++)
		{	m.shiftRight(false);
			delay(500);
		}
	}
	else if(freq>=470&&freq<490)
	{	m.writeSprite(0,0,happy);
		delay(500);
		for(i=0;i<5;i++)
		{	m.shiftLeft(false);
			delay(500);
		}
		m.writeSprite(0,0,Left);
		for(i=0;i<5;i++)
		{	m.shiftLeft(false);
			delay(500);
		}
	}*/
}


