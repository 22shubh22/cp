#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;

		int countA=0;
		int countB=0; 
		int nim=0;

		int flag=0;
		char first;
		char last;

		int  temp=0;

		for(int i=0;i<s.length();i++){
			if(flag==0 && s[i]=='.'){
				continue;
			} else if(flag==1 && s[i]=='.'){
				temp++;
			} else if(flag==0 && s[i]!='.'){    //start a char
				flag=1;
				first = s[i];
			} else if(flag==1 && s[i]!='.'){
				last = s[i];
				flag=0;

				if(first==last){
					if (first=='A'){countA+=temp;}
					else {countB+=temp;}
				} else{
					nim^=temp;
				}
				temp=0;
			}
		}
		if (temp!=0){
			if(first=='A'){ countA+=temp;}
			else{ countB+=temp;}
			temp=0;
		}

		/*
		* If x==0  B finishes nim game, and now it is turn of A.
		*/
		
		if(nim!=0){
			//A finishes nim game. B's turn
			if(countB -1<countA){
				cout << "A" << endl;
			} else{
				cout << "B" << endl;
			}
		} else{
			//x==1: B finishes nim game. A's turn
			if(countA-1<countB){
				cout << "B" << endl;
			} else{
				cout << "A" << endl;
			}
		}

	}
}