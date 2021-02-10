
// We have to declare the motor[x] index we will assign to the left and right motors. 
//They are global variables as we are using them in functions outside of main() and will not be changed
int leftMotor = 1;
int rightMotor = 2;


task main()
{	
	//move robot fowards
	setMotorSyncTime(leftMotor, rightMotor , 0, 4000, 50);
	sleep(4000);
	
}


void moveRobot(int motor1,int motor2,int time)
{
	nMotorPIDSpeedCtrl[leftMotor] = mtrSpeedReg;	//set the leftMotor to half power (50)
	nMotorPIDSpeedCtrl[rightMotor] = mtrSpeedReg;	//set the rightMotor to half power (50)
	sleep(time);	
}