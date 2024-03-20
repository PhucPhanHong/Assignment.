#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	char c[1000];
	char fileName[100];
	int r;
	int n;
    do{
    	printf("\nMain Menu\n");
    	printf("1. Create a file.\n");
    	printf("2. Add value to file.\n");
   		printf("3. Read data from file.\n");
    	printf("4. Delete file\n");
    	printf("5. Save and quit.\n");
    	printf(".........................\n\n");
    	scanf("%d",&n);

    	switch(n){
    	case 1:
        	r = createFile();
        	break;
    	case 2:
        	r = AddValueToFile();
        	break;
    	case 3:
        	r = ReadValueFromFile();
        	break;
    	case 4:
    	  	r = RemoveFile();
        	break;
    	case 5:
    		printf("exit");
        	break;
        default: 
        	printf("lỗi.");
    	}
    }	while(n != 5);}

int createFile() {
	FILE *file;
	char fileName[100];
	printf("nhap ten file can tao: ");
	scanf("%s", &fileName);
	if((file = fopen(fileName, "w")) == NULL) {
		printf("khong the tao file");
		return 0;
	}
	printf("tao file thanh cong\n");
	fclose(file);
	return 1;}

int AddValueToFile() {
	FILE *file;
	char fileName[100];
	char content[100];
	printf("nhap file can tuong tac: ");
	scanf("%s", &fileName);
	if((file = fopen(fileName, "r")) == NULL) {
		printf("khong the mo %c file", fileName);
		return 0;
	} else {
		file = fopen(fileName, "a");
		printf("noi dung can them vao :\n");
    	scanf(" %[^\n]", content);

    	
    	fprintf(file, "%s\n", content);
	}
	fclose(file);
	printf("them noi dung thanh cong\n");
	printf(".........................\n");

	return 1;}

int ReadValueFromFile() {
	FILE *file;
	char fileName[100];
	char line[100];

	printf("nhap ten file: ");
	scanf("%s", &fileName);
	if((file = fopen(fileName, "r")) == NULL) {
		printf("khong the mo %s file de doc\n", fileName);
		return 0;
	} else {
		printf("\n.........................\n");
		printf("noi dung file %s:\n", fileName);
    	while (fgets(line, sizeof(line), file) != NULL) {
        	printf("%s", line);
    	}
    	printf("\n.........................\n");
	}
	fclose(file);
	printf("doc gia tri tu %s file thanh cong\n", fileName);
	printf(".........................\n");
	return 1;}

int RemoveFile() {
	FILE *file;
	char fileName[100];

	printf("Enter a fileName: ");
	scanf("%s", &fileName);
	printf("\n.........................\n");
	if (remove(fileName) == 0) {
        	printf("File %s xoa thanh cong.\n", fileName);
    	} else {
        printf("khong the xoa file %s.\n", fileName);
        	return 0;
    	}
		printf("\n.........................\n");
	printf(".........................\n");
	return 1;}

