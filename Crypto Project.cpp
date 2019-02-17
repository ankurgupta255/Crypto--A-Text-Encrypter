#include<iostream>
#include<string>
using namespace std;

string normalizeText(string str){
	string s={};
	for(int i=0;i<str.length();i++){
		if(int(str[i])>=97 && int(str[i])<=122){
			s+=str[i]-32;
		}
		else if(int(str[i])>=65 && int(str[i])<=90){
			s+=str[i];
		}
	}
	return s;
}
string shiftAlphabet(int shift){
	int start = 0;
    if (shift < 0) {
        start = (int) 'Z' + shift + 1;
    } 
	else {
        start = 'A' + shift;
    }
    string result = "";
    char currChar = (char) start;
    for(; currChar <= 'Z'; ++currChar) {
        result = result + currChar;
    }
    if(result.length() < 26) {
        for(currChar = 'A'; result.length() < 26; ++currChar) {
            result = result + currChar;
        }
    }
    return result;
}
string caesarify(string str,int n){
	string a={};
	a=shiftAlphabet(n);
	for(int i=0;i<str.length();i++){
		str[i]=a[str[i]-65];
	}
	return str;
}

string groupify(string str,int n){
	string s={};
	int num=0;
	num=str.length()%n;
	int cnt=0;
	if(num==0){
		for(int i=0;i<str.length();){
		while(cnt<n){
			s+=str[i];
			i++;
			cnt++;
		}
		s+=' ';
		cnt=0;
	}
	}
	else{
		int cnt=0;
		int v=str.length()-num;
		for(int i=0;i<str.length();){
		while(cnt<n && i<str.length()){
			s+=str[i];
			i++;
			cnt++;
		}
		if(i<str.length()){
			s+=' ';
		}
		cnt=0;
	}
	for(int i=0;i<n-num;i++){
		s+='x';
	}	
	}
	return s;
}
string encryptString(string s,int shift,int size){
	string str;
	str=normalizeText(s);
	str=caesarify(str,shift);
	str=groupify(str,size);
	return str;
}
string ungroupify(string s){
	string x;
	for(int i=0;i<s.length();i++){
		if(s[i]!=' '){
			x+=s[i];
		}
	}
	return x;
}
string decrypt(string s,int shift){
	string s1=ungroupify(s);
	s1=normalizeText(s1);
	return s1;
}
int main(){
	string str={};
	cout<<"Enter the string: ";
	getline(cin,str);
	cout<<"Enter the shift value: ";
	int shift;
	cin>>shift;
	cout<<"Enter the size of blocks: ";
	int size;
	cin>>size;
	string fin=encryptString(str,shift,size);
	cout<<"The String is: "<<fin<<endl;
	string d=decrypt(str,shift);
	cout<<"THe decrypted String is: "<<d;
	return 0;
}
