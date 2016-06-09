#include<iostream>
using namespace std;

struct subString{
    string word;
    int length;
};

void setWordIndex(int* wordIndexArr,string text);

int main(){
    string text;
    cout<<"Enter Text: ";
    getline(cin,text);


    int wordCount=1;
    for(int i=0;i<text.length();i++){
        if(text[i]==' '){
            wordCount++;
        }
    }
    //cout<<wordCount;
    int wordIndexArr[wordCount];
    setWordIndex(wordIndexArr,text);

    //extract words

    subString subWord[wordCount];

    int endIndex;
    int startIndex=0;
    int i=0;
    //cout<<wordCount;
    //cout<<wordIndexArr[3];
    while(i<wordCount){
        endIndex=wordIndexArr[i];
        int tempIndex=0;
        while(startIndex<endIndex){
            subWord[i].word[tempIndex]=text[startIndex];
            startIndex++;
            tempIndex++;
        }
        subWord[i].length=tempIndex;
        //insert into array of words
        startIndex=endIndex+1;
        i++;
    }

    //print
    //search for similar text
    for(int i=0;i<wordCount;i++){
        int wordCounter=1;
        int len=subWord[i].length;
        for(int j=i+1;j<wordCount;j++){
            if(len==subWord[j].length && subWord[j].length!=NULL){
                bool isMatch;
                for(int k=0;k<len;k++){
                    isMatch=false;
                    if(subWord[i].word[k]==subWord[j].word[k]){
                        wordCounter++;
                        isMatch=true;
                    }
                }
                wordCounter--;
                if(isMatch){
                    subWord[j].length=NULL;
                }
            }
        }
        if(subWord[i].length!=NULL){
            cout<<"Word at index("<<i<<") : "<<wordCounter+1<<endl;
        }

    }
}

void setWordIndex(int* wordIndexArr,string text){
    int j=0;
    for(int i=0;i<text.length();i++){
        if(text[i]==' '){
            wordIndexArr[j]=i;
            j++;
        }
    }
    wordIndexArr[j]=text.length();
}
