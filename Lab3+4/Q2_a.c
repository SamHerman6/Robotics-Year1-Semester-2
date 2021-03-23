/*
Lab 3/4 - Q2a
Turn to complete a square with a perimeter of 200cm,
First turn is random.
*/
#define rotations 1040.46
#define length 50

int leftMotor = 1;
int rightMotor = 2;
/* int randomturn = turn90degreesLeft() || turn90degreesRight(); */

void straight_50cm(int speed, int target)
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

void turn90degreesLeft(void)
{ //start turn90left

    setMotorSpeed(leftMotor,90);
    setMotorSpeed(rightMotor,0);

    sleep (420);
}

/*
void turn90degreesRight(void)
{ //start turn90left

    setMotorSpeed(leftMotor,0);
    setMotorSpeed(rightMotor,90);

    sleep (420);
}
*/

/*void square(int speed, int target)
{

	while (SensorValue[S2] > length)
	{
		setMotorSpeed(leftMotor , speed);	//Set both Motors (motor1 and motor 2) to full power forward (100) - Go Foward
		setMotorSpeed(rightMotor , speed);
	} //end while

} //end void square()
*/

task main()
{
	int i;
	straight_50cm(50, rotations);
    sleep(100);
    turn90degreesLeft();

    straight_50cm(50, rotations);
    sleep(100);
    turn90degreesLeft();
	sleep(10);

    straight_50cm(50, rotations);
    sleep(100);
    turn90degreesLeft();
	sleep(15);

    straight_50cm(50, rotations);
    sleep(100);
    turn90degreesLeft();
	sleep(20);

}
