#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
struct BookInfo{
    int id;
    string title;
    string author;
    vector<string> keyWords;
    string publisher;
    int publishedYear;
};
vector<string> split(const string& str, const char& sep){
    std::vector<string> ret;
    for(int i = 0; i < str.size(); ){
        string sav;
        int j;
        for(j = i; str[j] != ' ' && j != str.size(); j++){
            sav += str[j];
        }
        ret.push_back(sav);
        i = j + 1;
    }
    return ret;
}
bool cmp(const BookInfo& a, const BookInfo& b){
    return a.id < b.id;
}
int getNum(string s){
    int ret = 0;
    for(int i = 0; i < s.length(); i++){
        ret = ret * 10 + s[i] - '0';
    }
    return ret;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int nBook;
    cin >> nBook;
    vector<BookInfo> books(nBook);

    for(int i = 0; i < nBook; i++){
        cin >> books[i].id;
        cin.clear(); cin.ignore();
        getline(cin, books[i].title);
        getline(cin , books[i].author);
        string words;
        getline(cin, words);
        books[i].keyWords = split(words, ' ');
        getline(cin, books[i].publisher);
        cin >> books[i].publishedYear;
    }

    sort(books.begin(), books.end(), cmp);
    // for(int i = 0; i < books.size(); i++){
    //     cout << endl;
    //     cout << books[i].id << endl;
    //     cout << books[i].title << endl;
    //     cout << books[i].author << endl;
    //     cout << "keyWords size is " << books[i].keyWords.size() << endl;
    //     for(vector<string>::iterator it = books[i].keyWords.begin(); it != books[i].keyWords.end(); ++it){
    //         cout << *it << " ";
    //     }
    //     cout << endl;
    //     cout << books[i].publisher << endl;
    //     cout << books[i].publishedYear << endl << endl;
    // }
    int nQuery;
    cin >> nQuery;
    cin.clear();
    cin.ignore();
    // 1: a book title
    // 2: name of an author
    // 3: a key word
    // 4: name of a publisher
    // 5: a 4-digit number representing the year
    for(int q = 1; q <= nQuery; ++q){
        string query;
        getline(cin, query);
        cout << query << endl;
        // cout << "query is " << query;
        int n = query[0] - '0';
        string tarS = query.substr(3);
        // cout << tarS << endl;
        vector<int> ans;
        if(n == 1){
            for(int i = 0; i < books.size(); i++){
                if(books[i].title == tarS){
                    ans.push_back(books[i].id);
                }
            }
        }
        else if(n == 2){
            for(int i = 0; i < books.size(); i++){
                if(books[i].author == tarS){
                    ans.push_back(books[i].id);
                }
            }
        }
        else if(n == 3){
            for(int i = 0; i < books.size(); i++){
                for(int j = 0; j < books[i].keyWords.size(); j++){
                    // cout << "books["<< i << "].keyWords[" <<j << "] is--" << books[i].keyWords[j] << "--" << endl;
                    // cout << "book id is " << books[i].id << endl;
                    if(tarS == books[i].keyWords[j]){
                        ans.push_back(books[i].id);
                        break;
                    }
                }
            }
        }
        else if(n == 4){
            for(int i = 0; i < books.size(); i++){
                if(books[i].publisher == tarS)
                    ans.push_back(books[i].id);
            }
        }
        else if(n == 5){
            for(int i = 0; i < books.size(); i++){
                int y = getNum(tarS);
                if(books[i].publishedYear == y)
                    ans.push_back(books[i].id);
            }
        }
        if(ans.size() == 0){
            cout << "Not Found" << endl;
        }
        for(int i = 0; i < ans.size(); i++)
            cout << setw(7) << setfill('0') << ans[i] << endl;
    }
    return 0;
}
