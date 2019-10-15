#include <IRremote.h>

//Pultelio hex kodai ir nustatymai
#define Number1  0xFF906F
#define Number2  0xFFB847
#define Number3  0xFFF807
#define Number4  0xFF9867
#define Number5  0xFFD827
#define Number6  0xFF8877
#define Number7  0xFFE817
#define Number8  0xFF48B7
#define Number9  0xFF9A65
#define Enter    0xFFE01F
#define MY_PROTOCOL NEC;

//Siustuvo nustatymai
const byte RECV_PIN = 30;
IRrecv irrecv(RECV_PIN);
decode_results results;
int etr = 0;

byte myLINE  = B0000;
byte myLINEBACK  = B00;
byte mySIDES = B000000;//buvo 6
byte myFRONT = B000000;
byte myMOUSE = B00;//8

//varikliu pajungimas
const byte PWM1 = 7;
const byte PWM2 = 9;
const byte DIR1 = 6;
const byte DIR2 = 10;

//Linijos sensoriai
const byte LeftLine1 = 35;//rau
const byte LeftLine2 = 36;//g

const byte RightLine1 = 37;//ru
const byte RightLine2 = 38;//z


//puolimo sensoriai

const byte Right1 = 19;//23---  90
const byte Right2 = 22;//22---45
const byte Right22 = 18;//lazeris ilgas
const byte Right3 = 17;//21 lazeris trumpas
//--------------------gali pjautis trumpas su ilgu---------------------
//const byte Right3 = 17;//21 lazeris trumpas
const byte Middle1 = 21;//20 pan sone
const byte Middle2 = 15;//19  yra lazeris trumpas
const byte Middle22 = 16;//19  yra lazeris ilgas------------------- pasitikrinti ar mato per leda !!!!!
const byte Middle3 = 34;//33   pan sone
//const byte Left3 = 39;//18 lazeris trumpas
///-----------------------------------------------
const byte Left3 = 39;//18 lazeris trumpas
const byte Left22 = 14 ;//18 lazeris ilgas 45
const byte Left2 = 20;//17--   45
const byte Left1 = 23;//16--  90

//-------------------------------------------


int k = 0;
int b = 0;

const byte START_MODULE = 29;

//Varikliu greiciai
const byte SPEED_NORMAL = 255;//200 tiesiai su senais ratais, 255 nurauna pries gala i sona
const byte SPEED_TURN = 255;// 220 210
const byte SPEED_TURN2 = 210;//210
const byte SPEED_GO_BACK_LINE = 255;
const byte SPEED_GO_BACK_LINE_TURN = 200;
const byte SPEED_GO_BACK_LINE_TURN2 = 200;

//atsitraukimo ir pasisukimo atsitraukiant laikai priekiniu linijos
const unsigned short TIME_FOR_GO_BACK = 90;//60
const unsigned short TIME_FOR_GO_BACK_1 = 90;//105

byte START_STRATEGY_STATE = 0;
byte MAIN_STRATEGY_STATE = 0;

//Milis
unsigned long time;

bool Front = false;

//Strategiju laikai
const byte FIRST_TURN_M = 20;
const byte SECOND_TURN_M = 45;
const byte STRAIGHT_M = 120;//buvo120---------

const byte FIRST_TURN_D = 20;
const byte SECOND_TURN_D = 45;
const byte STRAIGHT_D = 120;//buvo140--------------

byte check;

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);

  pinMode(PWM1, OUTPUT);//PWM1
  pinMode(PWM2, OUTPUT);//PWM1
  pinMode(DIR1, OUTPUT); //DIR1
  pinMode(DIR2, OUTPUT); //DIR2

  pinMode(LeftLine1, INPUT); //LeftLine1
  pinMode(LeftLine2, INPUT); //LeftLine2
  pinMode(RightLine1, INPUT); //RightLine1
  pinMode(RightLine2, INPUT); //RightLine2


  pinMode(Right1, INPUT);
  pinMode(Right2, INPUT);
  pinMode(Right3, INPUT);
  pinMode(Right22, INPUT);


  pinMode(Middle1, INPUT);
  pinMode(Middle2, INPUT);
  pinMode(Middle22, INPUT);
  pinMode(Middle3, INPUT);

  pinMode(Left22, INPUT);
  pinMode(Left3, INPUT);
  pinMode(Left2, INPUT);
  pinMode(Left1, INPUT);


  leduIndikacijaSonamsIrPriekiui(); /** TESTING */

  analogWriteFrequency(9, 15000);//
  analogWriteFrequency(7, 15000);// varikliu valdymo daznis

  irrecv.enableIRIn();
  IR_Remote();

  pinMode(START_MODULE, INPUT);
  while (true) {
    if (digitalRead(START_MODULE)== HIGH) {
      break;
    }
    Jutikliu_duom();
    if (myFRONT != 0b000000) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }

  	Start_Streategy();
}

/**
 * paprastas startinės strategijos testavimas
 * bus galima ištrinti.
 */
// // void loop()
// // {
// // 	// 	Serial.print("\nstart Strategija ");
// // 	// Serial.print(START_STRATEGY_STATE);

// // 	digitalWrite(13, HIGH);

// //   	Start_Streategy();

// // 	digitalWrite(13, LOW);

// // 	delay(1000);
// // }

//------------------------------------------------------------------------------
void loop() {
  leduIndikacijaSonamsIrPriekiui(); /** TESTING */

  //motor(0,0);
  Jutikliu_duom();
  Line();
  switch (MAIN_STRATEGY_STATE)
  {
    case 1:
      switch (myFRONT) {
        /*case 0b10000:
        case 0b11000:
          SpinLeft(SPEED_TURN, 0.1);
          break;
        case 0b00001:
        case 0b00011:
          SpinRight(SPEED_TURN, 0.1);
          break;*/
        case 0b00000:
          Jutikliu_duom();
          Line();
          switch (mySIDES)
          {
            //--------------------------------------------------------------------------
            case 0b00000000://
              Jutikliu_duom();
              Line();
              break;
            case 0b00010000://lazeris ilgas
            case 0b00100000://lazeris trumpas
            case 0b00110000://lazeriai abu
            case 0b01100000://lazeris ir pan 45
            case 0b01110000:// abu laz ir pan 45

            //case 0b11100000:
           // case 0b10100000:


              SpinLeft(SPEED_TURN, 25);//30--i kaire Ar nepersisuks pilnu greiciu???????
              break;

            case 0b00001000:// lazeris ilgas
            case 0b00000100://lazeris trumpas
            case 0b00001100://lazeriai abu
            case 0b00000110://lazeris ir pan 45
            case 0b00001110://abu laz ir pan 45

            //case 0b00000111:
           // case 0b00000101:

              SpinRight(SPEED_TURN, 25);//30//i desine ar nepersisuka?????
              break;
            //case 0b01000000:

             // SpinLeft(SPEED_TURN, 25);//5
             // break;
           // case 0b00000010:

              //SpinRight(SPEED_TURN, 25);//5
              //break;
            case 0b11000000:
            case 0b10000000:
              SpinLeft(SPEED_TURN, 60);//40 perdaug pasisuka
              break;
            case 0b00000011:
            case 0b00000001:
              SpinRight(SPEED_TURN, 60);//40 perdaug pasisuka
              break;
              //-------------------------------------------------------------------
          }
          break;
        default:
          time = millis();
          while (millis() - time <= 100 && digitalRead(Middle1) == 0 && digitalRead(Middle2) == 0 && digitalRead(Middle22) == 0 && digitalRead(Middle3) == 0 && millis() - time >= 40)
          {
            motor(255, 255);
          }
          break;
      }
      break;
      case 2:
        switch (myFRONT) {
        /*case 0b10000:
        case 0b11000:
          SpinLeft(SPEED_TURN, 0.1);
          break;
        case 0b00001:
        case 0b00011:
          SpinRight(SPEED_TURN, 0.1);
          break;*/
        case 0b00000:
          Jutikliu_duom();
          Line();
        default:
          time = millis();
          while (millis() - time <= 100 && digitalRead(Middle1) == 0 && digitalRead(Middle2) == 0 && digitalRead(Middle22) == 0 && digitalRead(Middle3) == 0 && millis() - time >= 40)
          {
            motor(255, 255);
          }
          break;
        }
      break;
      case 3:
        Jutikliu_duom();
        Line();
      break;
      case 9:
        motor(250,250);
        delay(2000);
        motor(-250,-250);
        delay(2000);
      break;
  }

}
void motor(int a, int b) {
  a = constrain(a, -255, 255);
  b = constrain(b, -255, 255);
 //a-=60;//beveik//60

  if (digitalRead(START_MODULE)== LOW) {
      a=0;
      b=0;
    }
  if (a <= -1 )//&& a > -255
  {
    digitalWrite(DIR1, 1);
    analogWrite(PWM1, (255 - abs(a)));
  } else if (a >= 1 )
  {
    digitalWrite(DIR1, 0);
    analogWrite(PWM1, a);
  } else if (a == 0)
  {
    digitalWrite(DIR1, 0);
    analogWrite(PWM1, 0);
  }

  if (b >= 1 )//&& b > -255
  {
    // b = map(abs(b), 0,255,255,0);
    digitalWrite(DIR2, 0);
    analogWrite(PWM2, b); // 255 -
  } else if (b <= -1 )//&& b < 255
  {
    digitalWrite(DIR2, 1);
    analogWrite(PWM2, (255 - abs(b)));
  } else if (b == 0)
  {
    digitalWrite(DIR2, 0);
    analogWrite(PWM2, 0);
  }

}
int Jutikliu_duom() {
  for (int i = 0; i <= 9; i++) {//9
    bitClear(myLINE, i);
    bitClear(myFRONT, i);
    bitClear(mySIDES, i);
  }
  //Sonai


  if (digitalRead(Right1) == 0)     bitSet(mySIDES, 0);//90
  if (digitalRead(Right2) == 0)     bitSet(mySIDES, 1);//45
  if (digitalRead(Right22) == 0)  bitSet(mySIDES, 2);// 45 lazeris
   //if (digitalRead(Right3) == 0)     bitSet(mySIDES, 3);//0
  // if (digitalRead(Left3) == 0)      bitSet(mySIDES, 4);//4
  if (digitalRead(Left22) == 0)   bitSet(mySIDES, 3);//45 lazeris
  if (digitalRead(Left2) == 0)      bitSet(mySIDES, 4);//45
  if (digitalRead(Left1) == 0)      bitSet(mySIDES, 5);//90


  //Priekis
  //if (digitalRead(Right3) == 0)     bitSet(myFRONT, 0);//0
  if (digitalRead(Middle1) == 0)    bitSet(myFRONT, 0);//1
  if (digitalRead(Middle2) == 0)    bitSet(myFRONT, 1);//2
  if (digitalRead(Middle22) == 0)    bitSet(myFRONT, 2);//prikabintas naujas papildomas
  if (digitalRead(Middle3) == 0)    bitSet(myFRONT, 3);//3
  //if (digitalRead(Left3) == 0)      bitSet(myFRONT, 5);//4



  //Linija
  if (digitalRead(LeftLine1) == 1)    bitSet(myLINE, 3);
  if (digitalRead(LeftLine2) == 1)    bitSet(myLINE, 2);
  if (digitalRead(RightLine1) == 1)   bitSet(myLINE, 0);
  if (digitalRead(RightLine2) == 1)   bitSet(myLINE, 1);

}

void Line()
{
  //Back = false;
  //Linija
  switch (myLINE)
  {
    case 0b0011://Right
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK)
      {
        motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK_1)
      {
        motor(-SPEED_GO_BACK_LINE_TURN, SPEED_GO_BACK_LINE_TURN2);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      break;
    case 0b1100://Left
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK)
      {
        motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK_1)
      {
        motor(SPEED_GO_BACK_LINE_TURN, -SPEED_GO_BACK_LINE_TURN2);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      break;
    case 0b1111://Both
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK)
      {
        motor(-SPEED_GO_BACK_LINE, -SPEED_GO_BACK_LINE);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      time = millis();
      while (millis() - time <= TIME_FOR_GO_BACK)
      {
        motor(-SPEED_GO_BACK_LINE_TURN, SPEED_GO_BACK_LINE_TURN2);
        //Jutikliu_duom_back();
        if (myLINEBACK != 0b00)
        {
          break;
        }
      }
      break;
    case 0:
      motor(SPEED_NORMAL, SPEED_NORMAL);
      break;
  }
}
void SpinRight(int a, int t)// kad nepersisuktu, viduriniai siek tiek i sona ziurintys lockina robota
{
  time = millis();
  while (millis() - time <= t && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
  {
    motor(a, -a);
  }
}
void SpinLeft(int a, int t)
{
  time = millis();
  while (millis() - time <= t && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
  {
    motor(-a, a);
  }
}
