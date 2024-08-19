#include <iostream>
#include <string>

using namespace std;

int hashFunction(const string& placa){
	int hashValue = 0;
	for(char c : placa){
		if(c>='A' && c<='Z'){
			hashValue += c - 'A' + 1;
		}else if(c>='0' && c<='9'){
			hashValue += c - '0';
		}
	}
	
	return hashValue;
}

int main(){
	string p1 = "ABC1234";
	string p2 = "ABC1235";
	string p3 = "XYZ1235";
	cout << hashFunction(p1) << endl << hashFunction(p2) << endl << hashFunction(p3);
	
}