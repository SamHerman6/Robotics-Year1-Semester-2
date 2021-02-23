
int leftMotor = 1;
int rightMotor = 2;

void Drive(long nMotorRatio, long dist, long power)
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	setMotorSyncEncoder(leftMotor, rightMotor, 0, 1800, nMotorRatio);
	wait1Msec(dist);
	wait1Msec(100);
	return;
}


task main()
{	
	int i;
	Drive(50, 5000, 50);
}