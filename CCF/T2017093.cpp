#include <iostream>
#include <string>
#include <cstring>
#include <map>

//默认引号中没有{} ,:   大胆假设 不求满分 但求80  结果满分

#define rep(i,s,e) for(int i = s;i<e;i++)

using namespace std;

const int maxL = 81;

int n, m;
map<string,string> mp;

void buildmap(string json,string root){
	json = json.substr(1,json.size()-2);
	//按,分割 
	int i =0 ,j = 0;
	string k,v;
	while(true){
		i = json.find(":");
		if(json[i+1] == '"'){  //是字符串 
			j = json.find(",",i+1);
			if(j == string::npos) j = json.size();
			k = root == "" ? json.substr(1,i-2):root+"."+json.substr(1,i-2);
			v = json.substr(i+2,j-i-3);
		}else{                  //是对象 
			k = root == "" ? json.substr(1,i-2):root+"."+json.substr(1,i-2);
			v = "{";
			//找到对应的}
			int count = 1;
			j = i +2;
			while(count != 0){
				if(json[j] == '{'){
					count++;
				}else if(json[j] == '}'){
					count--;
				}
				j++;
			}
			buildmap(json.substr(i+1,j-i-1),k);
		}
		mp[k] = v;
		if(j == json.size()){
			break;
		}
		json = json.substr(j+1,json.size()-j);
	}
	
}

int main(){
	cin >> n >> m;
	string s,json;
	getline(cin,s);
	rep(i,0,n){
		getline(cin,s);
		for(string::iterator it = s.begin();it!=s.end();){
			if(isspace(*it)){
				it = s.erase(it);
			}else if(*it == '\\'){
				it = s.erase(it);
				it++;
			}else{
				it++;
			}
		}
		json += s;
	}

	buildmap(json,"");
	
	//for(map<string,string>::iterator it = mp.begin();it != mp.end();it++){
	//	cout << it->first << ":"<<it->second<<endl;
	//}
	rep(i,0,m){
		getline(cin,s);
		string v = mp[s];
		if(v == ""){
			cout << "NOTEXIST" << endl;
		}else if(v == "{"){
			cout << "OBJECT" <<endl;
		}else {
			cout <<"STRING "<< v <<endl;
		}
	}
	
	return 0;
}

