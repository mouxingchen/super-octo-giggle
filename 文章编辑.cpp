#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 80
#define MAX_TEXT INT_MAX

void print_lines(char text[]);
void count_chars(char text[]);
void count_spaces(char text[]);
void count_nums(char text[]);
void count_string(char text[], char search_string[]);
void remove_substring(char text[], char substring[]);

int main() {
    // ��ȡ�û����������
    printf("������һҳ���֣�\n"); 
    char text[MAX_TEXT];
    fgets(text, MAX_TEXT, stdin);
	
     // ��� switch ѡ��ṹ������ѡ��ͬ�Ĳ���
     while(1){
     	int choice;
	    printf("------------------------------��ѡ�������----------------------------------------\n");
	    printf("------------------------------1. �����������-------------------------------------\n");
	    printf("------------------------------2. ͳ����ĸ���ո����ֺ�������---------------------\n");
	    printf("------------------------------3. �����ַ������ִ���-------------------------------\n");
	    printf("------------------------------4. ɾ���ַ���---------------------------------------\n");
	    printf("------------------------------5. �˳�ϵͳ-----------------------------------------\n");
	    scanf("%d", &choice);
	    switch (choice) {
	        case 1:  // ��������û�����ĸ����ַ�
	            print_lines(text);
	            break;
	        case 2:  // ͳ�������е���ĸ�����ո�������������������
	            count_chars(text);
	            count_spaces(text);
	            count_nums(text);
	            break;
	        case 3:  // ͳ��ĳһ�ַ����������г��ֵĴ���
	            char search_string[MAX_TEXT];
	            printf("������Ҫ�������ַ�����");
	            scanf("%s", search_string);
	            count_string(text, search_string);
	            break;
	        case 4:  // ɾ��ĳһ�Ӵ�������������ַ�ǰ��
	            char substring[MAX_TEXT];
	            printf("������Ҫɾ�����Ӵ���");
	            scanf("%s", substring);
	            remove_substring(text, substring);
	            printf("ɾ���Ӵ�������£�\n");
	            print_lines(text);  // ���ɾ���Ӵ��������
	            break;
	        case 5:
	        	exit(0); 
	    		break;
	        default:
	            printf("��������ȷ�Ĳ������\n");
	            break;
	    }
	 }
    return 0;
}

// ��������û�����ĸ����ַ�
void print_lines(char text[]){
    int i;
    int len = strlen(text);
    for (i = 0; i < len; i++) {
        printf("%c", text[i]);
        if (text[i] == '\n') {
            continue;
        }
        if ((i + 1) % MAX_LINE == 0) {
            printf("\n");
        }
    }
}

// ͳ�������е���ĸ��
void count_chars(char text[]) {
    int i;
    int len = strlen(text);
    int count = 0;
    for (i = 0; i < len; i++) {
        if ((text[i] >= 'A' && text[i] <= 'Z') ||
            (text[i] >= 'a' && text[i] <= 'z')) {
            count++;
        }
    }
    printf("ȫ����ĸ����%d\n", count);
}

// ͳ�������еĿո���
void count_spaces(char text[]) {
    int i;
    int len = strlen(text);
    int count = 0;
    for (i = 0; i < len; i++) {
        if (text[i] == ' ') {
            count++;
        }
    }
    printf("�ո������%d\n", count);
}

// ͳ�������е�������
void count_nums(char text[]) {
    int i;
    int len = strlen(text);
    int count = 0;
    for (i = 0; i < len; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            count++;
        }
    }
    printf("���ָ�����%d\n", count);
}

// ͳ��ĳһ�ַ����������г��ֵĴ���
void count_string(char text[], char search_string[]) {
    int i, j;
    int count = 0;
    int text_len = strlen(text);
    int search_len = strlen(search_string);

    for (i = 0; i <= text_len - search_len; i++) {
        for (j = 0; j < search_len; j++) {
            if (text[i + j] != search_string[j]) {
                break;
            }
        }
        if (j == search_len) {
            count++;
        }
    }
    printf("'%s' ���ֵĴ�����%d\n", search_string, count);
}

// ɾ��ĳһ�Ӵ�������������ַ�ǰ��
void remove_substring(char text[], char substring[]) {
    int i, j, k;
    int text_len = strlen(text);
    int sub_len = strlen(substring);

    for (i = 0; i <= text_len - sub_len; i++) {
        for (j = 0; j < sub_len; j++) {
            if (text[i + j] != substring[j]) {
                break;
            }
        }
        if (j == sub_len) {
            for (k = i; k <= text_len - sub_len; k++) {
                text[k] = text[k + sub_len];
            }
            text_len -= sub_len;
            i -= sub_len;
        }
    }
}
