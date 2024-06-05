void reverseString(char* s, int sSize) {
    char *start = s;
    char *end = s + sSize-1;

    if(!s) return;

    while(start < end)
    {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
    return;
}