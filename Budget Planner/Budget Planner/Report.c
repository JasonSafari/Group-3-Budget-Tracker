#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include "Report.h"
#define MAX_TRANSACTIONS 1000

TRANSACTION transactions[MAX_TRANSACTIONS];
int transactionCount = 0;

void LoadTransactions(char* filename) {

	FILE* file = fopen(filename, "r");

	if (!file) {
	
		printf("Error Couldn't Open File %s\n",filename);
		return;
	
	}

	char line[1024];

	while (fgets(line, sizeof(line), file)) {

		TRANSACTION t;
		
		if (sscanf(line, "%10[^,],%9[^,],%19[^,],%49[^,],%lf",
			t.date, t.type, t.category, t.description, &t.amount) == 5) {
			transactions[transactionCount++] = t;
		}
	}

	fclose(file);

}


