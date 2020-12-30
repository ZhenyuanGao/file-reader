#include <string>
#include <fstream>
#include <sstream>
#include<string.h>
#include <iostream>
#include<unordered_map>
#include <cctype>
#include<vector>

using namespace std;
string result;
vector<string>token_holder;
string get_text="";
vector<string>vector2;
string empty_string="";
string get_number="";
string all_file="";
string comment="";
bool comment_occur=false;
char ch;
char ch2;
bool single_quote=false;
int counter=1;
int counter2 =1;
int counter3 =1;
bool double_add_sub=false;
bool cond4print = false;
bool while_condition=false;
bool uncomment_occur = false;
bool special_comment_occur = false;
void input_file(){
//first step, seperateing it into all the small characters.
    ifstream infile("sample_cppProgram.cpp");
    while(!infile.eof()){
        //repeatedly get the first char.
        infile.get(ch);
        //case for handling the // comment
        if(ch=='/'&&counter3%2==0){
            //set the boolen to true
               special_comment_occur=true;
               all_file+=ch;
               continue;    
           }
        // case for handling // comment
        if(ch=='/'&&counter3%2==1){
               comment_occur=false;
               all_file+=ch;
               counter3+=1;
               continue;
                
           }
           //case for handling /* comment
           if(ch=='*'&&counter3%2==0){
               comment_occur=true;
               all_file+=ch;
               all_file="";
               continue;
                
           }
           //special comment means // comment indicator
            if(special_comment_occur==true){
                if(ch+empty_string== "\n"){
                all_file="";
                special_comment_occur=false;
                ch=' ';
                continue;
                }
            //ignore all the content in the comment    
            all_file+=ch;
            continue;
        }
        //while condition is a boolen designed for printf command.
        if(while_condition==true){
            if(ch==')'){
                vector2.push_back(all_file);
                all_file="";
                while_condition =false;
            }
            //print all the stuff after printf
            all_file+=ch;
            continue;
        }
        //when /* and */ format of comment occur
        if(comment_occur==true){
            
            if(ch=='/'){
                all_file="";
                comment_occur=false;
                
            }
           // ignore everything comes after /* until */
            all_file+=ch;
            

            continue;
        }
        if(ch=='*'&&all_file=="/*"){
            all_file="";
            continue;
        }
        // for printf command, starting to print everything after the printf ( until the end ).
        if(ch=='('&&cond4print==true){
            vector2.push_back(empty_string+ch);
            all_file="";
            while_condition = true;
            
            continue;
            
        }
        
        //case for handleing '' single quote.
        if(ch=='\''&&counter%2==1){
               single_quote=true;
               all_file+=ch;
               counter+=1;
               continue;
                
           }
           //get the second single quote
           if(ch=='\''&&counter%2==0){
               single_quote=false;
               all_file+=ch;
               vector2.push_back(all_file);
               all_file="";
               continue;
                
           }
           
           //++, case for double add marks and subtract marks
            if((ch=='+'||ch=='-')&&counter2%2==1){
               double_add_sub=false;
               all_file+=ch;
               counter2+=1;
               continue;
                
           }
           if((ch=='+'||ch=='-')&&counter2%2==0){
               double_add_sub=true;
               all_file+=ch;
               vector2.push_back(all_file);
               all_file="";
               continue;
                
           }
           

            //check whether the character is an alphetical character, if yes, add up and print out
          if((isalpha(ch)>0||ch=='_')){
            all_file+=ch;
            if(all_file=="printf"){
                vector2.push_back(all_file);
                cond4print=true;
            }

            if(get_number!=""){
                vector2.push_back(get_number);
            }
            get_number="";

             continue;
        }
        //check if the charcter is a punction letter, if yes, print it out.
        if(ispunct(ch)>0){
           
            if(all_file!=""){
                vector2.push_back(all_file);

            }
            if(get_number!=""){
                vector2.push_back(get_number);

            }
            all_file="";
            get_number="";
            vector2.push_back(empty_string+ch);
            ch=' ';
            continue;
        }
         // check if the character is a white space, if yes, print it out and set it as the flag to print out words 
          if(isblank(ch)>0){
                if(all_file!=""){
                    vector2.push_back(all_file);
             }         
                all_file="";
             continue;
        }
        //check if the character is a number, if yes, put it into variable get_number to hold all the numbers.
         if(isdigit(ch)>0){
            get_number+=ch;
             continue;
        }
    }
    
}
int main(){
    //call the function.
    input_file();
    // put all of the value into a vector and print it out one by one.
    for(int i=0;i<vector2.size();i++){
        cout<<vector2[i]<<"\n";
    }
    return 0;
}