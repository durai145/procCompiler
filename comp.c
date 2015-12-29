/*
 
 Action  03032011:	1. define the Language
			2. define common library
			3. test in windows and lunix plateform
 History : It has been tested in Apple  Mac env at 20110927
 
 */
 
 




#include<stdio.h>
/* --  
 this is for only windows
 #include<dos.h>
 #include "windows.h"
 --*/
#include "time.h"
#include <string.h>
#include <curses.h>
int drawWin();


char tibcoLib[1000]=" ";
char procInclude[1000]="-I/cygdrive/c/app/oracle/product/12.1.0/dbhome_1/precomp/public";
char tibcoInclude[1000]=" ";
char sqlInclude[1000]="-I/cygdrive/c/app/oracle/product/12.1.0/dbhome_1/precomp/public -I/cygdrive/c/app/oracle/include ";
//char sqlLib[1000]=" -dynamic /usr/local/lib/libclntsh.dylib ";
//char sqlLib[1000]="  -L/cygdrive/c/app/oracle/product/12.1.0/dbhome_1/lib -loraldapclnt12 -lpthread -loracore12";
char sqlLib[1000]="  -L/cygdrive/c/app/oracle/product/12.1.0/dbhome_1/OCI/lib/MSVC -loci";
char subPgmName[1000]=" ";
char subPgmType[10]=" ";
char tmpSubPgmType[100]=" ";
char cfgFileName[100];
char cfgFileNameBuff[10000];
char tmpCfgFileNameBuff[10000];
char outFile[10000];
char outFileExtn[10000];
char inpFileTypes[10000];
char userLink[10000];
char logFileName[100];
const char version[100] = "1.0.0";
const char os[100] ="WinCyg";
int rmEntrChr(char *inp);
char* to_upper(char *inp);
char * getLinkFiles(char * outFile, char * outFileExtn);
char pgmnm[1000];
char pgmTyp[1000];
int f_pos=0;
int debug=1;
FILE *fpDebug;
FILE *fpCfg;
int main(int argc, char *argv[])
{
	int i=0;
	int line =0;
	int exec_rslt=1;
	unsigned int a=0,b=0;
	char exec_str[1000];
	char exec_errFile[1000];
	char inp='N';
	char *tmp;
	char *reVarCharComp;
	char givnTmpVer[100];
	char tmp_msg[100];
	memset(logFileName,0x00,sizeof(logFileName));
	memset(givnTmpVer,0x00,sizeof(givnTmpVer));
	memset(tmp_msg,0x00,sizeof(tmp_msg));
	/*system("alias clear='printf \"\033c\"'");*/
	system("printf \"\033c\"");
	system("pwd");
	/*[
	 while( i<argc)
	 {
	 printf("argv[%d]= <%s>\n",i,argv[i]);
	 i++;
	 }
	 ]*/
	int drawWin();
	
	if(argc > 1)
	{
		if(debug ==1 )
		{
				sprintf(logFileName,"%s.log",argv[0]);
				fpDebug=fopen(logFileName,"a+");
				if(fpDebug == NULL)
				{
					alert("unable to open file ");
					return 1;
				}
		}
		/*********************************
		 proc compilation 
		 **********************************/
		memset(pgmnm,0x00,sizeof(pgmnm));
		memset(pgmTyp,0x00,sizeof(pgmTyp));
		memset(exec_str,0x00,sizeof(exec_str));
		memset(exec_errFile,0x00,sizeof(exec_errFile));


		a=strlen(argv[1]);
		tmp= strstr(argv[1],".");
		if(tmp != NULL)
		b=strlen(tmp);
		if(b!=0)
		{
			strncpy(pgmnm,argv[1],a-b);
			strncpy(pgmTyp,argv[1]+(a-b)+1,b);
		}
		else
		{
			strcpy(pgmnm,argv[1]);
			//strcpy(pgmTyp,"PC");
			printf("Please Enter Program Type: ");
			scanf("%s",pgmTyp);
		}
		
		to_upper(pgmTyp);
		memset(cfgFileName,0x00,sizeof(cfgFileName));

		if(strlen(pgmnm)  <= 0 )
		{
			alert("program name is null ");
			return 1;
		
		}
		sprintf(cfgFileName,".%s.cfg",pgmnm);
		sprintf(exec_errFile,"vi %s.err",pgmnm );
		if( debug ==1)	
		{
				fprintf(fpDebug, "\n%s:A.001:pgmTyp =<%s>",pgmnm,pgmTyp); fflush(fpDebug);
				fprintf(fpDebug, "\n%s:A.002: opening config file ",pgmnm); fflush(fpDebug);
		}
		if( debug ==1)	
		{
				fprintf(fpDebug, "\n%s:A.003:  try to open cfgFileName:cfgFileName =<%s>",pgmnm,cfgFileName); fflush(fpDebug);
		}

		fpCfg=fopen(cfgFileName,"r+");
		if(fpCfg == NULL)
		{
			if( debug ==1 )	
			{
					fprintf(fpDebug, "\n%s:3.2.2:  prompt the user for \'Do you want add the dependent Prpgram\' ",pgmnm); fflush(fpDebug);
			}
			inp=alert("Do you want add the dependent Prpgram[ Y/N]");
			if(inp == 'Y')
			{
				if ( debug  ==1 )
				{
						fprintf(fpDebug, "\n%s:3.2.2.1  if user entered as \'Y\' ",pgmnm); fflush(fpDebug);
				}

				fpCfg=fopen(cfgFileName,"w+");
				if(fpDebug == NULL)
				{
					alert("Unable to open the file for add links ");
					return 1;
				}
				if ( debug  ==1 )
				{
						fprintf(fpDebug, "\n%s:3.2.2.1.2  add the compiler version and os details ",pgmnm); fflush(fpDebug);
				}
				fprintf(fpCfg,"%s %s %s",pgmTyp,version,os);
				movexy(10,11);
				movexy(4,11);
						printf("Please Enter link object or lib files  [ To stop add file \"exit\"]\n");
				if ( debug  ==1 )
				{
						fprintf(fpDebug, "\n%s:3.2.2.1.2.1i while program name as entered exit get the file name ",pgmnm); fflush(fpDebug);
				}
				while(1)
				{
					memset(outFile,0x00,sizeof(outFile));
					if ( debug  ==1 )
					{
					fprintf(fpDebug, "\n%s:3.2.2.1.2.1 get program name",pgmnm); fflush(fpDebug);
					}
					getLinkFiles(outFile,outFileExtn);
					//scanf("%s",outFile);
					if(strcmp(outFile,"exit") == 0 )
					{
						break;
					}
					printf("Type :");
					scanf("%s",inpFileTypes);
					
					fprintf(fpCfg,"\n%s %s",outFile,inpFileTypes);
					
				}
				fclose(fpCfg);

				system("printf \"\033c\"");
				fpCfg=fopen(cfgFileName,"r+");
				if(fpCfg == NULL)
				{
					printf("Unable to open the file for add links ");
					return 1;
				}
				//Repeating the code again
				/*[==
				memset(outFile,0x00,sizeof(outFile));
				while(fgets(cfgFileNameBuff,750,fpCfg) != NULL )
				{
					sprintf(userLink,"%s ",strcat(userLink,cfgFileNameBuff));
				}			
				fclose(fpCfg);
				==]*/
			}
						
		}
		else
		{
		if( debug ==1)	
		{
				fprintf(fpDebug, "\n%s:A.004: file pointer is not null ",pgmnm); fflush(fpDebug);
		}
		}

	
		memset(outFile,0x00,sizeof(outFile));
		if( debug ==1)	
		{
				fprintf(fpDebug, "\n%s:A.004.01: strat read the config file ",pgmnm); fflush(fpDebug);
		}
		while(fgets(cfgFileNameBuff,750,fpCfg) != NULL )
		{
			if( debug ==1)	
			{
					fprintf(fpDebug, "\n%s:A.004: Read  line from  config file  ",pgmnm); fflush(fpDebug);
			}
			line = line +1;
			rmEntrChr(cfgFileNameBuff);
			if( line == 1 )	
			{
				if( debug ==1)	
				{
						fprintf(fpDebug, "\n%s:A.005:Frame the version string  ",pgmnm); fflush(fpDebug);
				}
				sprintf(givnTmpVer,"%s %s %s",pgmTyp,version,os);	
				if( debug ==1)	
				{
						fprintf(fpDebug, "\n%s:A.005.01:After Frame the version string:givnTmpVer <%s>  ",pgmnm,givnTmpVer); fflush(fpDebug);
				}
			//	sprintf(givnTmpVer,"%s %s %s" ,pgmTyp,version,os);
				if( debug ==1)	
				{
						fprintf(fpDebug, "\n%s:A.005.02:before compare :cfgFileNameBuff <%s>  ",pgmnm,cfgFileNameBuff); fflush(fpDebug);
				}
				if (strcmp(cfgFileNameBuff,givnTmpVer ) != 0 )
				{

					sprintf(tmp_msg,"compilation version is differed <%s> ",cfgFileNameBuff);
					alert(tmp_msg);
					return 1;
				}
				continue;
			}
			memset(tmpCfgFileNameBuff,0x00,sizeof(tmpCfgFileNameBuff));
			if( debug ==1)	
			{
				fprintf(fpDebug, "\n%s:A.006: parse the config file: line  <%d> cfgFileNameBuff  <%s>  ",pgmnm,line,cfgFileNameBuff); fflush(fpDebug);
			}
			strcpy(tmpCfgFileNameBuff,cfgFileNameBuff);
			if( debug ==1)	
			{
				fprintf(fpDebug, "\n%s:A.006.01:  tmpCfgFileNameBuff  <%s> ",pgmnm,tmpCfgFileNameBuff); fflush(fpDebug);
			}

			reVarCharComp=strchr(tmpCfgFileNameBuff,' ');	
			f_pos=reVarCharComp-tmpCfgFileNameBuff +1;
			memset(subPgmName,0x00,sizeof(subPgmName));
			strncpy(subPgmName,tmpCfgFileNameBuff,f_pos-1);
			strcpy(tmpCfgFileNameBuff,cfgFileNameBuff + f_pos);
			if( debug ==1)	
			{
				fprintf(fpDebug, "\n%s:A.006.01:  tmpCfgFileNameBuff  <%s> ",pgmnm,tmpCfgFileNameBuff); fflush(fpDebug);
			}
			strcpy(subPgmType,cfgFileNameBuff + f_pos);


/*--
			reVarCharComp=strchr(tmpCfgFileNameBuff ,' ');	
			f_pos=reVarCharComp-tmpCfgFileNameBuff +1;
			memset(subPgmType,0x00,sizeof(subPgmType));
			strncpy(subPgmType,tmpCfgFileNameBuff,f_pos);
			printf("###  subPgmType %s ",subPgmType);
--*/
			printf("###  subPgmType %s ",subPgmType);
			memset(tmpSubPgmType,0x00,sizeof(tmpSubPgmType));
			
			if(strcmp(subPgmType, "OBJ") == 0 )	
			{
				sprintf(tmpSubPgmType, " ~/obj/%s.o ",subPgmName);
			}
/*--
			if(strcmp(subPgmType, "H") == 0 )	
			{
			sprintf(tmpSubPgmType, "-I~/include/ ",subPgmName);
			}
--*/
			sprintf(userLink,"%s ",strcat(userLink,tmpSubPgmType));
			
		}			
			if( debug ==1)	
			{
				fprintf(fpDebug, "\n%s:A.007:final link string : userLink  <%s>  ",pgmnm,userLink); fflush(fpDebug);
			}
		fclose(fpCfg);
		drawWin();
		 
		if(strcmp(pgmTyp,"PC")== 0)
		{
			fprintf(fpDebug, "\n COMPMAIN002: process the PRO*C compilation  "); fflush(fpDebug);
			
			sprintf(exec_str,"proc %s include=$HOME/include 1> %s.proc 2>%s.err",pgmnm,pgmnm,pgmnm);
			fprintf(fpDebug,"\n cfgFileName= <%s>", cfgFileName);
			fprintf(fpDebug,"\n %s",exec_str);
			exec_rslt=system(exec_str);
			if(exec_rslt== 0)
			{

				show_status("Successful");
				alert(" proc is compiled ");
			}
			else
			{
				fclose(fpDebug);	
				show_status("Unsuccessful");
				inp=alert("Do u want see errlog [Y/N] :");
				if(inp == 'Y')
				{
					system(exec_errFile);	
				}
				return 1;	
			}
		}
		
		if(strcmp(pgmTyp,"C")== 0 || strcmp(pgmTyp,"PC")== 0)
		{
			show_status(" C compilation Running");
			/*********************************
			 C compilation 
			 **********************************/
			memset(exec_str,0x00,sizeof(exec_str));
			memset(exec_errFile,0x00,sizeof(exec_errFile));
			sprintf(exec_errFile,"vi %s.err",pgmnm );
			//sprintf(exec_str,"cl %s.c %s %s %s %s %s 1>%s.err 2>%s.log ",pgmnm,userLink,sqlInclude,tibcoInclude,sqlLib,tibcoLib,pgmnm,pgmnm);
			rmEntrChr(exec_str);
			//sprintf(exec_str,"cc %s.c %s %s %s %s %s 1>%s.log 2>%s.err ",pgmnm,userLink,sqlInclude,tibcoInclude,sqlLib,tibcoLib,pgmnm,pgmnm);
			sprintf(exec_str,"gcc -m64  %s.c %s %s %s %s %s -o ~/bin/%s 1>%s.log 2>%s.err ",pgmnm,userLink,sqlInclude,tibcoInclude,sqlLib,tibcoLib,pgmnm,pgmnm,pgmnm);
			fprintf(fpDebug,"\n %s",exec_str);
			exec_rslt=system(exec_str);
			if(exec_rslt== 0)
			{
				show_status(" C Successful");
			}
			else
			{
				
				fclose(fpDebug);	
				show_status("Unsuccessful ");
				inp=alert("Do u want see errlog [Y/N] :");
				if(inp == 'Y')
				{
					system(exec_errFile);	
				}
				return 1;	
			}
		}
		if(strcmp(pgmTyp,"CPP")== 0)
		{
			show_status(" C compilation Running");
			/*********************************
			 C compilation 
			 **********************************/
			memset(exec_str,0x00,sizeof(exec_str));
			memset(exec_errFile,0x00,sizeof(exec_errFile));
			sprintf(exec_errFile,"vi %s.err",pgmnm );
			//sprintf(exec_str,"cl %s.c %s %s %s %s %s 1>%s.err 2>%s.log ",pgmnm,userLink,sqlInclude,tibcoInclude,sqlLib,tibcoLib,pgmnm,pgmnm);
			rmEntrChr(exec_str);
			//sprintf(exec_str,"cc %s.c %s %s %s %s %s 1>%s.log 2>%s.err ",pgmnm,userLink,sqlInclude,tibcoInclude,sqlLib,tibcoLib,pgmnm,pgmnm);
			sprintf(exec_str,"g++ -m64  %s.cpp %s %s %s %s %s -o ~/bin/%s 1>%s.log 2>%s.err ",pgmnm,userLink,sqlInclude,tibcoInclude,sqlLib,tibcoLib,pgmnm,pgmnm,pgmnm);
			fprintf(fpDebug,"\n %s",exec_str);
			exec_rslt=system(exec_str);
			if(exec_rslt== 0)
			{
				show_status(" CPP Successful");
			}
			else
			{
				
				fclose(fpDebug);	
				show_status("Unsuccessful ");
				inp=alert("Do u want see errlog [Y/N] :");
				if(inp == 'Y')
				{
					system(exec_errFile);	
				}
				return 1;	
			}
		}
	}
	else 
	{
		printf("%s  <filename.extn>",argv[0]);
		getchar();
	}

	if(exec_rslt== 0)
	{
		show_status("Successful ");
	}
	else
	{
		fclose(fpDebug);	
		show_status("Unsuccessful\n");
		return 1;	
	}
	movexy(24,1);
	fclose(fpDebug);	
}

int drawWin()
{
		system("printf \"\033c\"");
		rect( 2,2,23,78);
		
		movexy(3,23);	
		printf("[92mHE[37mAERIE   [0mCompiler [0m [9m %-10.10s [0m",version);
		movexy(5,3);	
		printf("[7mPROGRAM NAME :[0m [9m %-57.57s [0m",pgmnm);
		movexy(7,3);	
		printf("[7mPROGRAM TYPE :[0m [9m %-57.57s [0m",pgmTyp);

	return 0;
}
int rmEntrChr(char *inp)
{
	while(*inp)
	{
		if(*inp == '\n')
			*inp='\0';
		inp++;
	}
	return 0;
}
char* to_upper(char *inp)
{
	char *prev;
	prev = inp;
	while(*inp)
	{
		if((*inp >= 'a' )&& (*inp <= 'z') )
		{
				*inp= *inp -32;

		}
		inp++;
	}
	return prev;
}

char * getLinkFiles(char * outFile, char * outFileExtn)
{
	char inpFile[500];
	char *tmp;
	int a=0,b=0;
	if ( debug  ==1 )
	{
	fprintf(fpDebug, "\n%s:3.2.2.1.2.1i    while program name as entered exit get the file name",pgmnm); fflush(fpDebug);
	}

	
	
	while (1) {
		memset(inpFile,0x00,sizeof(inpFile));
		movexy(10,11);
		printf("\nPlease enter Link  Name :");
		scanf("%s",inpFile);
		if ( debug  ==1 )
		{
		fprintf(fpDebug, "\n%s:3.2.2.1.2.1     get program name : inpFile <%s>",pgmnm,inpFile); fflush(fpDebug);
		}
		
		printf("");
		a=strlen(inpFile);
		
		tmp=strstr(inpFile,".");
		
		if (tmp  != NULL) {
			b=strlen(tmp);
		}
		//printf("a= %d b=%d a-b=",a,b,a-b);
		//printf("\nb = %d\n",b);
		if(( b != 0 ) || (strcmp(inpFile, "exit") == 0))
		{
			
			strncpy(outFile,inpFile,a-b);
			strncpy(outFileExtn,inpFile+(a-b)+1,b);
		}
		else
		{
			//strcpy(inpFile,outFile);
			alert("Please provid with extension:");
			//getchar();
			continue;
			//strcpy(pgmTyp,"PC");
//			printf("\r Please Enter Program Type: ");
//			scanf("%s",pgmTyp);
			if ( debug  ==1 )
			{
				fprintf(fpDebug, "\n%s:3.2.2.1.2.2     get program Type : pgmTyp <%s>",pgmnm,pgmTyp); fflush(fpDebug);
			}
		}
		break;
		
		
	}
	
}

	

int valLang(char  *lang)
{
	char USSLang[] = "PC|C|LIB|JAVA|JAR|SQL|PLSQL|H";
	
	if( strstr(USSLang,lang)> 0)
	{
		alert("Lang is found");
		return 0;
	}
	else {
		alert("Lang is not found");
		return 1;
	}

	
}

show_status(char *status)
{
	movexy(5,45);	
	printf("[7m STATUS :[0m [9m %-20.20s [0m",status);
}
