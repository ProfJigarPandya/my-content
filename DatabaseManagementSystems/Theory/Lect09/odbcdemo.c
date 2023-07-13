/* Copyright (c) 2004, 2008, Oracle and/or its affiliates. All rights reserved.*/

/*

   NAME
     odbcdemo.c - odbc demo file

   DESCRIPTION
     odbc demo file that does the connect, insert and fetching
     of the data
     This file is the superset of connect,insert1,
     insert2 and select demos

   EXPORT FUNCTION(S)
     <external functions defined for use outside package - 
     one-line descriptions>

   INTERNAL FUNCTION(S)
     <other external functions defined - one-line descriptions>

   STATIC FUNCTION(S)
     <static functions defined - one-line descriptions>

   NOTES
     <other useful comments, qualifications, etc.>

   MODIFIED   (MM/DD/YY)
   mvasudev    10/06/08 - Add 64 bit flags
   sprabhak    02/20/08 - Fix bug 6800511 
   sprabhak    11/05/07 - Fix bug 6598705
   mvasudev    07/24/07 - Set the ODBC Version
   sprabhak    11/05/05 - Generalize error handling routine
   sprabhak    10/13/05 - Error Handling
   rpingte     10/03/05 - rpingte_linux_final_db_parms
   ardesai     03/04/05 - Include windows.h for windows platform.
   subanerj    06/06/04 - subanerj_odbc_env_setup
   ardesai     06/02/04 - Creation

*/

#ifdef WIN32COMMON
#include <windows.h>
#endif
#include <stdio.h>
#include <sql.h>
#include <sqlext.h>

#define  STR_LEN 50

HENV        henv;                      /* environment handle */
HDBC        hdbc;                      /* connection handle  */
HSTMT       hstmt;                     /* statement handle   */

void freehdls();
static int printSQLError (long handletype, SQLHANDLE handle);

int main()
{
  SDWORD      retcode;                   /* return code        */
  SQLCHAR     *stmt ="insert into departments(department_id, department_name) values (?,?)";
  SQLCHAR     deptname[STR_LEN];
  SQLUINTEGER deptid;
  SQLCHAR     SqlState[6], Msg[SQL_MAX_MESSAGE_LENGTH];
  SQLINTEGER  NativeError;
  SQLSMALLINT MsgLen;
  #ifdef _WIN64
  SQLLEN dnind,diind;
  SQLLEN deptnameInd=SQL_NTS, deptidInd=0;
  #elif BUILD_REAL_64_BIT_MODE
  SQLLEN dnind,diind;
  SQLLEN deptnameInd=SQL_NTS, deptidInd=0;
  #else
  SQLINTEGER dnind,diind;
  SQLINTEGER deptnameInd=SQL_NTS, deptidInd=0;
  #endif
  printf("Allocating Environment handle...");
  retcode = SQLAllocEnv(&henv);
  if (retcode != SQL_SUCCESS)
    printSQLError(1, henv);
  else
    printf(" success\n");
    retcode = SQLSetEnvAttr (henv, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3,
              SQL_IS_INTEGER);
  if (retcode != SQL_SUCCESS)
    printSQLError(1, henv); 
  printf("Allocating Connection handle...");
  retcode = SQLAllocConnect(henv, &hdbc);
  if (retcode != SQL_SUCCESS)
    printSQLError(1, henv);
  else
    printf(" success\n");
  

  printf("Connecting to database using DSN...");
  retcode = SQLConnect(hdbc, "TestDBDSN", SQL_NTS, "hr", SQL_NTS, "hr",
                       SQL_NTS);
  if (retcode != SQL_SUCCESS)
    printSQLError(2, hdbc);
  else
    printf(" success\n");

  printf("Allocating Statement  handle...");
  retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
  if (retcode != SQL_SUCCESS)
    printSQLError(2, hdbc);
  else
    printf(" success\n");

  printf("Fetching department data\n");
  printf("Binding Column-1...");
  if ((retcode = SQLBindCol(hstmt, 1, SQL_C_ULONG, &deptid, 0, 
                 &diind)) != SQL_SUCCESS)
    printSQLError(3, hstmt);
  else
    printf(" success\n");

  printf("Binding Column-2...");
  if ((retcode = SQLBindCol(hstmt, 2, SQL_C_CHAR, deptname, sizeof(deptname), 
                 &dnind)) != SQL_SUCCESS)
    printSQLError(3, hstmt);
  else
    printf (" success\n");

  printf("Executing Statement...");
  if ((retcode = SQLExecDirect(hstmt, 
                 "select department_id, department_name from departments", 
                 SQL_NTS)) != SQL_SUCCESS)
  {
    printSQLError (3, hstmt);
    exit(1);
  }
  else
    printf (" success\n");

  while ((retcode = SQLFetch(hstmt)) != SQL_NO_DATA )
  {
    if (diind == SQL_NULL_DATA)
      printf("Department ID = NULL\n");
    else
      printf("Department ID = %ld, ",deptid);

    if (dnind == SQL_NULL_DATA)
      printf("Department Name = NULL\n");
    else
      printf("Department Name = %s\n",deptname);
  }
  retcode = SQLCloseCursor (hstmt);
  printf("Preparing insert statement...");
  if ((retcode =  SQLPrepare(hstmt, stmt, SQL_NTS)) != SQL_SUCCESS)
    printSQLError(3, hstmt);
  else
    printf(" success\n");
      
  printf("Binding parameter-1...");
  if ((retcode = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_ULONG,
                      SQL_INTEGER, 4, 0,  &deptid, sizeof(deptid), 
                      &deptidInd)) != SQL_SUCCESS)
    printSQLError(3, hstmt);
  else
    printf(" success\n");
 
  printf("Binding parameter-2...");
   if ((retcode = SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR,
                      SQL_VARCHAR, 0, 0, &deptname[0], 30, &deptnameInd))
                       != SQL_SUCCESS)
    printSQLError(3, hstmt);
  else
    printf(" success\n");

  /* Bind Data */
  deptid = 1024; 
  strcpy (deptname, "ODBC Test Development");
 
  printf("Executing insert statement for values...\n");
  printf("Department ID = %ld, Department Name = %s\n", deptid, deptname);

  if ((retcode = SQLExecute(hstmt)) != SQL_SUCCESS)
  {
    printSQLError(3, hstmt);
    exit(1);
  }
  else
    printf("Success\n");

  SQLEndTran(SQL_HANDLE_ENV, henv, SQL_COMMIT);

  /* Free all handles */
  freehdls();

  return 0;
}

int printSQLError (long handletype, SQLHANDLE handle)
{   
  SQLSMALLINT errRecNo = 1;
  SQLSMALLINT arg_handleType;
  SQLCHAR errSQLStateBuf[256];
  SQLINTEGER errCode = 0;
  SQLCHAR errMsgBuf[256]; 
  SQLSMALLINT errMsgBufLen = 256;
  SQLSMALLINT errInfoSize;
  long retcode;

  memset (errSQLStateBuf, 0x00, sizeof (errSQLStateBuf));
  memset (errMsgBuf, 0x00, sizeof (errMsgBuf));

  if (handletype == 1)
  {
    arg_handleType = SQL_HANDLE_ENV;
  }
  if (handletype == 2)
  {
    arg_handleType = SQL_HANDLE_DBC;
  }
  if (handletype == 3)
  {
    arg_handleType = SQL_HANDLE_STMT;
  }
  retcode = SQLGetDiagRec (arg_handleType, handle, errRecNo,
               errSQLStateBuf, &errCode, errMsgBuf, errMsgBufLen,
               &errInfoSize);

  if (SQL_NO_DATA_FOUND != retcode)
    printf ("errCode:%d errSQLStateBuf:%s\n errMsg:%s\n", errCode,
        errSQLStateBuf, errMsgBuf);
  errRecNo++;

  /* Free all handles */
  freehdls();

  return 0;
}

/*Freeing handles*/
void freehdls()
{
  if (hstmt)  
  {
    SQLFreeStmt(hstmt, SQL_CLOSE);
  }
  if (hdbc)
  {
    SQLDisconnect(hdbc);
    SQLFreeConnect(hdbc);
  }
  if (henv)
  {
    SQLFreeEnv(henv);
  }
}

/* end of file odbcdemo.c */

