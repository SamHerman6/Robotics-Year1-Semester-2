
int leftMotor = 1;
int rightMotor = 2;

void turn45left()
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
	while(degrees < 36)
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


task main()
{
	//declaring variables
	int base = 0;
	int hypo = 0;
	int area = 0;
	int formula = 0;
	int height = 0;
	
	SensorType[0] = sensorEV3_Ultrasonic;
	
	while(getButtonPress(buttonEnter) == 0)
	{
		//displaying base distance and storing
		displayTextLine(1, "Get distance of base");
		displayTextLine(4, "Base is %d", SensorValue[0]);
		wait1Msec(100);
	}
	
	base = SensorValue[0];
	wait1Msec(100);
	
	turn45left();
	
	while(getButtonPress(buttonEnter) == 0)
	{
		//displaying height distance and storing
		displayTextLine(1, "Get distance of the hypotenuse");
		displayTextLine(4, "Height is %d", SensorValue[0]);
		wait1Msec(100);
	}
	
	hypo = SensorValue[0];
	wait1Msec(100);
	
	
	eraseDisplay();
	
	//formual to calculate area
	formula = ( ((hypo)*(hypo)) - ((base)*(base)) );
	height = sqrt(formula);
	area = (base / 2) * (height);
	displayTextLine(3, "The area is %d", area);//displaying the area
	
	sleep(5000);
}