/* VERSION @!? FAYg/sTd3luJI */
/* 10 REM "UNXFNS",911002,"SCREEN FUNCTIONS, SQL CONNECT & DISCONNECT","PRO*C","PAGES=00","PW"        */
/* a */
#include <string.h>
#include <signal.h>
/*
[
#include <termio.h>
]
*/
#include <stdio.h>
#include <stdlib.h>
#define UNIX_BUFSIZE 20
#define UNIX_MAXSEQ 23 
#define UNIX_EXTRA  3
#define UNIX_RECSIZE 1007 
#define UNIX_ERROR (sqlca.sqlcode < 0)
/*-- 
EXEC SQL BEGIN DECLARE SECTION;
	VARCHAR bulb[1000];
   VARCHAR unix_uid[20];
   VARCHAR unix_pwd[20];
EXEC SQL END DECLARE SECTION;
--*/
char* prompt(int x, int y,char *stmnt);

extern char s02_orauid[13];
extern char s02_orapwd[13];
extern char s02_dbpath1[60];

char *unix_seqarr[UNIX_MAXSEQ+UNIX_EXTRA+1];
static int unix_flag = 0;
char alert(char *stmnt);
int blink(char *str); /* Prints the string at current position & blinks */
/*********************************************************************/
/*                                                                   */
/*   This file contains functions written using termcap escape sequ- */
/*   ences. Handles vt100 capabilities at present. To be enhanced    */
/*   to handle other terminal types.                                 */
/*                                                                   */
/*********************************************************************/
blink(str) /* Prints the string at current position & blinks */
char *str;
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[1])) {
     printf("%s",str);
     return;
  }
  printf(unix_seqarr[1],27);
  printf("%s",str);
  printf(unix_seqarr[7],27);
}

revmode(str) /* puts the string in reverse mode */
 char *str;
{
  int i;

  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[2])) {
        printf("%s",str);
        return; 
  }
  printf(unix_seqarr[2],27);
  printf("%s",str);
  printf(unix_seqarr[7],27);
}

revband(str) /* puts the string in reverse mode */
 char *str;
{
  int i;

  if (!strlen(unix_seqarr[2])) {
     if ((!strlen(unix_seqarr[8])) || (unix_seqarr[10][6] == '\0')) {
        printf("%s",str);
        return; 
     }
     else {
        setgraf();
        for (i=0;i<strlen(str);i++) 
            printf("%c",unix_seqarr[10][6]);
	fflush(stdout);
	endgraf();
	return;
     }
  }
  printf(unix_seqarr[2],27);
  printf("%s",str);
  printf(unix_seqarr[7],27);
}

cur_off() /* makes the cursor invisible */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[6])) return;
  printf(unix_seqarr[6],27);
}

cur_on() /* makes the cursor visible */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[5])) return; 
  printf(unix_seqarr[5],27);
}
uss_cur_on()
{
	printf("%c[2J",27);
}
uss_cur_off()
{
	printf("%c[2J",27);
}
full_int(str) /* puts the string in highlighted mode */
  char *str;
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[3])) {
     printf("%s",str);
     return;
  }
  printf(unix_seqarr[3],27);
  printf("%s",str);
  printf(unix_seqarr[3],27);
}

mess_bottom(str,bl) /* prints a blinking message in reverse mode at status */ 
  char *str; /* line position. A bell is sounded if parameter bl=1. */  
  int bl;
{
  if (!strlen(unix_seqarr[19])) return;
  printf(unix_seqarr[19],155,155,155);
  clrtoeol();
  blink(str);
  if (bl) printf("\007"); 
  printf(unix_seqarr[20],155);
}

clear_mess_bottom() /* clears the message printed  */
{
  char str[100];

  memset(str,' ',80);
  message_bottom(str,0);
}

clear_mess_top() /* clears the message printed  */
{
  char str[100];

  memset(str,' ',80);
  message_top(str,0);
}

rem_stat()  /* clears the status line */ 
{
  clear_mess_bottom();
}

clrtoeol() /* clears till end of the current line */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[18])) return;
  printf(unix_seqarr[18],155);
}


movexy(x,y)  /* places the cursor at position (x,y) */
 int x,y;
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[0])) return;
  printf(unix_seqarr[0],27,x,y);
}
move(x,y)  /* places the cursor at position (x,y) */
 int x,y;
{

	fflush(stdout);
		
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[0])) return;
  printf(unix_seqarr[0],27,x,y);
}


clr_scr() /* clears the screen */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[4])) system("cls");
  else printf(unix_seqarr[4],27); 
  move(0,0);
}

dis_break() /* disables the del key */
{
  signal(SIGINT,SIG_IGN);
}

enable_break() /* enables the del key */
{
  signal(SIGINT,SIG_DFL);
}

reverse(x,y,len) /* prints a area in reverse mode starting from (x,y) */
short x,y,len;   /* of length len.                                    */
{
  char *str;
  int i;

  str = (char *)malloc(len+1); 
  move(x,y);  
  for (i=0;i < len;i++) 
      str[i] = ' ';
  str[i] = '\0'; 
  revband(str);
  move(x,y);
}
echo_on() /* exits from protect mode */
{
/*[--
  struct termio curtype;
  char str[10];
  
  if (ioctl(0,TCGETA,&curtype) == -1) {
     printf("ioctl fails \n");
     exit(1);
  }
  curtype.c_lflag = 59;
  curtype.c_cc[4] = 1; 
  ioctl(2,TCSETA,&curtype);
--]*/
}

echo_off() /* enters protect mode. */
{
/*[
  struct termio curtype;
  char str[10];
  
  if (ioctl(0,TCGETA,&curtype) == -1) {
     printf("ioctl fails \n");
     exit(1);
  }
  curtype.c_lflag &= ~ICANON;
  curtype.c_lflag &= ~ECHO;
  curtype.c_cc[4] = 1; 
  ioctl(2,TCSETA,&curtype);
--]*/
}

rect(x1,y1,x2,y2)  /* calls the rectangle function to draw rectangle suitably */
 int x1,y1,x2,y2;
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[11])) {
      if (!strlen(unix_seqarr[8])) return;
      if (x1 == x2) horizontal_line(x1,y1,y2);
      else {
	if (y1 == y2) vertical_line(x1,y1,x2);
        else rectangle(0,x1,y1,x2,y2);
      }
  } 
  else 
     rectangle(1,x1,y1,x2,y2);
}

horizontal_line(x1,y1,y2)
  int x1,y1,y2;
{
  int i;

  move(x1,y1);
  printf(unix_seqarr[8],27);
  for (i=y1;i<=y2;i++) 
    printf("%c",unix_seqarr[10][5]);
  printf(unix_seqarr[9],27);
}

vertical_line(x1,y1,x2)
  int x1,y1,x2;
{
  int i;

  printf(unix_seqarr[8],27);
  for (i=x1;i<=x2;i++) {
    move(i,y1);
    printf("%c",unix_seqarr[10][4]);
  }
  printf(unix_seqarr[9],27);
}

rectangle(flag,x1,y1,x2,y2)  /* draws a rectangle between (x1,y1) and (x2,y2) */
  int flag,x1,y1,x2,y2;   /* flag identifies whether to enter graphics mode to draw or not */
{
   int x,y;
   
   move(x1,y1);
   if (flag) {
      printf(unix_seqarr[11],155,y2-y1 +160,x2-x1+160);
      fflush(stdout);
   }
   else { 
      printf(unix_seqarr[8],27);  /* enters graphic mode */
      move(x1,y1);
      printf("%c",unix_seqarr[10][0]); /* top left corner */
      fflush(stdout);
      for (y=y1+1;y<y2;y++)     /* top horizontal line */  
          printf("%c",unix_seqarr[10][5]);
      fflush(stdout);
      printf("%c",unix_seqarr[10][1]);  /* top right corner */ 
      fflush(stdout);
      for (x=x1+1;x<x2;x++) {   /* right vertical line */ 
          move(x,y2);
          printf("%c",unix_seqarr[10][4]);
      }
      move(x2,y2); 
      printf("%c",unix_seqarr[10][3]); /* bottom right corner */
      fflush(stdout);
      
      for (y=y2-1;y>y1;y--) {    /* bottom horizontal line */  
          move(x2,y);
          printf("%c",unix_seqarr[10][5]);
      }
      move(x2,y1); 
      printf("%c",unix_seqarr[10][2]); /* bottom left corner */
      for (x=x2-1;x>x1;x--) {   /* left vertical line */
          move(x,y1);
          printf("%c",unix_seqarr[10][4]);
      }
      printf(unix_seqarr[9],27); /* exits graphic mode */
   }
}

getarr()    /* This function loads the escape sequences into an array. Identifies */ 
{           /* by isssuing a call to getenv() function */
  /* char *getenv(); */
 int fdCunt =0;
  FILE *fp;
  char buffer[UNIX_BUFSIZE+1]; 
  char *tname, fname[150];
  int i;
  /* -- strcpy(fname,"/usr1/soft/install/unix_termseq"); --*/
  strcpy(fname,"/root/procCompiler/unix_termseq");
		printf( "/root/procCompiler/unix_termseq");
  if ((fp = fopen(fname,"r")) == NULL) {
     printf("\nUnable to open %s file for reading. \n",fname);
     printf("Exiting ... \n");
     exit(1);
  }
  tname = (char *)getenv("TERM"); 
  printf("\n tname = <%s> ",tname); fflush(stdout);
  do {
      /*if (fread(buffer,UNIX_BUFSIZE,1,fp) != 1)  */
	memset(buffer,0x00,sizeof(buffer));
	fdCunt=fread(buffer,UNIX_BUFSIZE,1,fp);
/*	printf("\n fdCunt = <%d> ",fdCunt); */
        if(fdCunt != 1 )
	{
	 printf("\nEntry for terminal type %s not found.\n",tname);
	 printf("Exiting ..... \n");
	 exit(1);
      }
  } while (strcmp(buffer,tname));
  for (i=0;i<UNIX_MAXSEQ+UNIX_EXTRA;i++) {
      unix_seqarr[i] = (char *)malloc(UNIX_BUFSIZE);
      fread(unix_seqarr[i],UNIX_BUFSIZE,1,fp);
/*      printf("\nunix_seqarr[%d] =  <%s>",i,unix_seqarr[i]); --*/
  }    
  fclose(fp);
}

printmess_bottom(str,bl)      /* prints the bottom message(status line). */
 char *str;                   /* Bell is sounded if bl is set to 1 */
 int bl;
{
  if (strlen(unix_seqarr[1])) 
     printf(unix_seqarr[1],27);
  if (bl) printf("\007"); 
  printf(unix_seqarr[22],27,str,'\n',27);
  printf(unix_seqarr[7],27);
}

print_mess(x,y,stmnt,blk)  /* prints message at position x,y */
 int x,y;
 char *stmnt;
 int blk;
{
   move(x,y);
   if ((blk) && (strlen(unix_seqarr[1]))) printf(unix_seqarr[1],27);
   printf("%s",stmnt);
   if (strlen(unix_seqarr[7])) printf(unix_seqarr[7],27);
} 



clear_mess(tempx,tempy)  /* clears message at tempx,tempy */
  int tempx, tempy;
{
  move(tempx,tempy);
  printf("%80s"," ");
}


printmess_top(str,bl)    /* prints message at top status line position */
 char *str;
 int bl;
{
  if (strlen(unix_seqarr[1])) 
     printf(unix_seqarr[1],27);
  if (bl) printf("\007"); 
  printf(unix_seqarr[21],27,str,'\n',27);
  printf(unix_seqarr[7],27);
}

message_bottom(str,bl)   /* for printing status line message this is to be */
 char *str;  /* invoked. This calls either mess_bottom or printmess_bottom */ 
 int bl;
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[15])) mess_bottom(str,bl);
  else printmess_bottom(str,bl);
}

message_top(str,bl)   /* this is to be invoked for message at top status line */
 char *str;/* position. Calls printmess_top or returns depending on sequences */
 int bl;
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[15])) return;
  else printmess_top(str,bl);
}
/*
box(x1,y1,x2,y2)
 int x1,y1,x2,y2;
{
  if (!strlen(unix_seqarr[15])) return;
  printf(unix_seqarr[15],155,y1,x1,155,(y2-y1+160),(x2-x1+160));
}
*/

setgraf()  /* puts the terminal in graph mode */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[8])) return;
  else printf(unix_seqarr[8],27);
}

endgraf()  /* ends the graphic mode of the terminal */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[9])) return;
  else printf(unix_seqarr[9],27);
}

dis_clear()  /* disables clear key */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[12])) return;
  printf(unix_seqarr[12],155);
}

enable_clear() /* enables clear key */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[13])) return;
  printf(unix_seqarr[13],155);
}

clear_bottom() /* clears bottom status line */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[15])) return;
  printf(unix_seqarr[15],155);
}

clear_top()  /* clears top status line */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[14])) return;
  printf(unix_seqarr[14],155);
}

half_int()  /* half_intensity mode */ 
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[17])) return;
  printf(unix_seqarr[17],155);
}

end_modes() /* end all modes that the terminal has been put in */
{
  if (!unix_flag) {
     getarr();
     unix_flag = 1;
  }
  if (!strlen(unix_seqarr[7])) return;
  printf(unix_seqarr[7],155);
}

getch_tr() /* enters protect mode. */
{
/*[--
  struct termio curtype,savetype;
  int c;
 
  if (ioctl(0,TCGETA,&curtype) == -1) {
     printf("ioctl fails \n");
     exit(1);
  }
  savetype = curtype;
  curtype.c_lflag &= ~ICANON;
  curtype.c_lflag &= ~ECHO;
  curtype.c_cc[4] = 1; 
  ioctl(0,TCSETA,&curtype);
  c=getchar();
  ioctl(0,TCSETA,&savetype);

  return(c);
--]*/
}


get_var(x,y,var,type,length,flex,quit,f_name,highlight,statment)                
short x,y,length,flex,highlight;                                                
char type,f_name[20],statment[40],var[80];                                      
{                                                                               
int c,i=0,error=0,add=0;                                                        
short *dot_entered,tempx,tempy;                                                 
tempx = x;                                                                      
tempy = y;                                                                      
                                                                                
    move (x,(y-strlen(f_name)-1));                                              
    printf("%s",f_name);                                                        
    print_mess(24,10,statment,1);          
    if (highlight) reverse(x,y,length);                                         
    else move(x,y);                                                             
    do                                                                          
    {                                                                           
         while ((c=getch_tr())!=quit)                                           
         {                                                                      
              if (error) clear_mess(24,1);                               
              error=0;                                                          
              if (!highlight && c==27)                                         
              {                                                                 
                   var[i]='\0';                                                 
                   return(9);                                                   
              }                                                                 
              if (!highlight && c==30)                                         
              {                                                                 
                   var[i]='\0';                                                 
                   return(8);                                                   
              }                                                                 
              if (c == '\b')                                                    
              {                                                                 
                   if (tempy != y)                                              
                   {                                                            
                        putchar(' ');                                           
                        tempy--;                                                
                        move(tempx,tempy);                                      
                        i--;                                                    
                   }                                                            
              }                                                                 
              if (!valid(c,type,&dot_entered))                                  
              {                                                                 
                   print_mess(24,10,"Invalid Char..",1);                  
                   error=1;                                                     
                   continue;                                                    
              }                                                                 
              if (c != '\b')                                                    
              {                                                                 
                   move(tempx,tempy);
                   putchar(c);                                                  
                   var[i]=c;                                                    
                   if (i == length-1) add=1;                                    
                   else                                                         
                   {                                                            
                        tempy++;i++;                                            
                   }                                                            
              }                                                                 
         }                                                                      
                                                                                
         if (flex)                                                              
         {                                                                      
              if (i != length-1)                                                
              {                                                                 
                   print_mess(24,10,"Field must be enterd fully",1);      
                   error=1;                                                     
                   continue;                                                    
              }                                                                 
         }                                                                      
         if (i!=0)                                                              
         {                                                                      
              if (add) var[++i]='\0';                                           
              else var[i]='\0';                                                 
              return(1);                                                        
         }                                                                      
         else                                                                   
         {                                                                      
              var[0]='\0';                                                      
              return(0);                                                        
         }                                                                      
         break;                                                                 
    } while(1);                                                                 
}                                                                               
                                                                                
valid(Chart,type,dot_entered)                                               
char type,Chart;                                                            
short *dot_entered;                                                             
{                                                                               
    if (Chart == '\b') return(1);                                           
    switch(upcase(type))                                                        
    {                                                                           
    case 'N':                                                                   
             return(Chart >= '0' && Chart <= '9');                      
             break;                                                             
    case 'A':                                                                   
             return(upcase(Chart) >= 'A' && upcase(Chart) <= 'Z');      
             break;                                                             
    case 'U':                                                                   
             return((Chart >= 'A' && Chart <= 'Z')                      
                     || Chart == ' ' || Chart == '.');                  
             break;                                                             
    case 'L':                                                                   
             return(Chart >= 'a' && Chart <= 'z');                      
             break;                                                             
    case 'F':                                                                   
             if (Chart == '.')                                              
                     if (*dot_entered) return(0);                               
                     else                                                       
                     {                                                          
                         *dot_entered = 1;                                      
                         return(1);                                             
                     }                                                          
               else return(Chart >= '1' && Chart <= '9');               
               break;                                                           
    case 'C':                                                                   
             return ((Chart >= '!' && Chart <= '~') || Chart==' '); 
             break;                                                             
    default :                                                                   
             return(0);                                                         
    }                                                                           
 }                                                                              
                                                                                
upcase(Chart)                                                               
char Chart;                                                                 
{                                                                               
    if  (Chart >= 'a' &&  Chart <= 'z')                                 
         return(Chart - ('a' - 'A'));                                       
    else                                                                        
         return(Chart);                                                     
}


erase_window(x,y,a,b)
int x,y,a,b;
{
   int i,j,k;
   char st_space[80];
   i = b - y;
   for (j=0;j<i;j++)
      st_space[j] = ' ';
   st_space[j] = '\0';
   for (i=x;i<=a;i++)
   {
       move(i,y);
       printf (st_space);
   }
}

message(str1,str2)                   
{
   move(22,15);
   printf ("%s",str2);
}

print_on()
{
   if (!strcmp((char *)getenv("TERM"),"tvi950")) 
     printf("%c`",27); 
   else  
     if (!strcmp((char *)getenv("TERM"),"vt100")) 
        printf("%c[5i",27); 
}

print_off()
{
   if (!strcmp((char *)getenv("TERM"),"tvi950")) 
     printf("%ca",27); 
   else  
     if (!strcmp((char *)getenv("TERM"),"vt100")) 
        printf("%c[4i",27); 
}
char alert(char *stmnt)
{
	char * dipMsg[76];
	char  cnfm;

	memset(dipMsg,0x00,sizeof(dipMsg));
	strncpy((char*)dipMsg,stmnt,75);
	printf("A:001:before move");
	move(21,3);	
	printf("[91m%s[0m",dipMsg);
	cnfm=getchar();
	printf("[91m%76.76s[0m"," ");
        return	cnfm;
}
char* prompt(int x, int y,char *stmnt)
{
	char * dipMsg[76];
	char * cnfm;
	memset(dipMsg,0x00,sizeof(dipMsg));
	strncpy((char*)dipMsg,stmnt,75);
	move(y,x);	
	printf("[91m%s[0m",dipMsg);
	/*cnfm=getchar(); */
	scanf("%s",cnfm);
        return	cnfm;
}
