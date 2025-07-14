//Topic 5
public class Topic_5 {
    public static void main(String[] args){
        String s1 = "Hasibujjaman", s2 = "Chowdhury";
        System.out.println(s1);
        System.out.println("The first character is: " +s1.charAt(0));
        System.out.println("String 1: "+s1);
        System.out.println("String 2: "+s2);
        int d = s1.compareTo(s2);
        if(d>0)
            System.out.println("Sring 1 is greater than String 2 lexicographically");
        else if ( d < 0)
            System.out.println("Sring 2 is greater than String 1 lexicographically");
        else 
            System.out.println("Sring 1 and String 2 are equal lexicographically");
        String s3 = s1.concat(" Chowdhury");
        System.out.println(s3);
        s3 = s1.concat(" ").concat(s2).concat(" Emon");
        System.out.println(s3);
        boolean check = s1.equals("Hasibujjaman");
        if(check) System.out.println("String 1 and String 2 are eqaul character by character");
        check = s1.isEmpty();
        if(!check) System.out.println("String 1 is not empty");
        int length = s1.length();
        System.out.println("Length of sting 1 is: "+length);
        String s4 = s1.replace("a","e");
        System.out.println(s4);
        s4 = s3.replace("Chowdhury","");
        System.out.println(s4);
        s3 = s4.substring(0,12);
        System.out.println(s3);
        s4 = s1.toLowerCase();
        System.out.println(s4);
        s4 = s1.toUpperCase();
        System.out.println(s4);
        s4 = s1.toString();
        System.out.println(s4);
        s1 = "  Emon Chowdhury     ";
        s4 = s1.trim();
        System.out.println(s4);

    }
}
