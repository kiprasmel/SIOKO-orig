#include "START_STRATEGIES.h"

void Start_Streategy()
{
  //Pradinės strategijos
  switch (START_STRATEGY_STATE) {
    case 1:
      motor(SPEED_NORMAL, SPEED_NORMAL);
      break;
    case 2:
      motor(255, 255);
      delay(200);
      break;
    case 3:
      motor(255, 255);
      delay(325);
      break;
    case 4: zigzag_desine_M();
      break;
    case 5: zigzag_kaire_M();
      break;
    case 6: zigzag_desine_D();
      break;
    case 7: zigzag_kaire_D();
      break;
	// case 8: {
	// 	laukimoStrategija();
	// 	break;
	// }
	case 8: {
		lankasKairen();
	}
	case 9: {
		lankasDesinen();
	}
  }
}
//------------------------------------------------------------------------------
void zigzag_desine_M()
{
  bool see = false;
  time = millis();
  while (millis() - time <= FIRST_TURN_M && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
  {
    motor(-200, 200);
    Jutikliu_duom();
    if (myLINE != 0b0000)
    {
      see = true;
      break;
    }
    if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
    {
      see = true;
      break;
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= STRAIGHT_M && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= SECOND_TURN_M && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(200, -200);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= STRAIGHT_M && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  /*motor(-200, 200);
    delay(20);
    motor(0, 0);
    delay(5);
    motor(255, 255);
    delay(135);
    motor(200, -200);
    delay(45);
    motor(0, 0);
    delay(5);
    motor(255, 255);
    delay(135);*/
}

void zigzag_kaire_M()
{
  bool see = false;
  time = millis();
  while (millis() - time <= FIRST_TURN_M && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
  {
    motor(200, -200);
    Jutikliu_duom();
    if (myLINE != 0b0000)
    {
      see = true;
      break;
    }
    if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
    {
      see = true;
      break;
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= STRAIGHT_M && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= SECOND_TURN_M && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(-200, 200);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= STRAIGHT_M && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }

  /*motor(200, -200);
    delay(15);
    motor(255, 255);
    delay(50);
    motor(-200, 200);
    delay(20);
    motor(255, 255);
    delay(150);*/
}
//------------------------------------------------------------------------------
void zigzag_desine_D()
{
  bool see = false;
  time = millis();
  while (millis() - time <= FIRST_TURN_D && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
  {
    motor(-200, 200);
    Jutikliu_duom();
    if (myLINE != 0b0000)
    {
      see = true;
      break;
    }
    if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 0 or digitalRead(Middle3) == 0)
    {
      see = true;
      break;
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= STRAIGHT_D && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= SECOND_TURN_D && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(200, -200);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= STRAIGHT_D && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 0 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  /*motor(-200, 200);
    delay(40);
    motor(255, 255);
    delay(100);
    motor(200, -200);
    delay(40);
    motor(255, 255);
    delay(150);*/
}
void zigzag_kaire_D()
{
  bool see = false;
  time = millis();
  while (millis() - time <= FIRST_TURN_D && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
  {
    motor(200, -200);
    Jutikliu_duom();
    if (myLINE != 0b0000)
    {
      see = true;
      break;
    }
    if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
    {
      see = true;
      break;
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= STRAIGHT_D && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= SECOND_TURN_D && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(-200, 200);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= 5 && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(0, 0);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  if (see != true)
  {
    time = millis();
    while (millis() - time <= STRAIGHT_D && (digitalRead(Middle1) == 1 or digitalRead(Middle2) == 1 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 1))
    {
      motor(255, 255);
      Jutikliu_duom();
      if (myLINE != 0b0000)
      {
        see = true;
        break;
      }
      if (digitalRead(Middle1) == 0 or digitalRead(Middle2) == 0 or digitalRead(Middle22) == 1 or digitalRead(Middle3) == 0)
      {
        see = true;
        break;
      }
    }
  }
  /*motor(200, -200);
    delay(40);
    motor(255, 255);
    delay(100);
    motor(-200, 200);
    delay(40);
    motor(255, 255);
    delay(150);*/
}
//------------------------------------------------------------------------------

bool arMato(const byte sensorius) {
	return digitalRead(sensorius) == 0 ? true : false;
}

bool arPriekisMatoBentVienas() {
	if (
		   arMato(Middle1)
		|| arMato(Middle2)
		|| arMato(Middle22)
		|| arMato(Middle3)
	) {
		return true;
	}

	return false;
}

bool arKaireMatoBentVienas() {
	if (
		   arMato(Left1)
		|| arMato(Left2)
		|| arMato(Left22)
		|| arMato(Left3)
	) {
		return true;
	}

	return false;
}

bool arDesineMatoBentVienas() {
	if (
		   arMato(Right1)
		|| arMato(Right2)
		|| arMato(Right22)
		|| arMato(Right3)
	) {
		return true;
	}

	return false;
}

bool arNutrauktiLaukima() {
	if (
		/** TODO - o kur middle panasonic? */
		(arMato(Middle2) || arMato(Middle22)) /** priekis */
		&& (arMato(Middle1) || arMato(Middle3)) /** šoninis */
	) {
		return true;
	}

	return false;
}

void laukimoStrategija() {
  enum Sonai {
	  priekis,
	  kaire,
	  desine,
	  nezinomas
  } paskutinePozicija;

  paskutinePozicija == Sonai::nezinomas;

	while (!arNutrauktiLaukima())
	{
		Jutikliu_duom();
		// Line(); /** TODO FIXME - linija trukdo laukimo strategijai. */

		if (arPriekisMatoBentVienas())
		{
			motor(0, 0);
      paskutinePozicija = Sonai::priekis;
		}
		else if (arDesineMatoBentVienas())
		{
			motor(+SPEED_TURN, -SPEED_TURN);
      paskutinePozicija = Sonai::desine;
		}
		else if (arKaireMatoBentVienas())
		{
			motor(-SPEED_TURN, +SPEED_TURN);
      paskutinePozicija = Sonai::kaire;
		}
		else {
			if (paskutinePozicija == Sonai::priekis) {
        motor(0, 0);
      } else if (paskutinePozicija == Sonai::kaire) {
        motor(-SPEED_TURN, +SPEED_TURN);
      } else if (paskutinePozicija == Sonai::desine) {
        motor(+SPEED_TURN, -SPEED_TURN);
      } else {
        motor(0, 0);
        paskutinePozicija == Sonai::nezinomas;
      }
		}
	}

	motor(255, 255);

	return;
}

void amzinasStop() {
	motor(0, 0);
	while (true) {}
}

void lankoStrategija(bool kaire0Desine1) {
	/** pasiruošiam (numanoma, jog stovim tiesiai pirmyn) */

	Krastai krastas = kaire0Desine1 == 1 ? Krastai::desine : Krastai::kaire;

	if (krastas == Krastai::kaire) {
		motor(-255, +255);
	} else {
		motor(+255, -255);
	}

	unsigned int laikas90DegPasisukimui = 50;

	delay(laikas90DegPasisukimui);
	motor(0, 0);

	/** važiuojam lanku */

	int letesnioGreitis = SPEED_NORMAL * 3 / 4;

	if (krastas == Krastai::kaire) {
		motor(SPEED_NORMAL, letesnioGreitis);
	}
	else if (krastas == Krastai::desine) {
		motor(letesnioGreitis, SPEED_NORMAL);
	}
	else {
		motor(-100, -100); /** TESTIGN */
	}

	/**
	 * jeigu sukamės kairėn, tai tikrins, ar dešinės sensoriai ką nors mato.
	 * jeigu dešinėn, tai ar kairės sensoriai mato
	 */
	// auto arVidujeKasNorsMatosi = (krastas == Krastai::kaire) ? arKaireMatoBentVienas : arDesineMatoBentVienas;

	int maxLaikasVaziavimoLanku = 5000;

	unsigned long pradziosLaikas = millis();

	/**
	 * važiuojam lanku TOL,
	 * KOL nesibaigė max laikas
	 * ARBA KOL viduje ką nors pamatom.
	 *
	 */
	while (true) {
		/** laukiam, nes `motor`ai jau važiuoja */

		/** baigiam, jei baigėsi laikas */
		if (millis() > pradziosLaikas + maxLaikasVaziavimoLanku) {
			break;
		}

		/** FIXME; siunčiam pirmyn ir baigiam, jei pamatom priekyje */
		// if (arVidujeKasNorsMatosi()) {
		// // if (krastas == Krastai::kaire && arKaireMatoBentVienas()) {

		// // }

		if (krastas == Krastai::desine) {
			if (arKaireMatoBentVienas()) {
				break;
			}
		}
		else if (krastas == Krastai::kaire) {
			if (arDesineMatoBentVienas()) {
				break;
			}
		}

		// // if ((krastas == Krastai::kaire) ? arDesineMatoBentVienas() : arKaireMatoBentVienas()) {
		// // 	// motor(255, 255);
		// // 	break;
		// // }
	}

	/** TESTING */
	// digitalWrite(13, HIGH);
	// amzinasStop();

	return;
}

void lankasKairen() {
	lankoStrategija(Krastai::kaire);
}

void lankasDesinen() {
	lankoStrategija(Krastai::desine);
}
