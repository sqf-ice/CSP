
#ifndef __CSP_SERVICE_IMPL__
#define __CSP_SERVICE_IMPL__

/*
int CPAcquireContextImpl();

int CPGetProvParamImpl(HCRYPTPROV hProv, DWORD dwParam, DWORD dwFlags, BYTE *pbData, DWORD *pdwDataLen);

int CPSetProvParamImpl(HCRYPTPROV hProv, DWORD dwParam, BYTE *pbData, DWORD dwFlags);

int CPDeriveKeyImpl(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTHASH hBaseData, HCRYPTKEY *phKey);

int CPExportKeyImpl(HCRYPTPROV hProv, HCRYPTKEY hKey, HCRYPTKEY hPubKey, BYTE *pbData, DWORD *pdwDataLen);

int CPGenKeyImpl(HCRYPTPROV hProv, ALG_ID Algid, DWORD dwFlags, HCRYPTKEY *phKey);

int CPGenRandomImpl(HCRYPTPROV hProv, DWORD dwLen, BYTE *pbBuffer);

int CPGetKeyParamImpl(HCRYPTPROV hProv, HCRYPTKEY hKey, DWORD dwParam, LPBYTE pbData, LPDWORD pcbDataLen);

int CPGetUserKeyImpl(HCRYPTPROV hProv, DWORD dwKeySpec, HCRYPTKEY *phUserKey);

int CPImportKeyImpl(HCRYPTPROV hProv, const BYTE *pbData, DWORD dwDataLen, HCRYPTKEY hPubKey, DWORD dwFlags, HCRYPTKEY *phKey);

int CPSetKeyParamImpl(HCRYPTPROV hProv, HCRYPTKEY hKey, DWORD dwParam, BYTE *pbData, DWORD dwFlags);

int CPDecryptImpl(HCRYPTPROV hProv, HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE *pbData, DWORD *pdwDataLen);

int CPEncryptImpl(HCRYPTPROV hProv, HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE *pbData, DWORD *pdwDataLen, DWORD dwBufLen);

int CPCreateHashImpl(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTKEY hKey, DWORD dwFlags, HCRYPTHASH *phHash);

int CPGetHashParamImpl(HCRYPTPROV hProv, HCRYPTHASH hHash, DWORD dwParam, BYTE *pbData, DWORD *pdwDataLen, DWORD dwFlags);

int CPHashDataImpl( HCRYPTPROV hProv, HCRYPTHASH hHash, const BYTE *pbData, DWORD dwDataLen, DWORD dwFlags);

int CPSetHashParamImpl(HCRYPTPROV hProv, HCRYPTHASH hHash, DWORD dwParam, BYTE *pbData, DWORD dwFlags);

int CPSignHashImpl(HCRYPTPROV hProv, HCRYPTHASH hHash, DWORD dwKeySpec, LPCWSTR sDescription, DWORD dwFlags, BYTE *pbSignature, DWORD *pdwSigLen);

int CPVerifySignatureImpl(HCRYPTPROV hProv, HCRYPTHASH hHash, const BYTE *pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCWSTR sDescription, DWORD dwFlags);

int CPHashSessionKeyImpl( HCRYPTPROV hProv, HCRYPTHASH hHash, HCRYPTKEY hKey,DWORD dwFlags);
*/

//1 CPAcquireContext
int CPAcquireContextImpl(HCRYPTPROV *phProv,CHAR *pszContainer,DWORD dwFlags,PVTableProvStruc pVTable);

//2 CPGetProvParam
int   CPGetProvParamImpl(HCRYPTPROV hProv,DWORD dwParam,BYTE *pbData,DWORD *pdwDataLen,DWORD dwFlags);

//3 CPReleaseContext
int   CPReleaseContextImpl(HCRYPTPROV hProv,DWORD dwFlags);

//4 CPSetProvParam
int   CPSetProvParamImpl(HCRYPTPROV hProv,DWORD dwParam,BYTE *pbData,DWORD dwFlags);

//5 CPDeriveKey
int   CPDeriveKeyImpl(HCRYPTPROV hProv,ALG_ID Algid,HCRYPTHASH hBaseData,DWORD dwFlags,HCRYPTKEY *phKey);

//6 CPDestroyKey
int   CPDestroyKeyImpl(HCRYPTPROV hProv,HCRYPTKEY hKey);

//7 CPExportKey
int   CPExportKeyImpl(HCRYPTPROV hProv,HCRYPTKEY hKey,HCRYPTKEY hPubKey,DWORD dwBlobType,DWORD dwFlags,BYTE *pbData,DWORD *pdwDataLen);

//8 CPGenKey
int   CPGenKeyImpl(HCRYPTPROV hProv,ALG_ID Algid,DWORD dwFlags,HCRYPTKEY *phKey);

//9 CPGenRandom
int   CPGenRandomImpl(HCRYPTPROV hProv,DWORD dwLen,BYTE *pbBuffer);

//10 CPGetKeyParam
int   CPGetKeyParamImpl(HCRYPTPROV hProv,HCRYPTKEY hKey,DWORD dwParam,LPBYTE pbData,LPDWORD pcbDataLen,DWORD dwFlags);

//11 CPGetUserKey
int   CPGetUserKeyImpl(HCRYPTPROV hProv,DWORD dwKeySpec,HCRYPTKEY *phUserKey);

//12 CPImportKey
int   CPImportKeyImpl(HCRYPTPROV hProv,const BYTE *pbData,DWORD dwDataLen,HCRYPTKEY hPubKey,DWORD dwFlags,HCRYPTKEY *phKey);

//13 CPSetKeyParam
int   CPSetKeyParamImpl(HCRYPTPROV hProv,HCRYPTKEY hKey,DWORD dwParam,BYTE *pbData,DWORD dwFlags);

//14 CPDecrypt
int   CPDecryptImpl(HCRYPTPROV hProv,HCRYPTKEY hKey,HCRYPTHASH hHash,BOOL Final,DWORD dwFlags,BYTE *pbData,DWORD *pdwDataLen);

//15 CPEncrypt
int   CPEncryptImpl(HCRYPTPROV hProv,HCRYPTKEY hKey,HCRYPTHASH hHash,BOOL Final,DWORD dwFlags,BYTE *pbData,DWORD *pdwDataLen,DWORD dwBufLen);

//16 CPCreateHash
int   CPCreateHashImpl(HCRYPTPROV hProv,ALG_ID Algid,HCRYPTKEY hKey,DWORD dwFlags,HCRYPTHASH *phHash);

//17 CPDestroyHash
int   CPDestroyHashImpl(HCRYPTPROV hProv,HCRYPTHASH hHash);

//18 CPDuplicateHash ���Ӻ���
int   CPDuplicateHashImpl(HCRYPTPROV hProv,HCRYPTHASH hHash,DWORD *pdwReserved,DWORD dwFlags,HCRYPTHASH *phHash);

//19 CPGetHashParam
int   CPGetHashParamImpl(HCRYPTPROV hProv,HCRYPTHASH hHash,DWORD dwParam,BYTE *pbData,DWORD *pdwDataLen,DWORD dwFlags);

//20 CPHashData
int   CPHashDataImpl(HCRYPTPROV hProv,HCRYPTHASH hHash,const BYTE *pbData,DWORD dwDataLen,DWORD dwFlags);

//21 CPSetHashParam
int   CPSetHashParamImpl(HCRYPTPROV hProv,HCRYPTHASH hHash,DWORD dwParam,BYTE *pbData,DWORD dwFlags);

//22 CPSignHash
int   CPSignHashImpl(HCRYPTPROV hProv,HCRYPTHASH hHash,DWORD dwKeySpec,LPCWSTR sDescription,DWORD dwFlags,BYTE *pbSignature,DWORD *pdwSigLen);

//23 CPVerifySignature
int   CPVerifySignatureImpl(HCRYPTPROV hProv,HCRYPTHASH hHash,const BYTE *pbSignature,DWORD dwSigLen,HCRYPTKEY hPubKey,LPCWSTR sDescription,DWORD dwFlags);

//24 CPDuplicateKey ���Ӻ���
int   CPDuplicateKeyImpl(HCRYPTPROV hUID,HCRYPTKEY hKey,DWORD *pdwReserved,DWORD dwFlags,HCRYPTKEY *phKey);

//25 CPHashSessionKey
int   CPHashSessionKeyImpl(HCRYPTPROV hProv,HCRYPTHASH hHash,HCRYPTKEY hKey,DWORD dwFlags);

#endif