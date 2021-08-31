#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<sstream>
#include <algorithm>
#include<string>
#include <map>
using namespace std;
int main()
{
    int tagNumber, attrNumber;
    cin >> tagNumber >> attrNumber;
    cin.ignore();
    map <string, string> tag; //!  storing attribute-value pairs
    string inputStr, tag_pre = "";

    //! get each HTML line
    for (int i = 0; i < tagNumber; i++) {
        getline(cin, inputStr);//!reading data

        // for each HTML line, break it up into token words
        stringstream ss(inputStr);//!parsing operation
        string word, attribute, value;
        size_t pos;
        while (getline(ss, word, ' ')) { //! for each token word
            if (word[0] == '<') {
                string tag;
                if (word[1] == '/') { //! it's tag closing
                    tag = word.substr(2);
                    tag = tag.substr(0, tag.length() - 1); //! get rid of ">"
                    pos = tag_pre.find("." + tag);
                    if (pos == string::npos) tag_pre = "";
                    else tag_pre = tag_pre.substr(0, pos);
                }
                else { //! it's tag opening
                    tag = word.substr(1);
                    if (tag.find(">") != string::npos)
                        tag = tag.substr(0, tag.length() - 1); //! get rid of ">"
                    if (tag_pre == "") tag_pre = tag;
                    else tag_pre = tag_pre + "." + tag;
                }
            }
            //! value detected
            else if (word[0] == '"') {
                pos = word.find_last_of('"');
                value = word.substr(1, pos - 1);
                tag[attribute] = value; //! insert into map
            }
            //! attribute name detected
            else if (word[0] != '=') {
                attribute = tag_pre + "~" + word;
            }
        }
    }
    for (int i = 0; i < attrNumber; i++) {
        getline(cin, inputStr);//!reading data(querys)
        if (tag.find(inputStr) == tag.end())//!control whether finding or not in the map
            cout << "Not Found!" << endl;
        else
            cout << tag[inputStr] << endl;
    }
    return 0;
}


