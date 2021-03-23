
int leftMotor = 1;
int rightMotor = 2;


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
			setMotorSyncTime(leftMotor, rightMotor, 0, 1000, 15);
			sleep(1000);
		}
		
		else
		{
			setMotorSyncTime(leftMotor, rightMotor, 0, 0, 0);
			sleep(100);
		}
	}
	
}