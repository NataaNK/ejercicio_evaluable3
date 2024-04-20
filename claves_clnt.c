/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "claves_head.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
init_1(int *clnt_res, CLIENT *clnt)
{
	 return (clnt_call (clnt, INIT, (xdrproc_t) xdr_void, (caddr_t) NULL,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));

}

enum clnt_stat 
set_value_1(SetValueArgs arg1, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, SET_VALUE,
		(xdrproc_t) xdr_SetValueArgs, (caddr_t) &arg1,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
get_value_1(GetValueArgs arg1, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, GET_VALUE,
		(xdrproc_t) xdr_GetValueArgs, (caddr_t) &arg1,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
delete_key_1(int arg1, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, DELETE_KEY,
		(xdrproc_t) xdr_int, (caddr_t) &arg1,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
modify_value_1(SetValueArgs arg1, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, MODIFY_VALUE,
		(xdrproc_t) xdr_SetValueArgs, (caddr_t) &arg1,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
exist_1(int arg1, int *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, EXIST,
		(xdrproc_t) xdr_int, (caddr_t) &arg1,
		(xdrproc_t) xdr_int, (caddr_t) clnt_res,
		TIMEOUT));
}
