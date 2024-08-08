#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char infix_eq[100];
char postfix_eq[100];

int size_of(char xyz[]) {
    int y = 0;
    int cnt = 0;
    while (xyz[y] != '\0') {
        cnt++;
        y++;
    }
    return cnt;
}

void infix() {
    printf("ENTER EXPRESSION (end with ';'): ");
    int l = 0;
    char ch;
    while ((ch = getchar()) != ';') {
        infix_eq[l++] = ch;
    }
    infix_eq[l] = '\0'; // Null-terminate the string

    int count = size_of(infix_eq);
    printf("\n");

    for (int j = 0; j < count; j++) {
        int loop = 3;
        if ((infix_eq[j] >= 'a' && infix_eq[j] <= 'z') || (infix_eq[j] >= 'A' && infix_eq[j] <= 'Z') || infix_eq[j] == '+' || infix_eq[j] == '-' || infix_eq[j] == '*' || infix_eq[j] == '/') {
            while (infix_eq[j] != '(' && infix_eq[j] != ';' && infix_eq[j] != '\0') {
                if (infix_eq[j + 3] == '*' || infix_eq[j + 3] == '/') {
                    loop = 5;
                } else if (infix_eq[j + 5] == '*' || infix_eq[j + 5] == '/') {
                    loop = 7;
                } else if (infix_eq[j + 7] == '*' || infix_eq[j + 7] == '/') {
                    loop = 9;
                } else if (infix_eq[j + 9] == '*' || infix_eq[j + 9] == '/') {
                    loop = 11;
                }
                int z = size_of(postfix_eq);
                for (int h = z; h < loop + z && infix_eq[j] != '\0'; h++) {
                    if ((infix_eq[j] >= 'a' && infix_eq[j] <= 'z') || (infix_eq[j] >= 'A' && infix_eq[j] <= 'Z')) {
                        postfix_eq[h] = infix_eq[j];
                        j++;
                    } else {
                        j++;
                    }
                }
                for (int h = size_of(postfix_eq); h < z + loop && infix_eq[j] != '\0'; h++) {
                    if (infix_eq[j] == '+' || infix_eq[j] == '-' || infix_eq[j] == '*' || infix_eq[j] == '/') {
                        postfix_eq[h] = infix_eq[j];
                        j++;
                    } else {
                        j++;
                    }
                }
            }
        } else if (infix_eq[j] == '(') {
            int counter = 0, loop1 = 4;
            while (infix_eq[j] != ')' && infix_eq[j] != '\0') {
                counter++;
                j++;
            }
            for (int k = 0; k < counter; k++) {
                if ((infix_eq[k] >= 'a' && infix_eq[k] <= 'z') || (infix_eq[k] >= 'A' && infix_eq[k] <= 'Z') || infix_eq[k] == '+' || infix_eq[k] == '-' || infix_eq[k] == '*' || infix_eq[k] == '/') {
                    if (infix_eq[k + 4] == '*' || infix_eq[k + 4] == '/') {
                        loop1 = 6;
                    } else if (infix_eq[k + 6] == '*' || infix_eq[k + 6] == '/') {
                        loop1 = 8;
                    } else if (infix_eq[k + 8] == '*' || infix_eq[k + 8] == '/') {
                        loop1 = 10;
                    } else if (infix_eq[k + 10] == '*' || infix_eq[k + 10] == '/') {
                        loop1 = 12;
                    }
                    int z1 = size_of(postfix_eq);
                    for (int h2 = z1; h2 < z1 + loop1 && infix_eq[k] != '\0'; h2++) {
                        if ((infix_eq[k] >= 'a' && infix_eq[k] <= 'z') || (infix_eq[k] >= 'A' && infix_eq[k] <= 'Z')) {
                            postfix_eq[h2] = infix_eq[k];
                            k++;
                        } else {
                            k++;
                        }
                    }
                    for (int h2 = size_of(postfix_eq); h2 < z1 + loop1 && infix_eq[k] != '\0'; h2++) {
                        if (infix_eq[k] == '+' || infix_eq[k] == '-' || infix_eq[k] == '*' || infix_eq[k] == '/') {
                            for (int h2 = size_of(postfix_eq); h2 < z1 + loop1 && infix_eq[k] != '\0'; h2++) {
                                if (infix_eq[k] == '/') {
                                    postfix_eq[h2] = infix_eq[k];
                                    k++;
                                } else {
                                    k++;
                                }
                            }
                            for (int h2 = size_of(postfix_eq); h2 < z1 + loop1 && infix_eq[k] != '\0'; h2++) {
                                if (infix_eq[k] == '*') {
                                    postfix_eq[h2] = infix_eq[k];
                                    k++;
                                } else {
                                    k++;
                                }
                            }
                            for (int h2 = size_of(postfix_eq); h2 < z1 + loop1 && infix_eq[k] != '\0'; h2++) {
                                if (infix_eq[k] == '+') {
                                    postfix_eq[h2] = infix_eq[k];
                                    k++;
                                } else {
                                    k++;
                                }
                            }
                            for (int h2 = size_of(postfix_eq); h2 < z1 + loop1 && infix_eq[k] != '\0'; h2++) {
                                if (infix_eq[k] == '-') {
                                    postfix_eq[h2] = infix_eq[k];
                                    k++;
                                } else {
                                    k++;
                                }
                            }
                        } else {
                            k++;
                        }
                    }
                }
            }
        } else if (infix_eq[j] == ')' && (infix_eq[j - 1] == '+' || infix_eq[j - 1] == '-' || infix_eq[j - 1] == '*' || infix_eq[j - 1] == '/')) {
            int z2 = 0, m = 0;
            while (infix_eq[m] != '\0' && infix_eq[m] != '(') {
                z2++;
                m++;
            }
            while (infix_eq[j] != '(' && infix_eq[j] != '\0') {
                if ((infix_eq[j] >= 'a' && infix_eq[j] <= 'z') || (infix_eq[j] >= 'A' && infix_eq[j] <= 'Z')) {
                    int h = size_of(postfix_eq);
                    postfix_eq[h] = infix_eq[j];
                    h++;
                }
                j++;
            }
            for (int o = size_of(postfix_eq); o < size_of(infix_eq) && infix_eq[j] != '\0'; o++) {
                if (infix_eq[j] == '+' || infix_eq[j] == '-' || infix_eq[j] == '*' || infix_eq[j] == '/') {
                    for (int h2 = size_of(postfix_eq); h2 < z2 && infix_eq[j] != '\0'; h2++) {
                        if (infix_eq[j] == '/') {
                            postfix_eq[h2] = infix_eq[j];
                            j++;
                        } else {
                            j++;
                        }
                    }
                    for (int h2 = size_of(postfix_eq); h2 < z2 && infix_eq[j] != '\0'; h2++) {
                        if (infix_eq[j] == '*') {
                            postfix_eq[h2] = infix_eq[j];
                            j++;
                        } else {
                            j++;
                        }
                    }
                    for (int h2 = size_of(postfix_eq); h2 < z2 && infix_eq[j] != '\0'; h2++) {
                        if (infix_eq[j] == '+') {
                            postfix_eq[h2] = infix_eq[j];
                            j++;
                        } else {
                            j++;
                        }
                    }
                    for (int h2 = size_of(postfix_eq); h2 < z2 && infix_eq[j] != '\0'; h2++) {
                        if (infix_eq[j] == '-') {
                            postfix_eq[h2] = infix_eq[j];
                            j++;
                        } else {
                            j++;
                        }
                    }
                } else {
                    j++;
                }
            }
        }
    }
    postfix_eq[size_of(postfix_eq)] = '\0'; // Null-terminate the postfix expression
}

int main() {
    infix();
    printf("Postfix Expression: %s\n", postfix_eq);
    return 0;
}
