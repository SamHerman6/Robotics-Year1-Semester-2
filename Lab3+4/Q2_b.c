/*
To go foward (at 100%) for 100 cm and do 180 degrees turn and return at 25% speed
Lab:3/4
*/
#define rotations 2080.92

int leftMotor = 1;
int rightMotor = 2;

void straight_100cm(int speed, int target)
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

void turn180degreesLeft(void)
{ //start turn90left

    setMotorSpeed(leftMotor,90);
    setMotorSpeed(rightMotor,0);

    sleep (835);
}

task main()
{
	int i;
	straight_100cm(100, rotations);
    sleep(100);
    turn180degreesLeft();
   
    straight_100cm(50, rotations);
    sleep(100);
    turn180degreesLeft();
    sleep (20);
}
