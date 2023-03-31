#include "include/main.h"

/**
 * parser - functions that parse the string given
 * @: it gets the the string as input
 * Description: checks if this string is valid or not
 * Return: valid | not valid
 */

bool parser(char *line, int *number)
{
        /* Declare the variable that I'm gonna need */
        int lineIndex = 0;
        char nextChar;
        int sign = +1;
        int state;
        bool valid;
        valid = true;
        state = S_I;

        do {
                /* Get char by char of the syntax*/
                nextChar = line[lineIndex++];
                switch (state)
                {
                        case S_I:
                                if (nextChar == '+')
                                {
                                        sign = +1;
                                        state = S_F;
                                }
                                else if (nextChar == '-')
                                {
                                        sign = -1;
                                        state = S_F;
                                }
                                else if (isDigit(nextChar))
                                {
                                        sign = +1;
                                        *number = nextChar - '0';
                                        state = S_M;
                                }
                                else
                                {
                                        valid = false;
                                }

                                break;
                        case S_F:
                                if (isDigit(nextChar))
                                {
                                        *number = (10 * (*number)) + (nextChar - '0');
                                        state = S_M;
                                }
                                else
                                {
                                        valid = false;
                                }

                                break;

                        case S_M:
                                if (isDigit(nextChar))
                                {
                                        *number = (10 * (*number)) + (nextChar - '0');
                                        state = S_M;
                                }
                                else if (nextChar == '\n')
                                {
                                        *number *= sign;
                                        state = S_STOP;
                                }
                                else
                                {
                                        valid = false;
                                }

                                break;
                }
        } while ((state != S_STOP) && (valid));


        return (valid);
}



/* Local function it can be used by parser*/
bool isDigit(char ch)
{
        return ('0' <= ch) && (ch <= '9');
}
