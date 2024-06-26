/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "claves_iu.h"

bool_t
xdr_SetValueArgs (XDR *xdrs, SetValueArgs *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->key))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->value1, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->N_value2))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->V_value2.V_value2_val, (u_int *) &objp->V_value2.V_value2_len, ~0,
		sizeof (double), (xdrproc_t) xdr_double))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_GetValueResponse (XDR *xdrs, GetValueResponse *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->value1, ~0))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->N_value2))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->V_value2.V_value2_val, (u_int *) &objp->V_value2.V_value2_len, ~0,
		sizeof (double), (xdrproc_t) xdr_double))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->error_msg, ~0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_Response (XDR *xdrs, Response *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->result))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->error_msg, ~0))
		 return FALSE;
	return TRUE;
}
