package com.company;

public class StringCompression {

//    This approach has O(p+n^2) complexity as adding of string results copying and then adding
//    public static String strCompress(String str){
//        String res="";
//        int count=1;
//        for(int i=0;i<str.length()-1;i++){
//            if(str.charAt(i)!=str.charAt(i+1)){
//                res = res+str.charAt(i)+Integer.toString(count);
//                count=1;
//            }
//            else
//                count++;
//        }
//        res = res+str.charAt(str.length()-1)+Integer.toString(count);
//        if(res.length()>str.length())
//            res = str;
//        return res;
//    }

//    String builder can be an optimization over this approach
//    public static String strCompress(String str){
//        StringBuilder res= new StringBuilder();
//        int count=1;
//        for(int i=0;i<str.length()-1;i++){
//            if(str.charAt(i)!=str.charAt(i+1)){
//                res.append(str.charAt(i));
//                res.append(Integer.toString(count));
//                count=1;
//            }
//            else
//                count++;
//        }
//        res.append(str.charAt(str.length()-1));
//        res.append(Integer.toString(count));
//        if(res.length()<=str.length())
//            return res.toString();
//        return str;
//    }

//    More optimization can be performed if we first check the length of compressed string

    public static String strCompress(String str){
        int finalLength = countCompression(str);
        if(finalLength>=str.length()) return str;

        StringBuilder res= new StringBuilder();
        int count=1;
        for(int i=0;i<str.length()-1;i++){
            if(str.charAt(i)!=str.charAt(i+1)){
                res.append(str.charAt(i));
                res.append(Integer.toString(count));
                count=1;
            }
            else
                count++;
        }
        res.append(str.charAt(str.length()-1));
        res.append(Integer.toString(count));
        return res.toString();
    }

    public static int countCompression(String str){
        int compressedLength = 0;
        int countConsecutive = 0;
        for(int i=0;i<str.length();i++){
            countConsecutive++;
            if(i+1>=str.length() || str.charAt(i)!=str.charAt(i+1)){
                compressedLength += 1 + String.valueOf(countConsecutive).length();
                countConsecutive=0;
            }
        }
        return compressedLength;
    }

    public static void main(String[] args){
        String s ="abcde";
        System.out.println(strCompress(s));
    }
}
