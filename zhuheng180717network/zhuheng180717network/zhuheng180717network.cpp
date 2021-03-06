// zhuheng180717network.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int networkTest(FILE *file, SOCKET fd);

int handData(FILE *file, char *buf, int len);

int main()
{
	char c;
	SOCKET fd;
	FILE *file = NULL;
	char path[] = "C:\\zhuheng_LOG.txt";

	file = fopen(path, "a");
	if (NULL == file) 
	{
		printf("鼠标右击 以管理员身份运行. \n");
		getchar();
		return 0;
	}

	if ((fd = getSocket()) < 0)
	{
		fprintf(file, "SOCKET:%d\n", fd);
		fprintf(stdout, "SOCKET:%d\n", fd);
		return 0;
	}

	for (;;) 
	{
		networkTest(file,fd);
		c = getchar();
		if (c == 'n') 
		{
			break;
		}
	}

	
	fclose(file);
	closeSocket(fd);
	return 0;
}


int networkTest(FILE *file, SOCKET fd)
{
	char buf[4096];
	int bufLen;
	int recvLen;

	
	bufLen = sizeof(buf);
	
	if ((recvLen = recvBuffer(fd, buf, sizeof(buf))) <= 0)
	{
		fprintf(file, "RECV LEN:%d\n", recvLen);
		fprintf(stdout, "RECV LEN:%d\n", recvLen);
		return -1;
	}

	handData(file, buf, recvLen);
	return 0;
}

/*
int networkTest(FILE *file) 
{
	SOCKET fd;
	char buf[4096];
	int bufLen;
	int recvLen;

	if ((fd = getSocket()) < 0)
	{
		fprintf(file, "SOCKET:%d\n", fd);
		fprintf(stdout, "SOCKET:%d\n", fd);
		return 0;
	}

	bufLen = sizeof(buf);
	recvLen = recvBuffer(fd, buf, sizeof(buf));

	fprintf(file, "LEN:%d \nIP_HDR:%d\n", recvLen,sizeof(IP_HDR));
	fprintf(stdout, "LEN:%d \nIP_HDR:%d\n", recvLen, sizeof(IP_HDR));

	if (recvLen <= 0)
	{
		fprintf(file, "RECV LEN:%d\n", recvLen);
		fprintf(stdout, "RECV LEN:%d\n", recvLen);
		goto end;
	}
	handData(file,buf,recvLen);
end:
	closeSocket(fd);
	return 0;
}
*/

int handData(FILE *file,char *buf, int len) 
{
	TCP_HDR tcphdr;
	IP_HDR iphdr;
	UDP_HDR udphdr;
	ICMP_HDR icmphdr;
	char *p;
	int bufLen;


	fprintf(file, "\nLEN:%d \nIP_HDR:%d\n", len, sizeof(IP_HDR));
	fprintf(stdout, "\nLEN:%d \nIP_HDR:%d\n", len, sizeof(IP_HDR));

	p = buf;
	getData(p, (void *)(&iphdr), sizeof(iphdr));
	p += sizeof(iphdr);

	fprintf(file, "SOURCE IP:%s\n", inet_ntoa(iphdr.ip_src));
	fprintf(file, "DESTIN IP:%s\n", inet_ntoa(iphdr.ip_dst));
	fprintf(stdout, "SOURCE IP:%s\n", inet_ntoa(iphdr.ip_src));
	fprintf(stdout, "DESTIN IP:%s\n", inet_ntoa(iphdr.ip_dst));

	switch (iphdr.ip_p)
	{
	case IPPROTO_TCP:
	
		getData(p, &tcphdr, sizeof(tcphdr));
		p += sizeof(tcphdr);
		
		fprintf(file, "TCP_HDR:%d\n", sizeof(TCP_HDR));
		fprintf(file, "SOURCE PORT:%d\n", ntohs(tcphdr.sport));
		fprintf(file, "DESTIN PORT:%d\n", ntohs(tcphdr.dport));
		
		fprintf(stdout, "TCP_HDR:%d\n", sizeof(TCP_HDR));
		fprintf(stdout, "SOURCE PORT:%d\n", ntohs(tcphdr.sport));
		fprintf(stdout, "DESTIN PORT:%d\n", ntohs(tcphdr.dport));

		break;
	case IPPROTO_UDP:
		getData(p, &udphdr, sizeof(udphdr));
		p += sizeof(udphdr);
		
		fprintf(file, "UDP_HDR:%d\n", sizeof(UDP_HDR));
		fprintf(file, "SOURCE PORT:%d\n", ntohs(udphdr.sport));
		fprintf(file, "DESTIN PORT:%d\n", ntohs(udphdr.dport));
		
		fprintf(stdout, "UDP_HDR:%d\n", sizeof(UDP_HDR));
		fprintf(stdout, "SOURCE PORT:%d\n", ntohs(udphdr.sport));
		fprintf(stdout, "DESTIN PORT:%d\n", ntohs(udphdr.dport));

		break;
	case IPPROTO_ICMP:
		getData(p, &icmphdr, sizeof(icmphdr));
		p += sizeof(icmphdr);

		fprintf(file, "ICMP_HDR:%d\n", sizeof(ICMP_HDR));
		fprintf(stdout, "ICMP_HDR:%d\n", sizeof(ICMP_HDR));
		break;
	default:
		break;
	}

	bufLen = len - (p - buf);
	
	fprintf(file, "LEN:%d\n", bufLen);
	HexDumpBuffer(file, (unsigned char *)p, bufLen);

	fprintf(stdout, "LEN:%d\n", bufLen);
	HexDumpBuffer(stdout, (unsigned char *)p, bufLen);

	return 0;
}