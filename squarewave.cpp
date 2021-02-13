//Include all the necessary libraries.
#include<stdio.h>
#include<unistd.h>
#include<math.h>
#include<iostream>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include <fstream>
#include<string.h>
#include<iomanip>

using namespace std;
//Using address of the clock we want to read time and date
#define BUFFER_SIZE 19
#define RTCaddress      0x68
#define Control  	    0x0E
//Creating Base class RTCDS3231
class RTCDS3231{
  private:       
           int file;
           char buf[2];			//Carries the data and address to write
           char buffer[BUFFER_SIZE];	//Carries the data stored in RTCDS3231
 //Declaration of all functions used 
  public:
         RTCDS3231(){};
         int bcdToDec(unsigned char  b);
         void DetectRTC();
         int ReadRegisters();
         int SetSquareWave(unsigned int address1, unsigned char value1);

         ~RTCDS3231(){};
      };
//Convert BCD to decimal
int RTCDS3231::bcdToDec(unsigned char  b) { 
	int dec=(b/16)*10 + (b%16);
	return dec;
}

//Open RTCDS3231
void RTCDS3231::DetectRTC() {
	file=open("/dev/i2c-1", O_RDWR);
	ioctl(file, I2C_SLAVE, 0x68);
	char writeBuffer[1] = {0x00};
	if(write(file, writeBuffer, 1)!=1){
	perror("Failed to reset the read address\n");
	}
	close(file);
} 
int RTCDS3231::SetSquareWave(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	ioctl(file, I2C_SLAVE, 0x68);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}
//Read the Registers
int RTCDS3231::ReadRegisters() {
	file=open("/dev/i2c-1", O_RDWR);
	ioctl(file, I2C_SLAVE, 0x68);
	char writeBuffer[1] = {0x00};
	if(write(file, writeBuffer, 1)!=1){
	perror("Failed to reset the read address\n");
	}
	read(file, buffer, BUFFER_SIZE);
	close(file);
	return 0;
}
int main() {

	RTCDS3231 Obj;
	Obj.DetectRTC();
	Obj.SetSquareWave(Control,0x10);
	Obj.ReadRegisters();
}
