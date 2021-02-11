/*
square perimeter 200cm
*/

int leftMotor = 1;
int rightMotor = 2;
int distance_in_cm = 50;
void squarerandom200();

task main()
{ //start main

    squarerandom200();

} //end main

void squarerandom200()
{ //start squarerandom
    if (SensorValue [Sonic] >= distance_in_cm)
        { //start while
            leftMotor = 20;
            rightMotor = 20;
        } //end while

} //end squarerandom