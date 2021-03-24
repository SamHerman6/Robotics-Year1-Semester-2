/*
Lab5 -Q6
Line tracking algorithm to follow black line forever - (forever loop).
If the ultrasonic sensor comes accross a object it should go around it.
*/

int leftMotor = 1;
int rightMotor = 2;


void usonic_obstacle()
{
	setMotorSpeed(leftMotor, 0) && setMotorSpeed(rightMotor , 90); // right turn
	sleep(420);

	setMotorSpeed(leftMotor, 100);	//Set both Motors (motor1 and motor 2) to half power forward (50) - Go Foward    
	setMotorSpeed(rightMotor , 100);	
	sleep(420);
	
	
	setMotorSpeed(leftMotor, 0) && setMotorSpeed(rightMotor , 90); // right left
	sleep(420);

	/*
	setMotorSpeed(leftMotor, 90); // turn left
	setMotorSpeed(rightMotor , 0);
	sleep(420);
	
	setMotorSpeed(leftMotor, 50);	//Set both Motors (motor1 and motor 2) to half power forward (50) - Go Foward    
	setMotorSpeed(rightMotor , 50);	
	sleep(100);
	
	setMotorSpeed(leftMotor, 90); // turn left
	setMotorSpeed(rightMotor , 0);
	sleep(420);
	
	setMotorSpeed(leftMotor, 50);	//Set both Motors (motor1 and motor 2) to half power forward (50) - Go Foward    
	setMotorSpeed(rightMotor , 50);
	sleep(100);
	
	setMotorSpeed(leftMotor, 0) && setMotorSpeed(rightMotor , 90); // right turn
	sleep(420);
	*/	
	
} // usonic_obstacle()

task main()
{
	int threshold=50;
	int length = 10;
	SensorType[S3] = sensorEV3_Color;
	SensorType[S2] = sensorEV3_Ultrasonic;
	
	while (1<2)
	{
		while(SensorValue[S3] < threshold)
		{
			//displayBigTextLine(8,"threshold=%d",threshold);
			/* wait1Msec(20);
			
			setMotorSyncTime(leftMotor, rightMotor, 0, 1000, 15);
			sleep(1000);
			*/			
			setMotorSync(leftMotor, rightMotor,50,20);
			wait1Msec(20);         
		}
		while(SensorValue[S3] >= threshold)
		{
			setMotorSync(leftMotor, rightMotor,-50,20);
			wait1Msec(20);
		}
		while(SensorValue[S2] <= length)
		{
			usonic_obstacle();
		}
	} //end while true loop
	
	
} //end task main()