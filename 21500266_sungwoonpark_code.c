// gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // memset
#define G_SIZE 1024

typedef enum _CITY {
	Busan,
	Daegu,
	Daejeon,
	Gangeung,
	Gwangju,
	Jeonju,
	Jinju,
	Pohang,
	Seoul,
	Wonju
} CITY;

typedef struct ADJ_NODE {
	int distance;
	int dest;
	char *city;
	struct ADJ_NODE *next;
} NODE;

typedef struct ADJ_LIST {
	NODE *head;
}LIST;

typedef struct _GRAPH {
	int V;
	LIST *list;
}GRAPH;

struct ADJ_NODE* newAdjNode(int dest, int distance)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	if (dest == 0) newNode->city = "Busan";
	else if(dest == 1) newNode->city = "Daegu";
	else if(dest == 2) newNode->city = "Daejeon";
	else if(dest == 3) newNode->city = "Gangeung";
	else if(dest == 4) newNode->city = "Gwangju";
	else if(dest == 5) newNode->city = "Jeonju";
	else if(dest == 6) newNode->city = "Jinju";
	else if(dest == 7) newNode->city = "Pohang";
	else if(dest == 8) newNode->city = "Seoul";
	else newNode->city = "Wonju";
	newNode->dest = dest;
	newNode->distance = distance;
	newNode->next = NULL;
	return newNode;
}

struct _GRAPH* createGraph(int V)
{
	GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
	graph->V = V;
	graph->list = (LIST*)malloc(V * sizeof(LIST));
	int i;
	for (i=0;i<V;++i)
		graph->list[i].head = NULL;
	return graph;
}

void add(GRAPH* graph, int src, int dest, int distance)
{
	NODE* newNode = newAdjNode(dest, distance);
	newNode->next = graph->list[src].head;
	graph->list[src].head = newNode;

	newNode = newAdjNode(src, distance);
	newNode->next = graph->list[dest].head;
	graph->list[dest].head = newNode;
}

void printGraph(GRAPH* graph)
{
	int v;
	for (v=0; v<graph->V; ++v){
		NODE* showList = graph->list[v].head;
		if (v==0) {
			printf("Busan ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v==1) {
			printf("Daegu ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v==2) {
			printf("Daejeon ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v==3) {
			printf("Gangeung ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v==4) {
			printf("Gwangju ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v==5) {
			printf("Jeonju ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v==6) {
			printf("Jinju ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v==7) {
			printf("Pohang ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v==8) {
			printf("Seoul ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v==9) {
			printf("Wonju ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else { 
			printf("error in printGraph() : name other than city is on the list\n");
		}
	}
}

char *readFile(char *filename, int *readSize)
{
	FILE *fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("error in readFile() : could not read file\n");
		return NULL;
	}
	int size;
	char *buf;
	fseek(fp, 0, SEEK_END); 
	size = ftell(fp);
	rewind(fp);
	buf = malloc(size+1);
	memset(buf, 0, size + 1);
	while (!feof(fp)) {
		fread(buf,size,1,fp);
	}
	*readSize = size;
	fclose(fp);
	return buf;
}

int main()
{
	int size;
	char *file = readFile("hw6_2019.data",&size);
//	FILE *fp = fopen("hw6_2019.data","rb");	
	if (file == NULL) {
		printf("error in main() : could not open file\n");
		return -1;
	}
	printf("%s\n",file);
	/////////////////////////////// THIS PART MAKE ADJACENT LIST GRAPH ///////////////////////
	int V = 10;
	int dist;
	char distc[4] = {0};
	int row = 0, col = 0;
	GRAPH* graph = createGraph(V);
	CITY src;
	CITY dest;
	int i;
//	char c;
//	while ((c=fgetc(fp)) != EOF) {
	for (i=0; i<size; i++) {
//		c = fgetc(fp);
		if (file[i] == ' ' || file[i] == '\n' || file[i] == '\t') {
			if ( file[i] == '\n') row++;
			i++;
			col++;
			continue;
		}
		else if (file[i] == 'I' || file[i] == 'N' || file[i] == 'F') {
			i+=3;
			continue;
		} 
		else if (file[i] == '0' || file[i] == '1'
				|| file[i] == '2'
				|| file[i] == '3'
				|| file[i] == '4'
				|| file[i] == '5'
				|| file[i] == '6'
				|| file[i] == '7'
				|| file[i] == '8'
				|| file[i] == '9') {
			while (file[i] != ' ' || file[i] != '\n' || file[i] != '\t') {
				distc[i] = file[i];
				i++;
			}
			dist = atof(distc);
			if (dist == 0) continue;
			else add(graph, row, col, dist);						
		}
		else if (file[i] == 0x0) break;
		else {
			i++;
			continue;
		}
	}
	printf("test add");
	printGraph(graph);
	/////////////////////////////// THIS PART MAKE ADJACENT LIST GRAPH ///////////////////////

	free(file);
	printf("FINISH\n");
	return 0;
}
