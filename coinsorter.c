//Coin Sorter Using AT89S52
//Author : Vineet JK
//Date : 15/05/2019
//Anybody can use and modify this code its for everybody coded for opensourcing


#include<reg51.h>
#define display_port P2      //Data pins connected to port 2 on microcontroller
sbit rs = P3^2;  //RS pin connected to pin 2 of port 3
sbit rw = P3^3;  // RW pin connected to pin 3 of port 3
sbit e =  P3^4;  //E pin connected to pin 4 of port 3

sbit sensor1 = P1^1; //Sensor for 10rs
sbit sensor2 = P1^2; // Sensor for 2rs
sbit sensor3 = P1^3; // Sensor for 1rs


void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}
void lcd_cmd(unsigned char command)  //Function to send command instruction to LCD
{
    display_port = command;
    rs= 0;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}

void lcd_data(unsigned char disp_data)  //Function to send display data to LCD
{
    display_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}

 void lcd_init()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F);  // turn display ON, cursor blinking
    msdelay(10);
    lcd_cmd(0x01);  //clear screen
    msdelay(10);
    lcd_cmd(0x81);  // bring cursor to position 1 of line 1
    msdelay(10);
}
void main()
{

    int l=0,one=0,two=0,ten=0,total=0;

    lcd_init();

while(1){
    if(sensor1==1)
    {
        ten++;
    }
    if(sensor2==1)
    {
        two++;
    }
    if(sensor3==1)
    {
        one++;
    }
    total=ten*10+two*2+one;
    lcd_data(printf("10=%d 2=%d 1=%d",ten,two,one));//printing values to lcd
    lcd_cmd(0xC0);// setting cursor to second line
    lcd_data(printf("Total = %d",total));
}
    
}