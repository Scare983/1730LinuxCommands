#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>


class cal {
  //using namespace std;
 
  public:
  void calenderDisplay();
  ~cal();
  cal();
  cal(unsigned int);
  cal(unsigned int,unsigned int);
  unsigned int calculateNumDays(unsigned int,unsigned int);
  void createDisplay(unsigned int, unsigned int);
  void showDisplay(unsigned int, unsigned int);
  bool checkLeapYear(unsigned int);
  const char* monthToString(unsigned int);
  unsigned int calculateDay(unsigned int, unsigned int);
  





};
using namespace std;
cal * calender;
bool isLeapYear; 
unsigned int display[6][7];



cal::cal() {//when no argv[]


isLeapYear = checkLeapYear(2017);
//add for loop for each month right here

for(unsigned int i = 0; i < sizeof(display)/sizeof(*display); i++) {
  for(unsigned int j = 0; j < sizeof(display)/sizeof(*display); j++) {
  
    display[i][j] = NULL;
  
  }




}
time_t t = time(0);
struct tm * now = localtime( &t);

createDisplay(now->tm_mon +1 ,2017);

showDisplay(now->tm_mon+1, 2017);




}


cal::cal(unsigned int year)  { //when argv only contains year


isLeapYear = checkLeapYear(year);
for(int k = 1; k < 13; k++) {
for(unsigned int i = 0; i < sizeof(display)/sizeof(*display); i++) {
  for(unsigned int j = 0; j < sizeof(display)/sizeof(*display); j++) {
  
    display[i][j] = NULL;
  
  }




}
createDisplay(k,year);
showDisplay(k, year);
}

}




cal::cal(unsigned int month, unsigned int year) {//when argv contains year and month

isLeapYear = checkLeapYear(year);
for(unsigned int i = 0; i < sizeof(display)/sizeof(*display); i++) {
  for(unsigned int j = 0; j < sizeof(display)/sizeof(*display); j++) {
  
    display[i][j] = NULL;
  
  }




}
createDisplay(month,year);
showDisplay(month, year);



  }


bool cal::checkLeapYear(unsigned int year) {//cehcks if the year is leap, used within caluclateNumDays
if(((year % 4 == 0) && (year % 100 !=0)) || (year % 400 == 0)) {
return true;
}

else {
  return false;
  }
}




unsigned int cal::calculateNumDays(unsigned int month, unsigned int year) { //calcules and reutrns the amount of days within each month.
unsigned int days;
if(month ==4 || month == 6 || month == 9|| month == 11) {
days = 30;
}
else if(month ==2) {
  if(isLeapYear) {
  days = 29;
  
    }
  else {
  days = 28;
  }  
}
else {
days = 31;
}

return days;
}//works with julian and gregorian


unsigned int cal:: calculateDay(unsigned int month, unsigned int year) {
if((year == 1752 && month == 9) ) {





return 3;
}

unsigned int lastTwo = year%100;
unsigned int nextValue = lastTwo/4;
unsigned int addDayOfMonth = nextValue+1;
unsigned int monthValue = 0;
if(year < 1752 || (year ==1752 && month < 9)) {
switch(month) {
case 1:
case 5: monthValue = 0;
break;
case 2:
case 6: monthValue = 3;
break;
case 3:
case 11: monthValue = 2;
break;
case 4:
case 7: monthValue = 5;
break;
case  8: monthValue = 1;
break;
case 9:
case 12: monthValue = 4;
break;
case 10: monthValue = 6;
break;





}

monthValue -=1;

}
else{
switch(month){
case 1:
case 10: monthValue = 1;
break;
case 2:
case 3:
case 11: monthValue = 4;
break;
case 4:
case 7: monthValue = 0;
break;
case 8: monthValue = 3;
break;
case 5: monthValue =2;
break;
case 6: monthValue = 5;
break;
case 12:
case 9: monthValue = 6;
break;

}
}

nextValue = addDayOfMonth + monthValue;

if((month == 1 || month == 2)  && isLeapYear && year >1752) {
nextValue = nextValue - 1;
}



//might mess up this part
if(year < 1800) {
nextValue = nextValue +4;
}
else if(year >=1800 && year < 1900) {
nextValue = nextValue +2;
}
else if(year>= 1900 && year <2000) {
nextValue = nextValue;
}
else {
nextValue = nextValue+6;
}

nextValue += lastTwo;
if(month == 1 || month == 2 && year <=1752) {
nextValue -=2;
}
unsigned int remainder = (nextValue %7)  ;//to add one, or to not add 1gett
return remainder;

}

void cal::createDisplay(unsigned int month, unsigned int year) {
unsigned int firstDay = calculateDay(month,year);//inputs leap year.  0 = saturday, 1 = sunday, and so fourth
if(firstDay == 0) {
firstDay = 7;
}

//firstDay -= 1;//making sure that sunday is = 0, making indexing easy 

unsigned int numOfDays = calculateNumDays(month,year);

bool firstLine = true;
unsigned int dayNumber =1;
firstDay = firstDay-1;
 //first line is different size so we do this
if(firstLine) {
  for(firstDay; firstDay < sizeof(*display)/sizeof(**display); firstDay++) {
   if(month == 9 && year == 1752  && dayNumber == 3) {
        dayNumber+=11;
     display[0][firstDay] = dayNumber;
   dayNumber++;
   
    }
    else {
    display[0][firstDay] = dayNumber;
    dayNumber++;   
    }
  }
  firstLine = false;
  }
  
for(unsigned int i = 1; i < sizeof(display)/sizeof(*display); i++) {
  
    for(unsigned int j = 0; j < sizeof(*display)/sizeof(**display); j++) {
   
    
      display[i][j] = dayNumber;
    
      dayNumber++;
      
      if(dayNumber > numOfDays) {
      goto stop;
      }
    }
}
stop:;
}

void cal::showDisplay(unsigned int month, unsigned int year) {//creates the display , prob should create method to insert number at location, and this method just shows the contents.
time_t t = time(0);
struct tm * now = localtime(&t);





unsigned int numOfDays = calculateNumDays(month,year);
unsigned int currentDay =1;
cout << "    " << monthToString(month) << " " << year << endl;
const char * names[7] ={" Su", " Mo", " Tu", " We", " Th", " Fr", " Sa"};
for(unsigned int i = 0; i < 7; i ++) {
cout << names[i];
}
cout <<endl;
bool firstLine = true;
for(unsigned int i = 0; i < sizeof(display)/sizeof(*display); i++) {
  unsigned int k = 0;//k is just used to fix the visualization
  
  for(unsigned int j = 0; j < sizeof(*display)/sizeof(**display); j++) {
  if(j%7 ==0) {
    cout << endl;
  }
      if(firstLine == false && display[i][j] == 0) {
    goto end;
    } 
   if((now->tm_year + 1900 == year) && (now->tm_mon + 1 == month) && (now-> tm_mday ==  currentDay)) {
   // Color::Modifier red(Color::FG_RED);
   // Color::Modifier def(Color::FG_DEFAULT);
  string color = "\033[7;37m";
     if(display[i][j] >9){
    cout <<  " " <<  color <<display[i][j];
    }
    else {
    cout << "  " << color << display[i][j];
    }
    
    
    string default_console = "\033[0m";
     cout<<default_console ;
   
   }
      
 /* if(k == 0) {
   
   
      cout <<display[i][j];
    
  }*/
  else if(display[i][j] == 0) {
  cout << "   ";
  currentDay--;
  }
  else if(display[i][j] >9) {
    cout << " " << display[i][j];
  }
  else {
    cout << "  " << display[i][j];
    }
    k =1;
currentDay++;
  }
  
  
  firstLine = false;
  
   

}
end:

cout << endl;
cout << endl;
}

const char* cal::monthToString(unsigned int month) {
switch(month) {
  case 1: return "January";
  case 2: return "Febuary";
  case 3: return "March";
  case 4: return "April";
  case 5: return "May";
  case 6: return "June";
  case 7: return "July";
  case 8: return "August";
  case 9: return "September";
  case 10: return "October";
  case 11: return "Novemeber";
  case 12: return "December";
  default: return "NOT A REAL MONTH";



}

}


cal::~cal() {
delete calender;
}






 int main(int argc,  char* argv[]) {
unsigned int year;
unsigned int month;
//cal * calender;


  if(argv[1] != nullptr) {
      month = atoi(argv[1]);
  }
  if(argv[2] != nullptr) {
     year = atoi(argv[2]);
  }
  
  
  
  
  
  
  if(argv[1] == nullptr ) {
     calender = new cal;
   }
   else if((month >  0)  && (year >0) && (month < 13)) {
   delete calender;
      calender = new cal(month, year);
     
   }
   
   else if(month > 0) {//in this case, month is year.
    delete calender;
    calender = new cal(month);
   
   
   
   }
   
  
   else {
   cout << "Error Input"<< endl;
   return EXIT_SUCCESS;
   }
    







return EXIT_SUCCESS;
}
