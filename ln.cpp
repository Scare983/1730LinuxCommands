#include <cstdlib>
#include <unistd.h>
#include <iostream>


#include <stdlib.h>
#include <stdio.h>












using namespace std;

int main(int argc, char * const argv[]) {
if(argv[1] == nullptr) {
cout << "No arguments inputted.  Exiting..." << endl;
return EXIT_SUCCESS;

}

bool isS = false;

if(argv[1] != nullptr) {//checks 
    if(argv[1][0] == '-') {
        if(argv[1][1] == 's') {
        isS = true;
        }
        else {
        cout << "Not a command" << endl;
           exit(EXIT_FAILURE);
        }


    }

  if(isS) {//creates the symlink

    int link = symlink(argv[2],argv[3]);
      switch(errno) {//check if any errors occured
      
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

else { 
 if(argc !=3 ) {//if there are more arguements than needed, error
  fprintf(stderr, "Expected two argument after ln call\n");
      exit(EXIT_FAILURE);
  
  
}

 int here =  (link(argv[1], argv[2]));//still apart of else statement, so that it runs the link
  
        switch(errno) {//once agian checks for errors between the two files.
      
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




return EXIT_SUCCESS;
}
}
