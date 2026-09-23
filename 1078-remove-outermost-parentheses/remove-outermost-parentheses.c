char* removeOuterParentheses(char* s) {
    char stack[100000];
    int top=-1;
     char* answer = malloc(strlen(s) + 1);
    int balance = 0;
    int j = 0;

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(')
        {
            balance++;

            if(balance > 1)
            {
                answer[j] = s[i];
                j++;
            }
        }
        else
        {
            balance--;

            if(balance > 0)
            {
                answer[j] = s[i];
                j++;
            }
        }
    }

    answer[j] = '\0';

    return answer;
}