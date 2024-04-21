/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CLAVES_IU_H_RPCGEN
#define _CLAVES_IU_H_RPCGEN

#include <rpc/rpc.h>

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif


struct SetValueArgs {
	int key;
	char *value1;
	int N_value2;
	struct {
		u_int V_value2_len;
		double *V_value2_val;
	} V_value2;
};
typedef struct SetValueArgs SetValueArgs;

struct GetValueResponse {
	char *value1;
	int N_value2;
	struct {
		u_int V_value2_len;
		double *V_value2_val;
	} V_value2;
};
typedef struct GetValueResponse GetValueResponse;

#define CLAVES_PROG 99
#define CLAVES_VERS 1
#define MAXSIZE 256
#define MAX_N 32

#if defined(__STDC__) || defined(__cplusplus)
#define INIT 1
extern  enum clnt_stat init_1(int *, CLIENT *);
extern  bool_t init_1_svc(int *, struct svc_req *);
#define SET_VALUE 2
extern  enum clnt_stat set_value_1(SetValueArgs , int *, CLIENT *);
extern  bool_t set_value_1_svc(SetValueArgs , int *, struct svc_req *);
#define GET_VALUE 3
extern  enum clnt_stat get_value_1(int , GetValueResponse *, CLIENT *);
extern  bool_t get_value_1_svc(int , GetValueResponse *, struct svc_req *);
#define DELETE_KEY 4
extern  enum clnt_stat delete_key_1(int , int *, CLIENT *);
extern  bool_t delete_key_1_svc(int , int *, struct svc_req *);
#define MODIFY_VALUE 5
extern  enum clnt_stat modify_value_1(SetValueArgs , int *, CLIENT *);
extern  bool_t modify_value_1_svc(SetValueArgs , int *, struct svc_req *);
#define EXIST 6
extern  enum clnt_stat exist_1(int , int *, CLIENT *);
extern  bool_t exist_1_svc(int , int *, struct svc_req *);
extern int claves_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define INIT 1
extern  enum clnt_stat init_1();
extern  bool_t init_1_svc();
#define SET_VALUE 2
extern  enum clnt_stat set_value_1();
extern  bool_t set_value_1_svc();
#define GET_VALUE 3
extern  enum clnt_stat get_value_1();
extern  bool_t get_value_1_svc();
#define DELETE_KEY 4
extern  enum clnt_stat delete_key_1();
extern  bool_t delete_key_1_svc();
#define MODIFY_VALUE 5
extern  enum clnt_stat modify_value_1();
extern  bool_t modify_value_1_svc();
#define EXIST 6
extern  enum clnt_stat exist_1();
extern  bool_t exist_1_svc();
extern int claves_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_SetValueArgs (XDR *, SetValueArgs*);
extern  bool_t xdr_GetValueResponse (XDR *, GetValueResponse*);

#else /* K&R C */
extern bool_t xdr_SetValueArgs ();
extern bool_t xdr_GetValueResponse ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CLAVES_IU_H_RPCGEN */