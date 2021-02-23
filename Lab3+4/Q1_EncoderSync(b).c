
int leftMotor = 1;
int rightMotor = 2;

void Turn90(long nMotorRatio, long power)
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	setMotorSyncEncoder(leftMotor, rightMotor, -30, 1800, nMotorRatio);
	wait1Msec(power);
	wait1Msec(100);
	return;
}


task main()
{	
	int i;
	Turn90(50, 1150);
}

