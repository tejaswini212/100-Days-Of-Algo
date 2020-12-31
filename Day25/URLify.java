package com.company;

public class URLify {
    public static void urlIfy(char[] str, int trueLength){
        int countSpace=0;
        int index;
        int i=0;
        for(i=0;i<trueLength;i++){
            if(str[i]==' ')
                countSpace++;
        }
        index = trueLength+(countSpace*2);
        if(trueLength<str.length)
            str[trueLength]='\0';
        for(i=trueLength-1;i>=0;i--){
            if(str[i]==' '){
                str[index-3]='%';
                str[index-2]='2';
                str[index-1]='0';
                index -= 3;
            }
            else{
                str[index-1]=str[i];
                index--;
            }
        }
    }

    public static void main(String[] args){
        String str="Mr John Smith    ";
        char[] ch = new char[str.length()];
        for (int i = 0; i < str.length(); i++) {
            ch[i] = str.charAt(i);
        }
        urlIfy(ch,13);
        System.out.println(ch);
    }
}
