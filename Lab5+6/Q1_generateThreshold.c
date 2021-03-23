
int leftMotor = 1;
int rightMotor = 2;

task main()
{
	int darkvalue = 0;
	int lightvalue = 0;
	int threshold = 0;
	
	SensorType[0] = sensorEV3_Color;
	
	
	while(getButtonPress(buttonEnter) == 0)
	{
		displayTextLine(1, "Get light value: ");
		displayTextLine(4, "Light value is %d", SensorValue[0]);
		wait1Msec(100);
	}
	
	
	lightvalue = SensorValue[1];
	wait1Msec(100);
	
	
	eraseDisplay();
	
	
	while(getButtonPress(buttonEnter) == 0)
	{
		displayTextLine(1, "Get dark value: ");
		displayTextLine(4, "Dark value is %d", SensorValue[0]);
		wait1Msec(100);
	}
	
	
	darkvalue = SensorValue[0];
	wait1Msec(100);
	
	
	eraseDisplay();
	
	
	threshold = (lightvalue + darkvalue) / 2;
	
	displayTextLine(3, "The threshold is %d", threshold);
	
	sleep(5000);
	
}