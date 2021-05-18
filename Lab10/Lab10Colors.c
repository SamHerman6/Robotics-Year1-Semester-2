/*
    Program for EV3 to complete a route and check+display tile colour
*/

int leftMotor = 1;
int rightMotor = 2;

string colorOfObject; // for storing color name

int rotations_1 = (360/17.3)*10; // 10cm = 208.09 rotations
int rotations_2 = (360/17.3)*40; // 40cm = 832.37
int rotations_3 = (360/17.3)*60; // 60cm = 1248.55
int rotations_4 = (360/17.3)*90; // 90cm = 1872.832

//------------------------STRAIGHT------------------------------
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
}
//--------------------------TURN RIGHT-----------------------------------
void gyro_right() // 90 degrees turn
{	
	int count=0;
	int degrees = 90;
	int heading;
	int rate;
	
	motor[1]=-25;
	motor[2]=+25;
	while(count<24)
	{	degrees = getGyroDegrees(S1);
		heading = getGyroHeading(S1);
		rate = getGyroRate(S1);
		count++;
		sleep(40);	
	}
	return;
} // end gyro_left()

void gyro_left() // 90 degrees turn
{	
	int count=0;
	int degrees = 90;
	int heading;
	int rate;
	
	motor[1]=+25;
	motor[2]=-25;
	while(count<10)
	{	degrees = getGyroDegrees(S1);
		heading = getGyroHeading(S1);
		rate = getGyroRate(S1);
		count++;
		sleep(40);	
	}
	return;
} // end gyro_left()

//-------------------------------COLOUR------------------------------------------
void which_color()
{
	//If the color sensor plugged into port 3 returns
	// the colorRed name (a red object is detected)
	if(getColorName(S3) == colorRed)
	{
		//Store the text RED into the color string
		colorOfObject = "RED";
		displayBigTextLine(3,"Colour=%s",colorOfObject);
		sleep(100);
		//displayStringAt(1,"Colour=%d",colorOfObject);
		
		//Pulse the LED Red for two seconds 
		setLEDColor(ledRedPulse); 
		sleep(2000);
		eraseDisplay();
	}
	
	//If the color sensor plugged into port 3 returns
	// the colorBlue name (a Blue object is detected)
	else if(getColorName(S3) == colorBlue)
	{
		//Store the text Blue into the color string
		colorOfObject = "BLUE";
		displayBigTextLine(3,"Colour=%s",colorOfObject);
		
		//Pulse the LED Blue for two seconds 
		//setLEDColor(ledBluePulse); 
		sleep(2000);
		eraseDisplay();
		
	} // end else if
	else if(getColorName(S3) == colorYellow)
	{
		colorOfObject = "Yellow";
		displayBigTextLine(3,"Colour=%s",colorOfObject);
		
		//Pulse the LED Yellow for two seconds 
		//setLEDColor(ledYellowPulse); 
		sleep(2000);
		eraseDisplay(); 
		
	} // end else if
	
} // end which_color()



task main()
{
	
	//we must first establish the color sensor on port S3
	SensorType[S3] = sensorEV3_Color;//set TYPE
	SensorMode[S3] = modeEV3Color_Color;//set MODE
	SensorType[S1] = sensorEV3_Gyro;
	
	straight_Ncm(100, rotations_4);
	sleep(100);
	
	which_color();
	sleep(100);
	
	gyro_right();
	sleep(100);
	
	straight_Ncm(100, rotations_3);
	sleep(100);
	
	which_color();
	sleep(100);
	
	gyro_left();
	sleep(100);
	
	straight_Ncm(100, rotations_2);
	sleep(100);
	
	which_color();
	sleep(100);
	
} // end main()