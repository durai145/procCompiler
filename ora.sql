--File	Owner
--  tomg.scr generated version 1.2
--  All Copyright are Reserved (c) Heaerie Global Solutions Ltd.Vellore
  set echo on
  set feedback  on
  set serveroutput  on
  spool ora.log
  alter session set current_schema = c##DBHSP;


 drop  table mydb_timestamps ; 

 create table mydb_timestamps ( 
    create_time  VARCHAR     default CURRENT_TIMESTAMP 
 ,  update_time  VARCHAR      
  );


 drop  table mydb_MMM001MB ; 

 create table mydb_MMM001MB ( 
    MKR_ID  NUMBER      
 ,  DT_CREATED  TIMESTAMP      
 ,  ATH_ID  NUMBER      
 ,  DT_MODIFIED  TIMESTAMP      
 ,  PAGE_ID  NUMBER      
 ,  ACCESS_GROUP  VARCHAR (45)     
 ,  ACCESS_LEVEL  VARCHAR (45)     
 ,  CRIT_SJSON  VARCHAR (45)     
 ,  DTIL_SJSON  VARCHAR (45)     
 ,  RSLT_SJSON  VARCHAR (45)     
 ,  CRIT_PROC  VARCHAR (45)     
 ,  DTIL_PROC  VARCHAR (45)     
 ,  RSLT_PROC  VARCHAR (45)     
 ,  BASE_URL  VARCHAR (45)     
 ,  ACTIVE_ST  VARCHAR (45)     
  );


 drop  table C##DBHSP.DBER001MB ; 

 create table C##DBHSP.DBER001MB ( 
    ERR_CODE  VARCHAR (10)     
 ,  ERR_DESC  VARCHAR (200)     
 ,  ERROR_PAGE  VARCHAR (100)     
 ,  ERROR_TEXT  VARCHAR (40000)     
 ,  MKR_ID  NUMBER (11)     
 ,  DT_MODIFIED  DATE      
 ,  PROD_ID  NUMBER (11)     
 ,  GRP_ID  NUMBER (11)     
 ,  PAGE_GRP_ID  NUMBER (11)     
 ,  PAGE_ID  NUMBER (11)     
 ,  USR_ID  NUMBER (11)    default NULL 
  );


 drop  table C##DBHSP.PROD001MB ; 

 create table C##DBHSP.PROD001MB ( 
    PROD_ID  NUMBER (10)  not null   
 ,  PROD_NAME  VARCHAR (45)     
 ,  PROD_VERSION  VARCHAR (45)     
 ,  PROD_ST_DT  VARCHAR (45)     
 ,  MKR_ID  NUMBER      
 ,  DT_CREATED  TIMESTAMP      
 ,  ATH_ID  NUMBER      
 ,  DT_MODIFIED  TIMESTAMP      
 ,  DBNAME  VARCHAR (45)     
 ,  HOSTNAME  VARCHAR (45)     
 ,  BASE_HOME  VARCHAR (45)     
 ,  PORT  VARCHAR (45)     
 ,  PROTOCAL  VARCHAR (45)     
  );


 drop  table C##DBHSP.PRTL002MB ; 

 create table C##DBHSP.PRTL002MB ( 
    PROD_ID  NUMBER (10)  not null   
 ,  PRTL_ID  NUMBER (10)  not null   
 ,  PRTL_NAME  VARCHAR (45)     
 ,  PRTL_VERSION  VARCHAR (45)     
 ,  PRTL_ST  VARCHAR (15)     
 ,  PRTL_ST_DT  TIMESTAMP      
 ,  DBNAME  VARCHAR (45)     
 ,  HOSTNAME  VARCHAR (45)     
 ,  BASE_HOME  VARCHAR (45)     
 ,  PORT  VARCHAR (45)     
 ,  PROTOCAL  VARCHAR (45)     
 ,  MKR_ID  VARCHAR (45)     
 ,  DT_CREATED  VARCHAR (45)     
 ,  ATH_ID  VARCHAR (45)     
 ,  DT_MODIFIED  VARCHAR (45)     
  );


 drop  table C##DBHSP.GRP001MB ; 

 create table C##DBHSP.GRP001MB ( 
    PRTL_ID  NUMBER (11)     
 ,  GRP_ID  NUMBER (11)  not null   
 ,  GRP_NAME  VARCHAR (60)     
 ,  CUR_BAL  NUMBER (25,4)     
 ,  MAX_PEND_AMT  NUMBER (25,4)     
 ,  MAX_LEDGER  NUMBER (25,4)     
 ,  PASSWORD  VARCHAR (60)     
 ,  LAST_LOGIN  DATE      
 ,  MAX_PEND_Q_CNT  NUMBER (11)     
 ,  MAX_APVD_Q_CNT  NUMBER (11)     
 ,  LANG  VARCHAR (60)     
 ,  MAX_USR_CNT  NUMBER (11)     
 ,  DT_CREATED  DATE      
 ,  DT_MODIFIED  DATE      
 ,  MKR_ID  NUMBER (11)     
 ,  ATH_ID  NUMBER (11)     
 ,  STATUS  VARCHAR (60)     
  );


 drop  table C##DBHSP.GID001MB ; 

 create table C##DBHSP.GID001MB ( 
    USR_ID  NUMBER (11)  not null   
 ,  GRP_ID  NUMBER (11)  not null   
 ,  F_NAME  VARCHAR (60)     
 ,  L_NAME  VARCHAR (60)     
 ,  EMAIL_ID  VARCHAR (60)     
 ,  PASSWORD  VARCHAR (60)     
 ,  LAST_LOGIN  DATE      
 ,  LANG  VARCHAR (60)     
 ,  DT_CREATED  DATE      
 ,  DT_MODIFIED  DATE      
 ,  MKR_ID  NUMBER (11)     
 ,  ATH_ID  NUMBER (11)     
 ,  STATUS  VARCHAR (60)     
 ,  ADMIN_FLG  VARCHAR (45)     
  );


 drop  table C##DBHSP.GID001TB ; 

 create table C##DBHSP.GID001TB ( 
    USR_ID  NUMBER (11)  not null   
 ,  F_NAME  VARCHAR (60)     
 ,  L_NAME  VARCHAR (60)     
 ,  EMAIL_ID  VARCHAR (60)     
 ,  CUR_BAL  NUMBER (25,4)     
 ,  PEND_AMT  NUMBER (25,4)     
 ,  LEDGER  NUMBER (25,4)     
 ,  ACCT_TYPE  VARCHAR (60)     
 ,  PASSWORD  VARCHAR (60)     
 ,  LAST_LOGIN  DATE      
 ,  PEND_Q_CNT  NUMBER (11)     
 ,  APVD_Q_CNT  NUMBER (11)     
 ,  GRP_ID  NUMBER (11)     
 ,  LANG  VARCHAR (60)     
 ,  DT_CREATED  DATE      
 ,  DT_MODIFIED  DATE      
 ,  MKR_ID  NUMBER (11)     
 ,  ATH_ID  NUMBER (11)     
 ,  STATUS  VARCHAR (60)     
 ,  OTPE  VARCHAR (120)     
 ,  OTP  VARCHAR (12)     
  );


 drop  table C##DBHSP.GRBL001MB ; 

 create table C##DBHSP.GRBL001MB ( 
    PEND_Q_CNT  NUMBER (11)     
 ,  APVD_Q_CNT  NUMBER (11)     
 ,  GRP_ID  NUMBER (11)  not null   
 ,  HOLD_AMT  NUMBER (11)     
 ,  HOLD_CNT  NUMBER (11)     
 ,  SPL_HOLD_AMT  NUMBER (11)     
 ,  SPL_HOLD_CNT  NUMBER (11)     
 ,  DT_CREATED  TIMESTAMP      
 ,  MKR_ID  TIMESTAMP      
 ,  DT_MODIFIED  VARCHAR (45)     
 ,  ATH_ID  VARCHAR (45)     
 ,  LAST_LOGON  TIMESTAMP      
  );


 drop  table C##DBHSP.GRP001TB ; 

 create table C##DBHSP.GRP001TB ( 
    GRP_ID  NUMBER (11)     
 ,  GRP_NAME  VARCHAR (60)     
 ,  LEDGER  NUMBER (25,4)     
 ,  PASSWORD  VARCHAR (60)     
 ,  LAST_LOGIN  DATE      
 ,  LANG  VARCHAR (60)     
 ,  DT_CREATED  DATE      
 ,  DT_MODIFIED  DATE      
 ,  MKR_ID  NUMBER (11)     
 ,  ATH_ID  NUMBER (11)     
 ,  STATUS  VARCHAR (60)    default NULL 
  );


 drop  table C##DBHSP.GTRN002MB ; 

 create table C##DBHSP.GTRN002MB ( 
    GRP_ID  NUMBER (11)     
 ,  GBKT_TXN_ID  NUMBER (11)  not null   
 ,  TRAN_ST  VARCHAR (1)     
 ,  DR_AMT  NUMBER (25,4)     
 ,  CR_AMT  NUMBER (25,4)     
 ,  PND_CR_AMT  NUMBER (25,4)     
 ,  PND_DR_AMT  NUMBER (25,4)     
 ,  DT_CREATED  DATE      
 ,  MKR_ID  NUMBER (11)     
 ,  DT_MODIFIED  NUMBER (25,4)     
 ,  ATH_ID  NUMBER (11)     
 ,  DESCR  VARCHAR (300)     
 ,  BILL_AMT  NUMBER (25,4)     
 ,  BILL_DT  DATE      
 ,  CARD_NUM  NUMBER (11)     
 ,  SHARE_CNT  NUMBER (25,4)     
 ,  BILL_REF  VARCHAR (300)     
 ,  BANK  VARCHAR (300)     
 ,  PAY_MD  VARCHAR (300)     
 ,  STMT_ID  NUMBER (11)     
 ,  TRAN_TYPE  VARCHAR (45)     
  );


 drop  table C##DBHSP.LGNL001HT ; 

 create table C##DBHSP.LGNL001HT ( 
    BRWSR_NAME  VARCHAR (50)     
 ,  DEVICE  VARCHAR (45)     
 ,  OS  VARCHAR (45)     
 ,  LOGIN_DATE  TIMESTAMP      
 ,  LOGOUT_DATE  TIMESTAMP      
 ,  LOGIN_STATUS  VARCHAR (25)     
 ,  LOGIN_DESRC  VARCHAR (100)     
 ,  CLIENT_IP  VARCHAR (45)     
 ,  CLIENT_HOST  VARCHAR (45)     
 ,  GEO_COUNTRY  VARCHAR (120)     
 ,  LANG  NUMBER (11)     
 ,  USR_ID  NUMBER (11)     
 ,  GRP_ID  NUMBER (11)     
 ,  PROD_ID  NUMBER (11)     
 ,  GEO_CITY  VARCHAR (60)     
 ,  GEO_DTL  VARCHAR (1000)     
 ,  GEO_REGION  VARCHAR (60)     
 ,  DT_CREATED  TIMESTAMP      
 ,  MKR_ID  NUMBER      
 ,  DT_MODIFIED  TIMESTAMP      
 ,  ATH_ID  NUMBER      
  );


 drop  table C##DBHSP.ROLA003MB ; 

 create table C##DBHSP.ROLA003MB ( 
    GRP_ID  NUMBER (11)     
 ,  ROLE_ID  NUMBER (11)     
 ,  ROLE_NAME  VARCHAR (300)     
 ,  ROLE_ACCESS  VARCHAR (300)     
 ,  DT_CREATED  DATE      
 ,  DT_MODIFIED  DATE      
 ,  MKR_ID  NUMBER (11)     
 ,  ATH_ID  NUMBER (11)     
  );


 drop  table C##DBHSP.MEMA001MB ; 

 create table C##DBHSP.MEMA001MB ( 
    ROLE_ID  NUMBER (11)  not null   
 ,  USR_ID  NUMBER (11)     
 ,  ACCESS_IND  VARCHAR (45)     
 ,  DT_CREATED  TIMESTAMP      
 ,  MKR_ID  NUMBER (11)     
 ,  DT_MODIFIED  TIMESTAMP      
 ,  ATH_ID  NUMBER (11)     
  );


 drop  table C##DBHSP.ROLE001MB ; 

 create table C##DBHSP.ROLE001MB ( 
    PRTL_ID  NUMBER (11)     
 ,  ROLE_ID  VARCHAR (45)     
 ,  ROLE_NAME  VARCHAR (45)     
 ,  STATUS  VARCHAR (45)     
 ,  DT_CREATED  TIMESTAMP      
 ,  DT_MODIFIED  TIMESTAMP      
 ,  MKR_ID  NUMBER      
 ,  ATH_ID  NUMBER      
  );


 drop  table C##DBHSP.PDPG002MB ; 

 create table C##DBHSP.PDPG002MB ( 
    PROD_ID  NUMBER (11)  not null   
 ,  PROD_PAGE_GRP_ID  NUMBER (11)     
 ,  ACESS_IND  VARCHAR (2)     
 ,  DT_CREATED  VARCHAR (45)     
 ,  MKR_ID  VARCHAR (45)     
 ,  DT_MODIFIED  VARCHAR (45)     
 ,  ATH_ID  VARCHAR (45)     
  );


 drop  table C##DBHSP.PERSON ; 

 create table C##DBHSP.PERSON ( 
    PERSON_ID  NUMBER (11)     
 ,  MAX_NUM  NUMBER (11)     
 ,  PER_1_NAME  VARCHAR (100)     
 ,  PER_2_NAME  VARCHAR (100)     
 ,  PER_3_NAME  VARCHAR (100)     
 ,  PER_4_NAME  VARCHAR (100)     
 ,  PER_5_NAME  VARCHAR (100)     
 ,  PER_6_NAME  VARCHAR (100)    default NULL 
  );


 drop  table C##DBHSP.PGDT006MB ; 

 create table C##DBHSP.PGDT006MB ( 
    PAGE_ID  NUMBER (11)  not null   
 ,  PAGE_BASE  VARCHAR (300)     
 ,  PAGE_KEY  VARCHAR (60)     
 ,  PAGE_NAME  VARCHAR (100)     
 ,  PAGE_TYPE  VARCHAR (1)     
 ,  AUTH_REQ_FLG  VARCHAR (1)     
 ,  DISP_ORDER  NUMBER (11)     
 ,  MENU  VARCHAR (45)     
 ,  CRIT_JSON  VARCHAR (45)     
 ,  DTIL_JSON  VARCHAR (45)     
 ,  RSLT_JSON  VARCHAR (45)     
 ,  URL  VARCHAR (45)     
 ,  CRIT_PROC  VARCHAR (45)     
 ,  DTIL_PROC  VARCHAR (45)     
 ,  RSLT_PROC  VARCHAR (45)     
 ,  STATUS  VARCHAR (45)     
 ,  DT_MODIFIED  TIMESTAMP      
 ,  DT_CREATED  TIMESTAMP      
 ,  ATH_ID  NUMBER (11)     
 ,  MKR_ID  NUMBER (11)    default NULL 
  );


 drop  table C##DBHSP.PGGR005MB ; 

 create table C##DBHSP.PGGR005MB ( 
    PRTL_PAGE_GRP_ID  NUMBER (11)  not null   
 ,  PRTL_ID  NUMBER      
 ,  PAGE_GRP_ID  VARCHAR (45)     
 ,  PAGE_GRP_TITLE  VARCHAR (45)     
 ,  DT_CREATED  TIMESTAMP      
 ,  MKR_ID  NUMBER      
 ,  DT_MODIFIED  TIMESTAMP      
 ,  ATH_ID  NUMBER      
 ,  PAGE_GRP_KEY  VARCHAR (45)     
  );


 drop  table C##DBHSP.PGPD009LB ; 

 create table C##DBHSP.PGPD009LB ( 
    PAGE_ID  NUMBER (11)     
 ,  PRTL_PAGE_GRP_ID  NUMBER (11)  not null   
 ,  ACCESS_IND  VARCHAR (45)    default 'N' 
 ,  MKR_ID  NUMBER      
 ,  DT_CREATED  TIMESTAMP      
 ,  ATH_ID  NUMBER      
 ,  DT_MODIFIED  TIMESTAMP      
  );


 drop  table C##DBHSP.RAPG004LB ; 

 create table C##DBHSP.RAPG004LB ( 
    ROLE_PAGE_ID  VARCHAR (45)     
 ,  PAGE_GRP_ID  NUMBER (11)     
 ,  PRTL_PAGE_GRP_ID  NUMBER (11)     
 ,  ROLE_ID  NUMBER (11)  not null   
 ,  I  VARCHAR (45)     
 ,  DT_CREATED  TIMESTAMP      
 ,  MKR_ID  NUMBER      
 ,  DT_MODIFIED  TIMESTAMP      
 ,  ATH_ID  NUMBER      
  );


 drop  table C##DBHSP.PGRL010LB ; 

 create table C##DBHSP.PGRL010LB ( 
    ROLE_PAGE_ID  NUMBER (11)  not null   
 ,  PAGE_ID  NUMBER (11)     
 ,  ACCESS_IND  VARCHAR (45)     
 ,  DT_CREATED  TIMESTAMP      
 ,  MKR_ID  NUMBER (11)     
 ,  DT_MODIFIED  TIMESTAMP      
 ,  ATH_ID  NUMBER (11)     
  );


 drop  table C##DBHSP.CNTY001MB ; 

 create table C##DBHSP.CNTY001MB ( 
    PROD_ID  NUMBER      
 ,  COUNTRY_ID  VARCHAR (45)  not null   
 ,  COUNTRY_CODE  NUMBER (11)  not null   
 ,  COUNTRY_ISO  VARCHAR (45)  not null   
 ,  CURRENCY_CODE  VARCHAR (45)  not null   
 ,  CURRENCY_NAME  VARCHAR (45)     
 ,  TIMEZONE  VARCHAR (45)     
 ,  DST  VARCHAR (45)     
 ,  MKR_ID  VARCHAR (45)     
 ,  ATH_ID  VARCHAR (45)     
 ,  DT_CREATED  VARCHAR (45)     
 ,  DT_MODIFIED  VARCHAR (45)     
 ,  STATUS  VARCHAR (45)     
  );


 drop  table C##DBHSP.REGISTERED_MEMBERS ; 

 create table C##DBHSP.REGISTERED_MEMBERS ( 
    ID  NUMBER (4)  not null   
 ,  NAME  VARCHAR (65)  not null   
 ,  EMAIL  VARCHAR (65)  not null   
 ,  PASSWORD  VARCHAR (65)  not null   
 ,  COUNTRY  VARCHAR (65)  not null   
  );


 drop  table C##DBHSP.SEQ ; 

 create table C##DBHSP.SEQ ( 
    NAME  VARCHAR (20)  not null   
 ,  VAL  NUMBER (10)    default NULL 
  );


 drop  table C##DBHSP.STMT001MB ; 

 create table C##DBHSP.STMT001MB ( 
    GRP_ID  NUMBER (11)     
 ,  DESCR  VARCHAR (30)     
 ,  STATUS  VARCHAR (10)     
 ,  DT_CREATED  DATE      
 ,  MKR_ID  NUMBER (11)     
 ,  DT_MODIFIED  DATE      
 ,  AUTH_ID  NUMBER (11)     
  );


 drop  table C##DBHSP.STMT002MB ; 

 create table C##DBHSP.STMT002MB ( 
    GRP_ID  NUMBER (11)     
 ,  USR_ID  NUMBER (11)     
 ,  STMT_ID  NUMBER (11)     
 ,  MON_BAL  NUMBER (25,4)     
 ,  MON_SPND  NUMBER (25,4)     
 ,  DESCR  VARCHAR (30)     
 ,  CREATED_DT  DATE      
 ,  MAKER_ID  NUMBER (11)     
 ,  MODIFIED_DT  DATE      
 ,  AUTH_ID  NUMBER (11)     
  );


 drop  table C##DBHSP.TRN003MB ; 

 create table C##DBHSP.TRN003MB ( 
    GRP_ID  NUMBER (11)     
 ,  GBKT_TXN_ID  NUMBER (11)     
 ,  TBKT_TXN_ID  NUMBER (11)     
 ,  USR_ID  NUMBER (11)     
 ,  TRAN_AMT  NUMBER (25,4)     
 ,  DR_CR_FLG  VARCHAR (1)     
 ,  VALUE_DT  DATE      
 ,  CRETED_DT  DATE      
 ,  MAKER_ID  NUMBER (11)     
 ,  MODIFIED_DT  DATE      
 ,  AUTH_ID  NUMBER (11)     
 ,  BUS_DT  DATE      
  );


 drop  table C##DBHSP._SEQUENCE ; 

 create table C##DBHSP._SEQUENCE ( 
    SEQ_NAME  VARCHAR (50)  not null   
 ,  SEQ_VAL  NUMBER (10)    default NULL 
  );


 drop  table C##DBHSP.STAT002MB ; 

 create table C##DBHSP.STAT002MB ( 
    STATE_ID  NUMBER (11)  not null   
 ,  COUNTRY_ID  NUMBER   not null   
 ,  STATE_CODE  VARCHAR (45)  not null   
 ,  STATE_NAME  VARCHAR (45)  not null   
 ,  TIMEZONE  VARCHAR (45)     
 ,  MKR_ID  VARCHAR (45)     
 ,  ATH_ID  VARCHAR (45)     
 ,  DT_CREATED  VARCHAR (45)     
 ,  DT_MODIFIED  VARCHAR (45)     
 ,  STATUS  VARCHAR (45)     
 ,  PROD_ID  NUMBER      
  );


 drop  table C##DBHSP.ADDR003MB ; 

 create table C##DBHSP.ADDR003MB ( 
    ADDR_ID  NUMBER   not null   
 ,  PROD_ID  NUMBER      
 ,  ADDR_TYPE  VARCHAR (45)     
 ,  ADDR_LINE1  VARCHAR (60)  not null   
 ,  ADDR_LINE2  VARCHAR (60)  not null   
 ,  ADDR_LINE3  VARCHAR (45)     
 ,  CITY  VARCHAR (45)     
 ,  ATH_ID  VARCHAR (45)     
 ,  STATE_ID  NUMBER (11)  not null   
 ,  COUNTRY_ID  VARCHAR (45)  not null   
 ,  DT_CREATED  VARCHAR (45)     
 ,  DT_MODIFIED  VARCHAR (45)     
 ,  STATUS  VARCHAR (45)     
 ,  USR_ID  NUMBER      
  );


 drop  table C##DBHSP.GIBL002MB ; 

 create table C##DBHSP.GIBL002MB ( 
    USR_ID  NUMBER      
 ,  CUR_BAL  NUMBER      
 ,  PEND_AMT  NUMBER      
 ,  PEND_Q_CNT  NUMBER      
 ,  APVD_Q_CNT  NUMBER      
 ,  LAST_LOGIN  DATE      
 ,  MKR_ID  NUMBER      
 ,  ATH_ID  NUMBER      
 ,  DT_CREATED  TIMESTAMP      
 ,  DT_MODIFIED  TIMESTAMP      
  );


 drop  table C##DBHSP.PGRL010LB ; 

 create table C##DBHSP.PGRL010LB ( 
    ROLE_PAGE_ID  NUMBER (11)  not null   
 ,  PAGE_ID  NUMBER (11)     
 ,  ACCESS_IND  VARCHAR (45)     
 ,  DT_CREATED  TIMESTAMP      
 ,  MKR_ID  NUMBER (11)     
 ,  DT_MODIFIED  TIMESTAMP      
 ,  ATH_ID  NUMBER (11)     
  );


 drop  table C##DBHSP.CNRY001MB ; 

 create table C##DBHSP.CNRY001MB ( 
    CNTRY_ID  NUMBER   not null   
 ,  ALPHA2  VARCHAR (45)     
 ,  ALPHA3  VARCHAR (45)     
 ,  CNTRY_NAME  VARCHAR (45)     
 ,  MKR_ID  NUMBER      
 ,  DT_CREATED  TIMESTAMP      
 ,  ATH_ID  NUMBER      
 ,  DT_MODIFIED  TIMESTAMP      
  );


 drop  table C##DBHSP.BCDT001MB ; 

 create table C##DBHSP.BCDT001MB ( 
    USR_ID  NUMBER   not null   
 ,  BODY_TYPE  VARCHAR (45)     
 ,  COMPLEXION  VARCHAR (45)     
 ,  PHYSICAL_ST  VARCHAR (45)     
 ,  HEIGHT  VARCHAR (45)     
 ,  WEIGHT  VARCHAR (45)     
 ,  MOTHER_TOUGE_ID  NUMBER      
 ,  MARITAL_ST  VARCHAR (45)     
 ,  EATING_HABIT  VARCHAR (45)     
 ,  DRINKING_HABIT  VARCHAR (45)     
 ,  SMOKING_HABIT  VARCHAR (45)     
 ,  RELIGION_ID  VARCHAR (45)     
 ,  CASTE_ID  VARCHAR (45)     
 ,  SUB_CASTE_ID  VARCHAR (45)     
 ,  GOTHRAM  VARCHAR (45)     
 ,  STAR  VARCHAR (45)     
 ,  RASI  VARCHAR (45)     
 ,  EDUCATION  VARCHAR (45)     
 ,  EDUCATION_DTL  VARCHAR (45)     
 ,  COUNTRY_ID  VARCHAR (45)     
 ,  RESIDENT_STATUS  VARCHAR (45)     
 ,  CITIZENSHIP  VARCHAR (45)     
 ,  CUR_EMPLOYEE  VARCHAR (45)     
 ,  ANUAL_INCOME  VARCHAR (45)     
 ,  RACE  VARCHAR (45)     
 ,  ETHNICITY  VARCHAR (45)     
 ,  FATHER_NAME  VARCHAR (45)     
 ,  MOTHER_NAME  VARCHAR (45)     
  );


 drop  table C##DBHSP.view1 ; 

 create table C##DBHSP.view1 ( 
  );


 drop  table C##DBHSP.view2 ; 

 create table C##DBHSP.view2 ( 
  );


 drop  table C##DBHSP.view3 ; 

 create table C##DBHSP.view3 ( 

 --INSERT 
 INSERT INTO C##DBHSP.PROD001MB (PROD_ID, PROD_NAME, PROD_VERSION, PROD_ST_DT, MKR_ID, DT_CREATED, ATH_ID, DT_MODIFIED, DBNAME, HOSTNAME, BASE_HOME, PORT, PROTOCAL) VALUES (1, 'HOMESPACE', '1', '21-Jun-2014', 1, '21-Jun-2014', 1, '21-Jun-2014', 'C##DBHSP', 'localhost', 'uss11.0.1', NULL, 'http'); 

 --INSERT 
 INSERT INTO C##DBHSP.PROD001MB (PROD_ID, PROD_NAME, PROD_VERSION, PROD_ST_DT, MKR_ID, DT_CREATED, ATH_ID, DT_MODIFIED, DBNAME, HOSTNAME, BASE_HOME, PORT, PROTOCAL) VALUES (NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL); 

 --INSERT 
 INSERT INTO C##DBHSP.PRTL002MB (PROD_ID, PRTL_ID, PRTL_NAME, PRTL_VERSION, PRTL_ST, PRTL_ST_DT, DBNAME, HOSTNAME, BASE_HOME, PORT, PROTOCAL, MKR_ID, DT_CREATED, ATH_ID, DT_MODIFIED) VALUES (1, 1, 'Product', '1', NULL, '21-Jun-2014', 'C##DBHSP', 'localhost', 'homespace', NULL, NULL, '1', '21-Jun-2014', '1', '21-Jun-2014'); 

 --INSERT 
 INSERT INTO C##DBHSP.GRP001MB (PRTL_ID, GRP_ID, GRP_NAME, CUR_BAL, MAX_PEND_AMT, MAX_LEDGER, PASSWORD, LAST_LOGIN, MAX_PEND_Q_CNT, MAX_APVD_Q_CNT, LANG, MAX_USR_CNT, DT_CREATED, DT_MODIFIED, MKR_ID, ATH_ID, STATUS) VALUES (1, 0, 'PRODUCT TEAM', 0, 0, 9, '0', NULL, NULL, NULL, 'ENG', 5, '01-JAN-2015', '01-JAN-2015', 0, 0, 'ACTIVE'); 

 --INSERT 
 INSERT INTO C##DBHSP.GRP001MB (PRTL_ID, GRP_ID, GRP_NAME, CUR_BAL, MAX_PEND_AMT, MAX_LEDGER, PASSWORD, LAST_LOGIN, MAX_PEND_Q_CNT, MAX_APVD_Q_CNT, LANG, MAX_USR_CNT, DT_CREATED, DT_MODIFIED, MKR_ID, ATH_ID, STATUS) VALUES (1, 1, 'TEST PRODCUCT', 0, 1000, 99999999, '1QAZ2WSX', NULL, NULL, NULL, 'ENG', 10, '01-JAN-2015', '01-JAN-2015', 0, 0, 'ACTIVE'); 

 --INSERT 
 INSERT INTO C##DBHSP.GID001MB (USR_ID, GRP_ID, F_NAME, L_NAME, EMAIL_ID, PASSWORD, LAST_LOGIN, LANG, DT_CREATED, DT_MODIFIED, MKR_ID, ATH_ID, STATUS, ADMIN_FLG) VALUES (1, 1, 'DURAIMURUGAN', 'GOVINDARAJ', 'durai145@live.in', '1qaz2wsx', '01-jan-2015', 'ENG', '01-jan-2015', '01-jan-2015', 0, 0, 'ACTIVE', 'Y'); 

 --INSERT 
 INSERT INTO C##DBHSP.GID001MB (USR_ID, GRP_ID, F_NAME, L_NAME, EMAIL_ID, PASSWORD, LAST_LOGIN, LANG, DT_CREATED, DT_MODIFIED, MKR_ID, ATH_ID, STATUS, ADMIN_FLG) VALUES (0, 0, 'SYSTEM', 'IMPLEMENTATION', 'system@myroomexpense.com', '1qaz2wsx', '01-jan-2015', 'ENG', '01-jan-2015', '01-jan-2015', 0, 0, 'ACTIVE', NULL); 

 --INSERT 
 INSERT INTO C##DBHSP.GID001MB (USR_ID, GRP_ID, F_NAME, L_NAME, EMAIL_ID, PASSWORD, LAST_LOGIN, LANG, DT_CREATED, DT_MODIFIED, MKR_ID, ATH_ID, STATUS, ADMIN_FLG) VALUES (2, 1, 'AGALYA', 'RAMADOSS', 'agalyadoss@gmial.com', '1qaz2wsx', '01-jan-2015', 'ENG', '01-jan-2015', '01-jan-2015', 0, 0, NULL, NULL); 

 --INSERT 
 INSERT INTO C##DBHSP.ROLA003MB (GRP_ID, ROLE_ID, ROLE_NAME, ROLE_ACCESS, DT_CREATED, DT_MODIFIED, MKR_ID, ATH_ID) VALUES (1, 1, 'SEC_ADMIN', 'Y', '01-jan-2015', '01-jan-2015', 1, 1); 

 --INSERT 
 INSERT INTO C##DBHSP.MEMA001MB (ROLE_ID, USR_ID, ACCESS_IND, DT_CREATED, MKR_ID, DT_MODIFIED, ATH_ID) VALUES (1, 1, 'Y', '01-jan-2015', 0, '0', 0); 

 --INSERT 
 INSERT INTO C##DBHSP.ROLE001MB (PRTL_ID, ROLE_ID, ROLE_NAME, STATUS, DT_CREATED, DT_MODIFIED, MKR_ID, ATH_ID) VALUES (1, '1', 'SEC_ADMIN', 'ACTIVE', '01-jan-2015', '01-jan-2015', 0, 0); 

 --INSERT 
 INSERT INTO C##DBHSP.ROLE001MB (PRTL_ID, ROLE_ID, ROLE_NAME, STATUS, DT_CREATED, DT_MODIFIED, MKR_ID, ATH_ID) VALUES (1, '2', 'PROD_USER', 'ACTIVE', '01-jan-2015', '01-jan-2015', 0, 0); 

 --INSERT 
 INSERT INTO C##DBHSP.PGDT006MB (PAGE_ID, PAGE_BASE, PAGE_KEY, PAGE_NAME, PAGE_TYPE, AUTH_REQ_FLG, DISP_ORDER, MENU, CRIT_JSON, DTIL_JSON, RSLT_JSON, URL, CRIT_PROC, DTIL_PROC, RSLT_PROC, STATUS, DT_MODIFIED, DT_CREATED, ATH_ID, MKR_ID) VALUES (1, 'homespace', 'DASHBOARD', 'DASHBOARD', 'INQURY', 'N', 1, 'DSBD001MM', 'dashboard_crit.json', 'dashboard_dtit.json', 'dashboard_rslt.json', 'jsonSchema/', 'dashboard_crit_prpc', 'dashboard_dtil_prpc', 'dashboard_rslt_prpc', 'ACTIVE', '21-Jun-2013', '21-Jun-2013', 1, 1); 

 --INSERT 
 INSERT INTO C##DBHSP.PGGR005MB (PRTL_PAGE_GRP_ID, PRTL_ID, PAGE_GRP_ID, PAGE_GRP_TITLE, DT_CREATED, MKR_ID, DT_MODIFIED, ATH_ID, PAGE_GRP_KEY) VALUES (1, 1, 'DASHBOARD', 'Dashboard', '21-Jun-2014', 1, '21-Jun-2014', 1, 'index.ejs'); 

 --INSERT 
 INSERT INTO C##DBHSP.PGPD009LB (PAGE_ID, PRTL_PAGE_GRP_ID, ACCESS_IND, MKR_ID, DT_CREATED, ATH_ID, DT_MODIFIED) VALUES (1, 1, 'Y', 1, sysdate, 1, sysdate); 

 --INSERT 
 INSERT INTO C##DBHSP.RAPG004LB (ROLE_PAGE_ID, PAGE_GRP_ID, PRTL_PAGE_GRP_ID, ROLE_ID, I, DT_CREATED, MKR_ID, DT_MODIFIED, ATH_ID) VALUES ('1', 1, 1, 1, 'Y', NULL, NULL, NULL, NULL); 
  );
 spool off

 spool off
--done
