//calculations roations - ALL CONSTANT
int rotations_1 = (360/17.3)*10; // 10cm = 208.09 rotations
int rotations_2 = (360/17.3)*40; // 40cm = 832.37
int rotations_3 = (360/17.3)*60; // 60cm = 1248.55
int rotations_4 = (360/17.3)*80; // 80cm = 1664.74


int leftMotor = 1;
int rightMotor = 2;

void straight_Ncm(int speed, int target) //function to go foward with assigned target distance
{
	//NEED RESETS SINCE setMotorTarget() is to ABSOLUTE TARGET
	resetMotorEncoder(leftMotor);//since setMotorTarget is ABSOLUTE
	resetMotorEncoder(rightMotor);
	setMotorTarget(leftMotor,target, speed);//to ABSOLUTE encoder value
	setMotorTarget(rightMotor,target, speed);//to ABSOLUTE encoder value
	
	
	while(getMotorRunning(leftMotor) || getMotorRunning(rightMotor))
		wait1Msec(500);//until motor speeds will go to 0
	return;
} // end straight_Ncm()

void gyro_left() // 90 degrees turn
{	
	int count=0;
	int degrees = 90;
	int heading;
	int rate;

	motor[1]=+25;
	motor[2]=-25;
	while(count<20)
	{	degrees = getGyroDegrees(S1);
		heading = getGyroHeading(S1);
		rate = getGyroRate(S1);
		count++;
		sleep(40);	
	}
    return;
} // end gyro_left()

task main()
{
	SensorType[S1]= sensorEV3_Gyro;

	while(1<100) //infinite loop
	{
		//While the left button (1) is pressed
		if(getButtonPress(buttonLeft))
		{
			straight_Ncm(100, rotations_1); //foward 10cm
			sleep(100);

			gyro_left(); // 90 degrees turn
			sleep(100);

			straight_Ncm(100, rotations_1);
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_1);
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_1);
			sleep(100);

			gyro_left();
			sleep(40);
		}
			
		//While the left button (2) is pressed
		else if(getButtonPress(buttonRight))
		{
			straight_Ncm(100, rotations_2); //foward 40cm
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_2);
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_2);
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_2);
			sleep(100);

			gyro_left();
			sleep(60);
		}
			
		//While the left button (3) is pressed
		else if(getButtonPress(buttonUp))
		{
			straight_Ncm(100, rotations_3); //foward 60cm
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_3);
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_3);
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_3);
			sleep(100);

			gyro_left();
			sleep(50);
		}
			
		//While the left button (4) is pressed
		else if(getButtonPress(buttonDown))
		{
			straight_Ncm(100, rotations_4); //foward 80cm
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_4);
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_4);
			sleep(100);

			gyro_left();
			sleep(100);

			straight_Ncm(100, rotations_4);
			sleep(100);

			gyro_left();
			sleep(15);
		}
		else
		{
			//stop the robot
			setMotorSpeed(leftMotor, 0);
			setMotorSpeed(rightMotor, 0);
		}
		// Wait 10 ms, this gives us 50 readings per second
		sleep(100);
	} // end initite loop
} // end task main()