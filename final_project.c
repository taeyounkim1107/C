#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct data {
	int beonho;
	char nalja[20];
	char sooji[20];
	char hangmok[20];
	char bunryu[20];
	int geumaek;
	char card[20];
} data;

int line(FILE*);           //accout_book.txt 데이터의 가로 줄의 갯수를 세는 함수 생성  
void read(FILE*, data*);  //파일을 읽어드려서 acc 스트럭쳐에 저장하는 함수
void print(data*, int);    //파일을 읽어드려서 acc 스트럭쳐에 저장하는 함수  
void problem2(data*, int);
void problem3(data*);
void problem4(data*);
void problem5(data*);
void problem6(data*);
void problem7(data*);
void problem8_1(data*);
void problem8_2(data*);
void problem9(data*);
void problem10(data*);
void problem11(void);

int main() {
	FILE* fp;
	data* acc;                     //우리 가계부 데이터를 struct로  생성하였다  
	int line_num;                  //데이터의 가로행 수 
	fp = fopen("account_book.txt", "rt");

	if (!(fp = fopen("account_book.txt", "rt")))   //파일이 제대로 열리지 않을 경우 다음을 실행한다.  
	{
		fprintf(stderr, "account_book.txt does not exist\n");
		exit(1);
	}

	line_num = line(fp);                   //line 함수를 실행하여 가로행의 수를 세고 line_num에 저장한다. 
	acc = (data*)malloc(sizeof(data) * line_num * 2);   //데이터 저장을 위한 동적 메모리 지정  
	read(fp, acc);                         //txt파일로부터 데이터를 acc structure에 저장하는 함수 실행  
	print(acc, line_num);                   //acc에 저장된 값들을 화면상에 띄우는 함수 

	problem2(acc, line_num);

	problem3(acc);

	problem4(acc);
	problem5(acc);
	problem6(acc);
	problem7(acc);

	int ans;
	printf("\n\n                                    <Problem8>");
	printf("\n-----------------------------------------------------------------------------------\n");
	while (1)   //problem 8은 부득이하게 이렇게 코딩하였다. 
	{
		printf("\n      (1)날짜순으로 정렬하시겠습니까 아니면 (2)분류순으로  정렬하시겠습니까?");
		scanf("%d", &ans);
		if (ans == 1)
		{
			problem8_1(acc);
			break;
		}
		else if (ans == 2)
		{
			problem8_2(acc);
			break;
		}
		else
			printf("\n                        잘못 누르셨습니다. 다시 입력하세요");
	}



	problem9(acc);
	problem10(acc);
	problem11();
	fclose(fp);
	return 0;
}


int line(FILE* fp)       //파일의 가로행 갯수 세는 함수  
{

	char data_tmp[100], string[100];
	int line_num = 0;

	while (fgets(data_tmp, 100, fp))

	{
		if (sscanf(data_tmp, "%s", string) != 1)
			continue;
		line_num++;
	}

	rewind(fp);

	return line_num;
}



void read(FILE* fp, data* acc)       //파일을 읽어드려서 acc 스트럭쳐에 저장하는 함수  
{
	int i, r;
	int beonho, geumaek;
	char nalja[20], sooji[20], hangmok[20], bunryu[20], card[20];
	i = 0;
	while ((r = fscanf(fp, "%d %s %s %s %s %d %s", &beonho, nalja, sooji, hangmok, bunryu, &geumaek, card)) != EOF)
	{
		acc[i].beonho = beonho;
		acc[i].geumaek = geumaek;
		strcpy(acc[i].nalja, nalja);
		strcpy(acc[i].sooji, sooji);
		strcpy(acc[i].hangmok, hangmok);
		strcpy(acc[i].bunryu, bunryu);
		strcpy(acc[i].card, card);
		i++;
	}

}



void print(data* acc, int line_num)      //화면상에 가계부 출력하는 함수 
{
	printf("%-10s  %-10s  %-10s    %-10s  %-10s  %-10s  %-10s\n", "번호", "날짜", "수입/지출", "항목", "분류", "금액", "카드/현금");
	printf("-----------------------------------------------------------------------------------\n");
	int i;
	for (i = 0; i < line_num; i++)
		printf("%-9d%-10s       %-10s  %-10s  %-10s  %-10d    %-10s\n", acc[i].beonho, acc[i].nalja, acc[i].sooji, acc[i].hangmok, acc[i].bunryu, acc[i].geumaek, acc[i].card);
}

void problem2(data* acc, int line_num) // 2번 문제에 대한 함수입니다.
{

	int i;
	for (i = line_num - 1; i >= 2; i--)
	{
		acc[i + 1].beonho = acc[i].beonho + 1;
		acc[i + 1].geumaek = acc[i].geumaek;
		strcpy(acc[i + 1].nalja, acc[i].nalja);
		strcpy(acc[i + 1].sooji, acc[i].sooji);
		strcpy(acc[i + 1].hangmok, acc[i].hangmok);
		strcpy(acc[i + 1].bunryu, acc[i].bunryu);
		strcpy(acc[i + 1].card, acc[i].card);
	}
	char nalja[20] = "2019-11-15";
	char sooji[20] = "지출";
	char hangmok[20] = "햄버거";
	char bunryu[20] = "식비";
	char card[20] = "카드";

	acc[2].beonho = 3;
	acc[2].geumaek = 7000;
	strcpy(acc[2].nalja, nalja);
	strcpy(acc[2].sooji, sooji);
	strcpy(acc[2].hangmok, hangmok);
	strcpy(acc[2].bunryu, bunryu);
	strcpy(acc[2].card, card);

	for (i = line_num; i >= 9; i--)
	{
		acc[i + 1].beonho += 1;
		acc[i + 1].geumaek = acc[i].geumaek;
		strcpy(acc[i + 1].nalja, acc[i].nalja);
		strcpy(acc[i + 1].sooji, acc[i].sooji);
		strcpy(acc[i + 1].hangmok, acc[i].hangmok);
		strcpy(acc[i + 1].bunryu, acc[i].bunryu);
		strcpy(acc[i + 1].card, acc[i].card);
	}
	char nalja2[20] = "2019-10-10";
	char sooji2[20] = "수입";
	char hangmok2[20] = "용돈";
	char bunryu2[20] = "용돈";
	char card2[20] = "현금";

	acc[9].beonho = 10;
	acc[9].geumaek = 100000;
	strcpy(acc[9].nalja, nalja2);
	strcpy(acc[9].sooji, sooji2);
	strcpy(acc[9].hangmok, hangmok2);
	strcpy(acc[9].bunryu, bunryu2);
	strcpy(acc[9].card, card2);
	printf("\n\n                                    <Problem2>");
	printf("\n%-10s  %-10s  %-10s    %-10s  %-10s  %-10s  %-10s\n", "번호", "날짜", "수입/지출", "항목", "분류", "금액", "카드/현금");
	printf("-----------------------------------------------------------------------------------\n");

	for (i = 0; i < line_num + 2; i++)
		printf("%-9d%-10s       %-10s  %-10s  %-10s  %-10d    %-10s\n", acc[i].beonho, acc[i].nalja, acc[i].sooji, acc[i].hangmok, acc[i].bunryu, acc[i].geumaek, acc[i].card);
}

void problem3(data* acc) // 3번 문제에 대한 함수입니다.
{
	int i;
	for (i = 1; i <= 16; i++)
	{
		acc[i].beonho = acc[i + 1].beonho - 1;
		acc[i].geumaek = acc[i + 1].geumaek;
		strcpy(acc[i].nalja, acc[i + 1].nalja);
		strcpy(acc[i].sooji, acc[i + 1].sooji);
		strcpy(acc[i].hangmok, acc[i + 1].hangmok);
		strcpy(acc[i].bunryu, acc[i + 1].bunryu);
		strcpy(acc[i].card, acc[i + 1].card);
	}
	printf("\n\n                                    <Problem3>");
	printf("\n%-10s  %-10s  %-10s    %-10s  %-10s  %-10s  %-10s\n", "번호", "날짜", "수입/지출", "항목", "분류", "금액", "카드/현금");
	printf("-----------------------------------------------------------------------------------\n");
	for (i = 0; i < 16; i++)
	{
		if (*(acc[i].nalja + 6) == '0')
			printf("%-9d%-10s       %-10s  %-10s  %-10s  %-10d    %-10s\n", acc[i].beonho, acc[i].nalja, acc[i].sooji, acc[i].hangmok, acc[i].bunryu, acc[i].geumaek, acc[i].card);
		else
			continue;
	}
}
void problem4(data* acc) // 4번 문제에 대한 함수입니다.
{
	printf("\n\n                                    <Problem4>");
	char hangmok[20] = "곱창";
	strcpy(acc[0].hangmok, hangmok);
	printf("\n%-10s  %-10s  %-10s    %-10s  %-10s  %-10s  %-10s\n", "번호", "날짜", "수입/지출", "항목", "분류", "금액", "카드/현금");
	printf("-----------------------------------------------------------------------------------\n");
	printf("%-9d%-10s       %-10s  %-10s  %-10s  %-10d    %-10s\n", acc[0].beonho, acc[0].nalja, acc[0].sooji, acc[0].hangmok, acc[0].bunryu, acc[0].geumaek, acc[0].card);

}
void problem5(data* acc) // 5번 문제에 대한 함수입니다.
{
	int i, ans;
	char date[20], type[20];
	printf("\n\n                                    <Problem5>\n\n");

	printf("                 모든 질문에 대한 답은 1 또는 2로 답하셔야 합니다\n\n");
	printf("                   검색 기능을 실행하시겠습니까? (1=Yes / 2=No)");
	scanf("%d", &ans);
	if (ans == 1)
	{
		printf("\n         (1)날짜 를 검색하시겠습니까 아니면 (2)분류 를 검색하시겠습니까?");
		scanf("%d", &ans);
		if (ans == 1)
		{
			printf("\n                    형식에 맞춰 날짜를 입력하십시오: ");
			scanf("%s", date);
			printf("\n%-10s  %-10s  %-10s    %-10s  %-10s  %-10s  %-10s\n", "번호", "날짜", "수입/지출", "항목", "분류", "금액", "카드/현금");
			printf("-----------------------------------------------------------------------------------\n");
			for (i = 0; i < 16; i++)
			{
				if (strcmp(acc[i].nalja, date) == 0)
					printf("%-9d%-10s       %-10s  %-10s  %-10s  %-10d    %-10s\n", acc[i].beonho, acc[i].nalja, acc[i].sooji, acc[i].hangmok, acc[i].bunryu, acc[i].geumaek, acc[i].card);
				else
					continue;
			}
		}
		else if (ans == 2)
		{
			printf("\n                    형식에 맞춰 분류를 입력하십시오: ");
			scanf("%s", type);
			printf("\n%-10s  %-10s  %-10s    %-10s  %-10s  %-10s  %-10s\n", "번호", "날짜", "수입/지출", "항목", "분류", "금액", "카드/현금");
			printf("-----------------------------------------------------------------------------------\n");
			for (i = 0; i < 16; i++)
			{
				if (strcmp(acc[i].bunryu, type) == 0)
					printf("%-9d%-10s       %-10s  %-10s  %-10s  %-10d    %-10s\n", acc[i].beonho, acc[i].nalja, acc[i].sooji, acc[i].hangmok, acc[i].bunryu, acc[i].geumaek, acc[i].card);
				else
					continue;
			}
		}
		else
		{
			printf("\n                        잘못 누르셨습니다. 다시 입력하세요");
			problem5(acc);
		}
	}
	else
	{
		printf("\n                        잘못 누르셨습니다. 다시 입력하세요");
		problem5(acc);
	}



}

void problem6(data* acc) // 6번 문제에 대한 함수입니다.
{
	printf("\n\n                                    <Problem6>");

	int i;
	int sum_soo = 0;
	int sum_ji = 0;
	char soo[20] = "수입";
	char ji[20] = "지출";
	for (i = 0; i < 16; i++)
	{
		if (strcmp(acc[i].sooji, soo) == 0)
			sum_soo += acc[i].geumaek;
		else if (strcmp(acc[i].sooji, ji) == 0)
			sum_ji += acc[i].geumaek;
	}
	printf("\n-----------------------------------------------------------------------------------\n             총수입: %d원      총지출: %d원      잔액: %d원 ", sum_soo, sum_ji, sum_soo - sum_ji);
}

void problem7(data* acc) // 7번 문제에 대한 함수입니다.
{
	char food[20] = "식비";
	char date[20] = "데이트";
	char clothes[20] = "의류";
	char culture[20] = "문화";
	char travel[20] = "여행";
	char money[20] = "용돈";
	char fee[20] = "회비";
	char deposit[20] = "저금";
	int i, j;
	int num[8] = { 0,0,0,0,0,0,0,0 };
	for (i = 0; i < 16; i++)
	{
		if (strcmp(acc[i].bunryu, food) == 0)
			num[0]++;
		else if (strcmp(acc[i].bunryu, date) == 0)
			num[1]++;
		else if (strcmp(acc[i].bunryu, clothes) == 0)
			num[2]++;
		else if (strcmp(acc[i].bunryu, culture) == 0)
			num[3]++;
		else if (strcmp(acc[i].bunryu, travel) == 0)
			num[4]++;
		else if (strcmp(acc[i].bunryu, money) == 0)
			num[5]++;
		else if (strcmp(acc[i].bunryu, fee) == 0)
			num[6]++;
		else if (strcmp(acc[i].bunryu, deposit) == 0)
			num[7]++;
	}
	printf("\n\n\n                                    <Problem7>");
	printf("\n-----------------------------------------------------------------------------------\n");

	int max = 0;
	for (i = 0; i < 8; i++)
	{
		if (num[i] > max)
			max = num[i];
	}
	for (i = 0; i < max; i++)
	{
		printf("                    ");
		for (j = 0; j < 8; j++)
		{
			if (max - i <= num[j])
				printf("    *");
			else
				printf("     ");
		}
		printf("\n");
	}

	printf("                      식비 데이트 의류 문화 여행 용돈 회비 저금");
	printf("\n");
}
void problem8_1(data* acc) //https://blog.naver.com/sharonichoya/220471295643 8-1번 문제에 대한 함수입니다.
{
	printf("\n\n\n                                    <Problem8_1>");
	int i, j;
	data tempacc;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15 - i; j++)
		{
			if (strcmp(acc[j].nalja, acc[j + 1].nalja) > 0)
			{
				tempacc = acc[j];
				acc[j] = acc[j + 1];
				acc[j + 1] = tempacc;
			}
			else if (strcmp(acc[j].nalja, acc[j + 1].nalja) == 0)
			{
				if (acc[j].geumaek < acc[j + 1].geumaek)
				{
					tempacc = acc[j];
					acc[j] = acc[j + 1];
					acc[j + 1] = tempacc;
				}
			}
		}
	}
	printf("\n%-10s  %-10s  %-10s    %-10s  %-10s  %-10s  %-10s\n", "번호", "날짜", "수입/지출", "항목", "분류", "금액", "카드/현금");
	printf("-----------------------------------------------------------------------------------\n");

	for (i = 0; i < 16; i++)
		printf("%-9d%-10s       %-10s  %-10s  %-10s  %-10d    %-10s\n", acc[i].beonho, acc[i].nalja, acc[i].sooji, acc[i].hangmok, acc[i].bunryu, acc[i].geumaek, acc[i].card);
}
void problem8_2(data* acc) //https://blog.naver.com/sharonichoya/220471295643 8-2번 문제에 대한 함수입니다.
{

	printf("\n\n\n                                    <Problem8_2>");
	int i, j;
	data tempacc;
	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15 - i; j++)
		{
			if (strcmp(acc[j].bunryu, acc[j + 1].bunryu) < 0)
			{
				tempacc = acc[j];
				acc[j] = acc[j + 1];
				acc[j + 1] = tempacc;
			}
			else if (strcmp(acc[j].bunryu, acc[j + 1].bunryu) == 0)
			{
				if (acc[j].geumaek < acc[j + 1].geumaek)
				{
					tempacc = acc[j];
					acc[j] = acc[j + 1];
					acc[j + 1] = tempacc;
				}
			}

		}
	}
	printf("\n%-10s  %-10s  %-10s    %-10s  %-10s  %-10s  %-10s\n", "번호", "날짜", "수입/지출", "항목", "분류", "금액", "카드/현금");
	printf("-----------------------------------------------------------------------------------\n");

	for (i = 0; i < 16; i++)
		printf("%-9d%-10s       %-10s  %-10s  %-10s  %-10d    %-10s\n", acc[i].beonho, acc[i].nalja, acc[i].sooji, acc[i].hangmok, acc[i].bunryu, acc[i].geumaek, acc[i].card);
}

void problem9(data* acc) // 9번 문제에 대한 함수입니다.
{
	printf("\n\n                                    <Problem9>");

	int i;
	int sum_card = 0;
	int sum_bill = 0;
	char card[20] = "카드";
	char bill[20] = "현금";
	char ji[20] = "지출";
	for (i = 0; i < 16; i++)
	{
		if (strcmp(acc[i].card, card) == 0 && strcmp(acc[i].sooji, ji) == 0)
			sum_card += acc[i].geumaek;
		else if (strcmp(acc[i].card, bill) == 0 && strcmp(acc[i].sooji, ji) == 0)
			sum_bill += acc[i].geumaek;
	}
	printf("\n-----------------------------------------------------------------------------------\n             카드: %d원       현금: %d원       합계: %d원 ", sum_card, sum_bill, sum_card + sum_bill);
}

void problem10(data* acc) // 10번 문제에 대한 함수입니다.
{
	int i;
	FILE* fp = fopen("account_book_new.txt", "wt");
	for (i = 0; i < 16; i++)
		fprintf(fp, "%-10d %-10s %-10s %-10s %-10s %-10d %-10s\n", acc[i].beonho, acc[i].nalja, acc[i].sooji, acc[i].hangmok, acc[i].bunryu, acc[i].geumaek, acc[i].card);
	fclose(fp);
}

void problem11(void) // 11번 문제에 대한 함수입니다.
{
	printf("\n\n                                    <Problem11>");
	printf("\n-----------------------------------------------------------------------------------\n");


	printf("                           종료하시겠습니까? (1=YES/2=NO)");
	int a;
	scanf("%d", &a);
	if (a == 1)
		return 0;
	else
	{
		printf("\n                        잘못 누르셨습니다. 다시 입력하세요");
		problem11();
	}
}




