/*
Lab 3 - Q6a
Turn to complete a square and return to origin position,
*/
#define rotations 208.09 //10cm

int leftMotor = 1;
int rightMotor = 2;

void straight_10cm(int speed, int target)
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



task main()
{
	int i;
	straight_10cm(50, rotations);
    sleep(100);
    turn90degreesLeft();

    straight_10cm(50, rotations);
    sleep(100);
    turn90degreesLeft();
	sleep(10);

    straight_10cm(50, rotations);
    sleep(100);
    turn90degreesLeft();
	sleep(15);

    straight_10cm(50, rotations);
    sleep(100);
    turn90degreesLeft();
	sleep(20);

}
