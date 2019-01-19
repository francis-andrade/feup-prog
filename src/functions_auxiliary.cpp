#include "functions_auxiliary.h"
#include<vector>
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This functions eliminates extra spaces between words, so that if there is more than one space in 
the string, this function returns a string with only one space between two words. It also eliminates extra
spaces at the beginning and at the end of a string
parameter: string s - string that will have extra spaces eliminated from
return value: string s without extra spaces
*/
string removespaces(string s){
	unsigned int i = 0;
	//the following loop removes newlines
	while (i < s.size()){
		if (s[i] == 10){
			s.erase(i, 1);
			i--;
		}
		i++;
	}
	i = 0;
	//The following loops transforms multiple spaces in only one space
	while (i+1 < s.size()){
		if (s[i] == ' ' && s[i + 1] == ' '){
			s.erase(i, 1);
			i = i - 1;
		}
		i = i + 1;
	}
	if ((s.size()>0) && s[0] == ' '){
		s.erase(0, 1);//deletes space at the beginning of a string
	}
	if ((s.size() > 0) && s[s.size()-1]==' '){
		s.erase(s.size() - 1, 1);//deletes space at the end of a string
	}
	return s;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This functions checks if a string is an integer
parameter: const string &s-The function will check if this string is an integer
return value- true if string is an integer and false if not
source:http://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
*/
bool isInteger(const string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This function converts a string to an integer and returns -1 if string is not an integer
parameter: string s-string that is going to be converted
return value - integer that corresponds to the string
*/
int convint(string s){
	if (!isInteger(s)){
		return -1;
	}
	else{
		return stoi(s);
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
This functions returns true if string_left comes before string_right in alphabetical order
parameter: string s_left - left argument string
parameter: string s_right - right argument string
return value: true if s_left comes before s_right in alphabetic order
*/
bool alphabeticorderstring(const string & s_left, const string & s_right){
	unsigned int i = 0;
	while (i < s_left.size() && i < s_right.size() && tolower(s_left[i]) == tolower(s_right[i])){
		i++;
	}
	if ((i==s_left.size()) && (i < s_right.size())){
		return true;
	}
	else if ((i<s_left.size()) && (i == s_right.size())){
		return false;
	}
	else if (tolower(s_left[i]) < tolower(s_right[i])){
		return true;
	}
	else{
		return false;
	}
}