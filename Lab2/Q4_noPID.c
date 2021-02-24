// To implememnt functions which use no PID control

int leftMotor = 1;
int rightMotor = 2;

void turn90degreesLeft(void);
void turn90degreesRight(void);
void goForward1second(void);
void swingRight90degrees(void);
void swingLeft90degrees(void);
void reverse1second(void);

task main()
{
	
	turn90degreesLeft();
	turn90degreesRight();
	goForward1second();
	swingRight90degrees();
	swingLeft90degrees();
	reverse1second();
	
}
	


	void turn90degreesLeft()
	{	//start turn90left
		
		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, -50);
		wait1Msec(1000);
	}
	
	void turn90degreesRight()
	{	//start turn90right
		
		setMotorSpeed(leftMotor, -50);
		setMotorSpeed(rightMotor, 50);
		wait1Msec(1000);
	}
	
	void goForward1second()
	{	//start goforwars1sec
		
		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, 50);
		wait1Msec(1000);
	}
	
	void swingRight90degrees()
	{	//start swingright90
		
		setMotorSpeed(leftMotor, 100);
		setMotorSpeed(rightMotor, 50);
		wait1Msec(1000);
	}
	
	void swingLeft90degrees()
	{	//start swingleft90
		
		setMotorSpeed(leftMotor, 50);
		setMotorSpeed(rightMotor, 100);
		wait1Msec(1000);
	}
	
	void reverse1second()
	{	//start reverse1sec
		
		setMotorSpeed(leftMotor, -50);
		setMotorSpeed(rightMotor, -50);
		wait1Msec(1000);
	}




