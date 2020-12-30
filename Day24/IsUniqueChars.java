package com.company;

public class  IsUniqueChars{
//    static boolean isUniqueChars(String str){
//        if(str.length()>128)
//            return false;
//        boolean[] char_set = new boolean[128];
//        for(int i=0;i<str.length();i++){
//            int val = str.charAt(i);
//            if(char_set[val])
//                return false;
//            char_set[val]=true;
//        }
//        return true;
//    }

//    Space optimized approach:
//    Assume that the string will contain only lowercase 'a' to 'z'

    static boolean isUniqueChars(String str){
        int checker = 0;
        for(int i=0;i<str.length();i++){
            int val = str.charAt(i)-'a';
            if((checker & (1<<val))!=0)
                return false;
            checker = checker | (1<<val);
        }
        return true;
    }

    public static void main(String[] args) {
	    String s1 = "12341";
        System.out.println(isUniqueChars(s1));
    }
}
