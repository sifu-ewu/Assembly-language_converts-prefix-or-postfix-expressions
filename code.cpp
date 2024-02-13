include<bits/stdc++.h>
#include<stack>
#include <string.h>
using namespace std;
#define MAX 100

int st[MAX];
char postfix[MAX],infix[MAX],temp[MAX];
int top=-1;

void push(int a);
int pop();

void infixtopostfix(char temp[],char postfix[]);
void reverse(char str[]);
int getpriority(char);


class stackk
{
    private:
        char data [50];
        int top;
    public :
        stackk()
        {
            top=0;
        }

        void push(char item)
        {
            data [top]=item;
            top++;
        }

        char getTop()
        {
            return data[top-1];
        }

        char pop()
        {
            if(top==0)
                return '0';
            top--;
            char item=data[top];
            return item;
        }

        int isEmpty()
        {
            if (top==0)
                return 1;
            else
                return 0;
        }
        int getLength()
        {
            return top;
        }
};


void generate_Assembly_one_one(string postfix)
{
    stack<string> operand;
    int j=0;
    char ac[] = {'X'};

    for(int i=0; i<postfix.length(); i++)
    {
        if(postfix[i] >= 65 && postfix[i] <= 90)
        {
            operand.push(string (1, postfix[i]));
        }
        else
        {
            string a = operand.top(); operand.pop();
            string b = operand.top(); operand.pop();

            if (postfix[i] == '*') {
                cout << "\t\t\tLOAD " << a << endl;
                cout << "\t\t\tMUL " << b << endl;
                cout << "\t\t\tSTORE " << ac[j] << endl;
            } else if (postfix[i] == '/') {
                cout << "\t\t\tLOAD " << a << endl;
                cout << "\t\t\tDIV " << b << endl;
               // cout << "\t\t\tSTORE " << ac[j] << endl;
            } else if (postfix[i] == '-') {
               // cout << "\t\t\tLOAD " << a << endl;
                cout << "\t\t\tSUB " << b << endl;
                cout << "\t\t\tSTORE " << ac[j] << endl;
            } else if (postfix[i] == '+') {
                cout << "\t\t\tLOAD " << a << endl;
                cout << "\t\t\tADD " << b << endl;
                cout << "\t\t\tSTORE " << ac[j] << endl;
            }

            operand.push(string(1, ac[j]));
        }
    }
}


void generate_Assembly_two(string postfix)
{
    stack<string> operand;
    int j=0;
    char ac[] = {'X', 'Y'};
    for(int i=0; i<postfix.length(); i++)
    {
        if(postfix[i] >= 65 && postfix[i] <= 90)
        {
            operand.push(string (1, postfix[i]));
        }

        else
        {

            string a = operand.top(); operand.pop();
            string b = operand.top(); operand.pop();

            cout << "\t\t\tMOV "<<ac[j]<<", " << b<<endl;

            if (postfix[i] == '+')
                cout << "\t\t\tADD "<< ac[j]<<", "<< a <<endl;
            else if (postfix[i] == '-')
                cout << "\t\t\tSUB "<< ac[j]<<", "<< a  <<endl;
            else if (postfix[i] == '*')
                cout << "\t\t\tMUL "<< ac[j]<<", "<< a  <<endl;
            else if (postfix[i] == '/')
                cout << "\t\t\tDIV "<< ac[j]<<", "<< a  <<endl;

            operand.push(string(1, ac[j]));
            if(j==0)
                j=1;
            else
                j=0;
        }
    }
}


void generate_Assembly_three(string postfix)
{
    stack<string> operand;
    int j=0;
    char ac[] = {'X', 'Y', 'Z'};
    for(int i=0; i<postfix.length(); i++)
    {
        if(postfix[i] >= 65 && postfix[i] <= 90)
        {
            operand.push(string (1, postfix[i]));
        }

        else
        {
            string a = operand.top(); operand.pop();
            string b = operand.top(); operand.pop();

            if (postfix[i] == '+')
                cout << "\t\t\tADD "<< ac[j]<<", "<< b <<", "<< a<<endl;
            else if (postfix[i] == '-')
                cout << "\t\t\tSUB "<< ac[j]<<", "<< b <<", "<< a  <<endl;
            else if (postfix[i] == '*')
                cout << "\t\t\tMUL "<< ac[j]<<", "<< b <<", "<< a  <<endl;
            else if (postfix[i] == '/')
                cout << "\t\t\tDIV "<< ac[j]<<", "<< b <<", "<< a  <<endl;

            operand.push(string(1, ac[j]));
            if(j==0)
                j=1;
            else if(j==1)
                j==2;
            else
                j=0;
        }
    }
}

bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool AreParanthesesBalanced(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.empty() || !ArePair(S.top(),exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true:false;
}


void infix_postfix(char * str)
{
    stackk st;
    char temp[30];
    int j=-1;
    int size = strlen(str);

    for(int i=0; i<size; i++)
    {
        if(str[i]!='(' && str[i]!=')' && str[i]!='{' && str[i]!='}' && str[i]!='[' && str[i]!=']' && str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/')
        {
            temp[++j] = str[i];
        }
        else if(str[i]=='+' || str[i]=='-')
        {
            st.push(str[i]);
        }
        else if(str[i]=='(')
        {
            st.push(str[i]);
        }
        else if(str[i]=='*' || str[i]=='/')
        {
            st.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(1)
            {
                if(st.getTop()=='(')
                {
                    st.pop();
                    break;
                }
                temp[++j] = st.getTop();
                st.pop();
            }
        }
    }
    while(!st.isEmpty())
    {
        temp[++j] = st.getTop();
        st.pop();
    }


    int i=-1;
    for(j=0; j<size; j++)
    {
        str[++i]=temp[j];
    }
}

void reverse(char *exp)
{

    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++)
        swap(exp[i], exp[n - i - 1]);
}

void brackets(char * exp)
{
    int n = strlen(exp);
    for (int i = 0; i <=n; i++)
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
    }
}


void infix_prefix(char *exp)
{
    reverse(exp);
    brackets(exp);
    infix_postfix(exp);
    reverse(exp);
}


int main()
{
    cout<<"================ WELCOME TO ASSEMBLY CODE GENERATOR ================"<<endl;
    cout<<endl;
    cout<<endl;
        char str[30], exp[30];
        printf("\tInfix Expression : ");
        cin >> str;
        memcpy(exp, str, 30);
        infix_postfix(exp);

        if(AreParanthesesBalanced(str))
        {
            while(1)
            {
                printf("\n\tPress (1) to convert Infix to Prefix.  \n\tPress (2) to convert Infix to POSTFIX.  \n\tPress (0) to Exit\n\n");
                int ch;
                scanf("%d",&ch);

                if(ch==1)
                {
                    int f=1;
                    infix_prefix(str);

                    printf("\tPrefix Expression : ");
                    cout<<str<<endl;
                    printf("\n");
                    int s;
                    while(f==1)
                    {
                        printf("\n\t\tPress (1) to generate one address assembly code.    \n\t\tPress (2) to generate two address assembly code.\n\t\tPress (3) to generate three address assembly code.\n\t\tPress (0) to exit.\n\n");
                        cin>>s;
                        switch(s)
                        {
                        case  1:
                            generate_Assembly_one_one(exp);
                            break;
                        case 2:
                            generate_Assembly_two(exp);
                            break;
                        case 3:
                            generate_Assembly_three(exp);
                            break;
                        case 0:
                            f=0;
                            break;
                        }
                    }
                }

                else if(ch==2)
                {
                    int f=1;
                    infix_postfix(str);
                    printf("\tPostfix Expression : ");
                    cout<<str<<endl;
                    printf("\n");
                    int s;
                    while(f==1)
                    {
                        printf("\n\t\tPress (1) to generate one address assembly code.    \n\t\tPress (2) to generate two address assembly code.\n\t\tPress (3) to generate three address assembly code.\n\t\tPress (0) to exit.\n\n");
                        cin>>s;
                        switch(s)
                        {
                        case  1:
                            generate_Assembly_one_one(exp);
                            break;
                        case 2:
                            generate_Assembly_two(exp);
                            break;
                        case 3:
                            generate_Assembly_three(exp);
                            break;
                        case 0:
                            f=0;
                            break;
                        }
                    }
                }
                else if(ch==0)
                    break;
            }
        }

        else
            cout<<"\n\t\tInvalid Expression"<<endl;



    cout<<"\n\n\t================ THANK YOU FOR USING OUR ENVIRONMENT ==================="<<endl;

}
