/*
Using Lego buttons (4) to travel at given distance - 10,40,60,80cm at random speed
*/
#define rotations_1 208.09
#define rotations_2 832.37
#define rotations_3 1248.55
#define rotations_4 1664.74

int leftMotor = 1;
int rightMotor = 2;

void straight_Ncm(int speed, int target)
{
	//NEED RESETS SINCE setMotorTarget() is to ABSOLUTE TARGET
	resetMotorEncoder(leftMotor);//since setMotorTarget is ABSOLUTE
	resetMotorEncoder(rightMotor);
	setMotorTarget(leftMotor,target, speed);//to ABSOLUTE encoder value
	setMotorTarget(rightMotor,target, speed);//to ABSOLUTE encoder value
	
	
	while(getMotorRunning(leftMotor) || getMotorRunning(rightMotor))
		wait1Msec(50);//until motor speeds will go to 0
	return;
}
task main()
{
	int i;
	
	while(true)
	{
		//While the left button (5) is pressed
		if(getButtonPress(buttonLeft) == 1)
		{
			straight_Ncm(500, rotations_1);
			sleep(100);   
		}
		else
		{
			//stop the robot
			setMotorSpeed(leftMotor, 0);
			setMotorSpeed(rightMotor, 0);
		}
	}
	while(true)
	{
		//While the left button (5) is pressed
		if(getButtonPress(buttonLeft) == 2)
		{
			straight_Ncm(100, rotations_2);
			sleep(100);
		}
		
		else
		{
			//stop the robot
			setMotorSpeed(leftMotor, 0);
			setMotorSpeed(rightMotor, 0);
		}
	}
	while(true)
	{
		//While the left button (5) is pressed
		if(getButtonPress(buttonLeft) == 3)
		{
			straight_Ncm(100, rotations_3);
			sleep(100);
		}
		else
		{
			//stop the robot
			setMotorSpeed(leftMotor, 0);
			setMotorSpeed(rightMotor, 0);
		}
	}
	while(true)
	{
		//While the left button (5) is pressed
		if(getButtonPress(buttonLeft) == 4)
		{
			straight_Ncm(100, rotations_4);
			sleep(100);
		}
		else
		{
			//stop the robot
			setMotorSpeed(leftMotor, 0);
			setMotorSpeed(rightMotor, 0);
		}
	}
}