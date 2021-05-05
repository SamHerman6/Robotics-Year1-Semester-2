/*
    Program for EV3 to complete a route with location finder
*/

int leftMotor = 1;
int rightMotor = 2;

int rotations_1 = (360/17.3)*10; // 10cm = 208.09 rotations
int rotations_2 = (360/17.3)*14; // 14cm = 291.329 --------> IN USE
int rotations_3 = (360/17.3)*30; // 30cm = 624.277


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
	while(degrees < 85)
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

/*-----------------------------------DESTINATION 1 [5,5]-----------------------------------*/
void destination_1(int x, int y)
{
	//declaring variables
	int destinationX = 5;
	int destinationY = 5;
	
	// display chosen destination
	displayBigTextLine(2, "Destination chosen:");
	displayCenteredBigTextLine(4, "%d, %d", destinationX, destinationY);
	wait1Msec(1000);
	eraseDisplay();
	
	while(x < destinationX)
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
	}//end while
	
	turn90right(); // FUNCTION CALL to turn LEFT
	
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
} // end destination_1()

/*-----------------------------------DESTINATION 2 [1,1]-----------------------------------*/
void destination_2(int x, int y)
{
	//declaring variables
	int destinationX = 1;
	int destinationY = 1;

	int i = 0;
	
	// display chosen destination
	displayBigTextLine(2, "Destination chosen:");
	displayCenteredBigTextLine(4, "%d, %d", destinationX, destinationY);
	wait1Msec(1000);
	eraseDisplay();
	
	//180 degree turn to left
	turn90left(); // FUNCTION CALL to turn LEFT

	while(x > destinationX)
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
	}//end while
	

	turn90left_2(); // FUNCTION CALL to turn RIGHT

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
} // end destination_2()

/*-----------------------------------DESTINATION 3 [1,6]-----------------------------------*/
void destination_3(int x, int y)
{
	//declaring variables
	int destinationX = 1;
	int destinationY = 6;
	
	// display chosen destination
	displayBigTextLine(2, "Destination chosen:");
	displayCenteredBigTextLine(4, "%d, %d", destinationX, destinationY);
	wait1Msec(1000);
	eraseDisplay();

	turn90left(); // FUNCTION CALL to turn LEFT
	while(x > destinationX)
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
} // end destination_3()

/*-----------------------------------DESTINATION 4 [7,1]-----------------------------------*/
void destination_4(int x, int y)
{
	//declaring variables
	int destinationX = 7;
	int destinationY = 1;
	
	// display chosen destination
	displayBigTextLine(2, "Destination chosen:");
	displayCenteredBigTextLine(4, "%d, %d", destinationX, destinationY);
	wait1Msec(1000);
	eraseDisplay();
	
	turn90right(); // FUNCTION CALL to turn LEFT

	while(x < destinationX)
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
} // end destination_4()


task main()
{
	//declaring variables
	int destination = 0;
	int x = 0;
	int y = 0;
	
	SensorType[S1] = sensorEV3_Gyro;//assigning sensors
	
	destination = destinationSelect();
	
	if (destination == 1)
	{
		x = 1;
		y = 1;
		destination_1(x, y);
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
