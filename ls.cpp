#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <iomanip>
            #include <sys/types.h>
       #include <sys/stat.h>
       #include <time.h>
       #include <stdio.h>
       #include <dirent.h>
       #include <stdlib.h>
       #include <iostream>	
	#include <grp.h>	    
       #include <pwd.h>

#include <time.h>
#include<vector>
#include<fstream>
#include<dirent.h>
#include <string.h>
#include <algorithm>




using namespace std;
 
 bool compareNoCase( const string& s1, const string& s2 ) {
    return strcasecmp( s1.c_str(), s2.c_str() ) <= 0;
}
 

void access(string filename) {
           struct stat sb;
		   struct passwd *type;
//const char * name = nullptr;
	   struct group *groupname; //= getgrnam(name);
	

			 
          
//argv supposed to be here

           if ((stat(filename.c_str(), &sb)== -1)) {
               perror("stat");
               exit(EXIT_SUCCESS);
           }

      
           /*
            printf("  Size: %lld\t\t",
                   (long long) sb.st_size);
            printf("Blocks: %lld\t\t",
                   (long long) sb.st_blocks);
                   
            printf("I/O Block: %ld\t\t",
                   (long) sb.st_blksize);
          */
           switch (sb.st_mode & S_IFMT) {
           case S_IFBLK:  
           case S_IFCHR:  
           case S_IFDIR:  cout << "d"; break;
           case S_IFIFO: 
           case S_IFLNK:  
           case S_IFREG:  cout << "-"; break;
           case S_IFSOCK: 
           default:  break;    
           }

string total = "";




if ((sb.st_mode & S_IRUSR) && (sb.st_mode & S_IREAD))cout << "r";
else cout << "-";
if ((sb.st_mode & S_IWUSR) && (sb.st_mode & S_IWRITE)) cout <<"w";
else cout <<"-";
if ((sb.st_mode & S_IXUSR) && (sb.st_mode & S_IEXEC)) cout <<"x";
else cout <<"-";
if ((sb.st_mode & S_IRGRP) && (sb.st_mode & S_IREAD)) cout <<"r";
else cout <<"-";
if ((sb.st_mode & S_IWGRP) && (sb.st_mode & S_IWRITE)) cout <<"w";
else cout <<"-";
if ((sb.st_mode & S_IXGRP) && (sb.st_mode & S_IEXEC))cout <<"x";
else cout <<"-";
if ((sb.st_mode & S_IROTH) && (sb.st_mode & S_IREAD)) cout <<"r";
else cout <<"-";
if ((sb.st_mode & S_IWOTH) && (sb.st_mode & S_IWRITE))cout <<"w";
else cout <<"-";
if ((sb.st_mode & S_IXOTH) && (sb.st_mode & S_IEXEC))cout <<"x.";
else cout << "-.";  
         	type = getpwuid(sb.st_uid);
	      if(type == NULL) perror("getpwuid");
	    groupname = getgrgid(sb.st_gid);
	    // const char * name = nullptr;
	//	groupname = getgrnam(const char * name);
 cout << " 1";
 cout << " ";
 cout <<  type->pw_name;
 cout << " ";
 cout << right << groupname-> gr_name;
  cout << " ";
   cout << setw(7) << left <<  ((long long ) sb.st_size);
  
  string time = ctime(&sb.st_mtime);
  time.erase(time.end()-1, time.end());
  
 cout << time;
 
  
   
 
         
      




}

  vector<string> alpha(vector<string> list) { //with -l
    sort(list.begin(), list.end(), compareNoCase);
      return list;
}






vector<string> explore(char *  dir_name, char * const argv[] ) {//used when  -a is used. 
vector<string> list;
DIR *dir;
struct dirent *entry;
struct stat info;
dir = opendir(dir_name);
  if(!dir) {
  cout << "Directory not found in explore";
 
  }

while( (entry=readdir(dir)) != NULL)  {//read
  if(entry->d_name[0] != '.') {
      
       string path = string(entry->d_name);
    //    access(path);
    
    //   cout << path << endl;
    list.push_back(path);
    //   stat(path.c_str(), &info);
      /*   if(S_ISDIR(info.st_mode))  { //for recursion / going into another directory for the files
             explore((char*) path.c_str());
         
         }*/
  }
  



}
list = alpha(list);
return list;
}
vector<string> exploreA(char *  dir_name, char * const argv[] ) {//used when  -a is used. 
vector<string> list;
DIR *dir;
struct dirent *entry;
struct stat info;
dir = opendir(dir_name);
  if(!dir) {
  cout << "Directory not found in explore";
 
  }

while( (entry=readdir(dir)) != NULL)  {//read

      
       string path = string(entry->d_name);
    //    access(path);
    
    //   cout << path << endl;
    list.push_back(path);
    //   stat(path.c_str(), &info);
      /*   if(S_ISDIR(info.st_mode))  { //for recursion / going into another directory for the files
             explore((char*) path.c_str());
         
         }*/
  
  



}
list = alpha(list);
return list;
}




void printOutL(vector<string> list) { // prints with L
  for(int t = 0; t < list.size(); t++) {
   access(list.at(t));
  cout << " ";
  cout << list.at(t);
  cout << "\n";
    }




}
void printOutReg(vector<string> list) { // prints without L or A
  for(int t = 0; t < list.size(); t++) {
  
  
  cout <<   list.at(t)  << endl;
 
  }
    
   




}




int main(int argc, char * const argv[]) {
int opt;
int flags;

  bool isL = false;
  bool isA = false;;
  
if(argv[1] != nullptr) {//checks 

    if(argv[1][0] == '-') {
        if(argv[1][1] == 'a') {
        isA = true;
        }
         if(argv[1][1] == 'l') {
        isL = true;
        }
         if(argv[1][2] == 'l') {
        isL = true;
        }
         if(argv[1][2] == 'a') {
        isA = true;
        }
      
        }


    }
    struct stat buffer;  
   
 //       for(unsigned int k = k; k < argc; k++) {
    //check if file is a file
bool first = true;
for(unsigned int k= 0; k < argc; k++) {
if((isL || isA) && first) {

k+=2;
first = false;
}
if(first) {
k++;
first = false;
}
if((argv[k]!= nullptr && isA && !isL)) { //-a and file afterwards
 if((stat (argv[k], &buffer) == 0)) {
      if(argv[k][0] == '.' && argv[k][1] == '.' && argv[k][2] == 0) { //if .. is specified
     chdir("..");
     vector<string> list =  exploreA((char*)".",argv);
printOutReg(list);
goto end;;
}
 else{
cout << argv[k] << endl;
goto end;;

}
}
else{
cout << argv[k] << " is not a file." << endl;
goto end;;
}

}

if(argv[k] != nullptr && isL && !isA) { //-l and file afterwards
 if((stat (argv[k], &buffer) == 0)) {
 
     if(argv[k][0] == '.' && argv[k][1] == '.' && argv[k][2] == 0) { //if .. is specified
     chdir("..");
     vector<string> list =  explore((char*)".",argv);
printOutL(list);
goto end;;
     }
     else {
access(argv[k]);
cout << " " << argv[k] << endl;
goto end;;
}
}
else {
cout << argv[k] << " is not a file." << endl;
goto end;;
}
}


if((argv[k] != nullptr && isL && isA)) { //-l and file afterwards
 if((stat (argv[k], &buffer) == 0)) {
   if(argv[k][0] == '.' && argv[k][1] == '.' && argv[k][2] == 0) { //if .. is specified
     chdir("..");
     vector<string> list =  exploreA((char*)".",argv);
printOutL(list);
goto end;;
     }
 access(argv[k]);
 cout << " " << argv[k] << endl;
goto end;;
}
else {
cout << argv[k] << " is not a file." << endl;
goto end;;
}
}




if(isL && !isA && argv[k] == nullptr) { // -l and nothering else, If capitoal letter, it is moved to the top
vector<string> list =  explore((char*)".",argv);
printOutL(list);
goto end;;
}
if(!isL && isA && argv[k] == nullptr) {

vector<string> list =  exploreA((char*)".",argv);
printOutReg(list);
goto end;;
}

if(!isL && !isA && argv[k] == nullptr) {

vector<string> list =  explore((char*)".",argv);
printOutReg(list);
goto end;;
}
if(!isL && !isA && argv[k] != nullptr) {
if((stat (argv[k], &buffer) == 0)) {
cout << argv[k] << endl;

goto end;
}
else {
cout << argv[k] << " is not a file." << endl; 
}
}
if(isL && isA && argv[k] == nullptr) {

vector<string> list =  exploreA((char*)".",argv);
printOutL(list);


}



end:;
}

return EXIT_SUCCESS;
}
