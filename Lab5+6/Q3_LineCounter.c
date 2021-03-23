
int leftMotor = 1;
int rightMotor = 2;

int countline = 0;

task main()
{	
	short currentValue;
	
	SensorType[S1] = sensorEV3_Color;
	SensorMode[S1] = modeEV3Color_Color;
	
	setLEDColor(ledOff);
	
	while(true)
	{
		currentValue = SensorValue[S1];
		
		if (currentValue == 4)
		{
			setMotorSyncTime(leftMotor, rightMotor, 0, 1000, 10);
			sleep(1000);
		}
		
		else
		{
			setMotorSyncTime(leftMotor, rightMotor, 0, 1000, 10);
			sleep(100);
			countline = countline + 1;
		}
	}
}