
/** @vmasiokas */
void leduIndikacijaSonamsIrPriekiui() {
    // priekio indikacija
	if (digitalRead (Middle1) == 0 || digitalRead(Middle2) == 0 || digitalRead(Middle22) == 0 || digitalRead(Middle3) == 0 ) {
    	digitalWrite(2, HIGH);
    }
	else {
    	digitalWrite(2, LOW);
	}

    // kaires indikacija
    if (digitalRead (Left1) == 0 ||digitalRead(Left2) == 0 || digitalRead(Left22) == 0 || digitalRead(Left3) == 0 ) {
    	digitalWrite(32, HIGH);
    } else {
    	digitalWrite(32, LOW);
	}

    // desines indikacija
    if (digitalRead (Right1) == 0 || digitalRead(Right2) == 0 || digitalRead(Right22) == 0 || digitalRead(Right3) == 0 ) {
      	digitalWrite(31, HIGH);
    } else {
    	digitalWrite(31, LOW);
    }

	return;
}
