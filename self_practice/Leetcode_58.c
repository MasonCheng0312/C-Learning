int lengthOfLastWord(char* s) {
    char* str_end = s;
    while(*str_end != '\0'){ // find position of \0
        str_end++;
    }
    while(*str_end == '\0' || *str_end == ' '){
        str_end--;
    }
    char* str_start = str_end;
    while(str_start >= s && *str_start != ' '){
        str_start--;
    }// 將邊界判斷邏輯放置於取值之前避免越界存取。
    return str_end - str_start;

}