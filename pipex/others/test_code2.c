#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int *a;

int fatal(char *s){
  perror(s);
  exit(1);
}

void pipeRec(char **coms[], int *p, int ncmd, int npipe){
  // pipeRec(coms,p,1,npipe);
  // ì´ë¯¸ ìžì‹ì¸ ìƒíƒœ.
  int np[2];
  char **com;
  com = coms[npipe-ncmd];
  if(ncmd==npipe){
    close(1); // stdout == 1
    dup(p[1]); //  p[1] is writing part
    close(p[1]);
    close(p[0]);
    execvp(com[0],com);
  }else{
    if(pipe(np)==-1)
      fatal("pipe call error");
    switch(fork()){
    case -1: fatal("fork error in pipeRec");
    case 0: ncmd++; pipeRec(coms,np,ncmd,npipe);
    default : 
      close(0);  // stdin == 0
      dup(np[0]);
      close(np[0]);
      close(np[1]);
      close(1);
      dup(p[1]);
      close(p[1]);
      close(p[0]);
      execvp(com[0],com);
    }
  }
}

int pipeCmd(char **coms[],int npipe){
  // each command 
  int i=0,p[2],status;
  char **com1,**com2;
  printf("Come into PipeCmd!! \n");

  for(i=0;i<npipe;i++){
    if(i==0){
      com1 = coms[0];
      printf("cmd%d:%s\n",i+1,com1[0]);
    }
    com1 = coms[i+1];
    printf("cmd%d:%s\n",i+2,com1[0]);
  }
  
  // First child
  switch(fork()){
  case -1: fatal("1st fork call in pipeCmd");
  case 0:  break;
  default: 
    // Parent
    wait(&status);
    return status;
  }
  printf("%d npipe\n",npipe);

  if(pipe(p)==-1)
    fatal("pipe call in join");
  switch(fork()){
  case -1: fatal("2nd fork call in pipeCmd");
  case 0:    // writing process
    // under child 1.
    pipeRec(coms,p,1,npipe);
  default :  // Reading process
    // child 1.
    com2 = coms[npipe];
    close(0);
    dup(p[0]);
    close(p[0]);
    close(p[1]);
    execvp(com2[0],com2);
  }

}
int main(){
  char *command[10][10], **s[10];
  command[0][0] = "ls";
  command[0][1] = "-la";
  command[0][2] = NULL;
  s[0] = command[0];
  command[1][0] = "wc";
  command[1][1] = NULL;
  s[1] = command[1];
  command[2][0] = "wc";
  command[2][1] = NULL;
  s[2] = command[2];
  pipeCmd(s,2);
}include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int *a;

int fatal(char *s){
  perror(s);
  exit(1);
}

void pipeRec(char **coms[], int *p, int ncmd, int npipe){
  // pipeRec(coms,p,1,npipe);
  // ì´ë¯¸ ìžì‹ì¸ ìƒíƒœ.
  int np[2];
  char **com;
  com = coms[npipe-ncmd];
  if(ncmd==npipe){
    close(1); // stdout == 1
    dup(p[1]); //  p[1] is writing part
    close(p[1]);
    close(p[0]);
    execvp(com[0],com);
  }else{
    if(pipe(np)==-1)
      fatal("pipe call error");
    switch(fork()){
    case -1: fatal("fork error in pipeRec");
    case 0: ncmd++; pipeRec(coms,np,ncmd,npipe);
    default : 
      close(0);  // stdin == 0
      dup(np[0]);
      close(np[0]);
      close(np[1]);
      close(1);
      dup(p[1]);
      close(p[1]);
      close(p[0]);
      execvp(com[0],com);
    }
  }
}

int pipeCmd(char **coms[],int npipe){
  // each command 
  int i=0,p[2],status;
  char **com1,**com2;
  printf("Come into PipeCmd!! \n");

  for(i=0;i<npipe;i++){
    if(i==0){
      com1 = coms[0];
      printf("cmd%d:%s\n",i+1,com1[0]);
    }
    com1 = coms[i+1];
    printf("cmd%d:%s\n",i+2,com1[0]);
  }
  
  // First child
  switch(fork()){
  case -1: fatal("1st fork call in pipeCmd");
  case 0:  break;
  default: 
    // Parent
    wait(&status);
    return status;
  }
  printf("%d npipe\n",npipe);

  if(pipe(p)==-1)
    fatal("pipe call in join");
  switch(fork()){
  case -1: fatal("2nd fork call in pipeCmd");
  case 0:    // writing process
    // under child 1.
    pipeRec(coms,p,1,npipe);
  default :  // Reading process
    // child 1.
    com2 = coms[npipe];
    close(0);
    dup(p[0]);
    close(p[0]);
    close(p[1]);
    execvp(com2[0],com2);
  }

}
int main(){
  char *command[10][10], **s[10];
  command[0][0] = "ls";
  command[0][1] = "-la";
  command[0][2] = NULL;
  s[0] = command[0];
  command[1][0] = "wc";
  command[1][1] = NULL;
  s[1] = command[1];
  command[2][0] = "wc";
  command[2][1] = NULL;
  s[2] = command[2];
  pipeCmd(s,2);
}
