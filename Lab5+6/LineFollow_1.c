/*
Lab5 -Q4
Line tracking algorithm to follow black line forever - (forever loop).
*/
int leftMotor = 1;
int rightMotor = 2;


task main()
{
	int threshold=50;
	SensorType[S3] = sensorEV3_Color;
	
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
	} //end while true loop
	
	
} //end task main()