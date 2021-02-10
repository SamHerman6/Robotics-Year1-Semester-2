
/*------------------------------------------------------------------------------------------------
  This program will move your robot make a series of moves for different lengths of time.
  At the end of the program, all motors will shut down automatically and turn off.
------------------------------------------------------------------------------------------------*/

task main()
{
	// We have to declare the motor[x] index we will assign to the left and right motors. motor[0] is unused in this example. 
	int leftMotor = 1;
	int rightMotor = 2;
	
	
	// Move forward at half power for 1.5 seconds
	setMotorSpeed(leftMotor, 50);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(rightMotor , 50); 	//Set the rightMotor (motor2) to half power forward (50)
	sleep(1500);			//Wait for 1.5 seconds before continuing on in the program.
	
	// Stop for 1 second
	setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motor1) to Off
	setMotorSpeed(rightMotor , 0);  	//Set the rightMotor (motor2) to Off
	sleep(1000);			//Wait for 1 second before continuing on in the program.
	
	// Move reverse at half power for 1.5 seconds
	setMotorSpeed(leftMotor, -50);	//Set the leftMotor (motor1) to half power reverse (50)
	setMotorSpeed(rightMotor , -50);	//Set the rightMotor (motor2) to half power reverse (50)
	sleep(1500);			//Wait for 1.5 seconds before continuing on in the program.
	
	// Turn left at full power for 0.75 seconds
	setMotorSpeed(leftMotor, 100);	//Set the leftMotor (motor1) to full power forward (100)
	setMotorSpeed(rightMotor, -100);//Set the rightMotor (motor2) to full power reverse (-100)
	sleep(750);			//Wait for .75 second before continuing on in the program.
}
