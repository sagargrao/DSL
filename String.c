#include <stdio.h>
#include <string.h>

char str[100], pat[50], rep[50], ans[100];
int i = 0, j = 0, k, c, flag = 0;

void stringmatch() {
    i = j = c = 0;

    while (str[c] != '\0') {
        if (str[c] == pat[i]) {
            i++;
            c++;

            // Pattern fully matched
            if (pat[i] == '\0') {
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++) {
                    ans[j] = rep[k];
                }
                i = 0;
            }
        } 
        else {
            // Copy unmatched character
            ans[j++] = str[c++];
            i = 0;
        }
    }
    ans[j] = '\0';
}

int main() {
    printf("Enter the main string:\n");
    gets(str);

    printf("Enter the pattern string:\n");
    gets(pat);

    printf("Enter the replace string:\n");
    gets(rep);

    stringmatch();

    if (flag == 1)
        printf("The result string is: %s\n", ans);
    else
        printf("Pattern NOT FOUND\n");

    return 0;
}
