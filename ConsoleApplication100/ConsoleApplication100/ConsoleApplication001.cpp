// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <tchar.h>
#include "hsmcmd.h"

typedef struct _key {
	UCHAR ALGID[64];
	UCHAR BLOCKLEN[64];
	UCHAR KEYLEN[64];
	UCHAR PERMISSIONS[64];
	UCHAR IV[64];
	UCHAR PADDING[64];
	UCHAR MODE[64];

	int len;
	UCHAR key[256];
	UCHAR cv[64];
}HKEY_Z, *PHKEY_Z;

typedef struct _pupvkey {
	UCHAR ALGID[64];
	UCHAR BLOCKLEN[64];
	UCHAR KEYLEN[64];
	UCHAR PERMISSIONS[64];
	UCHAR IV[64];
	UCHAR PADDING[64];
	UCHAR MODE[64];

	int puLen;
	UCHAR puKey[4096];
	int pvLen;
	UCHAR pvKey[4096];
}HPKEY_Z, *PHPKEY_Z;

/*
int Create() {
HKEY hKey;
LPCTSTR lpRun = _T("SoftWare\\_MyTest");
DWORD state, dwType, sizeBuff;
long lRet;
WCHAR reBuff[14] = {0};

//创建子键
//lRet = RegCreateKeyEx(HKEY_CURRENT_USER,lpRun,0,NULL,0,0,NULL,&hKey,&state);
lRet = RegCreateKeyEx(HKEY_CURRENT_USER, lpRun, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, &state);
if (lRet == ERROR_SUCCESS) {
if (state == REG_CREATED_NEW_KEY) {
puts("表项创建成功");
}

RegCloseKey(hKey);
}

//打开 修改键值
lRet = RegOpenKeyEx(HKEY_CURRENT_USER,lpRun,0,KEY_WRITE,&hKey);
if (lRet == ERROR_SUCCESS) {
RegSetValueEx(hKey,_T("test"),0,REG_SZ,(BYTE*)_T("success"),14);
puts("打开 修改键值");
RegCloseKey(hKey);
}

//读取键值
lRet = RegOpenKeyEx(HKEY_CURRENT_USER,lpRun,0,KEY_READ,&hKey);
if (lRet == ERROR_SUCCESS) {
sizeBuff = sizeof(reBuff);
lRet = RegQueryValueEx(hKey,_T("test"),0,&dwType,(BYTE*)reBuff,&sizeBuff);
if (lRet == ERROR_SUCCESS) {
puts("SUCCESS");
wprintf(_T("BUFF: %s\n"),reBuff);
}
else {
printf("ERROR: %ul",lRet);
RegCloseKey(hKey);
}
}

删除键
lRet = RegOpenKeyEx(HKEY_CURRENT_USER,lpRun,0,KEY_WRITE,&hKey);
if (lRet == ERROR_SUCCESS) {
//删除
RegDeleteValue(hKey,_T("test"));

puts("删除键成功");
RegCloseKey(hKey);
system("pause");
}
return lRet;
}


void Create2() {
long lRet = 1L;
HKEY hKey;

lRet = GMN_RegOpen(&hKey);
printf("REV: %u\n", lRet);


char csKey1[] = "CSPname";
char csValue1[] = "北京江南哥盟科技有限公司";
DWORD len1 = strlen(csValue1);

char csKey2[] = "Tpye";
DWORD csValue2 = 1;
DWORD len2 = sizeof(DWORD);

char csKey3[] = "SigInFile";
DWORD csValue3 = 0;
DWORD len3 = sizeof(DWORD);

char csKey4[] = "Signature";
char csValue4[] = "Signature";
DWORD len4 = strlen(csValue4);

char csKey5[] = "ImagePath";
char csValue5[] = "ImagePath";
DWORD len5 = strlen(csValue5);

lRet = GMN_RegSetValueEx(hKey, csKey1, 0, REG_SZ, (BYTE*)csValue1, len1);
printf("REV: %u\n", lRet);

lRet = GMN_RegSetValueEx(hKey, csKey2, 0, REG_DWORD, (LPBYTE)&csValue2, len2);
printf("REV: %u\n", lRet);

lRet = GMN_RegSetValueEx(hKey, csKey3, 0, REG_DWORD, (LPBYTE)&csValue3, len3);
printf("REV: %u\n", lRet);

lRet = GMN_RegSetValueEx(hKey, csKey4, 0, REG_BINARY, (BYTE*)csValue4, len4);
printf("REV: %u\n", lRet);

lRet = GMN_RegSetValueEx(hKey, csKey5, 0, REG_SZ, (BYTE*)csValue5, len5);
printf("REV: %u\n", lRet);


char csValue6[1024];
DWORD sizeBuff1 = 1024;
DWORD dwType1;

char csValue7[1024];
DWORD sizeBuff2 = 1024;
DWORD dwType2;

char csValue8[1024];
DWORD sizeBuff3 = 1024;
DWORD dwType3;

char csValue9[1024];
DWORD sizeBuff4 = 1024;
DWORD dwType4;

char csValue10[1024];
DWORD sizeBuff5 = 1024;
DWORD dwType5;

lRet = GMN_RegQueryValueEx(hKey, csKey1, 0, &dwType1, (BYTE*)csValue6, &sizeBuff1);
printf("REV: %u | key: %s | len: %u | value: %s | type: %u \n", lRet,
csKey1,
sizeBuff1,
csValue6,
dwType1);

lRet = GMN_RegQueryValueEx(hKey, csKey2, 0, &dwType2, (BYTE*)csValue7, &sizeBuff2);
printf("REV: %u | key: %s | len: %u | value: %s | type: %u \n", lRet,
csKey2,
sizeBuff2,
csValue7,
dwType2);

lRet = GMN_RegQueryValueEx(hKey, csKey3, 0, &dwType3, (BYTE*)csValue8, &sizeBuff3);
printf("REV: %u | key: %s | len: %u | value: %s | type: %u \n", lRet,
csKey3,
sizeBuff3,
csValue8,
dwType3);

lRet = GMN_RegQueryValueEx(hKey, csKey4, 0, &dwType4, (BYTE*)csValue9, &sizeBuff4);
csValue9[sizeBuff4] = '\0';
printf("REV: %u | key: %s | len: %u | value: %s | type: %u \n", lRet,
csKey4,
sizeBuff4,
csValue9,
dwType4);

lRet = GMN_RegQueryValueEx(hKey, csKey5, 0, &dwType5, (BYTE*)csValue10, &sizeBuff5);
printf("REV: %u | key: %s | len: %u | value: %s | type: %u \n", lRet,
csKey5,
sizeBuff5,
csValue10,
dwType5);



GMN_RegDeleteValue(hKey, csKey1);
GMN_RegDeleteValue(hKey, csKey2);
GMN_RegDeleteValue(hKey, csKey3);
GMN_RegDeleteValue(hKey, csKey4);
GMN_RegDeleteValue(hKey, csKey5);


GMN_RegCloseKey(hKey);
}

void testOne() {
char test[] = "zhuheng";
DWORD dwTest = (DWORD)test;
printf("S: %s\n", (CHAR *)dwTest);

printf("%d\n", strlen((char*)test));
printf("%d\n", strlen((char*)dwTest));
}

void testTwo() {
unsigned
char test[] = "zhuheng";
BYTE *bs = test;
printf("%s\n",test);
printf("%s\n", bs);


unsigned char ucs[] = "12345678";

printf("%d %d\n",sizeof(test),sizeof(bs));
printf("%d %d\n", strlen((char*)test) , strlen((char*)bs));

}

void testThree() {
HKEY hKey;
LONG lRet;
DWORD dwFlag;
BYTE pbData[1024];
DWORD pdwDataLen;

lRet = GMN_RegOpen(&hKey);
printf("REV: %u\n", lRet);

lRet = GMN_RegQueryValueEx(hKey,"zhuheng001" , 0,
&dwFlag, pbData, &pdwDataLen);
printf("REV: %u\n", lRet);
printf("len: %u buff:%s type: %u",pdwDataLen,pbData,dwFlag);
}
*/

//生成HASH
void testFour() {
	char ip[] = "192.168.1.209";
	int port = 8000;
	int timeout = 0;
	int ret = -1;
	int cmdid;

	cmdid = InitHsmDevice(ip, port, timeout);
	if (cmdid<0) {
		puts("connect error");
	}
	puts("connect success");

	ret = testHSM(cmdid, 0, NULL, NULL, NULL);
	if (ret != 0) {
		printf("RETURN: %d\n", ret);
	}

	const int rndLen = 64;
	UCHAR rnd[rndLen + 1];

	ret = genrandom(cmdid, 0, NULL, rndLen, rnd);
	if (ret != 0) {
		printf("RETURN: %d LINE: %d\n", ret, __LINE__);
	}
	puts("------------------------RANDOM------------------------------");
	for (int i = 0; i<rndLen; i++) {
		printf("%02X ", rnd[i]);
	}
	printf("\n");

	int hash_id = HASH_SHA1;
	UCHAR data[] = "zhuheng";
	int data_len = strlen((char*)data);
	UCHAR hash_value[256];
	memset(hash_value, 0x00, sizeof(hash_value));

	ret = genhash(cmdid, 0, NULL, hash_id, data_len, data, hash_value);
	if (ret != 0) {
		printf("RETURN: %d LINE: %d\n", ret, __LINE__);
	}

	printf("DATA LEN: %d\n", data_len);
	puts("------------------------HASH------------------------------");
	for (int i = 0; i<strlen((char*)hash_value); i++) {
		printf("%02X ", hash_value[i]);
	}
	printf("\n");

	CloseHsmDevice(cmdid);

}

//生成随机数
void testFive() {
	char ip[] = "192.168.1.209";
	int port = 8000;
	int timeout = 0;
	int comid;
	int ret;

	comid = InitHsmDevice(ip, port, timeout);
	if (comid < 0) {
		puts("connect error");
	}
	puts("------------>connect success");

	int rndLen = 32;
	UCHAR rnd[32 + 1];
	__try {
		ret = genrandom(comid, 0, NULL, rndLen, rnd);
		if (ret<0) {
			printf("ret:%d\n", ret);
			return;
		}
		return;
	}
	__finally
	{
		puts("--------->execute success");
		printf("rnd : %s\n", &rnd);
		for (int i = 0; i<rndLen; i++) {
			printf("%02X", rnd[i]);
		}
		puts("");

		CloseHsmDevice(comid);
	}

}

//生成DES密钥
void testSix(ULONG *phKey) {
	char ip[] = "192.168.1.205";
	int port = 8000;
	int timeout = 0;
	int comid;
	int ret;

	comid = InitHsmDevice(ip, port, timeout);
	if (comid < 0) {
		puts("connect error");
	}
	puts("------------>connect success");

	__try {
		char checkValue[6 + 1];
		char *key;
		key = (char*)malloc(256);
		if (NULL == key) {
			return;
		}
		ret = generateKey(comid, 0, NULL, 0, 0, (char*)ZPK_TYPE, 'X', key, checkValue);
		if (ret<0) {
			printf("RET:%d\n", ret);
			return;
		}

		*phKey = (ULONG)key;
		printf("phKey:%s\n", *phKey);
		printf("checkValue:%s\n", checkValue);
	}
	__finally
	{
		CloseHsmDevice(comid);
	}
}

//派生密钥
void testSeven(ULONG hKey) {
	char ip[] = "192.168.1.205";
	int port = 8000;
	int timeout = 0;
	int comid;
	int ret = 0;

	comid = InitHsmDevice(ip, port, timeout);
	if (comid < 0) {
		puts("connect error");
	}
	puts("------------>connect success");

	//char key[] = "9F138201AE689DB895A5725BC638CA06";
	printf("hKey:%s\n",hKey);
	char *key = (char*)hKey;

	CHAR cKey[256];
	UCHAR deriveKey[256];
	UCHAR checkValue[256];
	PackBCD(key,(unsigned char*)cKey,strlen(key));
	
	__try {
		int algo = 0;
		int derivationmode = 0;
		int encmode = 0;
		char deriveKeyType[] = ZPK_TYPE;
		char derivationKeyType[] = ZPK_TYPE;
		int keyLen = 16;
		int dataLen = 8;
		char *iv = NULL;
		char data[] = "12345678";
		
		ret = derivatekey(comid, 0, NULL, algo,derivationmode,encmode,deriveKeyType,derivationKeyType, keyLen, cKey, dataLen, iv, data, 0, NULL, NULL, (char*)deriveKey, (char*)checkValue);
		if (ret<0) {
		
			("RETURN:%d\n", ret);
			return;
		}
		printf("deriveKey:%s\n", deriveKey);
		printf("checkValue:%s\n", checkValue);
	}
	__finally
	{
		CloseHsmDevice(comid);
	}
}

//生成RSA密钥
void testEight(UCHAR * public_key, int  * public_key_len, UCHAR * private_key,int * private_key_len) {
	char ip[] = "192.168.1.205";
	int port = 8000;
	int timeout = 0;
	int comid;
	int ret;

	comid = InitHsmDevice(ip, port, timeout);
	if (comid < 0) {
		puts("connect error");
	}
	puts("------------>connect success");

	__try {
		int key_usage = 2;
		int mode_flag = 0;
		int key_length = 2048;
		int public_exponent_len = 32;
		UCHAR public_exponent[] = {0x00,0x01,0x00,0x01};
		UCHAR mac[16];

		int public_key_encoding = 1;
		ret = genrsakey( comid, 0, NULL,
			key_usage,mode_flag,key_length,public_key_encoding,
			public_exponent_len,
			public_exponent,
			99,
			0,
			NULL,
			public_key,
			public_key_len,
			mac,
			private_key,
			private_key_len,
			NULL, NULL,NULL, NULL,
			NULL, NULL,NULL, NULL,
			NULL, NULL,NULL, NULL,
			NULL, NULL,NULL, NULL);
		if (ret < 0) {
			printf("ERROR RETURN : %d\n",ret);
			return;
		}
		//printf("LEN:%d", iPublic_key_len);
	}
	__finally
	{
		CloseHsmDevice(comid);
	}
}

//导出密钥
void testNine(UCHAR * data,int * data_length, UCHAR * public_key,int  public_key_len) {
	char ip[] = "192.168.1.205";
	int port = 8000;
	int timeout = 0;
	int comid;
	int ret;

	comid = InitHsmDevice(ip, port, timeout);
	if (comid < 0) {
		puts("connect error");
	}
	puts("------------>connect success");
	//////////////////////////
	UCHAR cKey[] = "9F138201AE689DB895A5725BC638CA06";
	UCHAR wkLmk[32];
	PackBCD((CHAR*)cKey,wkLmk,32);
	///////////////////////////
	int msghdlen = 0;
	char * msghd = NULL;
	int algo = 0;
	int sig_alg = 01;
	int pad_mode = 04;
	int mgfHash = NULL;
	int OAEP_parm_len = NULL;
	UCHAR *OAEP_parm = NULL;
	int keyBlockType =3;
	int keyBlockTemplateLen = NULL;
	UCHAR *keyBlockTemplate = NULL;
	int keyOffset = NULL;
	int chkLen = NULL;
	int chkOffset = NULL;
	int keyLen = 16;
	int keyTypeMode = 0;
	UCHAR keyType[] = ZPK_TYPE;
	int index = -1;
	UCHAR *mac = NULL;
	int authenDataLen = NULL;
	UCHAR *authenData = NULL;
	UCHAR *iv = NULL;
	UCHAR *cv = NULL;

	__try {
		ret = exportrsadeskey(
			comid,
			msghdlen,
			msghd,
			algo,
			sig_alg,
			pad_mode,
			mgfHash,
			OAEP_parm_len,
			OAEP_parm,
			keyBlockType,
			keyBlockTemplateLen,
			keyBlockTemplate,
			keyOffset,
			chkLen,
			chkOffset,
			keyLen,
			keyTypeMode,
			keyType,
			wkLmk,
			index,
			mac,
			public_key,
			public_key_len,
			authenDataLen,
			authenData,
			iv,
			cv,
			data,
			data_length
		);
		if (ret < 0) {
			printf("ERROR RETURN : %d\n", ret);
			return;
		}
	}
	__finally
	{
		CloseHsmDevice(comid);
	}
	return;
}

//导入密钥
void testTen(UCHAR * data, int data_length,UCHAR * private_key,int  private_key_len, UCHAR * wkLmk, int * keylen) {
	char ip[] = "192.168.1.205";
	int port = 8000;
	int timeout = 0;
	int comid;
	int ret;

	comid = InitHsmDevice(ip, port, timeout);
	if (comid < 0) {
		puts("connect error");
	}
	puts("------------>connect success");
	//////////////////////////
	int msghdlen = 0;
	char * msghd = NULL;
	int algo = 0;
	int sig_alg = 01;
	int pad_mode = 04;
	int mgfHash = NULL;
	int OAEP_parm_len = NULL;
	UCHAR *OAEP_parm = NULL;
	int keyBlockType = 3;
	int keyBlockTemplateLen = NULL;
	UCHAR *keyBlockTemplate = NULL;
	int keyOffset = NULL;
	int chkLen = NULL;
	int chkOffset = NULL;
	int keyTypeMode = 0;
	UCHAR keyType[] = ZPK_TYPE;
	int index = 99;
	UCHAR *mac = NULL;
	int authenDataLen = NULL;
	UCHAR *authenData = NULL;
	UCHAR *iv = NULL;
	UCHAR cv[32];
	CHAR lmkSchem = 'X';
	CHAR cvFlag = 0;
	
	__try {
		ret = importrsadeskey(
				comid,
				msghdlen,  msghd,
				algo,
				sig_alg,
				pad_mode,
				mgfHash,
				OAEP_parm_len,
				OAEP_parm,
				keyBlockType,
				keyBlockTemplateLen,
				keyBlockTemplate,
				keyOffset,
				chkLen,
				chkOffset,
				keyTypeMode,
				keyType,
				data_length,
				data,
				index,
				private_key_len,
				private_key,
				lmkSchem,
				cvFlag,
				iv,
				cv,
				wkLmk,
				keylen
		);
		if (ret < 0) {
			printf("ERROR RETURN : %d\n", ret);
			return;
		}
	}
	__finally
	{
		CloseHsmDevice(comid);
	}
	return;
}

//加解密
void testEleven() {
	char ip[] = "192.168.1.205";
	int port = 8000;
	int timeout = 0;
	int comid;
	int ret;

	comid = InitHsmDevice(ip, port, timeout);
	if (comid < 0) {
		puts("connect error");
	}
	puts("------------>connect success");
	/////////////////////////////////////
	/////////////////////////////////////
	__try {
		int algo = 0;
		int dataBlockFlag = 0;
		int encryptFlag = 0;
		int algoOperationMode = 0;
		int inputFormat = 1;
		int outputFormat = 1;
		char keyType[] = ZEK_TYPE;
		char key[] = "XCB8B629920622806464AB4C738053BFA";
		int paddingMode = 0;
		char paddingChar[] = "0000";
		int paddingFlag = 0;
		char *iv = NULL;
		int outFlag;
		int dataLen = 8;
		char data[] = "AAAAAAAAAAAAAAAA";

		ret = encryptDecrypt(comid, 0, NULL, algo,
			dataBlockFlag,
			encryptFlag,
			algoOperationMode,
			inputFormat,
			outputFormat,
			keyType,
			key,
			paddingMode,
			paddingChar,
			paddingFlag,
			iv,
			&outFlag,
			&dataLen,
			data);
		if (ret < 0) {
			printf("RET:%d\n",ret);
			return;
		}
		printf("LEN:%d\n",dataLen);
		printf("DATA:%s\n",data);

		encryptFlag = 1;
		ret = encryptDecrypt(comid, 0, NULL, algo,
			dataBlockFlag,
			encryptFlag,
			algoOperationMode,
			inputFormat,
			outputFormat,
			keyType,
			key,
			paddingMode,
			paddingChar,
			paddingFlag,
			iv,
			&outFlag,
			&dataLen,
			data);
		if (ret < 0) {
			printf("RET:%d\n", ret);
			return;
		}
		printf("LEN:%d\n", dataLen);
		printf("DATA:%s\n", data);
	}
	__finally
	{
		CloseHsmDevice(comid);
	}
}

//私钥签名 公钥验签
void testTwelve() {

	UCHAR public_key[4096];
	int  public_key_len;
	UCHAR private_key[4096];
	int  private_key_len;
	testEight(public_key, &public_key_len, private_key, &private_key_len);
	printf("PUBLEN: %d PRILEN:%d\n", public_key_len, private_key_len);

	puts("------------------------------------------------------------------------");
	
	////////////////////////////////
	char ip[] = "192.168.1.205";
	int port = 8000;
	int timeout = 0;
	int comid;
	int ret;

	comid = InitHsmDevice(ip, port, timeout);
	if (comid < 0) {
		puts("connect error");
	}
	puts("------------>connect success");
	__try {
		int msghdlen = 0;
		char *msghd = NULL; 
		int hash_id = 01; 
		int sign_id = 01;
		int pad_mode = 01;
		int mgfHash = NULL;
		int OAEP_parm_len = NULL;
		UCHAR *OAEP_parm = NULL;
		int pssRule = NULL;
		int trailerField = NULL;
		int data_length = 8;
		UCHAR data[] = "zhuheng0";
		int index = 99;
		UCHAR sign[4096];
		int sign_length;
		int authenDataLen = 0;
		UCHAR * authenData = NULL;

		ret = rsaprisign(comid,msghdlen,msghd,hash_id,sign_id,
			pad_mode,
			mgfHash,
			OAEP_parm_len,
			OAEP_parm,
			pssRule,
			trailerField,
			data_length,
			data,
			index,
			private_key_len,
			private_key,
			sign,
			&sign_length);
		if (ret<0) {
			printf("RET:%d\n",ret);
			return;
		}
		printf("LEN:%d\n",sign_length);
		
		///////////////////////////////////
	
		ret = rsapubverify(comid, msghdlen, msghd, hash_id, sign_id,
			pad_mode,
			mgfHash,
			OAEP_parm_len,
			OAEP_parm,
			pssRule,
			trailerField,
			sign_length,
			sign,
			data_length,
			data,
			index,
			NULL,
			public_key,
			public_key_len,
			authenDataLen,
			authenData
		);
		printf("RET:%d\n",ret);
	}
	__finally
	{
		CloseHsmDevice(comid);
	}

	////////////////////////////////

}

//类型强制转换
void testThirteen() {
	LONG dwKey;
	HKEY_Z desKey;
	HPKEY_Z rsaKey;
	memcpy(desKey.ALGID,"12345678",sizeof("12345678"));
	printf("CV:%s\n",desKey.ALGID);
	dwKey = (LONG)&desKey;
	//HKEY_Z *dwKey_t = (HKEY_Z *)dwKey;
	HPKEY_Z *dwKey_t = (HPKEY_Z*)dwKey;
	printf("CV:%s\n",dwKey_t->ALGID);
}

//SM2密钥
void testFourteen() {
	int ret = 0;
	
	///////////////////////////
	int comid;
	int msghdlen = 0;
	char *msghd = NULL;
	int algflag  = 3;
	int key_usage = 3;
	int compflag = 4;
	int key_length = 256;
	int index = 01;
	int Plen = 0;
	UCHAR *Pbuf = NULL;
	int Alen = 0;
	UCHAR *Abuf = NULL;
	int Blen = 0;
	UCHAR *Bbuf = NULL;
	int Gxlen = 0;
	UCHAR *Gxbuf = NULL;
	int Gylen = 0;
	UCHAR *Gybuf = NULL;
	int Nlen = 0;
	UCHAR *Nbuf = NULL;
	UCHAR puKey[4096], pvKey[4096], deKey[4096];
	int puLen, pvLen, deLen;
	UCHAR *public_key = puKey;
	int * public_key_len = &puLen;
	UCHAR *private_key = pvKey;;
	int *private_key_len = &pvLen;
	UCHAR *derpubkey = deKey;
	int * derpubkeylen = &deLen;
		///////////////////////////////////////////

	char ip[] = "192.168.1.205";
	int port = 8000;
	int timeout = 0;

	comid = InitHsmDevice(ip, port, timeout);
	if (comid < 0) {
		puts("connect error");
	}
	puts("------------>connect success");
	__try {
		ret = gensm2key( comid,  msghdlen, msghd,  algflag, key_usage, compflag, key_length, index, Plen, Pbuf, Alen,Abuf, Blen,
			Bbuf, Gxlen,Gxbuf, Gylen,Gybuf, Nlen,Nbuf,public_key, public_key_len,private_key,private_key_len,derpubkey,derpubkeylen);
		printf("RET:%d\n",ret);
		printf("PUBLIC KEY LEN %d\n", puLen);
		printf("PUBLIC KEY LEN %d\n", pvLen);
		printf("PUBLIC KEY LEN %d\n", deLen);
	}
	__finally {
		CloseHsmDevice(comid);
	}
}

/*
///////////////////////////////////////////
//TEMPLATE
int comid;
char ip[] = "192.168.1.205";
int port = 8000;
int timeout = 0;

comid = InitHsmDevice(ip, port, timeout);
if (comid < 0) {
puts("connect error");
}
puts("------------>connect success");
__try {

}
__finally {
CloseHsmDevice(comid);
}
//////////////////////////////////////////////
*/

//RSA 加解密
void testFifteen(){
	/////////////////////////////////////////
	UCHAR public_key[4096];
	int  public_key_len;
	UCHAR private_key[4096];
	int  private_key_len = 0;
	testEight(public_key, &public_key_len, private_key, &private_key_len);
	printf("PUBLEN: %d PRILEN:%d\n", public_key_len, private_key_len);
	puts("------------------------------------------------------------------------");
	///////////////////////////////////////////
	//TEMPLATE
	int ret = 0;
	int comid;
	char ip[] = "192.168.1.205";
	int port = 8000;
	int timeout = 0;

	comid = InitHsmDevice(ip, port, timeout);
	if (comid < 0) {
		puts("connect error");
	}
	puts("------------>connect success");
	__try {
		/////////////////////////////
		int msghdlen = 0;
		char * msghd = NULL;
		int mgfHash = NULL;
		int OAEP_parm_len = NULL;
		UCHAR *OAEP_parm = NULL;
		int index = 99;
		
		//RSA 1 SM2 3
		int sig_alg = 1;
		//0加密   1解密
		int dec_flag = 0;
		//RSA 1234 SM2 00
		int pad_mode = 1;
		
		int sign_length = 8;
		UCHAR *sign = (UCHAR*)"zhuheng0";

		int data_len ;
		UCHAR data[4096];
		////////////////////////////
		UCHAR *mac = NULL;
		int authenDataLen = 0;
		UCHAR *authenData = NULL;

		ret =  rsapubkeyoper(
			 comid,
			 msghdlen,  msghd,
			 sig_alg,
			 dec_flag,
			 pad_mode,
			 mgfHash,
			 OAEP_parm_len,
			 OAEP_parm,
			 sign_length,
			 sign,
			 index,
			 mac,
			public_key,
			public_key_len,
			 authenDataLen,
			 authenData,
			 data,
			 &data_len
		);
		printf("ER RET:%d\n",ret);
		//////////////////解密///////////////////////
		//0加密<-仅限RSA   1解密
		
		dec_flag = 1;
		UCHAR sign_t[4096];
		int sign_length_t;
		ret = rsaprikeyoper(
			 comid,
			 msghdlen, msghd,
			 sig_alg,
			dec_flag,
			 pad_mode,
			 mgfHash,
			 OAEP_parm_len,
			 OAEP_parm,
			 data_len,
			 data,
			 index,
			 private_key_len,
			 private_key,
			 sign_t,
			 &sign_length_t
		);
		printf("EP RET:%d\n",ret);
		////////////////////////////////////////

	}
	__finally {
		CloseHsmDevice(comid);
	}
	//////////////////////////////////////////////
}

int main()
{
	puts("--------------------REGEDIT TEST ------------------------>");
	/*
	Create();
	Create2();
	testOne();
	testTwo();
	testThree();
	testFour();
	testFive();

	ULONG hKey = 0 ;
	testSix(&hKey);
	testSeven(hKey);
	if (NULL != hKey) {
		free((void*)hKey);
		hKey = NULL;
	}
	UCHAR public_key[4096];
	int  public_key_len;
	UCHAR private_key[4096];
	int  private_key_len;
	testEight(public_key, &public_key_len, private_key, &private_key_len);
	
	UCHAR data[4096];
	int data_length;
	testNine(data,&data_length, public_key, public_key_len);
	printf("LEN:%d\n",data_length);
	
	UCHAR wkLmk[4096];
	int keyLen;
	testTen(data, data_length, private_key, private_key_len,wkLmk,&keyLen);
	printf("IMPLEN:%d\n", keyLen);
	
	testEleven();
	testTwelve();
	
	PHKEY_Z pKey = (PHKEY_Z)malloc(sizeof(HKEY_Z));
	if (NULL == pKey) {
		puts("---------------Memory error!----------------->");
	}
	memset(pKey,0x00,sizeof(pKey));
	printf("TEST:%d\n",strlen((CHAR*)pKey->ALGID));

	if (pKey!=NULL) {
		free(pKey);
		pKey = NULL;
		puts("-----------------------------SUCCESS------------------>");
	}
	testThirteen();
	testFourteen();
	*/
	testFifteen();


	getchar();
	return 0;
}



