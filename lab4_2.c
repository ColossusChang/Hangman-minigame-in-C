#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"wordbank.h"
#include<time.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int score = 10;
	char items[6]="*/#@$";
	char word[50];
	char gword[50];
	char gwordn[50];
	char tae[54]="                                                    ";
	char gl;
	char GL[1];
	char apb[26] = "abcdefghijklmnopqrstuvwxyz";
	char vwl[6] = "aeiou";
	int i,w;
	int wr = 0;
	//srand((unsigned)time(NULL));//rand word
	//strcpy(word, words[rand() % 49]);
	printf("input the word number:");
	scanf("%d", &w);
	strcpy(word, words[w]);
	strcpy(gword, word);//create the guessword
	strcat(gword, word);
	for (i = 0; i < 2 * strlen(word); i = i + 2)
		gword[i] = '_';
	for (i = 1; i < 2 * strlen(word); i = i + 2)
		gword[i] = ' ';
	while (score>0)
	{
		printf("Score: %d\nItem: ", score);//print score
		printf("%s\n", items);	
		printf("%s\n", gword);
		printf("%s\n", word);//del
		printf("Already known wrong answers: %s\n", tae);
		for (int T = 0; T <= 2 * strlen(word); T++)
		{
			gwordn[T] = gword[2 * T];
		}
		if (strcmp(gwordn, word) == 0)
			break;
		printf("Please enter a letter : ");
		scanf("%s", &gl);
		GL[0] = gl; GL[1] = '\0';
		printf("\n");
		if (gl >= 'a' && gl <= 'z')
		{
			if (strstr(word, GL))
			{
				for (int T = 0; T <= 2 * strlen(word); T++)
				{
					if (word[T] == gl)
						gword[2 * T] = gl;
				}
			}
			else
			{
				score--;
				if (wr == 0)
				{
					tae[wr] = gl;
					wr++;
				}
				else
				{
					tae[wr] = ',';
					tae[wr+1] = gl;
					wr += 2;
				}				
			}
		}
		else if (gl == '*')
		{
			char gwordnew[50];
			strcpy(gwordnew, gword);
			while (strcmp(gwordnew, gword) == 0)
			{
				int ran = rand() % (strlen(word));
				gword[2 * (ran)] = word[ran];
			}
			items[0] = ' ';
		}
		else if (gl == '/')
		{
			for (i = 0; i < 2; i++)
			{
				srand((int)time(NULL));
				int ran = rand() % (26);
				char RAN[2];
				RAN[0] = apb[ran]; RAN[1] = '\0';
				while (strstr(word, RAN) || strstr(tae, RAN))
				{
					srand((int)time(NULL));
					ran = rand() % (26);
					RAN[0] = apb[ran]; RAN[1] = '\0';
				}
				if (wr == 0)
				{
					tae[wr] = apb[ran];
					wr++;
				}
				else
				{
					tae[wr] = ',';
					tae[wr + 1] = apb[ran];
					wr += 2;
				}
			}
			items[1] = ' ';
		}	
		else if (gl == '#')
		{
			break;
		}
		else if (gl == '@')
		{
			for (int y = 0; y <strlen(word); y++)
			{
				for (int u = 0; u < strlen(vwl); u++)
					if (word[y] == vwl[u] && word[y] != gword[2 * y])
						gword[2 * y] = gl;
			}
			items[3] = ' ';
		}
		else if (gl == '$')
		{
			srand((int)time(NULL));
			int ran = rand() % (4);
			if (ran == 0)//*
			{
				char gwordnew[50];
				strcpy(gwordnew, gword);
				while (strcmp(gwordnew, gword) == 0)
				{
					int ran = rand() % (strlen(word));
					gword[2 * (ran)] = word[ran];
				}
			}
			else if (ran == 1)//'/'
			{
				for (i = 0; i < 2; i++)
				{
					srand((int)time(NULL));
					int ran = rand() % (26);
					char RAN[2];
					RAN[0] = apb[ran]; RAN[1] = '\0';
					while (strstr(word, RAN) || strstr(tae, RAN))
					{
						srand((int)time(NULL));
						ran = rand() % (26);
						RAN[0] = apb[ran]; RAN[1] = '\0';
					}
					if (wr == 0)
					{
						tae[wr] = apb[ran];
						wr++;
					}
					else
					{
						tae[wr] = ',';
						tae[wr + 1] = apb[ran];
						wr += 2;
					}
				}
			}
			else if (ran == 2)//'#'
			{
				break;
			}
			else if (ran == 3)//@
			{
				for (int y = 0; y < strlen(word); y++)
				{
					for (int u = 0; u < strlen(vwl); u++)
						if (word[y] == vwl[u] && word[y] != gword[2 * y])
							gword[2 * y] = '@';
				}
			}
			items[4] = ' ';
		}
	}
	if (strcmp(gwordn, word) == 0)
		printf("You win. \n");
	else
	{
		printf("You lose. \n");
		printf("The right answer is: %s\n", word);
	}	
	return 0;
}