# Pi Stepper Motor Driver
This project uses a Qt interface to drive stepper motors using a Raspberry Pi.
The core Stepper Motor Class can be used in any C++ project built for Raspberry Pi's.
It relies upon the WiringPi libraries which are pre-installed on the new Raspbian Distros.

Primary usage is testing and calibrating resolution on stepper motors for other projects.

To compile this project on your Pi:

Open a terminal and navigate to the location where the RepRap.pro resides and then execute:

  qmake RepRap.pro

next execute:
  make

After that you should have an executable in the direcotry that you can run.
  
