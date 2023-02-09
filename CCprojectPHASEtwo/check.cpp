#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;
//function decleration
string leftrotate(string* str1, int n);
string rightrotate(string* str1, int n);
void inp(int flg);
void valid();
void reading_Table();
bool is_alphabet(char ch);
bool is_digit(char ch);
int check_operator(int state, char ch);
bool is_Keyword(char *token);
int next_State(int state, char ch);
bool strkey(char input);
void reaDcfg();
void readPT();
int row1=51;
int col1=25;
int ptArr[52][25];
string cfgARR[52][10];
int colarr[52];
string inpp[100];
string stacck[50];
void mininput();
void minstack();
int check_olist(string input);
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
                            'e',
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

string olist[] = { "identifier", "," ,";" ,"int", "float" ,"whilestmt" ,"for" ,"loop" ,"agar" ,"magar" ,"==" ,"<" ,">" ,"<=" ,">=" ,"!=" ,"<>" ,"+" ,"-" ,"*", "/" ,"no" ,"$","{","}"};
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
ifstream fiin11("tokens.txt");
string chkk=" ";
string yy=" ";
int i=0,l=0,r=0;
int ind=0;
int stackind=1;
int chkrow=1;
int chkcol=1;    
int main()
{
    reading_Table();
    readPT();
    reaDcfg();
   stacck[0]="?";

	//opening file
   
    // ofstream fout("tokens.txt");
    // ofstream errors("errors.txt");

    // if (!fin.is_open())
    // {
    //     cout << "File Not Found.\n"
    //          << endl;
    //     exit(0);
    // }
    

    // while(!fiin.eof())
    // {
    //     fiin>>yy;
    //     l++;
    // }
    // fiin.close();



  
    // while(!fin.eof())
    // {
    //     r++;
    // fin >> chkk;


    // int len=chkk.size();
    // i=0;
    // if(r==l)
    // {
        
    //     chkk[len]=';';
    //     len++;
    // }
  
   
    // for(;i<len;)
    // {
    //     cout<<"input "<<chkk[i]<<endl;
    //     pre_state = current_state;
    //     cout << "\nCurrent state: " << current_state;
    //     current_state = next_State(current_state, chkk[i]);
	// 	cout << "\n update Current state: " << current_state<<endl;

    //     if ((current_state >= 2 && current_state <= 8) || (current_state >= 10 && current_state <= 15) || (current_state >= 17 && current_state <= 18)||(current_state>=20&&current_state<=21) || (current_state >= 23 && current_state <= 26) || (current_state >= 28 && current_state <= 31) || (current_state >= 33 && current_state <= 34) || (current_state >= 33 && current_state <= 34) || (current_state >= 36 && current_state <= 39) || (current_state >= 41 && current_state <= 42) || (current_state >= 44 && current_state <= 50) || (current_state >= 52 && current_state <= 53) ||  (current_state == 55) || (current_state >= 57 && current_state<=58)||(current_state==60))
    //     {
    //         token[token_index] =  chkk[i];
    //         token_index++;

    //         token[token_index] = '\0';
	// 		 string tmp=token;
   	// 		 for (int i = 0; i < 61; i++)
  	// 		{
    //    			 if (keywords[i]==tmp)
	// 			 {chk=true;
	// 			 break;

	// 			 }
    //    			chk=false;
    // 		}
				 
    //         if ((chk==true) && ((i==len-1)||strkey(chkk[i+1])==true))
    //         {   
                
    //             fout << token << " is a Keyword" << endl;
    //             cout << token << " is a Keyword" << endl;
    //             inpp[ind]=token;
    //             ind++;
    //             current_state = 1;
    //             token_index = 0;
    //         }
            
    //             flag = 0;
            
    //     }

    //     else if (current_state == 9)
    //     {
    //         token[token_index] = '\0';
    //         fout << token << " is a Number" << endl;
    //          inpp[ind]="number";
    //         ind++;
    //         cout << token << " is a Number" << endl;
	// 		if(advance_Table[current_state][1]==0)
	// 		{
	// 			flag = 1;
	// 		}
    //         current_state = 1;
    //         token_index = 0;
            
    //     }

    //     else if (current_state == 16)
    //     {

    //         fout << token << " is an Identifier" << endl;
    //          inpp[ind]="identifier";
    //         ind++;
    //         cout << token << " is an Identifier" << endl;
      
	// 		if(advance_Table[current_state][0]==0)
	// 		{
	// 			flag = 1;
	// 		}
    //         current_state = 1;
    //         token_index = 0;
    //     }
    //     else if (current_state == 27 || current_state == 35 || current_state == 51 || current_state == 54 || current_state == 59 || current_state == 56 || current_state == 40 || current_state == 32 || current_state == 22 || current_state == 43 || current_state == 19)
    //     {
    //         token[token_index] = '\0';
	// 		if(pre_state==21||pre_state==20||pre_state==17||pre_state==18||pre_state==57||pre_state==58)
	// 		{
	// 			fout << token << " is an bracket" << endl;
    //             inpp[ind]=token;
    //             ind++;
    //             cout << token << " is an bracket" << endl;
	// 		}
	// 		else{
	// 			fout << token << " is an Operator" << endl;
    //             inpp[ind]=token;
    //             ind++;
    //             cout << token << " is an Operator" << endl;
	// 		}
	// 		int kaka=0;
    //          for (int i = 0; i < 23; i++)
    // 		{
    //    			 if ( chkk[i] == operator_list[i])
    //    			 {
    //      		    kaka=advance_Table[current_state][i + 2];
   	//    			  }
   	// 		 }
	// 		if(kaka==0)
	// 		{
	// 			flag = 1;
	// 		}

    //         current_state = 1;
    //         token_index = 0;
         
    //     }
    //     else
    //     {
    //         token[token_index] =  chkk[i];
    //         token[token_index + 1] = '\0';
    //         errors << token << " is an Invalid token" << endl;
    //         current_state = 1;
    //         token_index = 0;
    //     }


    //    inp(flag);


    // }

    // }
    
    // fin.close();
    // fout.close();
    // errors.close();
    // cout << "Tokens Created Successfully\nCheck your files for OutPut!\n";



    string re="";
    cout << "\nInput: ";
    while (!fiin11.eof())
    {
       
        fiin11 >> re;
         cout << re << " ";
         inpp[ind]=re;

     ind++;
    }
    fiin11.close();
    cout<<"size "<<ind<<endl;


    
    valid();
   
    return 0;
}


void inp(int flg)
{
    if (flg == 0)
    {

      
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

void readPT()
{
	ifstream filee("parsertable.txt");
    string var;
 
	if (filee)
	{
		
         int k=0;
		for (int i = 1; i <= row1; i++)
		{
			for (int j = 1; j <= col1; j++)
			{
				filee >> k;
                ptArr[i][j]=k;
                cout<<k<<" ";

			}
            cout<<endl;
		}
		filee.close();
	
	}
	else
	{
		cout << "File Not Open \n";
	}
}


void reaDcfg()
{
    ifstream file("CFG.txt");
	   string var;
	   string y="?";
 
	if (file)
	{
		
         int k=0;
		for (int i = 1; i <= 51; i++)
		{
			string var;
			 int c=0;
			for (int j = 1; var!=y; j++)
			{
				file >> var;
                cfgARR[i][j]=var;
				c++;
                cout<<var<<" ";

			}
            cout<<endl;
			colarr[i]=c-1;
		}
		file.close();
	
	}
	else
	{
		cout << "File Not Open \n";
	}
}
void mininput()
{
    for(int i=0;i<ind;i++)
    {
        inpp[i]=inpp[i+1];
    }
    ind--;
}
void minstack()
{
    for(int i=0;i<stackind;i++)
    {
        stacck[i]=stacck[i+1];
    }
    stackind--;
}
int check_olist(string input)
{
   

    for (int i = 0; i < 25; i++)
    {
        if (input == olist[i])
        {
            int num=i+1;
            return num;
        }
    }
    return 0;
}
bool check_olist11(string input)
{
   

    for (int i = 0; i < 25; i++)
    {
        if (input == olist[i])
        {
          
            return true;
        }
    }
    return false;
}
void updateStack(int r,int n,int sn)
{
    if(cfgARR[r][1]=="E")
    {

    }
    else
    {
        int x=0;
    
        string temp[100];
        for(int i=0,k=1;i<n;i++,k++)
        {
            temp[i]=cfgARR[r][k];
        
            x++;
        }
    

    
        for(int j=0,i=x; j<sn;i++,j++)
        {
            
            temp[i]=stacck[j];
        
        }

        for(int i=0; i<sn+x;i++)
        {
            
            stacck[i]=temp[i];
    
        
        }
    stackind=sn+x;
    }
   
}
void valid()
{
   int o=1;
       cout<<"\ninput remaining "<<ind<<endl;
            for(int i=0; i<ind;i++)
            {
            cout<<inpp[i]<<" ";
            }
    while(ind>0)
    {
        cout<<"\n--------------------------------------------------------------------------------------------";
        cout<<"\nalt "<<o<<endl;
        cout<<"--------------------------------------------------------------------------------------------\n";
        if(stacck[0]==inpp[0])
        {
            
            cout<<"matched stack first index with input first index\n";
            mininput();
            minstack();
            cout<<"stack remaining "<<endl;
            for(int i=0; i<stackind;i++)
            {
            cout<<stacck[i]<<" ";
            }

            cout<<"\ninput remaining "<<endl;
            for(int i=0; i<ind;i++)
            {
            cout<<inpp[i]<<" ";
            }
            bool temp1=check_olist11(stacck[0]);
            if(temp1==true)
            {

            }
            else
            {
                stringstream ss; 
                ss << stacck[0];
                ss >>chkrow;
            }
        }
        else
        {
                cout<<"not matched stack first index with input first index\n";
                chkcol=check_olist(inpp[0]);
                int cfgind=ptArr[chkrow][chkcol];
                
                if((cfgind==-1||cfgind==-2) && o==1)
                {
                    // cout<<"first input remove\n";
                    mininput();
                       cout<<"\ninput remaining "<<endl;
                    for(int i=0; i<ind;i++)
                    {
                    cout<<inpp[i]<<" ";
                    }
                }
                else if(cfgind==-1||cfgind==-2)
                {
                    cout<<"first stack remove\n";
                     minstack();
                }
                else
                {
                   
                    minstack();
                    updateStack(cfgind,colarr[cfgind],stackind);
                    cout<<"\nstack remaining after rulue "<<cfgind<<"  added"<<endl;
                    for(int i=0; i<stackind;i++)
                    {
                        cout<<stacck[i]<<" ";
                    }
                       cout<<"\ninput remaining "<<endl;
                    for(int i=0; i<ind;i++)
                    {
                    cout<<inpp[i]<<" ";
                    }
                    bool temp=check_olist11(stacck[0]);
                    if(temp==true)
                    {

                    }
                    else
                    {
                        stringstream ss; 
                        ss << stacck[0];
                        ss >>chkrow;
                        
                    }

                }
               
        
   
        }
        o++;
    }

}