/* LibTomCrypt, modular cryptographic library -- Tom St Denis
 *
 * LibTomCrypt is a library that provides various cryptographic
 * algorithms in a highly modular and flexible manner.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@gmail.com, http://libtomcrypt.org
 */
#include "tomcrypt.h"

/**
   @file cbc_getiv.c
   CBC implementation, get IV, Tom St Denis
*/

#ifdef CBC

/**
   Get the current initial vector
   @param IV   [out] The destination of the initial vector
   @param len  [in/out]  The max size and resulting size of the initial vector
   @param cbc  The CBC state
   @return CRYPT_OK if successful
*/
int cbc_getiv(unsigned char *IV, unsigned long *len, symmetric_CBC *cbc)
{
   LTC_ARGCHK(IV  != NULL);
   LTC_ARGCHK(len != NULL);
   LTC_ARGCHK(cbc != NULL);
   if ((unsigned long)cbc->blocklen > *len) {
      return CRYPT_BUFFER_OVERFLOW;
   }
   XMEMCPY(IV, cbc->IV, cbc->blocklen);
   *len = cbc->blocklen;

   return CRYPT_OK;
}

#endif

/* $Source: /cvs/libtom/libtomcrypt/src/modes/cbc/cbc_getiv.c,v $ */
/* $Revision: 1.3 $ */
/* $Date: 2005/05/05 14:35:59 $ */
