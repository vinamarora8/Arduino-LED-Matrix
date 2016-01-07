//Defining all the I/O pins
int clk_1 = 4;
int data_1 = 5;
int clk_2 = 6;
int data_2 = 7;
int clk_3 = 8;
int data_3 = 9;
int clk_4 = 10;
int data_4 = 11;
int clk_5 = 12;
int data_5 = 13;

//Setting up counters for cascading and changing pages
int col = 0;
int page = 0;
int frame = 0;

//The data to be displayed:
boolean rowdata[6][25][7] = {
  
  ////Page1////
  
  1,1,1,1,1,1,1,
  0,0,0,1,0,0,0,
  0,0,0,1,0,0,0,        //H
  0,0,0,1,0,0,0,
  1,1,1,1,1,1,1,
  1,1,1,1,1,1,0,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,        //A
  0,0,0,1,0,0,1,
  1,1,1,1,1,1,0,
  1,1,1,1,1,1,1,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,        //P
  0,0,0,1,0,0,1,
  0,0,0,0,1,1,0,
  1,1,1,1,1,1,1,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,        //P
  0,0,0,1,0,0,1,
  0,0,0,0,1,1,0,
  0,0,0,0,0,0,1,
  0,0,0,0,0,1,0,
  1,1,1,1,1,0,0,        //Y
  0,0,0,0,0,1,0,
  0,0,0,0,0,0,1,
  
  ///Page2/////
  
  1,1,1,1,1,1,1,
  1,0,0,1,0,0,1,
  1,0,0,1,0,0,1,
  1,0,0,1,0,0,1,
  0,1,1,0,1,1,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,1,0,
  0,0,0,0,0,0,1,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  1,1,1,1,1,1,1,
  1,0,0,0,0,0,1,
  1,0,0,0,0,0,1,
  1,0,0,0,0,0,1,
  0,1,1,1,1,1,0,
  1,1,1,1,1,1,0,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,
  1,1,1,1,1,1,0,
  0,0,0,0,0,0,1,
  0,0,0,0,0,1,0,
  1,1,1,1,1,0,0,
  0,0,0,0,0,1,0,
  0,0,0,0,0,0,1,
  
  ////Page3////
  
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  1,1,1,1,1,1,1,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,
  0,0,0,0,1,1,0,
  1,1,1,1,1,1,0,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,
  1,1,1,1,1,1,0,
  1,1,1,1,1,1,1,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,
  0,0,0,0,1,1,0,
  1,1,1,1,1,1,0,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,
  0,0,0,1,0,0,1,
  1,1,1,1,1,1,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  
  ////Page4////
  
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,1,1,
  0,0,1,1,1,0,0,
  1,1,0,0,0,0,0,
  0,0,1,0,0,0,0,
  0,0,0,1,0,0,0,
  0,0,1,0,0,0,0,
  1,1,0,0,0,0,0,
  0,0,1,1,1,0,0,
  0,0,0,0,0,1,1,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  1,1,1,1,1,1,1,
  1,0,0,1,0,0,1,
  1,0,0,1,0,0,1,
  1,0,0,1,0,0,1,
  1,0,0,0,0,0,1,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  
  /////Page5////
  
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,1,1,0,
  0,0,0,1,0,0,1,
  0,0,1,0,0,0,1,
  0,1,0,0,0,1,0,
  1,0,0,0,1,0,0,
  0,1,0,0,0,1,0,
  0,0,1,0,0,0,1,
  0,0,0,1,0,0,1,
  0,0,0,0,1,1,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,
  /////////////
  };

//Array whose data will be sent serially in reverse order
boolean arr[8];

//Arduino setup function
void setup() {
  //Setting up all the I/O pins
  pinMode(data_1, OUTPUT);
  pinMode(clk_1, OUTPUT);
  pinMode(data_2, OUTPUT);
  pinMode(clk_2, OUTPUT);
  pinMode(data_3, OUTPUT);
  pinMode(clk_3, OUTPUT);
  pinMode(data_4, OUTPUT);
  pinMode(clk_4, OUTPUT);
  pinMode(data_5, OUTPUT);
  pinMode(clk_5, OUTPUT);
  
}

//This function will send the data in arr[] array serially to a shift-register
void writereg(int clk, int data)
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(data, arr[7-i]);
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW);
  }
}

//Loop function
void loop() {
  
  //Managing frame rate
  if(frame >= 25)
  {
    page = (page+1)%6;
    frame = 0;
  }
  
  //initializing arr[] to all HIGH
  for(int i=0; i<8; i++)
  {
    arr[i] = HIGH;
  }
  
  //Clearing the screen at first
  writereg(clk_2,data_2);
  writereg(clk_3, data_3);
  writereg(clk_4, data_4);
  writereg(clk_5, data_5);
  arr[7-col%8] = LOW;
  
  //Series if and else if's to handle the 4 different shift register for cascading
  if (col <= 7)
  {
    writereg(clk_2,data_2);
  }
  else if(col <=15)
  {
    writereg(clk_3, data_3);
  }
  else if(col <=23)
  {
    writereg(clk_4, data_4);
  }
  else if(col == 24)
  {
    writereg(clk_5, data_5);
  }
  
  //Sending the data to a single column which will be cascaded
  for(int i=0; i<7; i++)
  {
    arr[i] = rowdata[page][col][i];
  }
  arr[7] = LOW;
  writereg(clk_1, data_1);
  
  //Creating a sense of time, cascading to the next column and managing frames
  delay(1);
  col++;
  if(col > 24)
  {
    frame ++;
    col = 0;
  }
}
