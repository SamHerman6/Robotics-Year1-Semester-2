/*
    Program for EV3 to complete a route with location finder
	+ Avoid obstacles (walls) using ultra-Sonic

	by: Roman Holub Ploshko
	Stu. ID: C20390201
*/

int leftMotor = 1;
int rightMotor = 2;

int rotations_0 = (360/17.3)*2;  // 2cm
int rotations_1 = (360/17.3)*10; // 10cm = 208.09 rotations
int rotations_2 = (360/17.3)*14; // 14cm = 291.329 --------> PRIMARILY IN USE
int rotations_3 = (360/17.3)*17; // 17cm = 353.757


/*-----------------------------------STRAIGHT_Ncm-----------------------------------*/
void straight_Ncm(int speed, int target)
{
	//NEED RESETS SINCE setMotorTarget() is to ABSOLUTE TARGET
	resetMotorEncoder(leftMotor);//since setMotorTarget is ABSOLUTE
	resetMotorEncoder(rightMotor);
	setMotorTarget(leftMotor,target, speed);//to ABSOLUTE encoder value
	setMotorTarget(rightMotor,target, speed);//to ABSOLUTE encoder value
	
	
	while(getMotorRunning(leftMotor) || getMotorRunning(rightMotor))
		wait1Msec(500);//until motor speeds will go to 0
	return;
} // end straight_Ncm

/*-----------------------------------DESTINATION SELECT-----------------------------------*/
int destinationSelect()
{	
	while(getButtonPress(buttonEnter) == 0)
	{
		//displaying options
		displayCenteredTextLine(1, "Press left for [5,5]");
		displayCenteredTextLine(3, "Press Right for [1,1]");
		displayCenteredTextLine(5, "Press UP for [1,6]");
		displayCenteredTextLine(7, "Press Down for [7,1]");
		
		
		wait1Msec(200);
		eraseDisplay();
		
		if (getButtonPress(buttonLeft))//if button right selected return 1
		{
			return 1;
		}
		
		else if (getButtonPress(buttonRight))//if button left selected return 2
		{
			return 2;
		}
		
		else if (getButtonPress(buttonUp))//if button left selected return 3
		{
			return 3;
		}
		
		else if (getButtonPress(buttonDown))//if button left selected return 4
		{
			return 4;
		}
		
	} //end while loop
} // end destinationSelect()

/*-----------------------------------LEFT TURN-----------------------------------*/
void turn90left()
{
	//declaring variables
	int degrees;
	int heading;
	int rate;
	
	SensorType[S1] = sensorEV3_Gyro;
	
	
	eraseDisplay();
	resetGyro(S1);
	degrees = getGyroDegrees(S1);
	
	//turn90
	while(degrees < 86)
	{
		setMotorSpeed(leftMotor, 40);
		setMotorSpeed(rightMotor, -40);
		
		degrees = getGyroDegrees(S1);
		heading = getGyroHeading(S1);
		rate = getGyroRate(S1);
		
		sleep(10);	
	}// end while
	
	//stop turn
	eraseDisplay();
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	
	return;
} // end turn90left()

//-------Fixes inconsistencies after 2nd left turn-------//
void turn90left_2() 
{
	//declaring variables
	int degrees;
	int heading;
	int rate;
	
	SensorType[S1] = sensorEV3_Gyro;
	
	
	eraseDisplay();
	resetGyro(S1);
	degrees = getGyroDegrees(S1);
	
	//turn90
	while(degrees < 85) // changed to 85
	{
		setMotorSpeed(leftMotor, 40);
		setMotorSpeed(rightMotor, -40);
		
		degrees = getGyroDegrees(S1);
		heading = getGyroHeading(S1);
		rate = getGyroRate(S1);
		
		sleep(10);	
	}// end while
	
	//stop turn
	eraseDisplay();
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	
	return;
} // end turn90left_2()

//-------A few straight left turns got caught in the obstacle, this left turn fixes this-------//
void turn90left_3() 
{
	//declaring variables
	int degrees;
	int heading;
	int rate;
	
	SensorType[S1] = sensorEV3_Gyro;
	
	
	eraseDisplay();
	resetGyro(S1);
	degrees = getGyroDegrees(S1);
	
	//turn90
	while(degrees < 84) //changed to 84
	{
		setMotorSpeed(leftMotor, 40);
		setMotorSpeed(rightMotor, -40);
		
		degrees = getGyroDegrees(S1);
		heading = getGyroHeading(S1);
		rate = getGyroRate(S1);
		
		sleep(10);	
	}// end while
	
	//stop turn
	eraseDisplay();
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	
	return;
} // end turn90left_3()

/*-----------------------------------RIGHT TURN-----------------------------------*/
void turn90right()
{
	//declaring variables
	int degrees;
	int heading;
	int rate;
	
	
	eraseDisplay();
	resetGyro(S1);
	degrees = getGyroDegrees(S1);
	
	//turn90
	while(degrees > -85)
	{
		setMotorSpeed(leftMotor, -40);
		setMotorSpeed(rightMotor, 40);
		
		degrees = getGyroDegrees(S1);
		heading = getGyroHeading(S1);
		rate = getGyroRate(S1);
		
		sleep(10);	
	}//end while
	
	//stop turn
	eraseDisplay();
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	return;
} // end turn90right()

/*-----------------------------------OBSTACLE_AROUND_LEFT-----------------------------------*/

/*----FOR DESTINATION_1----*/
void obstacle_around_right()
{
	turn90right();
	straight_Ncm(100, rotations_2);
	straight_Ncm(100, rotations_2);
	
	turn90left_3();
	straight_Ncm(100, rotations_2);
}

/*----FOR DESTINATION_2----*/
void obstacle_around_left()
{
	straight_Ncm(100, rotations_0);
	turn90left();
	straight_Ncm(100, rotations_2);
	straight_Ncm(100, rotations_2);
	straight_Ncm(100, rotations_2);
	straight_Ncm(100, rotations_2);
	turn90right();
}

/*----FOR DESTINATION_3----*/
void obstacle_around_left_2()
{
	turn90left();
	straight_Ncm(100, rotations_3);
	turn90right();
}

/*----FOR DESTINATION_4----*/
void obstacle_around_right_2()
{
	turn90right();
	straight_Ncm(100, rotations_3);
	turn90left_2();
}

/*-----------------------------------CURRENT_DISTANCE-----------------------------------*/
int current_distance()
{
	int count = 0;
	int currentDistance;
	currentDistance = SensorValue[S2];	
	
	while(count<10)
	{
		count = count + 1; //this while loop gets the current distance from the nearest obstacle
		wait1Msec(2);
		getUSDistance(S2);
	}
	return currentDistance; //returns the current distance to destination_#
}

/*-----------------------------------DESTINATION 1 [5,5]-----------------------------------*/
void destination_1(int x, int y)
{
	//declaring variables
	int destinationX = 5;
	int destinationY = 5;
	
	int currentDistance;
	currentDistance = SensorValue[S2];
	
	// display chosen destination
	displayBigTextLine(2, "Destination chosen:");
	displayCenteredBigTextLine(4, "%d, %d", destinationX, destinationY);
	wait1Msec(1000);
	eraseDisplay();
	
	while(x < destinationX)
	{
		if (SensorValue[S2] > 20)
		{	//displaying current location on board
			displayBigTextLine(2, "Your current local:");
			displayCenteredBigTextLine(4, "%d, %d", x, y);				
			wait1Msec(1000);
			
			straight_Ncm(100, rotations_2); // FUNCTION CALL to drive straight 30cm
			wait1Msec(1000); 
			
			x++; 
			
			displayBigTextLine(2, "Your current local:");
			displayCenteredBigTextLine(4, "%d, %d", x, y);
			
			wait1Msec(1000);
			
			currentDistance = current_distance();
		}
		else
		{
			obstacle_around_right();
			x++;
			y++;
			y++; // since straight_Ncm was used x2
		}
	}//end while
	
	turn90right(); // FUNCTION CALL to turn RIGHT
	
	while(y < destinationY)
	{
		//displaying current location on board after turn
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
		
		straight_Ncm(100, rotations_2); // FUNCTION CALL to drive straight 30cm
		wait1Msec(1000);
		
		y++;
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
	}// end while loop
	
	//displaying destination reached
	displayCenteredBigTextLine(2, "Destiny reached!");
	displayCenteredBigTextLine(4, "(%d, %d)", x, y);
	wait1Msec(3000);
	
} // end destination_1()
/*-----------------------------------DESTINATION 2 [1,1]-----------------------------------*/
void destination_2(int x, int y)
{
	//declaring variables
	int destinationX = 1;
	int destinationY = 1;
	
	int currentDistance;
	currentDistance = SensorValue[S2];
	
	// display chosen destination
	displayBigTextLine(2, "Destination chosen:");
	displayCenteredBigTextLine(4, "%d, %d", destinationX, destinationY);
	wait1Msec(1000);
	eraseDisplay();
	
	turn90left(); // FUNCTION CALL to turn LEFT
	
	while(x > destinationX)
	{
		if (SensorValue[S2] > 18)
		{
			//displaying current location on board
			displayBigTextLine(2, "Your current local:");
			displayCenteredBigTextLine(4, "%d, %d", x, y);
			wait1Msec(1000);
			
			straight_Ncm(100, rotations_2); // FUNCTION CALL to drive straight 30cm
			wait1Msec(1000); 
			
			x--; 
			
			displayBigTextLine(2, "Your current local:");
			displayCenteredBigTextLine(4, "%d, %d", x, y);
			wait1Msec(1000);
			
			
			currentDistance = current_distance(); // FUNCTION CALL TO GET CURRENT DISTANCE
		} // end if
		else
		{
			obstacle_around_left();
			
			y--;
			y--;
			y--;
			y--; // since straight_Ncm was used x2
		}
	}//end while
	
	while(y > destinationY)
	{
		//displaying current location on board after turn
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
		
		straight_Ncm(100, rotations_2); // FUNCTION CALL to drive straight 30cm
		wait1Msec(1000);
		
		y--;
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
	}// end while loop
	
	//displaying destination reached
	displayCenteredBigTextLine(2, "Destiny reached!");
	displayCenteredBigTextLine(4, "(%d, %d)", x, y);
	wait1Msec(3000);
	
} // end destination_2()

/*-----------------------------------DESTINATION 3 [1,6]-----------------------------------*/
void destination_3(int x, int y)
{
	//declaring variables
	int destinationX = 1;
	int destinationY = 6;
	
	int currentDistance;
	currentDistance = SensorValue[S2];
	
	// display chosen destination
	displayBigTextLine(2, "Destination chosen:");
	displayCenteredBigTextLine(4, "%d, %d", destinationX, destinationY);
	wait1Msec(1000);
	eraseDisplay();
	
	turn90left(); // FUNCTION CALL to turn LEFT
	while(x > destinationX)
	{
		if (SensorValue[S2] > 18)
		{
			//displaying current location on board
			displayBigTextLine(2, "Your current local:");
			displayCenteredBigTextLine(4, "%d, %d", x, y);
			wait1Msec(1000);
			
			straight_Ncm(100, rotations_2); // FUNCTION CALL to drive straight 30cm
			wait1Msec(1000); 
			
			x--; 
			
			displayBigTextLine(2, "Your current local:");
			displayCenteredBigTextLine(4, "%d, %d", x, y);
			wait1Msec(1000);
			
			currentDistance = current_distance(); // FUNCTION CALL TO GET CURRENT DISTANCE
		} // end if
		else
		{
			obstacle_around_left_2(); // CALLING FUNCTION TO GO AROUND OBSTACLE
			y--;
		}
		
	}// end while
	
	turn90right();
	
	while(y < destinationY)
	{
		//displaying current location on board after turn
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
		
		straight_Ncm(100, rotations_2); // FUNCTION CALL to drive straight 30cm
		wait1Msec(1000);
		
		y++;
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
	}// end while loop
	
	//displaying destination reached
	displayCenteredBigTextLine(2, "Destiny reached!");
	displayCenteredBigTextLine(4, "(%d, %d)", x, y);
	wait1Msec(3000);
	
} // end destination_3()

/*-----------------------------------DESTINATION 4 [7,1]-----------------------------------*/
void destination_4(int x, int y)
{
	//declaring variables
	int destinationX = 7;
	int destinationY = 1;
	
	int currentDistance;
	currentDistance = SensorValue[S2];
	
	// display chosen destination
	displayBigTextLine(2, "Destination chosen:");
	displayCenteredBigTextLine(4, "%d, %d", destinationX, destinationY);
	wait1Msec(1000);
	eraseDisplay();
	
	turn90right(); // FUNCTION CALL to turn RIGHT
	
	while(x < destinationX)
	{
		if (SensorValue[S2] > 18)
		{
			//displaying current location on board
			displayBigTextLine(2, "Your current local:");
			displayCenteredBigTextLine(4, "%d, %d", x, y);
			wait1Msec(1000);
			
			straight_Ncm(100, rotations_2); // FUNCTION CALL to drive straight 30cm
			wait1Msec(1000); 
			
			x++; 
			
			displayBigTextLine(2, "Your current local:");
			displayCenteredBigTextLine(4, "%d, %d", x, y);
			wait1Msec(1000);
			
			currentDistance = current_distance(); // FUNCTION CALL TO GET CURRENT DISTANCE
			
		} // end if
		else
		{
			obstacle_around_right_2();
			y--;
			
		}
		
	}//end while
	
	turn90right(); // FUNCTION CALL to turn LEFT
	
	while(y > destinationY)
	{
		//displaying current location on board after turn
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
		
		straight_Ncm(100, rotations_2); // FUNCTION CALL to drive straight 30cm
		wait1Msec(1000);
		
		y--;
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
	}// end while loop

	//displaying destination reached
	displayCenteredBigTextLine(2, "Destiny reached!");
	displayCenteredBigTextLine(4, "(%d, %d)", x, y);
	wait1Msec(3000);

} // end destination_4()


task main()
{
	//declaring variables
	int destination = 0;
	int x = 0;
	int y = 0;
	
	SensorType[S1] = sensorEV3_Gyro;//assigning sensors
	SensorType[S2] = sensorEV3_Ultrasonic;
	
	destination = destinationSelect();
	
	if (destination == 1)
	{
		x = 1; // STARTING COORDS (EACH DESTINATION HAS DIFFERENT)
		y = 1;
		destination_1(x, y); //CALLS FUNCTION TO C
	}
	
	else if (destination == 2)
	{
		x = 5;
		y = 5;
		destination_2(x, y);
	}
	
	else if (destination == 3)
	{
		x = 6;
		y = 6;
		
		destination_3(x, y);
	}
	
	else if (destination == 4)
	{
		x = 1;
		y = 6;
		
		destination_4(x, y);
	}
	
}//end main
