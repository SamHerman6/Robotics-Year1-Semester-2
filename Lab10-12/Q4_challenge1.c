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
		displayCenteredTextLine(1, "Starting at [1,1] press left");
		displayCenteredTextLine(3, "Starting at [6,1] press right");
		
		wait1Msec(200);
		eraseDisplay();
		
		if (getButtonPress(buttonRight))//if button right selected return 0
		{
			return 0;
		}
		
		else if (getButtonPress(buttonLeft))//if button left selected return 1
		{
			return 1;
		}
		
	}//end while
}


void turn90left()
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
	while(degrees < 87)
	{
		setMotorSpeed(leftMotor, 40);
		setMotorSpeed(rightMotor, -40);
		
		degrees = getGyroDegrees(S2);
		heading = getGyroHeading(S2);
		rate = getGyroRate(S2);
		
		sleep(10);	
	}// end while
	
	//stop turn
	eraseDisplay();
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
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


void destinationOne(int x1, int y1)
{
	//declaring variables
	int destinationX = 5;
	int destinationY = 5;
	
	while(x1 < destinationX)
	{
		//displaying current location on board
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x1, y1);
		wait1Msec(1000);
		
		drive(0, 15, 50);
		wait1Msec(1000); 
		
		x1 = x1 + 1; 
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x1, y1);
		wait1Msec(1000);
	}//end while
	
	turn90right();//calling turn90right function
	
	while(y1 < destinationY)
	{
		//displaying current location on board after turn
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x1, y1);
		wait1Msec(1000);
		
		drive(0, 15, 50);
		wait1Msec(1000);
		
		y1 = y1 + 1;
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x1, y1);
		wait1Msec(1000);
	}//end while
	
}


void destinationTwo(int x2, int y2)
{
	//declaring variables
	int destinationX = 5;
	int destinationY = 5;
	
	turn90right();
	turn90right();
	
	while(x2 > destinationX)
	{
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x2, y2);
		wait1Msec(1000);
		
		drive(0, 15, 50);
		wait1Msec(1000);
		
		x2 = x2 - 1;
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x2, y2);
		wait1Msec(1000);
	}//end while
	
	
	while(y2 < destinationY)
	{
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x2, y2);
		wait1Msec(1000);
		
		drive(0, 15, 50);
		wait1Msec(1000);
		
		y2 = y2 + 1;
		
		displayBigTextLine(2, "Your current local:");
		displayCenteredBigTextLine(4, "%d, %d", x2, y2);
		wait1Msec(1000);
	}//end while
	
	turn90right();//calling turn90right function
	
}


task main()
{
	//declaring variables
	int destination = 0;
	int x1 = 1;
	int y1 = 1;
	int x2 = 6;
	int y2 = 1;
	
	SensorType[1] = sensorEV3_Gyro;//assigning sensors
	
	destination = destinationSelect();
	
	if (destination == 1)
	{
		destinationOne(x1, y1);
	}
	
	else
	{
		destinationTwo(x2, y2);
	}
	
}//end main