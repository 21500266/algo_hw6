// gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
// student name : sungwoon park
// student ID   : 21500266
// class 	: algorithm - 02
// assignment # : hw6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // memset
#include <time.h>	// clock_t, CLOCKS_PER_SEC

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
	if (dest == 1) newNode->city = "Busan";
	else if (dest == 2) newNode->city = "Daegu";
	else if (dest == 3) newNode->city = "Daejeon";
	else if (dest == 4) newNode->city = "Gangeung";
	else if (dest == 5) newNode->city = "Gwangju";
	else if (dest == 6) newNode->city = "Jeonju";
	else if (dest == 7) newNode->city = "Jinju";
	else if (dest == 8) newNode->city = "Pohang";
	else if (dest == 9) newNode->city = "Seoul";
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
	for (i = 0; i < V; ++i)
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
	for (v = 1; v < graph->V; ++v) {
		NODE* showList = graph->list[v].head;
		if (v == 1) {
			printf("Busan ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v == 2) {
			printf("Daegu ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v == 3) {
			printf("Daejeon ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v == 4) {
			printf("Gangeung ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v == 5) {
			printf("Gwangju ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v == 6) {
			printf("Jeonju ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v == 7) {
			printf("Jinju ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v == 8) {
			printf("Pohang ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v == 9) {
			printf("Seoul ");
			while (showList)
			{
				printf("-> %s", showList->city);
				showList = showList->next;
			}
			printf("\n");
		}
		else if (v == 10) {
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
	buf = malloc(size + 1);
	memset(buf, 0, size + 1);
	while (!feof(fp)) {
		fread(buf, size, 1, fp);
	}
	*readSize = size;
	fclose(fp);
	return buf;
}

int findMin (int a, int b)
{
	return (a < b) ? a : b;
}

void dijkstra(GRAPH* graph)
{ // Busan to Seoul shortest path
	int v;
	int i, z, x;
	int min = 1; // starting point is Busan
//	1		2		3			4			5			6		7		8		9		10
//	Busan	Daegu	Daejeon		Gangeung	Gwangju		Jeonju	Jinju	Pohang	Seoul	Wonju
	int dist[11] = { 0, 0, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999 };
	int s[10] = { 0 };
	x = 0;
	s[x++] = min; // starting point is Busan
	int city;
	for (v = 1; v < graph->V; ++v) {
		NODE* allPath = graph->list[min].head;
		while (allPath)
		{
			city = allPath->dest;
			int temp = dist[min] + allPath->distance;
			if (dist[city] == 99999) {
				dist[city] = temp;
				allPath = allPath->next;
			}
			else {
				int tmp = dist[min] + allPath->distance;
				dist[city] = findMin(dist[city], tmp);
				allPath = allPath->next;
			}
		} 
		min = 99999;
		for (i = 1; i < 11; i++) {	
			if (s[0] == i || s[1] ==i || s[2] == i || s[3] == i
				|| s[4] == i || s[5] == i || s[6] == i || s[7] == i
				|| s[8] == i || s[9] == i)
				continue;
			else {
				min = findMin(min, dist[i]);
//				printf("[%d] : %d\n", i, dist[i]);
			}
		}
		for (z = 1; z < 11; z++) {
			if (dist[z] == min) {
				min = z;
				s[x] = min;
				if (x == 9) break;
				else {
					x++;
					break;
				}
			}
		}
	}
	printf("\nDijkstra relaxed results\n");
	printf("Busan\tDaegu\tDaejeon\tGangeung\tGwangju\tJeonju\tJinju\tPohang\tSeoul\tWonju\n");
	printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",
		dist[1],dist[2],dist[3],dist[4],dist[5],dist[6],dist[7],dist[8],dist[9],dist[10]);
	printf("\n");
}

void bellman_ford(GRAPH *graph)
{ // start with Busan
	int v;
//	1		2		3			4			5			6		7		8		9		10
//	Busan	Daegu	Daejeon		Gangeung	Gwangju		Jeonju	Jinju	Pohang	Seoul	Wonju
	int dist[11] = { 0, 0, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999 };
	int city;
	for (v = 1; v < graph->V; ++v) {
		NODE* allPath = graph->list[v].head;
		while (allPath)
		{
			city = allPath->dest;
			int temp = dist[v] + allPath->distance;
			if (dist[city] == 99999) {
				dist[city] = temp;
				allPath = allPath->next;
			}
			else {
				int tmp = dist[v] + allPath->distance;
				dist[city] = findMin(dist[city], tmp);
				allPath = allPath->next;
			}
		}
	}
	printf("\nBellman-Ford relaxed results\n");
	printf("Busan\tDaegu\tDaejeon\tGangeung\tGwangju\tJeonju\tJinju\tPohang\tSeoul\tWonju\n");
	printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",
		dist[1], dist[2], dist[3], dist[4], dist[5], dist[6], dist[7], dist[8], dist[9], dist[10]);
	printf("\n");
}

void floyd(GRAPH* graph)
{ // start with Busan
	int v;
	//	1		2		3			4			5			6		7		8		9		10
	//	Busan	Daegu	Daejeon		Gangeung	Gwangju		Jeonju	Jinju	Pohang	Seoul	Wonju
	// matrix frame
	int A[11][11] = { 
		{ 0, 0,     0,     0,     0,     0,     0,     0,     0,     0,     0     },
		{ 0, 0,     99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999 },
		{ 0, 99999, 0,     99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999 },
		{ 0, 99999, 99999, 0,     99999, 99999, 99999, 99999, 99999, 99999, 99999 },
		{ 0, 99999, 99999, 99999, 0,     99999, 99999, 99999, 99999, 99999, 99999 },
		{ 0, 99999, 99999, 99999, 99999, 0,     99999, 99999, 99999, 99999, 99999 },
		{ 0, 99999, 99999, 99999, 99999, 99999, 0,     99999, 99999, 99999, 99999 },
		{ 0, 99999, 99999, 99999, 99999, 99999, 99999, 0,     99999, 99999, 99999 },
		{ 0, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 0,     99999, 99999 },
		{ 0, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 0,     99999 },
		{ 0, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 0     }
	};
	int B[11][11] = {
		{ 0, 0,     0,     0,     0,     0,     0,     0,     0,     0,     0     },
		{ 0, 0,     99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999 },
		{ 0, 99999, 0,     99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999 },
		{ 0, 99999, 99999, 0,     99999, 99999, 99999, 99999, 99999, 99999, 99999 },
		{ 0, 99999, 99999, 99999, 0,     99999, 99999, 99999, 99999, 99999, 99999 },
		{ 0, 99999, 99999, 99999, 99999, 0,     99999, 99999, 99999, 99999, 99999 },
		{ 0, 99999, 99999, 99999, 99999, 99999, 0,     99999, 99999, 99999, 99999 },
		{ 0, 99999, 99999, 99999, 99999, 99999, 99999, 0,     99999, 99999, 99999 },
		{ 0, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 0,     99999, 99999 },
		{ 0, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 0,     99999 },
		{ 0, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999, 0     }
	};
	printf("\nfloyd algorithm matrix\n");
/*	for (int a = 0; a < 11; a++) {
		printf("{ %d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d\t }\n", 
			A[a][0], A[a][1], A[a][2], A[a][3], A[a][4], A[a][5], A[a][6], A[a][7], A[a][8], A[a][9], A[a][10] );
	}*/
	int city;
	int i;
	// initialize matrix
	for (v = 1; v < graph->V; ++v) {
		NODE* allPath = graph->list[v].head;
		while (allPath)
		{
			city = allPath->dest;
			if (A[v][city] == 99999) {
				A[v][city] = allPath->distance;
				allPath = allPath->next;
			}
			else continue;
		}
	}
	// print A0 matrix
	for (int a = 0; a < 11; a++) {
		printf("{ %d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d\t }\n",
			A[a][0], A[a][1], A[a][2], A[a][3], A[a][4], A[a][5], A[a][6], A[a][7], A[a][8], A[a][9], A[a][10]);
	}
	printf("\n");
	for (i = 1; i < graph->V; ++i) {
		for (int j = 1; j < graph->V; ++j) {
			for (int z=1; z<graph->V; ++z)
			{
				if (i % 2 == 1) {
					B[j][z] = findMin(A[j][z], A[j][i] + A[i][z]);
				}
				else {
					A[j][z] = findMin(B[j][z], B[j][i] + B[i][z]);
				}
			}
		}
		if (v % 2 == 0) {
			for (int a = 0; a < 11; a++) {
				printf("{ %d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d\t }\n",
					A[a][0], A[a][1], A[a][2], A[a][3], A[a][4], A[a][5], A[a][6], A[a][7], A[a][8], A[a][9], A[a][10]);
			}
			printf("\n");
		}
		else {
			for (int a = 0; a < 11; a++) {
				printf("{ %d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d,\t%d\t }\n",
					B[a][0], B[a][1], B[a][2], B[a][3], B[a][4], B[a][5], B[a][6], B[a][7], B[a][8], B[a][9], B[a][10]);
			}
			printf("\n");
		}
	}
}

int main()
{
	int size;
	char *file = readFile("hw6_2019.data", &size);
//	FILE *fp = fopen("hw6_2019.data","rb");	
	if (file == NULL) {
		printf("error in main() : could not open file\n");
		return -1;
	}
	printf("%s\n", file);
	/////////////////////////////// THIS PART MAKE ADJACENT LIST GRAPH ///////////////////////
	int V = 10 + 1 ;
	int dist;
	char distc[3] = { 0 };
	int row = 0, col = 0;
	int exist[11][11] = { 0 };
	GRAPH* graph = createGraph(V);
	int i;
	//	char c;
	//	while ((c=fgetc(fp)) != EOF) {
	for (i = 0; i < size; i++) {
		//		c = fgetc(fp);
		if (file[i] == ' ' || file[i] == '\n' || file[i] == '\t' || file[i] == '\r') {
			if (file[i] == '\n') {
				col = 0;
				row++;
				continue;
			}
			if (file[i + 1] == ' ' || file[i + 1] == '\t' || file[i+1] == '\r' || file[i+1] == '\n') continue;
			col++;
			continue;
		}
		else if (file[i] == 'I' || file[i] == 'N' || file[i] == 'F') {
			i += 2;
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
			int j, z=0;
			for (j=i; j<i+4; ++j) {
				if (file[j] == ' ' || file[j] == '\n' || file[j] == '\t' || file[j] == '\r') {
					break;
				}
				distc[z++] = file[j];
			}
			i = j;
			z = 0;
//			printf("%s\n", distc);
			dist = (int)atof(distc);
			memset(distc, 0, 3);
//			printf("%d\n", dist);
			if (dist == 0) {
				if (file[i + 1] == ' ' || file[i + 1] == '\n' || file[i + 1] == '\t' || file[i + 1] == '\r')
					continue;
				col++;
				continue;
			}
			else {
				if (exist[row][col] == 1) {
					;
				}
				else {
					add(graph, row, col, dist);
					exist[col][row] = 1;
				}
				if (file[i + 1] == ' ' || file[i + 1] == '\n' || file[i + 1] == '\t' || file[i + 1] == '\r')
					continue;
				col++;
				continue;
			}
		}
		else if (file[i] == 0x0) break;
		else {
			continue;
		}
	}
//	printf("test add()\n");
	printGraph(graph);
	/////////////////////////////// THIS PART MAKE ADJACENT LIST GRAPH ///////////////////////
	clock_t t;
	/////////////////////////////// Dijkstra's algorithm ////////////////////////////////////
	t = clock();
	dijkstra(graph);
	t = clock() - t;
	double runtime1 = ((double)t) / CLOCKS_PER_SEC;
	printf("runtime of dijkstra algorithm is -> %f sec\n", runtime1);
	printf("\n");
	////////////////////////////// Dijkstra's algorithm /////////////////////////////////////
	////////////////////////////// Bellman-Ford algorithm ///////////////////////////////////
	t = clock();
	bellman_ford(graph);
	t = clock() - t;
	double runtime2 = ((double)t) / CLOCKS_PER_SEC;
	printf("runtime of bellman-ford algorithm is -> %f sec\n", runtime2);
	printf("\n");
	////////////////////////////// Bellman-Ford algorithm ///////////////////////////////////
	////////////////////////////// Floyd algorithm //////////////////////////////////////////
	t = clock();
	floyd(graph);
	t = clock() - t;
	double runtime3 = ((double)t) / CLOCKS_PER_SEC;
	printf("runtime of floyd algorithm is -> %f sec\n", runtime3);
	printf("\n");
	////////////////////////////// Floyd algorithm //////////////////////////////////////////
	free(file);
	printf("FINISH\n");
	return 0;
}
