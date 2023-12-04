public class _12Soundex {
    
    private static char soundScore(char x) {
        switch (x) {
            case 'B', 'F', 'P', 'V':
                return '1';
            case 'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z':
                return '2';
            case 'D', 'T':
                return '3';
            case 'L':
                return '4';
            case 'M', 'N':
                return '5';
            case 'R':
                return '6';
            default:
                return '0';
        }

    }
    
    public static String soundex(String inString) {
        String outString="";
        inString = inString.toUpperCase();
        outString = outString + inString.charAt(0);
        
        for (int i = 1; i < inString.length(); i++) {
            if (soundScore(inString.charAt(i)) != '0'
                    && soundScore(inString.charAt(i - 1)) != soundScore(inString.charAt(i))) {
                outString = outString + soundScore(inString.charAt(i));
            }
        }

        if (outString.length() < 4)
            for (int k=outString.length(); k<=4; k++)
                outString = outString + '0';

        if(outString.length()>4)
            outString = outString.substring(0, 4);
        

        return outString;
    }

    public static void main(String[] args) {
        
        System.out.println(soundex("dtygfd"));
    }
}