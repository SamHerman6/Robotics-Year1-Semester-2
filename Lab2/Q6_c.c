/*
Foward 2 sec and 180 turn and return to original position
*/

int leftMotor = 1;
int rightMotor = 2;

void comeback();

task main()
{ //start task main

    comeback();

} //end task main

void comeback()
{ //start comeback

    // Move forward at full power for 2 seconds
	setMotorSpeed(leftMotor, 100);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(rightMotor , 100); 	//Set the rightMotor (motor2) to half power forward (50)
	sleep(2000);			//Wait for 1.5 seconds before continuing on in the program.

    	// Stop for 1 second
	setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motor1) to Off
	setMotorSpeed(rightMotor , 0);  	//Set the rightMotor (motor2) to Off
	sleep(1000);			//Wait for 1 second before continuing on in the program.

    // Turn left at half power for 7.6 x2 seconds
	setMotorSpeed(leftMotor, 50);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(rightMotor , 0); 	//Set the rightMotor (motor2) to half power forward (50)
	sleep(1520);			//Wait for 1.5 seconds before continuing on in the program.

    // Stop for 1 second
	setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motor1) to Off
	setMotorSpeed(rightMotor , 0);  	//Set the rightMotor (motor2) to Off
	sleep(1000);			//Wait for 1 second before continuing on in the program.

    // Move forward at half power for 2 seconds
	setMotorSpeed(leftMotor, 50);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(rightMotor , 50); 	//Set the rightMotor (motor2) to half power forward (50)
	sleep(4000);			//Wait for 1.5 seconds before continuing on in the program.

    	// Stop for 1 second
	setMotorSpeed(leftMotor, 0);	//Set the leftMotor (motor1) to Off
	setMotorSpeed(rightMotor , 0);  	//Set the rightMotor (motor2) to Off
	sleep(1000);			//Wait for 1 second before continuing on in the program.




} //end comeback
