#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 80
#define MAX_TEXT 1000

void print_lines(char text[]);
void count_chars(char text[]);
void count_spaces(char text[]);
void count_nums(char text[]);
void count_string(char text[], char search_string[]);
void remove_substring(char text[], char substring[]);

int main() {
    // 读取用户输入的文章
    printf("请输入一页文字：\n"); 
    char text[MAX_TEXT];
    fgets(text, MAX_TEXT, stdin);
	
     // 添加 switch 选择结构，方便选择不同的操作
     while(1){
     	int choice;
	    printf("------------------------------请选择操作：----------------------------------------\n");
	    printf("------------------------------1. 分行输出文章-------------------------------------\n");
	    printf("------------------------------2. 统计字母、空格、数字和总字数---------------------\n");
	    printf("------------------------------3. 搜索字符串出现次数-------------------------------\n");
	    printf("------------------------------4. 删除字符串---------------------------------------\n");
	    printf("------------------------------5. 退出系统-----------------------------------------\n");
	    scanf("%d", &choice);
	    switch (choice) {
	        case 1:  // 分行输出用户输入的各行字符
	            print_lines(text);
	            break;
	        case 2:  // 统计文章中的字母数、空格数、数字数和总字数
	            count_chars(text);
	            count_spaces(text);
	            count_nums(text);
	            break;
	        case 3:  // 统计某一字符串在文章中出现的次数
	            char search_string[MAX_TEXT];
	            printf("请输入要搜索的字符串：");
	            scanf("%s", search_string);
	            count_string(text, search_string);
	            break;
	        case 4:  // 删除某一子串，并将后面的字符前移
	            char substring[MAX_TEXT];
	            printf("请输入要删除的子串：");
	            scanf("%s", substring);
	            remove_substring(text, substring);
	            printf("删除子串后的文章：\n");
	            print_lines(text);  // 输出删除子串后的文章
	            break;
	        case 5:
	        	exit(0); 
	    		break;
	        default:
	            printf("请输入正确的操作编号\n");
	            break;
	    }
	 }
    return 0;
}

// 分行输出用户输入的各行字符
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

// 统计文章中的字母数
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
    printf("全部字母数：%d\n", count);
}

// 统计文章中的空格数
void count_spaces(char text[]) {
    int i;
    int len = strlen(text);
    int count = 0;
    for (i = 0; i < len; i++) {
        if (text[i] == ' ') {
            count++;
        }
    }
    printf("空格个数：%d\n", count);
}

// 统计文章中的数字数
void count_nums(char text[]) {
    int i;
    int len = strlen(text);
    int count = 0;
    for (i = 0; i < len; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            count++;
        }
    }
    printf("数字个数：%d\n", count);
}

// 统计某一字符串在文章中出现的次数
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
    printf("'%s' 出现的次数：%d\n", search_string, count);
}

// 删除某一子串，并将后面的字符前移
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
