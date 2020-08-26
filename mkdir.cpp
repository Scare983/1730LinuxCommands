
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <err.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>
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
#include <sys/types.h>

#include <time.h>
#include<vector>
#include<fstream>
#include<dirent.h>
#include <string.h>
#include <algorithm>


using namespace std;

mode_t mode;

void pCreateDirectory(char * argv) {
string filename = argv;


DIR *dir;
struct dirent *entry;
struct stat info;
string::size_type loc = filename.find( "/", 0 );
bool containsSlash = false;
 if( loc != string::npos ) {
  
   containsSlash = true;
 } 
 string name = filename.substr(0, loc);
 string otherHalf = filename.substr(loc+1);

mkdir((char*) name.c_str(), mode);
switch(errno) {
      case EACCES: perror("Following error occurred:");
        break;
         case EEXIST: perror("Following error occurred:");
         break;
          case EFAULT: perror("Following error occurred:");
          break;
           case EIO: perror("Following error occurred:");
           break;
            case ELOOP: perror("Following error occurred:");
            break;
             case ENOTDIR: perror("Following error occurred:");
             break;
              case EPERM: perror("Following error occurred:");
             break;
              case EROFS: perror("Following error occurred:");
             break;



}

//chmod(name.c_str(), mode);
//put error signs here


if(containsSlash) { 

if(chdir(name.c_str()) == -1) {
cout << "Reading permissions for filestream was not given, writing directories in current file." << endl;
}

pCreateDirectory((char*) otherHalf.c_str());
         
         }
  
  



}
void createDirectory(char * argv) {
string filename = argv;
 
mkdir((char*) filename.c_str(), mode);
switch(errno) {
      case EACCES: perror("Following error occurred:");
        break;
         case EEXIST: perror("Following error occurred:");
         break;
          case EFAULT: perror("Following error occurred:");
          break;
           case EIO: perror("Following error occurred:");
           break;
            case ELOOP: perror("Following error occurred:");
            break;
             case ENOTDIR: perror("Following error occurred:");
             break;
              case EPERM: perror("Following error occurred:");
             break;
              case EROFS: perror("Following error occurred:");
             break;



}


}







void usage(void)
{

	(void)fprintf(stderr, "usage: mkdir [-pv] [-m mode] directory ...\n");
	exit (EX_USAGE);
}

int main(int argc, char *argv[])
{
	int ch, exitval, success, pflag;
	
 string modestring;
bool modeF  = false;
	pflag = 0;
	mode = 0;
	while ((ch = getopt(argc, argv, "m:p")) != -1)
		switch(ch) {
		case 'm':
			modestring = optarg;
      modeF = true;
       mode = strtol((char *)modestring.c_str(), NULL, 8);
			break;
		case 'p':
			pflag = 1;
			break;
	
		case '?':
		default:
			usage();
		}

	argc -= optind;
	argv += optind;
	if (argv[0] == NULL)
		usage();


 if(modeF) {
 mode_t umask(4000);
 mode =  umask | ~022;
  }
 else {
 mode_t umask(mode);
 
 mode = (S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH | ~umask);
 } 
  
  if(pflag && argv[1] != nullptr) {
  cout << "Error: command does not recognize input." << endl;
  exit(exitval);
  }
 if(pflag) {
     pCreateDirectory(argv[0]);
 }
 if(!pflag) {
 
 for(unsigned int i = 0; i < argc; i++) {
 createDirectory(argv[i]); 
 
 
 }
 }
 
 


	return EXIT_SUCCESS;
}
