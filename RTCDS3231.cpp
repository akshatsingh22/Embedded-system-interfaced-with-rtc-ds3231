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
extern "C" {
#include <wiringPi.h>
}

using namespace std;


//Using address of the clock we want to read time and date
#define BUFFER_SIZE 19
#define RTCaddress      0x68
#define Seconds  	    0x00
#define Minutes  	    0x01
#define Hours    	    0x02
#define Date     	    0x04
#define Month           0x05
#define Year            0x06
#define AlarmSeconds 	0x07
#define AlarmMinutes 	0x08
#define AlarmHours  	0x09
#define AlarmDate  	    0x0A
#define AlarmMinutes2 	0x0B
#define AlarmHours2  	0x0C
#define AlarmDate2  	0x0D
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
         int Displaytime();
         int ReadRegisters();
         int Alarm();
         int rtcon(unsigned int address1, unsigned char value1);
         int SetMinutes(unsigned int address1, unsigned char value1); 
         int SetHours(unsigned int address1, unsigned char value1);   
         int SetDay(unsigned int address1, unsigned char value1);  
         int SetDate(unsigned int address1, unsigned char value1); 
         int SetMonth(unsigned int address1, unsigned char value1);  
         int SetYear(unsigned int address1, unsigned char value1); 
         int SetAlarmSeconds(unsigned int address1, unsigned char value1); 
         int SetAlarmMinutes(unsigned int address1, unsigned char value1);  
         int SetAlarmHours(unsigned int address1, unsigned char value1);  
         int SetAlarmDate(unsigned int address1, unsigned char value1); 
         int SetAlarmMinutes2(unsigned int address1, unsigned char value1); 
         int SetAlarmHours2(unsigned int address1, unsigned char value1); 
         int SetAlarmDate2(unsigned int address1, unsigned char value1);
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

//Switch on the oscillator by setting CH bit to 0 which can be used to set Seconds
int RTCDS3231::rtcon(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	ioctl(file, I2C_SLAVE, 0x68);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}

//Set Minutes
int RTCDS3231::SetMinutes(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	ioctl(file, I2C_SLAVE, 0x68);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}

//Set Hours
int RTCDS3231::SetHours(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	ioctl(file, I2C_SLAVE, 0x68);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}

//Set Date
int RTCDS3231::SetDate(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	ioctl(file, I2C_SLAVE, 0x68);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}
//Set Month
int RTCDS3231::SetMonth(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	ioctl(file, I2C_SLAVE, 0x68);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}
//Set Year
int RTCDS3231::SetYear(unsigned int address1, unsigned char value1) {
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
//set the alarm 1 seconds
int RTCDS3231::SetAlarmSeconds(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}
//set the alarm 1 minutes
int RTCDS3231::SetAlarmMinutes(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}
//set the alarm 1 hours
int RTCDS3231::SetAlarmHours(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}
//set the alarm 1 date
int RTCDS3231::SetAlarmDate(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}
//set the alarm 2 minutes
int RTCDS3231::SetAlarmMinutes2(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}
//set the alarm 2 hours
int RTCDS3231::SetAlarmHours2(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}
//set the alarm 2 date
int RTCDS3231::SetAlarmDate2(unsigned int address1, unsigned char value1) {
	file=open("/dev/i2c-1", O_RDWR);
	buf[0]= address1;
	buf[1]= value1;
	write(file, buf,2 );
	close(file);
	return 0;
}
//Function to glow LED on alarm. Blinks the LED 5 times.
int RTC::Alarm() {
	wiringPiSetup () ;
	pinMode (LED, OUTPUT) ;
	for (int i=0;i<5;i++) {
    		digitalWrite (LED, 1) ;     // LED On
   	 	delay (1000) ;               // 1 sec delay
    		digitalWrite (LED, 0) ;     // LED Off
    		delay (1000) ;
  	}
  	return 0 ;
}







//Display Time and Date of RTCDS3231 and Alarm
int RTCDS3231::Displaytime() {
	int sec=this->bcdToDec(buffer[0]);
	int min=this->bcdToDec(buffer[1]);
	int hou=this->bcdToDec(buffer[2]);
	int date=this->bcdToDec(buffer[4]);
	int month=this->bcdToDec(buffer[5]);
	int year=this->bcdToDec(buffer[6]);
	
	int alsec=this->bcdToDec(buffer[7]);
	int almin=this->bcdToDec(buffer[8]);
	int alhou=this->bcdToDec(buffer[9]);
	int aldate=this->bcdToDec(buffer[10]);
	
	int almin2=this->bcdToDec(buffer[11]);
	int alhou2=this->bcdToDec(buffer[12]);
	int aldate2=this->bcdToDec(buffer[13]);
    
    //Multiply the hour and minutes with appropriate weights and add to make them one integer.
	int current_time= sec+min*100+hou*10000;
	int alarmtime= alsec+almin*100+alhou*10000; 
	int alarmtime2= almin2*100+alhou2*10000;
	//Multiply the month and year with appropriate weights and add to make them one integer.
	int current_date= date;
	
	
	if (current_time == alarmtime && current_date==aldate) {
        this->Alarm();
		cout<<"Alarm 1 LED is blinking!!"<<endl;
    } else if (current_time == alarmtime2 && current_date==aldate2) {
        this->Alarm();
		cout<<"Alarm 2 LED is blinking!!"<<endl;
    } else {
        cout<<"No Alarm!!"<<endl;
    }
	
	cout<<endl;
	cout << "Time at DS3231 is:" <<setw(2)<<setfill('0')<<this->bcdToDec(buffer[2]) <<":"<<setw(2)<<setfill('0')<<this->bcdToDec(buffer[1])<<":"<<setw(2)<<setfill('0')<<this->bcdToDec(buffer[0])<<endl;
	cout << "Date at DS3231 is:" <<setw(2)<<setfill('0')<<this->bcdToDec(buffer[4]) <<"/"<<setw(2)<<setfill('0')<<this->bcdToDec(buffer[5])<<"/"<<setw(2)<<setfill('0')<<this->bcdToDec(buffer[6])<<endl;
	cout << "The Alarm 1 time is:" <<setw(2)<<setfill('0')<<this->bcdToDec(buffer[9]) <<":"<<setw(2)<<setfill('0')<<this->bcdToDec(buffer[8])<<":"<<setw(2)<<setfill('0')<<this->bcdToDec(buffer[7])<<endl;
	cout << "The Alarm 1 date is:" <<setw(2)<<setfill('0')<<this->bcdToDec(buffer[10]) <<endl;
	cout << "The Alarm 2 time is:" <<setw(2)<<setfill('0')<<this->bcdToDec(buffer[12]) <<":"<<setw(2)<<setfill('0')<<this->bcdToDec(buffer[11])<<endl;
	cout << "The Alarm 2 date is:" <<setw(2)<<setfill('0')<<this->bcdToDec(buffer[13]) <<endl;
	return 0;
}

//Call functions in order and pass the respective arguments
int main() {

	RTCDS3231 Obj;
	Obj.DetectRTC();
	Obj.rtcon(Seconds,0x00);
	Obj.SetMinutes(Minutes,0x45);
	Obj.SetHours(Hours,0x23);
	Obj.SetDate(Date,0x06);
	Obj.SetMonth(Month,0x03);
	Obj.SetYear(Year,0x20);
	Obj.SetAlarmSeconds(AlarmSeconds,0x00);
	Obj.SetAlarmMinutes(AlarmMinutes,0x45);
	Obj.SetAlarmHours(AlarmHours,0x23);
	Obj.SetAlarmDate(AlarmDate,0x06);
	Obj.SetAlarmMinutes2(AlarmMinutes2,0x47);
	Obj.SetAlarmHours2(AlarmHours2,0x23);
	Obj.SetAlarmDate2(AlarmDate2,0x06);
	Obj.SetSquareWave(Control,0x10)

	//Using while loop to print the time continuously.
	while(1){
	Obj.ReadRegisters();
	Obj.Displaytime();
	sleep(1);
	printf("\r");
	}
}