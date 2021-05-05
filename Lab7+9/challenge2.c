int leftMotor = 1; 
int rightMotor = 2; 

void gyro_left(); // 90 degrees turn
void gyro_left_2();

task main()
{
	
	int count = 0;
	int currentDistance = 0;
	int Onoff = 0;
	
	//variables assigned to sensors
	SensorType[S1] = sensorEV3_Ultrasonic; 
	SensorType[S2] = sensorEV3_Touch;
	SensorType[S3] = sensorEV3_Gyro;
	
	currentDistance = SensorValue[S1];
	Onoff = SensorValue[S2];
	
	
	while(count<200)
	{
		count = count + 1; //this while loop gets the current distance from the nearest obstacle
		wait1Msec(2);
		getUSDistance(S1);
		getTouchValue(S2);
	}
	
	
	while(SensorValue[S1] > 22) //go forward while you are 22cm or more away from wall
	{
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 100);
	}
	
	//Stop
	setMotorSpeed(leftMotor, 0); 
	setMotorSpeed(rightMotor, 0);
	sleep(1000);
	
	gyro_left();
	
	
	while(SensorValue[S2] == 0)	//go forward until bump sensor is activated
	{
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 100);
	}
	
	//Stop
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(1000);
	
	gyro_left();
	
	while (SensorValue[S2] == 0 && SensorValue[S1] > 22) //go forward until bump sensor is activated or ultrasonic sensor is below 22
	{
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 100);
	}
	
	//Stop
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(2000);
	
	gyro_left();
	
	//Move Forward
	setMotorSpeed(leftMotor, 50);	//Set motorspeed to half power forward
	setMotorSpeed(rightMotor, 50);
	sleep(1500);	//Wait for 2 seconds
	
	//Stop
	setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motor1) to stop(0)
	setMotorSpeed(rightMotor , 0);	//Set the rightMotor (motor2) to stop (0)
}

void gyro_left() // 90 degrees turn
{	
	int count=0;
	int degrees =0;
	int heading= 0;
	int rate= 0;
	
	motor[1]=+25;
	motor[2]=-25;
	
	while(degrees<98)
	{	degrees = getGyroDegrees(S3);
		heading = getGyroHeading(S3);
		rate = getGyroRate(S3);
		count++;
		sleep(15);
	}
	
	resetGyro(S3); // RESET GYRO
	
	return;
} // end gyro_left()

void gyro_left_2() // 90 degrees turn
{	
	int count=0;
	int degrees =0;
	int heading= 0;
	int rate= 0;
	
	motor[1]=+25;
	motor[2]=-25;
	
	while(degrees<98)
	{	degrees = getGyroDegrees(S3);
		heading = getGyroHeading(S3);
		rate = getGyroRate(S3);
		count++;
		sleep(15);
	}
	
	resetGyro(S3); // RESET GYRO
	
	return;
} // end gyro_left()
