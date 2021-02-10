
task main()
{
	// We have to declare the motor[x] index we will assign to the left and right motors. motor[0] is unused in this example. 
	int leftMotor = 1;
	int rightMotor = 2;
	
	// Move forward at half power for 1.5 seconds
	setMotorSpeed(leftMotor, 50);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(rightMotor , 50); 	//Set the rightMotor (motor2) to half power forward (50)
	sleep(2000);			//Wait for 1.5 seconds before continuing on in the program.
	
	
	// Move forward at half power for 1.5 seconds
	setMotorSpeed(leftMotor, 50);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(rightMotor , -50); 	//Set the rightMotor (motor2) to half power forward (50)
	sleep(1650);			//Wait for 1.5 seconds before continuing on in the program.
	
	
}