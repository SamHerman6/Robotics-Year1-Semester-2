
int leftMotor = 1;
int rightMotor = 2;

int i;
float num = 0;

long randnum(long);

task main()
{
	for(i=0; i < 100; i++)
	{
		setMotorSyncTime(leftMotor, rightMotor, randnum(num), randnum(num), randnum(num));
		sleep(randnum(num));
	}
	
}

void setMotorSyncTime(int motor1,int motor2,int time)
{
	nMotorPIDSpeedCtrl[leftMotor] = mtrSpeedReg;	//set the leftMotor to half power (50)
	nMotorPIDSpeedCtrl[rightMotor] = mtrSpeedReg;	//set the rightMotor to half power (50)
	sleep(time);	
}

long randnum(long randval)
{
	randval = (randlong( ) % 100 - 0);
	return randval;
}

