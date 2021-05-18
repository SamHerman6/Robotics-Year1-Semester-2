
int leftMotor = 1;
int rightMotor = 2;


void drive(long nMotorRatio, long dist, long power) 
{
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, (360/17.28) * dist, power);
	wait1Msec(100);	
}//drive end


int destinationSelect()
{
	int speed;
	int distance;
	int i;
	int count = 0;
	int motorPower;
	
	while(getButtonPress(buttonEnter) == 0)
	{
		//displaying options
		displayCenteredTextLine(1, "Dont press right");
		displayCenteredTextLine(3, "Press left for [3,7]");
		
		wait1Msec(200);
		eraseDisplay();
		
		if (getButtonPress(buttonLeft))//if button left selected return 1
		{
			return 1;
		}
		
	}//end while
}


void turn90right()
{
	//declaring variables
	int degrees;
	int heading;
	int rate;
	
	SensorType[1] = sensorEV3_Gyro;
	
	eraseDisplay();
	resetGyro(S2);
	degrees = getGyroDegrees(S2);
	
	//turn90
	while(degrees > -85)
	{
		setMotorSpeed(leftMotor, -40);
		setMotorSpeed(rightMotor, 40);
		
		degrees = getGyroDegrees(S2);
		heading = getGyroHeading(S2);
		rate = getGyroRate(S2);
		
		sleep(10);	
	}//end while
	
	//stop turn
	eraseDisplay();
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
}





void destinationOne(int x, int y)
{
	//declaring variables
	int destinationX1 = 3;
	int destinationY1 = 7;
	int destinationX2 = 1;
	int destinationY2 = 1;
	
	
	turn90right();//calling turn90right function
	
	while(y < destinationY1)
	{
		//displaying current location on board after turn
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
		
		drive(0, 15, 50);
		wait1Msec(1000);
		
		y = y + 1;
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
	}//end while
	
	while(x < destinationX1)
	{
		//displaying current location on board
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
		
		drive(0, 15, 50);
		wait1Msec(1000); 
		
		x = x + 1; 
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
	}//end while
	
	turn90right();//calling turn90right function
	
	playTone(4000, 30000);
	sleep(5000);
	
	while(x > destinationX2)
	{
		//displaying current location on board
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
		
		drive(0, 15, 50);
		wait1Msec(1000); 
		
		x = x - 1; 
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
	}//end while
	
	turn90right();
	
	while(y > destinationY2)
	{
		//displaying current location on board after turn
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
		
		drive(0, 15, 50);
		wait1Msec(1000);
		
		y = y - 1;
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x, y);
		wait1Msec(1000);
	}//end while
	
}


task main()
{
	//declaring variables
	int destination = 0;
	int x = 3;
	int y = 1;
	
	SensorType[1] = sensorEV3_Gyro;//assigning sensors
	
	destination = destinationSelect();
	
	if (destination == 1)
	{
		destinationOne(x, y);
	}
	
}//end main