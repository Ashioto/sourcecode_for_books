#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<stdio.h>
using namespace std;
struct inc{
    set<int> doc,line[110];
};
map<string,inc> dict;
vector<string> a[110];
void pre(string s,int a,int l){
    for(int i=0;i<s.length();++i)
        if(isalpha(s[i])) s[i]=tolower(s[i]);
        else s[i]=' ';
    stringstream ss(s);
    while(ss>>s){
        if(!dict.count(s)) dict[s]=inc();
        dict[s].doc.insert(a);
        dict[s].line[a].insert(l);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    // freopen("in_1.txt","w",stdout);
    int n,m,cnt;
    cin>>n;cin.get();
    for(int i=0;i<n;++i){
        cnt=0;
        string s;
        while(getline(cin,s),s!="**********"){
            pre(s,i,cnt++);
            a[i].push_back(s);
        }
    }
    cin>>m;cin.get();
    for(int i=0;i<m;++i){
        bool flag=true;
        string s;
        getline(cin,s);
        if(s.find(" AND ")!=s.npos){
            stringstream ss(s);
            string s1,s2;
            ss>>s1>>s2>>s2;
            for(int i=0;i<n;++i){
                if(dict[s1].doc.count(i)&&dict[s2].doc.count(i)){
                    if(flag) flag=false;
                    else cout<<"----------\n";
                    set<int> k;
                    for(set<int>::iterator it=dict[s1].line[i].begin();it!=dict[s1].line[i].end();++it)
                        k.insert(*it);
                    for(set<int>::iterator it=dict[s2].line[i].begin();it!=dict[s2].line[i].end();++it)
                        k.insert(*it);
                    for(set<int>::iterator it=k.begin();it!=k.end();++it)
                        cout<<a[i][*it]<<endl;
                }
            }
        }
        else if(s.find(" OR ")!=s.npos){
            stringstream ss(s);
            string s1,s2;
            ss>>s1>>s2>>s2;
            for(int i=0;i<n;++i){
                if(dict[s1].doc.count(i)||dict[s2].doc.count(i)){
                    if(flag) flag=false;
                    else cout<<"----------\n";
                    set<int> k;
                    for(set<int>::iterator it=dict[s1].line[i].begin();it!=dict[s1].line[i].end();++it)
                        k.insert(*it);
                    for(set<int>::iterator it=dict[s2].line[i].begin();it!=dict[s2].line[i].end();++it)
                        k.insert(*it);
                    for(set<int>::iterator it=k.begin();it!=k.end();++it)
                        cout<<a[i][*it]<<endl;
                }
            }
        }
        else if(s.find("NOT ")!=s.npos){
            string s0=s.substr(4);
            for(int i=0;i<n;++i){
                if(!dict[s0].doc.count(i)){
                    if(flag) flag=false;
                    else cout<<"----------\n";
                    for(int j=0;j<a[i].size();++j)
                        cout<<a[i][j]<<endl;
                }
            }
        }
        else{
            for(int i=0;i<n;++i){
                if(dict[s].doc.count(i)){
                    if(flag) flag=false;
                    else cout<<"----------\n";
                    for(set<int>::iterator it=dict[s].line[i].begin();it!=dict[s].line[i].end();++it)
                        cout<<a[i][*it]<<endl;
                }
            }
        }
        if(flag) cout<<"Sorry, I found nothing.\n";
        cout<<"==========\n";
    }
    return 0;
}
