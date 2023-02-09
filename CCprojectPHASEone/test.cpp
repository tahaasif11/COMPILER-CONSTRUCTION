#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
//function decleration
void inp(int flg);
void reading_Table();
bool is_alphabet(char ch);
bool is_digit(char ch);
int check_operator(int state, char ch);
bool is_Keyword(char *token);
int next_State(int state, char ch);
bool strkey(char input);

//keywords
  string keywords[] = { "loop", "agar", "magar", "asm", "else", "new", "this", "auto", "enum", "operator", "throw", "bool", "explicit", "private",
		"true", "break", "export", "protected", "try", "case", "extern", " public", "typedef", "catch", "false", "register", "typeid",
		"char", "float", "typename", "class", "for", "return", "std", "union", "const", "friend", "short", "unsigned", "goto", "signed", "using",
		"continue", "if", "sizeof", "virtual", "default", "inline", "static", "void", "delete", "int", "volatile", "do", "long", "struct",
		"double", "mutable", "switch", "while", "namespace"};
//operatore
 char operator_list[] = {'+',
                            '-',
                            '*',
                            '/',
                            'E',
                            '{',
                            '}',
                            '[',
                            ']',
                            '_',
                            '.',
                            '<',
                            '>',
                            '&',
                            '!',
                            '|',
                            ':',
                            '%',
                            '=',
                            '^',
                            ';',
                            '(',
                            ')'};

// globels variable 
const int rows = 61, cols = 25;
int relation_Table[rows][cols];
int advance_Table[rows][cols];
char token[200];
int token_index = 0;
int pre_state = 0;
char input;
int current_state = 1, flag = 0;
bool chk;
ifstream fin("input.txt");
ifstream fiin("input.txt");
string chkk=" ";
string yy=" ";
int i=0,l=0,r=0;

int main()
{
    reading_Table();

	//opening file
   
    ofstream fout("tokens.txt");
    ofstream errors("errors.txt");

    if (!fin.is_open())
    {
        cout << "File Not Found.\n"
             << endl;
        exit(0);
    }
    

    while(!fiin.eof())
    {
        fiin>>yy;
        l++;
    }
    fiin.close();



  
    while(!fin.eof())
    {
        r++;
    fin >> chkk;


    int len=chkk.size();
    i=0;
    if(r==l)
    {
        
        chkk[len]=';';
        len++;
    }
  
   
    for(;i<len;)
    {
        cout<<"input "<<chkk[i]<<endl;
        pre_state = current_state;
        cout << "\nCurrent state: " << current_state;
        current_state = next_State(current_state, chkk[i]);
		cout << "\n update Current state: " << current_state<<endl;

        if ((current_state >= 2 && current_state <= 8) || (current_state >= 10 && current_state <= 15) || (current_state >= 17 && current_state <= 18)||(current_state>=20&&current_state<=21) || (current_state >= 23 && current_state <= 26) || (current_state >= 28 && current_state <= 31) || (current_state >= 33 && current_state <= 34) || (current_state >= 33 && current_state <= 34) || (current_state >= 36 && current_state <= 39) || (current_state >= 41 && current_state <= 42) || (current_state >= 44 && current_state <= 50) || (current_state >= 52 && current_state <= 53) ||  (current_state == 55) || (current_state >= 57 && current_state<=58)||(current_state==60))
        {
            token[token_index] =  chkk[i];
            token_index++;

            token[token_index] = '\0';
			 string tmp=token;
   			 for (int i = 0; i < 61; i++)
  			{
       			 if (keywords[i]==tmp)
				 {chk=true;
				 break;

				 }
       			chk=false;
    		}
				 
            if ((chk==true) && ((i==len-1)||strkey(chkk[i+1])==true))
            {   
                
                fout << token << " is a Keyword" << endl;
                cout << token << " is a Keyword" << endl;
                current_state = 1;
                token_index = 0;
            }
            
                flag = 0;
            
        }

        else if (current_state == 9)
        {
            token[token_index] = '\0';
            fout << token << " is a Number" << endl;
            cout << token << " is a Number" << endl;
			if(advance_Table[current_state][1]==0)
			{
				flag = 1;
			}
            current_state = 1;
            token_index = 0;
            
        }

        else if (current_state == 16)
        {

            fout << token << " is an Identifier" << endl;
            cout << token << " is an Identifier" << endl;
      
			if(advance_Table[current_state][0]==0)
			{
				flag = 1;
			}
            current_state = 1;
            token_index = 0;
        }
        else if (current_state == 27 || current_state == 35 || current_state == 51 || current_state == 54 || current_state == 59 || current_state == 56 || current_state == 40 || current_state == 32 || current_state == 22 || current_state == 43 || current_state == 19)
        {
            token[token_index] = '\0';
			if(pre_state==21||pre_state==20||pre_state==17||pre_state==18||pre_state==57||pre_state==58)
			{
				fout << token << " is an bracket" << endl;
                cout << token << " is an bracket" << endl;
			}
			else{
				fout << token << " is an Operator" << endl;
                cout << token << " is an Operator" << endl;
			}
			int kaka=0;
             for (int i = 0; i < 23; i++)
    		{
       			 if ( chkk[i] == operator_list[i])
       			 {
         		    kaka=advance_Table[current_state][i + 2];
   	   			  }
   			 }
			if(kaka==0)
			{
				flag = 1;
			}

            current_state = 1;
            token_index = 0;
         
        }
        else
        {
            token[token_index] =  chkk[i];
            token[token_index + 1] = '\0';
            errors << token << " is an Invalid token" << endl;
            current_state = 1;
            token_index = 0;
        }


       inp(flag);


    }

    }
    
    fin.close();
    fout.close();
    errors.close();
    cout << "Tokens Created Successfully\nCheck your files for OutPut!\n";
    return 0;
}


void inp(int flg)
{
    if (flg == 0)
    {

        // fin >> input;
        i++;
        
    }
    else
    {
        flg = 0;
    }
}

void reading_Table()
{
    ifstream fin("tables.txt");
	ifstream fin1("advancetable.txt");

    if (!fin.is_open())
    {
        cout << "File not found." << endl;
        exit(0);
    }

    int value;
    char temp;
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {
            if (i == 0)
            {
                fin >> temp;
                value = temp;
                relation_Table[i][j] = value;
            }
            else
            {
                fin >> value;
                relation_Table[i][j] = value;
            }
        }
    }
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << relation_Table[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

   for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {
            if (i == 0)
            {
                fin1 >> temp;
                value = temp;
                advance_Table[i][j] = value;
            }
            else
            {
                fin1 >> value;
                advance_Table[i][j] = value;
            }
        }
    }
cout<<"\nadvance table\n";

	//   for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << advance_Table[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    fin.close();
}
int check_operator(int current_state, char input)
{
   

    for (int i = 0; i < 23; i++)
    {
        if (input == operator_list[i])
        {
            return relation_Table[current_state][i + 2];
        }
    }
    return 0;
}



bool is_alphabet(char input)
{

    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
    {
        return true;
    }
    return false;
}

bool is_digit(char input)
{
    char digit[] = {"0123456789"};

    for (int i = 0; i < strlen(digit); i++)
    {
        if (digit[i] == input)
        {
            return true;
        }
    }
   return false;
}
int next_State(int current_state, char input)
{


    if (is_alphabet(input))
    {
        return relation_Table[current_state][0];
    }

    else if (is_digit(input))
    {
        return relation_Table[current_state][1];
    }

    else
    {
        return check_operator(current_state, input);
    }
}

bool strkey(char input)
{

       for (int i = 0; i < 23; i++)
    {
        if (input == operator_list[i])
        {
            return true;
        }

    }
    return false;
}

