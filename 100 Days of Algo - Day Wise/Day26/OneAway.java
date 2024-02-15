package com.company;

import static java.lang.Math.abs;

public class OneAway {
    public static boolean ifOneAway(String s,String t){
        if(abs(s.length()-t.length())>1)
            return false;
        if(s==t)
            return true;
        int i1=0,i2=0;
        boolean foundDiff = false;
        String s1 = s.length()<t.length()?s:t;
        String s2 = s.length()<t.length()?t:s;

        while(i1<s1.length() && i2<s2.length()){
            if(s1.charAt(i1)!=s2.charAt(i2)){
                if(foundDiff)
                    return false;
                foundDiff=true;
                if(s1.length()==s2.length())
                    i1++;
            }else
                i1++;
            i2++;
        }
        return true;
    }

    public static void main(String[] args){
        String s="pale";
        String t="bale";
        System.out.println(ifOneAway(s,t));
    }
}
