package com.company;

public class CheckPermutation {

//    private static String sort(String str){
//        char[] content = str.toCharArray();
//        java.util.Arrays.sort(content);
//        return new String(content);
//    }
//
//    private static boolean permutation(String s,String t){
//        if(s.length()!=t.length())
//            return false;
//        return sort(s).equals(sort(t));
//    }

//    More optimized approach
    private static boolean permutation(String s,String t){
        if(s.length()!=t.length())
            return false;

        int[] letters = new int[128];
        char[] s_array = s.toCharArray();
        for(char c:s_array)
            letters[c]++;

        for(int i=0;i<t.length();i++){
            int c = (int)t.charAt(i);
            letters[c]--;
            if(letters[c]<0)
                return false;
        }
        return true;
    }

    public static void main(String[] args){
        String s = "abcdegf";
        String t = "debcafg";
        System.out.println(permutation(s,t));
    }
}
