
task main()
{
	int leftMotor = 1; 
	int rightMotor = 2; 
	int count = 0;
	int currentDistance = 0;
	int Onoff = 0;
	
	//variables assigned to sensors
	SensorType[S1] = sensorEV3_Ultrasonic; 
	SensorType[S2] = sensorEV3_Touch;
	
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
		
		// Turn left 
		setMotorSpeed(leftMotor, 37);	//Set the leftMotor (motor1) to 30
		setMotorSpeed(rightMotor, -10);	//Set the rightMotor (motor2) to -5
		sleep(1000);	//Wait for 1 sec before continuing on in the program.
	
	
	while(SensorValue[S2] == 0)	//go forward until bump sensor is activated
	{
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 100);
	}
	
		//Stop
		setMotorSpeed(leftMotor, 0);
		setMotorSpeed(rightMotor, 0);
		sleep(1000);
		
		// Turn left 
		setMotorSpeed(leftMotor, 31);	//Set the leftMotor (motor1) to 30
		setMotorSpeed(rightMotor, -28);	//Set the rightMotor (motor2) to -29
		sleep(1000);	//Wait for 1 sec before continuing on in the program.
	
	
	while (SensorValue[S2] == 0 && SensorValue[S1] > 22) //go forward until bump sensor is activated or ultrasonic sensor is below 22
	{
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 100);
	}
	
		//Stop
		setMotorSpeed(leftMotor, 0);
		setMotorSpeed(rightMotor, 0);
		sleep(2000);
		
		//Turn left 
		setMotorSpeed(leftMotor, 30);	//Set the leftMotor (motor1) to 28
		setMotorSpeed(rightMotor, -5);	//Set the rightMotor (motor2) to -5
		sleep(1000);	//Wait for 1 sec before continuing on in the program.
		
		//Move Forward
		setMotorSpeed(leftMotor, 50);	//Set motorspeed to half power forward
		setMotorSpeed(rightMotor, 50);
		sleep(1500);	//Wait for 2 seconds
		
		//Stop
		setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motor1) to stop(0)
		setMotorSpeed(rightMotor , 0);	//Set the rightMotor (motor2) to stop (0)
}
